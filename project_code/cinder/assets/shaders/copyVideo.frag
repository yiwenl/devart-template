uniform sampler2DRect   texture;

void main(void) {
    vec2 texCoord   = gl_TexCoord[0].st;
    gl_FragColor    = texture2DRect(texture, texCoord);
}