#ifdef GL_ES
precision mediump float;
#endif

varying vec4 v_fragmentColor;
varying vec2 v_texCoord;

void main()
{
    gl_FragColor = texture2D(CC_Texture0, v_texCoord) * v_fragmentColor;
    float grey = dot(gl_FragColor.rgb, vec3(0.299, 0.587, 0.114));
    grey = grey * 1.2;
    gl_FragColor.rgb = vec3(grey * 0.757, grey * 0.627, grey * 0.549);
}
