#pragma once

#include <glm/glm.hpp>
#include <memory>
#include "Light.h"

class PointLight : public Light
{
public:
	PointLight(const glm::vec3& position);
	PointLight(const glm::vec3& position, const glm::vec3& color);
	virtual ~PointLight();
	glm::vec3& GetPosition();

private:
	glm::vec3 position;
};
