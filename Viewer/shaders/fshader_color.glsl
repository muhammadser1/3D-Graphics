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