#version 330
in  vec3 vertNormal;
in  vec3 lightDir;
out vec4 fragColor;

void main() { 
	
	const vec4 ks = vec4(0.5, 0.3, 0.3, 0.0);
	const vec4 kd = vec4(0.6, 0.8, 0.6, 0.0);  C++
	const vec4 ka = 0.1 * kd;					
	

	vec3 reflection = normalize(reflect(-lightDir, vertNormal));
	float diff = max(dot(vertNormal, lightDir), 0.0);
	float spec = max(0.0, dot(vertNormal, reflection));
	if(diff != 0.0){
		spec = pow(spec,16.0);
	}
	fragColor =  ka + (diff * kd) + (spec * ks);
	
} 

