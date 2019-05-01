// Fragment Shader
// Display the carpet on the surface of stairs
// Set color to red
const vec3 BlockColor = vec3(1,0,0);
const vec3 SideColor = vec3(0.5,0.5,0.5);
varying float LightIntensity;
varying vec2  ModelPos;

void main(){
    if(ModelPos.x < 2.5 && ModelPos.x > -2.5)
        gl_FragColor = vec4(BlockColor * LightIntensity, 1.0);
    else
        gl_FragColor = vec4(SideColor * LightIntensity, 1.0);
}
