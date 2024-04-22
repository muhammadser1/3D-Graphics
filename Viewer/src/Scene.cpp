#include "Scene.h"
#include "MeshModel.h"
#include <string>

Scene::Scene() :
	activeCameraIndex(0),
	activeModelIndex(0)
{

}

void Scene::AddModel(const std::shared_ptr<MeshModel>& model)
{
	models.push_back(model);
}

void Scene::AddCamera(const Camera& camera)
{
	cameras.push_back(camera);
}

int Scene::GetModelCount() const
{
	return models.size();
}

int Scene::GetCameraCount() const
{
	return cameras.size();
}

std::shared_ptr<MeshModel> Scene::GetModel(int index) const
{
	return models[index];
}

Camera& Scene::GetCamera(int index)
{
	return cameras[index];
}

const Camera& Scene::GetCamera(int index) const
{
	return cameras[index];
}

const Camera& Scene::GetActiveCamera() const
{
	return cameras[activeCameraIndex];
}

Camera& Scene::GetActiveCamera()
{
	return cameras[activeCameraIndex];
}

void Scene::SetActiveCameraIndex(int index)
{
	if (index >= 0 && index < cameras.size())
	{
		activeCameraIndex = index;
	}
}

const int Scene::GetActiveCameraIndex() const
{
	return activeCameraIndex;
}

void Scene::SetActiveModelIndex(int index)
{
	activeModelIndex = index;
}

const int Scene::GetActiveModelIndex() const
{
	return activeModelIndex;
}

const std::shared_ptr<MeshModel>& Scene::GetActiveModel() const
{
	return models[activeModelIndex];
}

void Scene::AddLight(const std::shared_ptr<PointLight>& light)
{
	lights.push_back(light);
}

int Scene::GetLightCount() const
{
	return lights.size();
}

std::shared_ptr<PointLight> Scene::GetLight(int index) const
{
	return lights[index];
}

const std::vector<std::shared_ptr<PointLight>>& Scene::GetActiveLights() const
{
	return lights;
}

const AmbientLight& Scene::GetAmbientLight()
{
	return ambientLight;
}