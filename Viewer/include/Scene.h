#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <vector>
#include <string>
#include <memory>
#include "MeshModel.h"
#include "AmbientLight.h"
#include "PointLight.h"
#include "Camera.h"

class Scene {
private:
	std::vector<std::shared_ptr<MeshModel>> models;
	std::vector<std::shared_ptr<PointLight>> lights;
	AmbientLight ambientLight;
	std::vector<Camera> cameras;

	int activeCameraIndex;
	int activeModelIndex;

public:
	Scene();
	/*********************************/
	glm::vec3 ambientLightColor = glm::vec3(0, 0, 0);
	glm::vec3 diffuseLightColor = glm::vec3(0, 0, 0);
	glm::vec3 specularLightColor = glm::vec3(0, 0, 0);
	float a = 1.0f;
	/*********************************/
	void AddModel(const std::shared_ptr<MeshModel>& model);
	int GetModelCount() const;
	std::shared_ptr<MeshModel> GetModel(int index) const;

	void AddCamera(const Camera& camera);
	int GetCameraCount() const;
	Camera& GetCamera(int index);
	const Camera& GetCamera(int index) const;

	void AddLight(const std::shared_ptr<PointLight>& light);
	int GetLightCount() const;
	std::shared_ptr<PointLight> GetLight(int index) const;
	const std::vector<std::shared_ptr<PointLight>>& GetActiveLights() const;

	const AmbientLight& GetAmbientLight();

	const Camera& GetActiveCamera() const;
	Camera& GetActiveCamera();

	void SetActiveCameraIndex(int index);
	const int GetActiveCameraIndex() const;

	const std::shared_ptr<MeshModel>& GetActiveModel() const;

	void SetActiveModelIndex(int index);
	const int GetActiveModelIndex() const;
};