const canvas = document.getElementById('the-canvas');
//const gl = canvas.getContext('webgl');
const gl = canvas.getContext( 'webgl2' );

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
        float grayscaleValue = coordinates.y * 0.5 + 0.5;
        vColor = vec4(grayscaleValue, grayscaleValue, grayscaleValue, 1.0);
    }
`;

const fragmentShaderSource = `
    precision mediump float;
    void main(void) {
        gl_FragColor = vec4(0.3, 0.3, 0.3, 1.0);  // Uniform gray color for the teapot
    }
`;

let shaderProgram = initShaders(gl, vertexShaderSource, fragmentShaderSource);
if (!shaderProgram) {
    console.error('Failed to initialize shaders.');
}

let teapotMesh; 
Mesh.from_obj_file(gl, './teapot.obj', shaderProgram, function(mesh) {
    teapotMesh = mesh; 
    console.log('Mesh loaded successfully:', mesh);
    render();  
}, function(error) {
    console.error('Error loading OBJ file:', error);
});

function render() {
    gl.clearColor(0.53, 0.81, 0.98, 1.0);
    gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
    gl.enable(gl.DEPTH_TEST);

    gl.useProgram(shaderProgram);

    const projectionMatrix = Mat4.perspective(45, canvas.width / canvas.height, 0.1, 1000);

    const modelviewMatrix = Mat4.identity()
        .mul(Mat4.scale(0.02, 0.02, 0.02)) // Scale to fit the canvas
       // .mul(Mat4.rotation_xy(performance.now() * 0.001 * 0.25))  // Rotate the teapot
        .mul(Mat4.rotation_xy(performance.now() * 0.001 * 0.25)) 
        //.mul(Mat4.translation(0, 2, -50)); 
        .mul(Mat4.translation(0, 0, -50)); 
    

    const uModelViewMatrixLocation = gl.getUniformLocation(shaderProgram, 'u_modelViewMatrix');
    if (uModelViewMatrixLocation === null) {
        console.error('Uniform "u_modelViewMatrix" not found.');
        return;
    }

    const combinedMatrix = projectionMatrix.mul(modelviewMatrix);
    gl.uniformMatrix4fv(uModelViewMatrixLocation, false, combinedMatrix.data);
    //gl.uniformMatrix4fv(uModelViewMatrixLocation, false, modelviewMatrix.data);

    // Ensure the mesh is loaded and then render it
    if (teapotMesh) {
        teapotMesh.render(gl);
        console.log('Rendering teapot...');
    } else {
        console.log('Waiting for mesh to load...');
    }

    requestAnimationFrame(render);  // Continue the animation loop
}

