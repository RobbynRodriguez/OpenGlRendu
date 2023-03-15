#version 330 core
layout (location = 0) out vec4 FragColor;
layout (location = 1) out vec4 BrightColor;

in VS_OUT {
    vec3 FragPos;
    vec3 Normal;
    vec2 TexCoords;
} fs_in;

struct Light {
    vec3 Position;
    vec3 Color;
};

uniform Light lights[2];
uniform sampler2D diffuseTexture;
uniform vec3 viewPos;
uniform bool blinn;

void main()
{
    vec3 color = texture(diffuseTexture, fs_in.TexCoords).rgb;
    // ambient
    vec3 ambient = 0.05 * color;
//  // diffuse
//     vec3 lightDir = normalize(lightPos - fs_in.FragPos);
    vec3 normal = normalize(fs_in.Normal);
//     float diff = max(dot(lightDir, normal), 0.0);
//     vec3 diffuse = diff * color;
//  // specular
    vec3 lighting = vec3(0.0);
    vec3 viewDir = normalize(viewPos - fs_in.FragPos);
    float spec = 0.0;
    for(int i = 0; i < 1; i++)
    {
    // diffuse
    vec3 lightDir = normalize(lights[i].Position - fs_in.FragPos);
    vec3 reflectDir = reflect(-lightDir, normal);

    if(blinn)
    {
        vec3 halfwayDir = normalize(lightDir + viewDir);
        spec = pow(max(dot(normal, halfwayDir), 0.0), 32.0);
    }
    else
    {
        vec3 reflectDir = reflect(-lightDir, normal);
        spec = pow(max(dot(viewDir, reflectDir), 0.0), 8.0);
    }

    float diff = max(dot(lightDir, normal), 0.0);
    vec3 result = lights[i].Color * diff * color;
    float distance = length(fs_in.FragPos - lights[i].Position);
    result *= 1.0 / (distance * distance);
    lighting += result;

    }
    vec3 specular = vec3(0.3) * spec; // assuming bright white light color

    vec3 result = ambient + lighting + specular;
    // check whether result is higher than some threshold, if so, output as bloom threshold color
    float brightness = dot(result, vec3(0.2126, 0.7152, 0.0722));
    if(brightness > 1.0)
        BrightColor = vec4(result, 1.0);
    else
        BrightColor = vec4(0.0, 0.0, 0.0, 1.0);
    FragColor = vec4(result, 1.0);
}