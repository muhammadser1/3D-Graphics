#include "Renderer.h"
#include "MeshModel.h"
#include "ShaderProgram.h"
#include <imgui/imgui.h>
#include <vector>
#include <memory>
#include <algorithm>
#include "iostream"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

}

void Renderer::Render(const std::shared_ptr<Scene>& scene)
{
	int cameraCount = scene->GetCameraCount();
	if (cameraCount > 0)
	{
		int modelCount = scene->GetModelCount();
		const Camera& camera = scene->GetActiveCamera();

		for (int currentModelIndex = 0; currentModelIndex < modelCount; currentModelIndex++)
		{
			std::shared_ptr<MeshModel> currentModel = scene->GetModel(currentModelIndex);

			// Activate the 'colorShader' program (vertex and fragment shaders)
			colorShader.use();

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


			// Set 'texture1' as the active texture at slot #0
			texture1.bind(0);

			// Drag our model's faces (triangles) in fill mode
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glBindVertexArray(currentModel->GetVAO());
			glDrawArrays(GL_TRIANGLES, 0, currentModel->GetModelVertices().size());
			glBindVertexArray(0);

			// Unset 'texture1' as the active texture at slot #0
			texture1.unbind(0);

			colorShader.setUniform("color", glm::vec3(0, 0, 0));

			// Drag our model's faces (triangles) in line mode (wireframe)
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glBindVertexArray(currentModel->GetVAO());
			//glDrawArrays(GL_TRIANGLES, 0, currentModel->GetModelVertices().size());
			glBindVertexArray(0);
		}
	}
}


void Renderer::LoadShaders()
{
	colorShader.loadShaders("vshader_color.glsl", "fshader_color.glsl");
}
void Renderer::LoadTextures()//loaded at the main
{
	if (!texture1.loadTexture("C:\\Users\\Mohammad\\Desktop\\2b\\Data\\crate.jpg", true))
	{
		texture1.loadTexture("C:\\Users\\Mohammad\\Desktop\\2b\\Data\\crate.jpg", true);
	}
}
