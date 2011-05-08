varying vec4 pos;
 
void main() 
{ 
    //vec4 pos = gl_ModelViewMatrix * gl_Vertex; 
	gl_TexCoord[0]  = gl_MultiTexCoord0;
    gl_Position     = ftransform(); 
	pos =  gl_Vertex; 
}