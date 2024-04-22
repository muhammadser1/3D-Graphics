Name: Muhammad Awawdi
Student Number: 209319003
Name: Muhammad sarahni
Student Number: 207662958

/*****************************************/
## PART 1:

The InitOpenGL function is responsible for initializing and allocating data on the GPU for rendering the scene. It does this by creating a texture and vertex array object, allocating space for the vertex and texture data, and then loading and compiling the vertex and fragment shaders.Once the shaders are compiled and linked, the function passes the vertex and texture data to the shaders and specifies where to find them. The shaders are then made active and ready to draw the scene.Overall, InitOpenGL sets up the necessary structures and data to render the scene using the vertex and fragment shaders 


/*****************************************/
## PART 2:

The MeshModel class has been updated to load the mesh on the GPU. the Draw function is called, which uses the glDrawArrays function to draw the mesh on the screen. 


/*****************************************/

## PART 3:

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
	planer:
	fragTexCoords = vec2(fragPos); 

	spher:
	float u = atan(fragPos.x, fragPos.z) / (2 * pi);
    	float v = asin(fragPos.y / 3) / pi;
	fragTexCoords = vec2(u , v );

	cy:
	float alpha =  (atan(fragPos.y , 1.5*fragPos.x)+ pi*0.5)/pi;
    	fragTexCoords = vec2(alpha , -(-fragPos.z+0.5) );
	
	*/


/*****************************************/

## PART 4:
#version 330 core

struct Material
{
	sampler2D textureMap;

	vec3 ambientReflectance;
	vec3 diffuseReflectance;
	vec3 specularReflectance;

	vec3 ambientLightColor;
	vec3 diffuseLightColor;
	vec3 specularLightColor;

	float alpha;//phong
	vec3 eye;
	vec3 location;
	
};

uniform Material material;

const float numLevels  = 6.0;

in vec3 fragPos;
in vec3 fragNormal;
in vec2 fragTexCoords;
in vec3 orig_fragPos;

out vec4 frag_color;

void main()
{
	vec3 textureColor = vec3(texture(material.textureMap, fragTexCoords));

	vec3 ambientLight  = material.ambientLightColor * material.ambientReflectance;

	float diffuseIntensity  = max(dot(normalize(fragNormal), material.location - fragPos), 0.0);

	vec3 I = normalize(material.location - fragPos);

	vec3 halfVector  = I - 2 * dot(I, normalize(fragNormal)) * normalize(fragNormal);

	vec3 diffuseLight  = material.diffuseReflectance * diffuseIntensity  * material.diffuseLightColor;

	vec3 vector = fragPos - material.eye;

	diffuseIntensity  = max(dot(halfVector , vector), 0.0);

	float level = floor(pow(diffuseIntensity , material.alpha) * numLevels );

	float avglevel = level/numLevels ;

	vec3 specularLight  = material.specularLightColor * avglevel * material.specularReflectance;


	vec3 finalColor  = ambientLight  + diffuseLight  + specularLight ;

	frag_color = vec4(avglevel * finalColor , 1); 



}


/*

vec3 Ia = material.Lambient * textureColor;

	float diffuseIntensity = max(dot(normalize(fragNormal), material.location - fragPos), 0.0);

	vec3 I = normalize(material.location - fragPos);

	vec3 halfVector = I - 2 * dot(I, normalize(fragNormal)) * normalize(fragNormal);

	vec3 diffuseLight = textureColor * diffuseIntensity * material.Ldiffuse;

	vec3 vector = fragPos - material.eye;

	diffuseIntensity = max(dot(halfVector, vector), 0.0);

	vec3 specularLight = material.Lspecular * pow(diffuseIntensity, material.alpha) * textureColor;

	vec3 finalColor  =ambientLight  + diffuseLight  + specularLight ;

	frag_color = vec4(finalColor , 1);

*/
/*****************************************/
## Part 5:
## The uniform variables:
			// Set the uniform variables
			colorShader.setUniform("model", currentModel->GetModelTransformation());
			colorShader.setUniform("view", camera.GetViewTransformation());
			colorShader.setUniform("Projection", camera.GetProjectionTransformation());
			colorShader.setUniform("material.textureMap", 0);
			/**********************************************************************************************************/
			colorShader.setUniform("material.ambientReflectance", scene->GetActiveModel()->ambientReflectance);
			colorShader.setUniform("material.diffuseReflectance", scene->GetActiveModel()->diffuseReflectance);
			colorShader.setUniform("material.specularReflectance", scene->GetActiveModel()->specularReflectance);
			/**********************************************************************************************************/
			colorShader.setUniform("material.ambientLightColor", scene->GetLight(0)->ambientLightColor);
			colorShader.setUniform("material.diffuseLightColor", scene->GetLight(0)->diffuseLightColor);
			colorShader.setUniform("material.specularLightColor", scene->GetLight(0)->specularLightColor);
			/**********************************************************************************************************/
			colorShader.setUniform("material.eye", scene->GetActiveCamera().GetEye());
			colorShader.setUniform("material.location", scene->GetLight(0)->location);
			colorShader.setUniform("material.alpha", scene->GetLight(0)->a);

/*****************************************/
## PART 6 (Phong):

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment3Report/phong.png)



![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment3Report/pong1.png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment3Report/pong.png)


## PART 7 (Texture):

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment3Report/part7_crate.png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment3Report/part7_tea.png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment3Report/part7_online.png)

## PART 8 (Mapping):


# normal mapping:


# toon shading:

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment3Report/888888888888888.png)

![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment3Report/part8_toon2.jpeg)
## MY GUI:
![](https://github.com/HaifaGraphicsCourses/computer-graphics-2023-awawdi-sarahni/blob/master/Assignment3Report/Screenshot%20(24).png)
