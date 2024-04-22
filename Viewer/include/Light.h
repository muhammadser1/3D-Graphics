#pragma once

#include <glm/glm.hpp>

class Light
{
public:
	Light();
	Light(const glm::vec3& color);
	virtual ~Light();

	const glm::vec3& GetColor()  const;
	void SetColor(const glm::vec3& color);
	glm::vec3 location = glm::vec3(0, 0, 0);
	float a = 1.0f;
	
	glm::vec3 ambientLightColor = glm::vec3(0, 0, 0);
	glm::vec3 diffuseLightColor = glm::vec3(0, 0, 0);
	glm::vec3 specularLightColor = glm::vec3(0, 0, 0);
	glm::vec3 color;
protected:

};
