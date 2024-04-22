#pragma once

#include <glm/glm.hpp>
#include "Light.h"

class AmbientLight : public Light 
{
public:
	AmbientLight();
	virtual ~AmbientLight();
};
