class Mesh {
    constructor(gl, program, vertices, indices) {
        this.verts = create_and_load_vertex_buffer(gl, vertices, gl.STATIC_DRAW);
        this.indis = create_and_load_elements_buffer(gl, indices, gl.STATIC_DRAW);
        this.raw_indices = indices;
        this.n_verts = vertices.length / 3;
        this.n_indis = indices.length;
        this.program = program;
    }

    render(gl) {
        if (!this.verts || !this.indis) {
            console.error('Buffers not initialized');
            return;
        }

        gl.useProgram(this.program);
        gl.bindBuffer(gl.ARRAY_BUFFER, this.verts);
        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.indis);

        const coordinatesLocation = gl.getAttribLocation(this.program, "coordinates");
        if (coordinatesLocation === -1) {
            console.error("Coordinates attribute not found in the shader program.");
        } else {
            gl.enableVertexAttribArray(coordinatesLocation);
            gl.vertexAttribPointer(coordinatesLocation, 3, gl.FLOAT, false, 0, 0); 
        }

        gl.drawElements(gl.TRIANGLES, this.n_indis, gl.UNSIGNED_SHORT, 0);
    }
}