export function rotation_xy(angle) {
    const cosX = Math.cos(angle);
    const sinX = Math.sin(angle);
    return new Float32Array([
        cosX, -sinX, 0, 0,
        sinX, cosX, 0, 0,
        0, 0, 1, 0,
        0, 0, 0, 1
    ]);
}

export function rotation_xz(angle) {
    const cosX = Math.cos(angle);
    const sinX = Math.sin(angle);
    return new Float32Array([
        cosX, 0, -sinX, 0,
        0, 1, 0, 0,
        sinX, 0, cosX, 0,
        0, 0, 0, 1
    ]);
}

export function rotation_yz(angle) {
    const cosX = Math.cos(angle);
    const sinX = Math.sin(angle);
    return new Float32Array([
        1, 0, 0, 0,
        0, cosX, -sinX, 0,
        0, sinX, cosX, 0,
        0, 0, 0, 1
    ]);
}

export function animate(gl, program, now, last, rotations) {
    const time = (now - last) / 1000.0;
    last = now;

    rotations['XY'] += time * 0.25 * Math.PI * 2; // 0.25 turns/sec
    rotations['XZ'] += time * 0.5 * Math.PI * 2; // 0.5 turns/sec
    rotations['YZ'] += time * 0.05 * Math.PI * 2; //  0.05 turns/sec

    const matrixXY = rotation_xy(rotations['XY']); 
    const matrixXZ = rotation_xz(rotations['XZ']);
    const matrixYZ = rotation_yz(rotations['YZ']); 

    set_uniform_matrix4(gl, program, 'rotationMatrixXY', matrixXY);
    set_uniform_matrix4(gl, program, 'rotationMatrixXZ', matrixXZ);
    set_uniform_matrix4(gl, program, 'rotationMatrixYZ', matrixYZ);

    // clear the screen and draw the updated triangle
    gl.clear(gl.COLOR_BUFFER_BIT);
    gl.drawArrays(gl.TRIANGLES, 0, 3);

    // start the animation
    requestAnimationFrame(function(current) {
        animate(gl, program, current, last, rotations);
    });
    
}