//  Water fragment shader
uniform float time;                                 // Time in seconds
uniform sampler3D Noise3D;                          // Noise texture
const vec4 Water     = vec4(0.0,0.3,0.7,1.0);
const vec4 Waveline  = vec4(0.0,0.5,0.8,1.0);
const float RingFreq = 5.0;
const float Scale    = 8.0;

void main(void)
{
    // Combine noise texture with time
    vec4 nv = 1.5 * texture3D(Noise3D,Scale * gl_TexCoord[0].xyz + 0.3 * time);
    vec3 loc = gl_TexCoord[0].xyz + nv.xyz;
    float dist = RingFreq*sqrt(loc.x*loc.x + loc.z*loc.z);
    float r = 2.0 * fract(dist + nv[0] + nv[1] + nv[2] + nv[3]);
    if (r > 1.0) r = 2.0 - r;
    vec4 color = mix(Water ,Waveline , r);
    gl_FragColor = length(gl_Color.xyz) * color;
}

