window.onload = function() {
  const canvas = document.getElementById('the-canvas');
  const gl = canvas.getContext('webgl2');
  if (!gl) {
      console.error('Unable to initialize WebGL.');
      return;
  }

  const mat4 = glMatrix.mat4;
  const vec3 = glMatrix.vec3;
  const mat3 = glMatrix.mat3;

  const vertexShaderSource = `
      attribute vec3 coordinates;
      attribute vec4 color;
      varying vec4 vColor;
      uniform mat4 uVPMatrix;
      uniform mat3 uOrdMatrix;
      void main(void) {
          gl_Position = uVPMatrix * vec4(coordinates, 1.0);
          vColor = color;
      }
  `;

  const fragmentShaderSource = `
      precision mediump float;
      varying vec4 vColor;
      void main(void) {
          gl_FragColor = vColor;
      }
  `;

  const program = create_compile_and_link_program(gl, vertexShaderSource, fragmentShaderSource);
  if (!program) return; // Stop if shaders failed
  gl.useProgram(program);

  // Enable depth testing
  gl.enable(gl.DEPTH_TEST);
  gl.depthFunc(gl.LEQUAL);
  gl.enable(gl.CULL_FACE);
  gl.cullFace(gl.BACK);

   // Create the mesh
  const mesh = Mesh.box(gl, program, 1, 1, 1);

  const cubeVertices = new Float32Array([
      // Front face
      -0.5, -0.5, 0.5,  1.0, 0.0, 0.0, 1.0,  // Red
       0.5, -0.5, 0.5,  0.0, 1.0, 0.0, 1.0,  // Green
       0.5,  0.5, 0.5,  0.0, 0.0, 1.0, 1.0,  // Blue
      -0.5,  0.5, 0.5,  1.0, 1.0, 0.0, 1.0,  // Yellow

      // Back face
      -0.5, -0.5, -0.5,  1.0, 0.0, 1.0, 1.0,  // Purple
       0.5, -0.5, -0.5,  0.0, 1.0, 1.0, 1.0,  // Cyan
       0.5,  0.5, -0.5,  1.0, 0.5, 0.5, 1.0,  // Pink
      -0.5,  0.5, -0.5,  0.5, 1.0, 0.5, 1.0   // Light Green
  ]);

  const indices = new Uint16Array([
      0, 1, 2,  2, 3, 0,  // Front face
      4, 5, 6,  6, 7, 4,  // Back face
      3, 2, 6,  6, 7, 3,  // Top face
      0, 1, 5,  5, 4, 0,  // Bottom face
      0, 3, 7,  7, 4, 0,  // Left face
      1, 2, 6,  6, 5, 1   // Right face
  ]);

  const vertexBuffer = gl.createBuffer();
  gl.bindBuffer(gl.ARRAY_BUFFER, vertexBuffer);
  gl.bufferData(gl.ARRAY_BUFFER, cubeVertices, gl.STATIC_DRAW);

  const indexBuffer = gl.createBuffer();
  gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, indexBuffer);
  gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, indices, gl.STATIC_DRAW);

  const positionLocation = gl.getAttribLocation(program, 'coordinates');
  const colorLocation = gl.getAttribLocation(program, 'color');
  const vpMatrixLocation = gl.getUniformLocation(program, 'uVPMatrix');
  const ordMatrixLocation = gl.getUniformLocation(program, 'uOrdMatrix');

  gl.vertexAttribPointer(positionLocation, 3, gl.FLOAT, false, 7 * Float32Array.BYTES_PER_ELEMENT, 0);
  gl.enableVertexAttribArray(positionLocation);
  gl.vertexAttribPointer(colorLocation, 4, gl.FLOAT, false, 7 * Float32Array.BYTES_PER_ELEMENT, 3 * Float32Array.BYTES_PER_ELEMENT);
  gl.enableVertexAttribArray(colorLocation);

  let viewMatrix = mat4.create();
  let projectionMatrix = mat4.create();
  let matCam = mat4.create();
  let ordMatrix = mat3.create();

  // let posCam = [0, 0, 5];
  // let rotCam = [0, 0, 0];
  let posCam = vec3.fromValues(0, 0, 5);
  let rotCam = vec3.create();  // Rotation initialized as zero vector

  const keys = {};
  window.addEventListener('keydown', (event) => (keys[event.key] = true));
  window.addEventListener('keyup', (event) => (keys[event.key] = false));

  function updateCamera() {
      const moveSpeed = 0.1;
      const rotSpeed = 0.02;

      if (keys['w']) vec3.add(posCam, posCam, [0, 0, -moveSpeed]);
      if (keys['s']) vec3.add(posCam, posCam, [0, 0, moveSpeed]);
      if (keys['a']) vec3.add(posCam, posCam, [-moveSpeed, 0, 0]);
      if (keys['d']) vec3.add(posCam, posCam, [moveSpeed, 0, 0]);
      if (keys[' ']) vec3.add(posCam, posCam, [0, moveSpeed, 0]);
      if (keys['c']) vec3.add(posCam, posCam, [0, -moveSpeed, 0]);

      if (keys['ArrowLeft']) rotCam[1] += rotSpeed;
      if (keys['ArrowRight']) rotCam[1] -= rotSpeed;
      if (keys['ArrowUp']) rotCam[0] += rotSpeed;
      if (keys['ArrowDown']) rotCam[0] -= rotSpeed;
      if (keys['q']) rotCam[2] += rotSpeed;
      if (keys['e']) rotCam[2] -= rotSpeed;

      mat4.identity(matCam);
      mat4.rotateX(matCam, matCam, rotCam[0]);
      mat4.rotateY(matCam, matCam, rotCam[1]);
      mat4.rotateZ(matCam, matCam, rotCam[2]);

      mat4.translate(matCam, matCam, [-posCam[0], -posCam[1], -posCam[2]]);
      mat4.invert(viewMatrix, matCam);
      mat3.normalFromMat4(ordMatrix, viewMatrix);
  }

  function frustum(left, right, bottom, top, near, far) {
      const matrix = mat4.create();
      mat4.set(
          matrix,
          (2 * near) / (right - left), 0, (right + left) / (right - left), 0,
          0, (2 * near) / (top - bottom), (top + bottom) / (top - bottom), 0,
          0, 0, -(far + near) / (far - near), (-2 * far * near) / (far - near),
          0, 0, -1, 0
      );
      return matrix;
  }

  function render() {
      gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

      updateCamera();

      gl.clearColor(0.53, 0.81, 0.98, 1.0);
      gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);

      projectionMatrix = frustum(-1.0, 1.0, -1.0, 1.0, 1.0, 100.0);
      const vpMatrix = mat4.create();
      mat4.multiply(vpMatrix, projectionMatrix, viewMatrix);

      gl.uniformMatrix4fv(vpMatrixLocation, false, vpMatrix);
      gl.uniformMatrix3fv(ordMatrixLocation, false, ordMatrix);

      gl.drawElements(gl.TRIANGLES, indices.length, gl.UNSIGNED_SHORT, 0);

      mesh.render(gl);

      requestAnimationFrame(render);
  }

  function create_compile_and_link_program(gl, vertexShaderSource, fragmentShaderSource) {
    // Compile vertex shader
    const vertexShader = gl.createShader(gl.VERTEX_SHADER);
    gl.shaderSource(vertexShader, vertexShaderSource);
    gl.compileShader(vertexShader);
    if (!gl.getShaderParameter(vertexShader, gl.COMPILE_STATUS)) {
        console.error('Vertex shader compilation error:', gl.getShaderInfoLog(vertexShader));
        return null;
    }
  
    // Compile fragment shader
    const fragmentShader = gl.createShader(gl.FRAGMENT_SHADER);
    gl.shaderSource(fragmentShader, fragmentShaderSource);
    gl.compileShader(fragmentShader);
    if (!gl.getShaderParameter(fragmentShader, gl.COMPILE_STATUS)) {
        console.error('Fragment shader compilation error:', gl.getShaderInfoLog(fragmentShader));
        return null;
    }
  
    // Link the shaders into a program
    const program = gl.createProgram();
    gl.attachShader(program, vertexShader);
    gl.attachShader(program, fragmentShader);
    gl.linkProgram(program);
  
    if (!gl.getProgramParameter(program, gl.LINK_STATUS)) {
        console.error('Program linking error:', gl.getProgramInfoLog(program));
        return null;
    }
  
    return program;
  }
  
  render();
};