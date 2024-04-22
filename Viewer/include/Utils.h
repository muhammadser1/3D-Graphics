#pragma once
#include <glm/glm.hpp>
#include <string>
#include "MeshModel.h"

class Utils
{
public:
	static glm::mat4x4 TranslationMatrix(const glm::vec3& translationVector);
	static glm::mat4x4 XRotationMatrix(double angle);
	static glm::mat4x4 YRotationMatrix(double angle);
	static glm::mat4x4 ZRotationMatrix(double angle);
	static glm::mat4x4 AxisRotationMatrix(glm::vec3 axis, double angle);
	static glm::mat4x4 ScalingMatrix(const glm::vec3& scalingVector);
	static glm::mat4x4 XScalingMatrix(double factor);
	static glm::mat4x4 YScalingMatrix(double factor);
	static glm::mat4x4 ZScalingMatrix(double factor);

	static glm::vec3 Vec3fFromStream(std::istream& issLine);
	static glm::vec2 Vec2fFromStream(std::istream& issLine);

	static std::shared_ptr<MeshModel> LoadMeshModel(const std::string& filePath);

	static std::vector<glm::vec3> CalculateNormals(std::vector<glm::vec3> vertices, std::vector<Face> faces);

	static std::string GetFileName(const std::string& filePath);
};
