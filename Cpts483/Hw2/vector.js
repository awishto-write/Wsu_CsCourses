
class Vec4 {

    constructor( x, y, z, w ) {
        this.x = x;
        this.y = y;
        this.z = z;
        this.w = w ?? 0;
    }

    /**
     * Returns the vector that is this vector scaled by the given scalar.
     * @param {number} by the scalar to scale with 
     * @returns {Vec4}
     */
    scaled(scalar) {
        return new Vec4(this.x * scalar, this.y * scalar, this.z * scalar, this.w * scalar);
    }

    /**
     * Returns the dot product between this vector and other
     * @param {Vec4} other the other vector 
     * @returns {number}
     */
    // dot( other ) {
        
    //     // return the dot product 
    // }
    dot(other) {
        return this.x * other.x + this.y * other.y + this.z * other.z + this.w * other.w;
    }

    /**
     * Returns the length of this vector
     * @returns {number}
     */
    // }
    length() {
        return Math.sqrt(this.x ** 2 + this.y ** 2 + this.z ** 2 + this.w ** 2);
    }

    /**
     * Returns a normalized version of this vector
     * @returns {Vec4}
     */
    norm() {
        const len = this.length();
        if (len === 0) return new Vec4(0, 0, 0, 0); // Avoid division by zero
        return new Vec4(this.x / len, this.y / len, this.z / len, this.w / len);
    }

    /**
     * Returns the vector sum between this and other.
     * @param {Vec4} other 
     */
    // add( other ) {
        
    //     // return the vector sum
    // }
    add(other) {
        return new Vec4(this.x + other.x, this.y + other.y, this.z + other.z, this.w + other.w);
    }

    // sub( other ) {
    //     return this.add( other.scaled( -1 ) );
    // }
    sub(other) {
        return new Vec4(this.x - other.x, this.y - other.y, this.z - other.z, this.w - other.w);
    }

    cross(other) {
        let x = this.y * other.z - this.z * other.y;
        let y = this.z * other.x - this.x * other.z;
        let z = this.x * other.y - this.y * other.x;
        return new Vec4(x, y, z, 0); // Cross product results in a Vec3 with w=0
    }
	
	toString() {
		return [ '[', this.x, this.y, this.z, this.w, ']' ].join( ' ' );
	}
}