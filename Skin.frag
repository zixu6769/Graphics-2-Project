//  Skin fragment shader
//  Used noise to create different level of skin tone
uniform sampler3D Noise3D;
const float Scale = 6.0;
const vec4  LightSkin       = vec4(0.89,0.67,0.41,1.0);
const vec4  DarkSkin        = vec4(0.77,0.52,0.26,1.0);

void main(void)
{
    vec4 nv = 1.5 * texture3D(Noise3D,Scale * gl_TexCoord[0].xyz + 0.3);
    vec3 loc = gl_TexCoord[0].xyz + nv.xyz;
    float r = 2.0 * fract(nv[0] + nv[1] + nv[2] + nv[3]);
    if (r > 1.0) r = 2.0 - r;
    vec4 color = mix(LightSkin ,DarkSkin , r);
    gl_FragColor = length(gl_Color.xyz) * color;
}
