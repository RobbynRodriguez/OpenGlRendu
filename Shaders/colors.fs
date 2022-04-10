#version 330 core
out vec4 FragColor;

struct Material {
    sampler2D diffuse;
    sampler2D specular;
    float shininess;
};

struct Light {
    vec3 position;

    vec3 ambient;
    vec3 diffuse;
    vec3 specular;

    float constant;
    float linear;
    float quadratic;
};

in vec3 FragPos;
in vec3 Normal;
in vec2 TexCoords;

uniform vec3 viewPos;
uniform Material material;
uniform Light light[3];

void main()
{
    // ambient
    vec3 result,ambient;
//     vec3 ambient = light.ambient * texture(material.diffuse, TexCoords).rgb;
    for(int i = 0 ; i< 3 ; i++){
        ambient += light[i].ambient * texture(material.diffuse, TexCoords).rgb;

    // diffuse
        vec3 norm = normalize(Normal);
        vec3 lightDir = normalize(light[i].position - FragPos);
        float diff = max(dot(norm, lightDir), 0.0);
        vec3 diffuse = light[i].diffuse * diff * texture(material.diffuse, TexCoords).rgb;

        // specular
        vec3 viewDir = normalize(viewPos - FragPos);
        vec3 reflectDir = reflect(-lightDir, norm);
        float spec = pow(max(dot(viewDir, reflectDir), 0.0), material.shininess);
        vec3 specular = light[i].specular * spec * texture(material.specular, TexCoords).rgb;

        // attenuation
        float distance    = length(light[i].position - FragPos);
        float attenuation = 1.0 / (light[i].constant + light[i].linear * distance + light[i].quadratic * (distance * distance));

        ambient  *= attenuation;
        diffuse   *= attenuation;
        specular *= attenuation;

        vec3 result2 = ambient + diffuse + specular;
        result += result2;
        }
    FragColor = vec4(result, 1.0);
}