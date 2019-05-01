// Fragment shader
// Color the maindoor
uniform sampler2D tex;
varying vec2  ModelPos;
const vec3 BlockColor  = vec3(0.5,0.5,0.5);
const vec2 BrickSize   = vec2(0.2,0.2);
void main()
{
    vec2 position = ModelPos / BrickSize;
    position = fract(position);
    // Create the empty blocks
    if(position.x>0.2 && position.x<0.8 && position.y>0.2 && position.y<0.8)
        discard;
    else
        gl_FragColor = gl_Color * texture2D(tex,gl_TexCoord[0].xy);
}

