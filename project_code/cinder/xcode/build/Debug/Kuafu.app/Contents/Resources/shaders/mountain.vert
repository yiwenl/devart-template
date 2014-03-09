attribute vec3  colorOffset;
varying vec3    vColorOffset;
varying float   heightOffset;


#define PI      3.1415926

float clamp(float value, float _min, float _max) {  return max(min(value, _max), _min); }

void main() {
    gl_FrontColor   = gl_Color;
    gl_TexCoord[0]  = gl_MultiTexCoord0;
    vec4 pos        = gl_Vertex;
    heightOffset    = clamp( (pos.y + 100.0 ) / 10.0, 0.0, 1.0 );
    heightOffset    = 1.0-cos(heightOffset*PI*.5);

    gl_Position     = gl_ModelViewProjectionMatrix * pos;
    vColorOffset    = colorOffset;
}