// Fragment shader
// Color the outer part of ground
uniform sampler2D tex;
varying vec2  ModelPos;
void main()
{
    // Create a empty box in the middle
    if(ModelPos.x < 0.55 && ModelPos.x > -0.55 && ModelPos.y < 0.55 && ModelPos.y > -0.55)
        discard;
    gl_FragColor = gl_Color * texture2D(tex,gl_TexCoord[0].xy);
}
