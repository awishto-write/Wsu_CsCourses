//const VERTEX_STRIDE = 28;
const VERTEX_STRIDE = 20;

class Mesh {
    /** 
     * Creates a new mesh and loads it into video memory.
     * 
     * @param {WebGLRenderingContext} gl  
     * @param {number} program
     * @param {number[]} vertices
     * @param {number[]} indices
    */
    constructor( gl, program, vertices, indices ) {
        this.verts = create_and_load_vertex_buffer( gl, vertices, gl.STATIC_DRAW );
        this.indis = create_and_load_elements_buffer( gl, indices, gl.STATIC_DRAW );

        this.n_verts = vertices.length;
        this.n_indis = indices.length;
        this.program = program;
    }

    /**
     * Create a box mesh with the given dimensions and colors.
     * @param {WebGLRenderingContext} gl 
     * @param {number} width 
     * @param {number} height 
     * @param {number} depth 
     */

    // static box( gl, program, width, height, depth ) {
    //     let hwidth = width / 2.0;
    //     let hheight = height / 2.0;
    //     let hdepth = depth / 2.0;

    //     let verts = [
    //         hwidth, -hheight, -hdepth,      1.0, 0.0, 0.0, 1.0,
    //         -hwidth, -hheight, -hdepth,     0.0, 1.0, 0.0, 1.0,
    //         -hwidth, hheight, -hdepth,      0.0, 0.0, 1.0, 1.0,
    //         hwidth, hheight, -hdepth,       1.0, 1.0, 0.0, 1.0,

    //         hwidth, -hheight, hdepth,       1.0, 0.0, 1.0, 1.0,
    //         -hwidth, -hheight, hdepth,      0.0, 1.0, 1.0, 1.0,
    //         -hwidth, hheight, hdepth,       0.5, 0.5, 1.0, 1.0,
    //         hwidth, hheight, hdepth,        1.0, 1.0, 0.5, 1.0,
    //     ];

    //     let indis = [
    //         // clockwise winding
    //         /*
    //         0, 1, 2, 2, 3, 0, 
    //         4, 0, 3, 3, 7, 4, 
    //         5, 4, 7, 7, 6, 5, 
    //         1, 5, 6, 6, 2, 1,
    //         3, 2, 6, 6, 7, 3,
    //         4, 5, 1, 1, 0, 4,
    //         */

    //         // counter-clockwise winding
    //         0, 3, 2, 2, 1, 0,
    //         4, 7, 3, 3, 0, 4,
    //         5, 6, 7, 7, 4, 5,
    //         1, 2, 6, 6, 5, 1,
    //         3, 7, 6, 6, 2, 3,
    //         4, 0, 1, 1, 5, 4,
    //     ];

    //     return new Mesh( gl, program, verts, indis );
    // }

    // So we need 24 vertices, 6 faces (having a squad '4')

    static box(gl, program, width, height, depth) {
        const hwidth = width / 2;
        const hheight = height / 2;
        const hdepth = depth / 2;

        const verts = [
             // Green leaves (back face) - Done
            hwidth,  hheight,  hdepth,   0.5, 0.25,   // Top-right
            -hwidth,  hheight,  hdepth,  0.75, 0.25,   // Top-left
            -hwidth, -hheight,  hdepth,  0.75, 0.5,   // Bottom-left
            hwidth, -hheight,  hdepth,   0.5, 0.5,   // Bottom-right

            // Spiral (front face) - Done
            hwidth,  hheight, -hdepth,   0.25, 0.25,   // Top-right
           -hwidth,  hheight, -hdepth,   0, 0.25,   // Top-left
           -hwidth, -hheight, -hdepth,   0, 0.5,   // Bottom-left
            hwidth, -hheight, -hdepth,   0.25, 0.5,   // Bottom-right

             // Wood (left side from front) - Done
            -hwidth,  hheight,  hdepth,   1, 0.25,   // Top-front
            -hwidth,  hheight, -hdepth,   0.75, 0.25,   // Top-back
            -hwidth, -hheight, -hdepth,   0.75, 0.5,   // Bottom-back
            -hwidth, -hheight,  hdepth,   1, 0.5,   // Bottom-front
        
            // Gray brick (right side from front) - Done
            hwidth,  hheight,  hdepth,   0.5, 0.25,   // Top-front
            hwidth,  hheight, -hdepth,   0.25, 0.25,   // Top-back
            hwidth, -hheight, -hdepth,   0.25, 0.5,   // Bottom-back
            hwidth, -hheight,  hdepth,   0.5, 0.5,   // Bottom-front

            // Small rocks (top face) - Done
            hwidth,  hheight,  hdepth,   0.5, 0,   // Front-right
           -hwidth,  hheight,  hdepth,   0.75, 0,   // Front-left
           -hwidth,  hheight, -hdepth,   0.75, 0.25,   // Back-left
            hwidth,  hheight, -hdepth,   0.5, 0.25,   // Back-right

            // Colorful brick (bottom face) - Done
            hwidth, -hheight,  hdepth,   0.5, 0.5,   // Front-right
           -hwidth, -hheight,  hdepth,   0.75, 0.5,   // Front-left
           -hwidth, -hheight, -hdepth,   0.75, 0.75,   // Back-left
            hwidth, -hheight, -hdepth,   0.5, 0.75    // Back-right
        ];

        const indis = [
            // Back face
            0, 1, 2,   0, 2, 3,
            // Front face
            4, 5, 6,   4, 6, 7,
            // Left face
            8, 9, 10,  8, 10, 11,
            // Right face
            12, 13, 14, 12, 14, 15,
            // Top face
            16, 17, 18, 16, 18, 19,
            // Bottom face
            20, 21, 22, 20, 22, 23
        ];

        return new Mesh(gl, program, verts, indis);
    }


