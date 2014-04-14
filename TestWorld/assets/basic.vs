
attribute vec3 in_Verts;
attribute vec2 in_TexCoords;
attribute vec3 in_Normals;

uniform mat4 in_Transform;
uniform mat4 in_View;


varying mediump vec2 p_TexCoords;
varying mediump vec3 p_normals;
varying mediump vec3 p_camPosition;

void main(void)
{
mediump vec4 verticies= in_View * in_Transform * vec4(in_Verts.xyz,1.0);
p_camPosition = verticies.xyz;
gl_Position = verticies;
p_TexCoords = in_TexCoords;
p_normals = in_Normals;
}