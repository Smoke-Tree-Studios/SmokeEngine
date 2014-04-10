varying mediump vec2 p_TexCoords;
void main()
{

gl_FragColor = vec4(p_TexCoords.x,p_TexCoords.y,0.0,1.0);

}
