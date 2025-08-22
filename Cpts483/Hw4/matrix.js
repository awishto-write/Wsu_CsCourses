class Mat4 {
    constructor(data) {
        this.data = data || [1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1];
    }

    static identity() {
        return new Mat4();
    }

    static rotation_y(angle) {
        const cosY = Math.cos(angle);
        const sinY = Math.sin(angle);
        return new Mat4([
            cosY, 0, sinY, 0,
            0, 1, 0, 0,
            -sinY, 0, cosY, 0,
            0, 0, 0, 1
        ]);
    }

    static rotation_xy(turns) {
        const angle = turns * 2 * Math.PI;
        const cosX = Math.cos(angle);
        const sinX = Math.sin(angle);
        return new Mat4([cosX, -sinX, 0, 0, sinX, cosX, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]);
    }

    static perspective(fov, aspect, near, far) {
        const f = 1.0 / Math.tan((fov * Math.PI) / 360.0);  
        const rangeInv = 1.0 / (near - far);

        return new Mat4([
            f / aspect, 0, 0, 0,
            0, f, 0, 0,
            0, 0, (near + far) * rangeInv, -1,
            0, 0, near * far * rangeInv * 2, 0
        ]);
    }

    static scale(sx, sy, sz) {
        return new Mat4([
            sx, 0, 0, 0,
            0, sy, 0, 0,
            0, 0, sz, 0,
            0, 0, 0, 1
        ]);
    }

    static translation(dx, dy, dz) {
        return new Mat4([1, 0, 0, dx, 0, 1, 0, dy, 0, 0, 1, dz, 0, 0, 0, 1]);
    }

    mul(right) {
        const a = this.data;
        const b = right.data;
        const result = new Array(16).fill(0);
        for (let row = 0; row < 4; row++) {
            for (let col = 0; col < 4; col++) {
                for (let i = 0; i < 4; i++) {
                    result[row * 4 + col] += a[row * 4 + i] * b[i * 4 + col];
                }
            }
        }
        return new Mat4(result);
    }

    static perspective(fov, aspect, near, far) {
        const f = 1.0 / Math.tan((fov * Math.PI) / 360.0);  // Convert FOV to radians
        const rangeInv = 1.0 / (near - far);

        return new Mat4([
            f / aspect, 0, 0, 0,
            0, f, 0, 0,
            0, 0, (near + far) * rangeInv, -1,
            0, 0, near * far * rangeInv * 2, 0
        ]);
    }
}
