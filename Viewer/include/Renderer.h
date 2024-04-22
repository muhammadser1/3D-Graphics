#pragma once
#include "Scene.h"
#include "ShaderProgram.h"
#include <vector>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <memory>
#include "Texture2D.h"

class Renderer
{
private:
	ShaderProgram lightShader;
	ShaderProgram colorShader;
	Texture2D texture1;

public:
	Renderer();
	~Renderer();

	void Render(const std::shared_ptr<Scene>& scene);
	void LoadShaders();
	void LoadTextures();
};
