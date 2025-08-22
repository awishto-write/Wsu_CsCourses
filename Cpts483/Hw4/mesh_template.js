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

    static from_obj_file(gl, file_name, program, successCallback, errorCallback) {
        let request = new XMLHttpRequest();
        request.onreadystatechange = function() {
            if (request.readyState != 4) { return; }
            if (request.status != 200) {
                if (errorCallback) errorCallback(request.statusText);
                return;
            }
            let mesh = Mesh.from_obj_text(gl, program, request.responseText);
            successCallback(mesh);
        };
        request.open('GET', file_name);
        request.send();
    }

    static from_obj_text(gl, program, text) {
        let lines = text.split('\n');
        let vertices = [];
        let indices = [];

        for (let line of lines) {
            if (line.startsWith('v ')) {
                let vertex = line.split(' ').slice(1).map(parseFloat);
                vertices.push(...vertex);
            }
            if (line.startsWith('f ')) {
                let face = line.split(' ').slice(1).map(i => parseInt(i) - 1);
                indices.push(...face);
            }
        }
        
        return new Mesh(gl, program, vertices, indices);
    }
}