    /**
     * Render the mesh. Does NOT preserve array/index buffer or program bindings! 
     * 
     * @param {WebGLRenderingContext} gl 
     */
    render( gl ) {
        gl.enable(gl.DEPTH_TEST); // Just added
        gl.depthFunc(gl.LEQUAL);  // Just added

        gl.cullFace( gl.BACK );
        //gl.enable( gl.CULL_FACE );
        gl.disable(gl.CULL_FACE);
        
        gl.useProgram( this.program );
        gl.bindBuffer( gl.ARRAY_BUFFER, this.verts );
        gl.bindBuffer( gl.ELEMENT_ARRAY_BUFFER, this.indis );

        set_vertex_attrib_to_buffer( 
            gl, this.program, 
            "coordinates", 
            this.verts, 3, 
            gl.FLOAT, false, 
            5 * Float32Array.BYTES_PER_ELEMENT, 0
        );

        // set_vertex_attrib_to_buffer( 
        //     gl, this.program, 
        //     "color", 
        //     this.verts, 4, 
        //     gl.FLOAT, false, VERTEX_STRIDE, 12
       // );

        set_vertex_attrib_to_buffer(
            gl, this.program, 
            "uv", 
            this.verts, 2, 
            gl.FLOAT, false, 
            5 * Float32Array.BYTES_PER_ELEMENT,
            3 * Float32Array.BYTES_PER_ELEMENT
        );

        gl.drawElements( gl.TRIANGLES, this.n_indis, gl.UNSIGNED_SHORT, 0 );
    }

    /**
     * Parse the given text as the body of an obj file.
     * @param {WebGLRenderingContext} gl
     * @param {WebGLProgram} program
     * @param {string} text
     */
    static from_obj_text( gl, program, text ) {
        let lines = text.split( /\r?\n/ );

        let verts = [];
        let indis = [];
        

        for( let line of lines ) {
            let trimmed = line.trim();
            let parts = trimmed.split( /(\s+)/ );

            if( 
                parts === null || parts.length < 2 || 
                parts[0] == '#' || parts[0] === '' ) 
            { 
                continue; 
            }
            else if( parts[0] == 'v' ) {
                
                verts.push( parseFloat( parts[2] ) );
                verts.push( parseFloat( parts[4] ) );
                verts.push( parseFloat( parts[6] ) );
                
                // color data
                verts.push( 1, 1, 1, 1 );
            }
            else if( parts[0] == 'f' ) {
                indis.push( parseInt( parts[2] ) - 1 );
                indis.push( parseInt( parts[4] ) - 1 );
                indis.push( parseInt( parts[6] ) - 1 );
            }
            else {
                console.log( parts) ;
                throw new Error( 'unsupported obj command: ', parts[0], parts );
            }
        }
		
		//console.log( verts.slice(540, 600) )
		// console.log( indis.slice(540, 600) )
        
        return new Mesh( gl, program, verts, indis );
    }

    /**
     * Asynchronously load the obj file as a mesh.
     * @param {WebGLRenderingContext} gl
     * @param {string} file_name 
     * @param {WebGLProgram} program
     * @param {function} f the function to call and give mesh to when finished.
     */
    static from_obj_file( gl, file_name, program, f ) {
        let request = new XMLHttpRequest();
        
        // the function that will be called when the file is being loaded
        request.onreadystatechange = function() {
            // console.log( request.readyState );

            if( request.readyState != 4 ) { return; }
            if( request.status != 200 ) { 
                throw new Error( 'HTTP error when opening .obj file: ', request.statusText ); 
            }

            // now we know the file exists and is ready
            let loaded_mesh = Mesh.from_obj_text( gl, program, request.responseText );

            console.log( 'loaded ', file_name );
            f( loaded_mesh );
        };

        
        request.open( 'GET', file_name ); // initialize request. 
        request.send();                   // execute request
    }
}