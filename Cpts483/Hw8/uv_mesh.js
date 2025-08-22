const VERTEX_STRIDE = 36;

class UvMesh {
    constructor(gl, program, vertices, indices, material) {
        this.gl = gl;
        this.program = program;
        this.material = material;

        // Create and load vertex buffer
        this.verts = this.createAndLoadVertexBuffer(gl, vertices);
        this.indis = this.createAndLoadIndexBuffer(gl, indices);

        this.nVerts = vertices.length;
        this.nIndis = indices.length;

    }

    createAndLoadVertexBuffer(gl, data) {
        const buffer = gl.createBuffer();
        gl.bindBuffer(gl.ARRAY_BUFFER, buffer);
        gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(data), gl.STATIC_DRAW);
        return buffer;
    }

    createAndLoadIndexBuffer(gl, data) {
        const buffer = gl.createBuffer();
        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, buffer);
        gl.bufferData(gl.ELEMENT_ARRAY_BUFFER, new Uint16Array(data), gl.STATIC_DRAW);
        return buffer;
    }

    setVertexAttributes() {
        const gl = this.gl;
        // Position Attribute
        const coordinates = gl.getAttribLocation(this.program, "coordinates");
        if (coordinates >= 0) {  // Those checks are helpful to remove the errors
            gl.bindBuffer(gl.ARRAY_BUFFER, this.verts);
            gl.vertexAttribPointer(coordinates, 3, gl.FLOAT, false, VERTEX_STRIDE, 0);
            gl.enableVertexAttribArray(coordinates);
        }
    
        // Color Attribute
        const color = gl.getAttribLocation(this.program, "color");
        if (color >= 0) {
            gl.vertexAttribPointer(color, 4, gl.FLOAT, false, VERTEX_STRIDE, 12);
            gl.enableVertexAttribArray(color);
        }
    
        // UV Attribute
        const uv = gl.getAttribLocation(this.program, "uv");
        if (uv >= 0) {
            gl.vertexAttribPointer(uv, 2, gl.FLOAT, false, VERTEX_STRIDE, 28);
            gl.enableVertexAttribArray(uv);
        }
    }
    
    static uvSphere(gl, program, radius, subdivisions, material) {
        const vertices = [];
        const indices = [];

        for (let i = 0; i <= subdivisions; i++) {
            const theta = (i * Math.PI) / subdivisions;
            const sinTheta = Math.sin(theta);
            const cosTheta = Math.cos(theta);

            for (let j = 0; j <= subdivisions; j++) {
                const phi = (j * 2 * Math.PI) / subdivisions;
                const sinPhi = Math.sin(phi);
                const cosPhi = Math.cos(phi);

                const x = cosPhi * sinTheta;
                const y = cosTheta;
                const z = sinPhi * sinTheta;

                const r = 1.0, g = 1.0, b = 1.0, a = 1.0;
                const u = j / subdivisions;
                const v = i / subdivisions;

                vertices.push(
                    x * radius, y * radius, z * radius,  // Position
                    r, g, b, a,                          // Color
                    u, v                                 // UV coordinates
                );
            }
        }

        for (let i = 0; i < subdivisions; i++) {
            for (let j = 0; j < subdivisions; j++) {
                const first = (i * (subdivisions + 1)) + j;
                const second = first + subdivisions + 1;

                indices.push(first, second, first + 1);
                indices.push(second, second + 1, first + 1);
            }
        }

        return new UvMesh(gl, program, vertices, indices, material);
    }

    render(gl) {
        gl.enable(gl.CULL_FACE);
        gl.useProgram(this.program);

        this.setVertexAttributes();
        gl.bindBuffer(gl.ARRAY_BUFFER, this.verts);
        gl.bindBuffer(gl.ELEMENT_ARRAY_BUFFER, this.indis);
        
        gl.activeTexture(gl.TEXTURE0);
        this.material.bind(gl);

        gl.drawElements(gl.TRIANGLES, this.nIndis, gl.UNSIGNED_SHORT, 0);
    }
    
}