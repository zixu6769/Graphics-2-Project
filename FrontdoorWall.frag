// Fragment shader to make a door shape on the front wall
uniform sampler2D tex;
varying vec2  ModelPos;
void main()
{
    float current_radius = sqrt((ModelPos.x*ModelPos.x) + (ModelPos.y*ModelPos.y));
    if(ModelPos.y < 0.0 && ModelPos.x > -0.25 && ModelPos.x < 0.25)
        discard;
    if(ModelPos.y >= 0.0 && current_radius < 0.25)
        discard;
    gl_FragColor = gl_Color * texture2D(tex,gl_TexCoord[0].xy);
}
