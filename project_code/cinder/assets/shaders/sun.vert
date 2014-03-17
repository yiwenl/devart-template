uniform vec3        position;

void main() {
    gl_TexCoord[0]  = gl_MultiTexCoord0;
    vec4 pos        = gl_Vertex;
    pos.xyz         += position;
    gl_Position     = gl_ModelViewProjectionMatrix * pos;
}