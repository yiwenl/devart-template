uniform sampler2DRect   texture;

void main(void) {
    vec2 texCoord   = gl_TexCoord[0].st;
    texCoord        *= vec2(1280.0, 720.0);
    gl_FragColor    = texture2DRect(texture, texCoord);
    gl_FragColor.rgb    *= .5;
}