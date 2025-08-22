const vertexShaderSource = `#version 300 es
    precision mediump float;

    in vec3 coordinates;
    in vec3 normal;
    in vec2 uv;

    uniform mat4 modelview;
    uniform mat4 projection;
    uniform mat3 normalMatrix;

    out vec3 v_normal;
    out vec3 v_fragPos;
    out vec2 v_uv;

    void main() {
        v_fragPos = vec3(modelview * vec4(coordinates, 1.0));
        v_normal = normalize(normalMatrix * normal);
        v_uv = uv;
        gl_Position = projection * modelview * vec4(coordinates, 1.0);
    }
`;

const fragmentShaderSource = `#version 300 es
    precision mediump float;

    in vec3 v_normal;
    in vec3 v_fragPos;
    in vec2 v_uv;

    uniform sampler2D tex_0;

    // Directional Light
    uniform vec3 dirLightColor;
    uniform vec3 dirLightDirection;

    // Point Light
    uniform vec3 pointLightColor;
    uniform vec3 pointLightPos;
    uniform float ambientStrength;
    uniform float diffuseStrength;
    uniform float specularStrength;
    uniform float shininess;
    uniform vec3 viewPos;

    out vec4 fragColor;

    void main() {
        vec3 norm = normalize(v_normal);
        vec3 viewDir = normalize(viewPos - v_fragPos);

        // Directional Light Calculation
        vec3 dirLightDir = normalize(-dirLightDirection);
        float dirDiff = max(dot(norm, dirLightDir), 0.0);
        vec3 dirDiffuse = diffuseStrength * dirDiff * dirLightColor;

        vec3 dirReflectDir = reflect(-dirLightDir, norm);
        float dirSpec = pow(max(dot(viewDir, dirReflectDir), 0.0), shininess);
        vec3 dirSpecular = specularStrength * dirSpec * dirLightColor;

        // Point Light Calculation with Attenuation
        vec3 pointLightDir = normalize(pointLightPos - v_fragPos);
        float pointDistance = length(pointLightPos - v_fragPos);
        float attenuation = 1.0 / (1.0 + 0.09 * pointDistance + 0.032 * (pointDistance * pointDistance));
        
        float pointDiff = max(dot(norm, pointLightDir), 0.0);
        vec3 pointDiffuse = attenuation * diffuseStrength * pointDiff * pointLightColor;

        vec3 pointReflectDir = reflect(-pointLightDir, norm);
        float pointSpec = pow(max(dot(viewDir, pointReflectDir), 0.0), shininess);
        vec3 pointSpecular = attenuation * specularStrength * pointSpec * pointLightColor;

        // Ambient and Combined Lighting
        vec3 ambient = ambientStrength * (dirLightColor + pointLightColor);
        vec3 diffuse = dirDiffuse + pointDiffuse;
        vec3 specular = dirSpecular + pointSpecular;
        vec3 lighting = ambient + diffuse + specular;

        // Texture and Final Color
        vec4 textureColor = texture(tex_0, v_uv);
        fragColor = vec4(lighting, 1.0) * textureColor;
    }
`;