const canvas = document.getElementById('the-canvas');
const gl = canvas.getContext('webgl2');

if (!gl) {
    console.error('WebGL not supported');
}

gl.viewport(0, 0, canvas.width, canvas.height);


const vertexShaderSource = `
    attribute vec4 coordinates;
    uniform mat4 u_modelViewMatrix;
    varying vec4 vColor;

    void main(void) {
        gl_Position = u_modelViewMatrix * coordinates;
        vColor = coordinates; // Assign colors based on vertex position
    }
`;

const fragmentShaderSource = `
    precision mediump float;
    void main(void) {
        gl_FragColor = vec4(vec3(gl_FragCoord.z), 1.0); // Depth shader for debugging
    }
`;


let shaderProgram = initShaders(gl, vertexShaderSource, fragmentShaderSource);
if (!shaderProgram) {
    console.error('Failed to initialize shaders.');
}

// Complete cube vertices (positions of each corner of the cube)
const vertices = [
    // Front face
    -1, -1,  1,  // bottom left
     1, -1,  1,  // bottom right
     1,  1,  1,  // top right
    -1,  1,  1,  // top left

    // Back face
    -1, -1, -1,  // bottom left
     1, -1, -1,  // bottom right
     1,  1, -1,  // top right
    -1,  1, -1,  // top left

    // Left face
    -1, -1, -1,  // back bottom left
    -1,  1, -1,  // back top left
    -1,  1,  1,  // front top left
    -1, -1,  1,  // front bottom left

    // Right face
     1, -1, -1,  // back bottom right
     1,  1, -1,  // back top right
     1,  1,  1,  // front top right
     1, -1,  1,  // front bottom right

    // Top face
    -1,  1, -1,  // back top left
     1,  1, -1,  // back top right
     1,  1,  1,  // front top right
    -1,  1,  1,  // front top left

    // Bottom face
    -1, -1, -1,  // back bottom left
     1, -1, -1,  // back bottom right
     1, -1,  1,  // front bottom right
    -1, -1,  1,  // front bottom left
];

// Cube indices to define faces
// Each group of 6 values defines two triangles forming a square face
const indices = [
    // Front face
    0, 1, 2,  2, 3, 0,

    // Back face
    4, 5, 6,  6, 7, 4,

    // Left face
    8, 9, 10,  10, 11, 8,

    // Right face
    12, 13, 14,  14, 15, 12,

    // Top face
    16, 17, 18,  18, 19, 16,

    // Bottom face
    20, 21, 22,  22, 23, 20
];

const cubeMesh = new Mesh(gl, shaderProgram, vertices, indices);

function render() {
    gl.clearColor(0.53, 0.81, 0.98, 1.0);
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
    gl.useProgram(shaderProgram);

   // const projectionMatrix = Mat4.perspective(90, canvas.width / canvas.height, 0.1, 1000);
    const projectionMatrix = Mat4.frustum(-1, 1, -1, 1, 1, 1000);

    const modelviewMatrix = Mat4.identity()
       .mul(Mat4.scale( 0.15, 0.15, 0.15 ))
       .mul(Mat4.rotation_y(performance.now() * 0.001 * 0.125 * 2 * Math.PI))  // Y-axis rotation
       // .mul(Mat4.rotation_xy(performance.now() * 0.125)) 
        .mul(Mat4.translation(0.0, 0.0, -3.5 ));

    const uModelViewMatrixLocation = gl.getUniformLocation(shaderProgram, 'u_modelViewMatrix');
    if (!uModelViewMatrixLocation) {
        console.error('u_modelViewMatrix location not found');
    }

    const combinedMatrix = projectionMatrix.mul(modelviewMatrix);
    gl.uniformMatrix4fv(uModelViewMatrixLocation, false, combinedMatrix.data);
    cubeMesh.render(gl);
    requestAnimationFrame(render);  
}

render();