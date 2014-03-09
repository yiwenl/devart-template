float contrast(float value, float offset) {     return .5 + (value-.5) * offset;    }
vec3 contrast(vec3 value, float offset) {
    return vec3(contrast(value.x, offset), contrast(value.y, offset), contrast(value.z, offset));
}


uniform sampler2D           texture;
varying vec3                vColorOffset;
varying float               heightOffset;


uniform float               brightness;
uniform float               saturationOffset;
uniform float               contrastOffset;

/*
#define saturationOffset    .1
#define brightness          1.27
#define contrastOffset      .85
*/

void main(void) {
    vec2 texCoord       = gl_TexCoord[0].st;
    gl_FragColor        = texture2D(texture, texCoord);

    float grey          = (gl_FragColor.r + gl_FragColor.g + gl_FragColor.b) / 3.0;
    vec3 colorGrey      = vec3(grey);

    float saturation    = (1.0 - heightOffset)*saturationOffset + (1.0-saturationOffset);

    gl_FragColor.rgb    = colorGrey * saturation + gl_FragColor.rgb * (1.0 - saturation);
    gl_FragColor.rgb    = contrast(gl_FragColor.rgb, contrastOffset);
    gl_FragColor.rgb    *= brightness;
    gl_FragColor.a      *= pow(heightOffset, 3.0);
}