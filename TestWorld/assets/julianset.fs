varying mediump vec2 p_TexCoords;
void main()
{
highp vec2 z;
z.x = 4.0 * (p_TexCoords.x -0.5);
z.y = 4.0 * (p_TexCoords.y- 0.5);

int i;
for(i=0; i<100; i++) {
highp float x = (z.x * z.x - z.y * z.y) + 1.0;
highp float y = (z.y * z.x + z.x * z.y) + 1.0;

if((x * x + y * y) > 4.0) break;
z.x = x;
z.y = y;
}

gl_FragColor = vec4(float(i) / 100.0,0.0,0.0,1.0);

}