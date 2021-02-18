#version 330 core
in vec2 TexCoord;

out vec3 FragColor;

uniform sampler2D ourTexture;

void main()
{
    FragColor = texture(ourTexture, TexCoord).rgb;
} 
