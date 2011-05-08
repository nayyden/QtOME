varying vec4 pos;

uniform vec4 SkyColor; 
uniform vec4 GroundColor; 
uniform sampler2D normalMap;
uniform sampler2D texMap;
uniform float Accessibility; 

void main(void) {
	  vec4 color = gl_FrontMaterial.diffuse;
	  vec4 matspec = gl_FrontMaterial.specular;
	  float shininess = gl_FrontMaterial.shininess;
	  vec4 lightspec = gl_LightSource[0].specular;
	  //vec4 lpos = gl_LightSource[0].position;
	
	vec4 lpos = vec4(00.0, -00.0, -14.0, 0.0);
	vec4 s = -normalize(pos-lpos);
	float dist = distance(pos,lpos);
	vec4 norm = texture2D(normalMap, gl_TexCoord[0].st);
	vec4 tnorm = normalize(norm);
	vec4 lightVec   = normalize(lpos); 
    float costheta  = dot(tnorm, lightVec); 
    float a         = 0.5 + 0.5 * costheta; 
	vec4 DiffuseColor = mix(GroundColor, SkyColor, a) * 0.9; 
	DiffuseColor *= DiffuseColor*1.9;
	  /* 
	  vec4 diffuse  = color * max(0.0, dot(n, s.xyz)) * gl_LightSource[0].diffuse + DiffuseColor;
	  vec4 specular;
	  if (shininess != 0.0) {
		specular = lightspec * matspec * pow(max(0.0,                 dot(r, v)), shininess);
	  } else {
		specular = vec4(0.0, 0.0, 0.0, 0.0);
	  }*/
DiffuseColor /= dist/20.0;
DiffuseColor = clamp(DiffuseColor, 0.1 , 0.7);
	  //gl_FragColor = //vec4(0,grayScale,0,0);//vec4(DiffuseColor,0);
	 //DiffuseColor.b *=  texture2D(texMap, gl_TexCoord[0].st).g;
	gl_FragColor = DiffuseColor;
}