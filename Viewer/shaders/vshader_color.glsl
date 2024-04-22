#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 normal;
layout(location = 2) in vec2 texCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 Projection;

// output of vertex shaders is in input of fragment shaders

out vec3 orig_fragPos;
out vec3 fragPos;
out vec3 fragNormal;
out vec2 fragTexCoords;

void main()
{
    
	float pi = 3.141592654;

	orig_fragPos = pos;

	fragPos = vec3(model * vec4(pos, 1));			

	fragNormal = vec3(model * vec4(normal, 1));	


	// Pass the vertex texture coordinates property as it is. Its interpolated value
	// will be avilable for us in the fragment shader
	fragTexCoords = texCoords;



	gl_Position = Projection * view *  model * vec4(pos, 1.0f);
}
/*	
	//planar
	//fragTexCoords = vec2(fragPos); 

	//cylindrical
	//float theta =  (atan(fragPos.y , 1.5*fragPos.x)+ pi*0.5)/pi;
    //fragTexCoords = vec2(theta , -(-fragPos.z+0.5) );

	//spherical
	//float u = atan(fragPos.x, fragPos.z) / (2 * pi);
    // float v = asin(fragPos.y / 3) / pi;
	//fragTexCoords = vec2(u , v );
	
	*/