//  Metal fragment shader
//  Used noise to create different level of skin tone
uniform sampler3D Noise3D;
const float Scale = 6.0;
const vec4  Lightgray       = vec4(0.3,0.3,0.3,1.0);
const vec4  Silver          = vec4(0.5,0.5,0.5,1.0);

void main(void)
{
    vec4 nv = 1.5 * texture3D(Noise3D,Scale * gl_TexCoord[0].xyz + 0.3);
    vec3 loc = gl_TexCoord[0].xyz + nv.xyz;
    float r = 2.0 * fract(nv[0] + nv[1] + nv[2] + nv[3]);
    if (r > 1.0) r = 2.0 - r;
    vec4 color = mix(Lightgray ,Silver , r);
    gl_FragColor = length(gl_Color.xyz) * color;
}
