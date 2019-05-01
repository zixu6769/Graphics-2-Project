//  Leaf fragment shader
//  Used noise to create different level of green
uniform sampler3D Noise3D;
const float Scale = 6.0;
const vec4  LightGreen       = vec4(0.3,0.5,0.0,1.0);
const vec4  DarkGreen        = vec4(0.0,0.3,0.0,1.0);
const float RingFreq         = 10.0;

void main(void)
{
    vec4 nv = 1.5 * texture3D(Noise3D,Scale * gl_TexCoord[0].xyz + 0.3);
    vec3 loc = gl_TexCoord[0].xyz + nv.xyz;
    float dist = RingFreq*sqrt(loc.x*loc.x + loc.z*loc.z);
    float r = 2.0 * fract(dist + nv[0] + nv[1] + nv[2] + nv[3]);
    if (r > 1.0) r = 2.0 - r;
    vec4 color = mix(LightGreen ,DarkGreen , r);
    gl_FragColor = length(gl_Color.xyz) * color;
}
