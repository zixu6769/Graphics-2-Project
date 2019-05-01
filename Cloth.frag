// Fragment Shader to draw the pattern of the floor

const vec3 BlockColor = vec3(0.8,0.0,0.0);
const vec3 SideColor = vec3(0.5,0.5,0.5);
// Set size for each block
const vec2 BlockSize  = vec2(0.5,0.5);
// Center for each block (and for each circle)
const vec2 Center     = vec2(0.5,0.5);
// Set radius for each circle to 0.5
const float radius    = 0.5;

varying float LightIntensity;
varying vec2  ModelPos;


void main(){
    // Normalize position to be in the range [0,1]
    vec2 position = ModelPos / BlockSize;
    // Only using the fractional part
    position = fract(position);
    // Calculate the distance between current point and center of the circle
    float current_radius = sqrt((position.x - Center.x)*(position.x - Center.x) + (position.y - Center.y)*(position.y - Center.y));
    // Decide whether current point is inside the circle. Output 1.0 if inside, 0.0 otherwise.
    float inside = step(current_radius, radius);
    if(inside != 1.0)
        gl_FragColor = vec4(SideColor * LightIntensity, 1.0);
    else
        gl_FragColor = vec4(BlockColor * LightIntensity, 1.0);
}
