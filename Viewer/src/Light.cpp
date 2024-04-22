#include "Light.h"

Light::Light() :
	color(glm::vec3(1.0, 1.0, 1.0))
{
}

Light::Light(const glm::vec3& color) :
	color(color)
{

}


Light::~Light()
{
}

const glm::vec3& Light::GetColor() const
{
	return color;
}

void Light::SetColor(const glm::vec3& color)
{
	this->color = color;
}