#define _USE_MATH_DEFINES
#include <cmath>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <imgui/imgui.h>

#include <nfd.h>

#include <stdio.h>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <sstream>
#include <stdlib.h>

#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "Renderer.h"
#include "Scene.h"
#include "Camera.h"
#include "ImguiMenus.h"
#include "AmbientLight.h"
#include "PointLight.h"
#include "Utils.h"
/*******************************************/
float tmp = 1;
static bool translation = false;
static bool scale = false;
static bool rotate = false;
int rotate_slider = 1;
static bool lighttrans = false;
/*******************************************/
double zoomFactor = 1;
int windowWidth = 1280;
int windowHeight = 720;
char* windowTitle = "OpenGL Demo";
glm::vec4 clearColor = glm::vec4(0.8f, 0.8f, 0.8f, 1.00f);
bool zoomChanged = false;
std::shared_ptr<Scene> scene;

ImGuiIO* imgui;
GLFWwindow* window;

GLFWwindow* SetupGlfwWindow(int w, int h, const char* window_name);
ImGuiIO& SetupImgui(GLFWwindow* window);
bool Setup(int windowWidth, int windowHeight, const char* windowName);
void Cleanup();

static void GlfwErrorCallback(int error, const char* description);
void RenderFrame(GLFWwindow* window, std::shared_ptr<Scene> scene, Renderer& renderer, ImGuiIO& io);

void glfw_OnMouseScroll(GLFWwindow* window, double xoffset, double yoffset);
void glfw_OnFramebufferSize(GLFWwindow* window, int width, int height);

float GetAspectRatio();
void DrawImguiMenus();
void HandleImguiInput();

int main(int argc, char** argv)
{

	if (!Setup(windowWidth, windowHeight, windowTitle))
	{
		std::cerr << "Setup failed" << std::endl;
		return -1;
	}

	scene = std::make_shared<Scene>();
	glm::vec3 eye = glm::vec3(0, 0, 10);
	glm::vec3 at = glm::vec3(0, 0, 0);
	glm::vec3 up = glm::vec3(0, 1, 0);
	Camera camera = Camera(eye, at, up, GetAspectRatio());
	scene->AddCamera(camera);

	scene->AddLight(std::make_shared<PointLight>(glm::vec3(0, 0, 15), glm::vec3(1, 1, 1)));
	scene->AddLight(std::make_shared<PointLight>(glm::vec3(0, 5, 5), glm::vec3(0, 0, 0)));
	scene->AddLight(std::make_shared<PointLight>(glm::vec3(-5, 0, 0), glm::vec3(0, 0, 0)));

	Renderer renderer;
	renderer.LoadShaders();
	renderer.LoadTextures();

	while (!glfwWindowShouldClose(window))
	{
		// Poll and process events
		glfwPollEvents();

		// Imgui stuff
		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplGlfw_NewFrame();
		ImGui::NewFrame();
		DrawImguiMenus();
		ImGui::Render();
		HandleImguiInput();

		// Clear the screen and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Render scene
		renderer.Render(scene);

		// Imgui stuff
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

		// Swap front and back buffers
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;
}

static void GlfwErrorCallback(int error, const char* description)
{
	fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

bool Setup(int windowWidth, int windowHeight, const char* windowName)
{
	GLFWwindow* window = SetupGlfwWindow(windowWidth, windowHeight, windowName);
	if (!window)
	{
		std::cerr << "Window setup failed" << std::endl;
		return false;
	}

	imgui = &SetupImgui(window);

	glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
	glEnable(GL_DEPTH_TEST);

	return true;
}

GLFWwindow* SetupGlfwWindow(int windowWidth, int windowHeight, const char* windowName)
{
	// Intialize GLFW
	if (!glfwInit())
	{
		// An error occured
		std::cerr << "GLFW initialization failed" << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// forward compatible with newer versions of OpenGL as they become available but not backward compatible (it will not run on devices that do not support OpenGL 3.3
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	// Create an OpenGL 3.3 core, forward compatible context window
	window = glfwCreateWindow(windowWidth, windowHeight, windowName, NULL, NULL);
	if (window == NULL)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return false;
	}

	// Make the window's context the current one
	glfwMakeContextCurrent(window);

	// Setup window events callbacks
	glfwSetFramebufferSizeCallback(window, glfw_OnFramebufferSize);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		// An error occured
		std::cerr << "GLAD initialization failed" << std::endl;
		return false;
	}

	return window;
}

ImGuiIO& SetupImgui(GLFWwindow* window)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;

	ImGui_ImplGlfw_InitForOpenGL(window, true);
	ImGui_ImplOpenGL3_Init();

	// Setup style
	ImGui::StyleColorsDark();

	glfwSetScrollCallback(window, glfw_OnMouseScroll);

	return io;
}

void HandleImguiInput()
{
	if (!imgui->WantCaptureKeyboard)
	{
		if (imgui->KeysDown[49]) // 1
		{
			scene->GetActiveModel()->RotateXModel(M_PI / 200);
		}

		if (imgui->KeysDown[50]) // 2
		{
			scene->GetActiveModel()->RotateXModel(-M_PI / 200);
		}

		if (imgui->KeysDown[51]) // 3
		{
			scene->GetActiveModel()->RotateYModel(M_PI / 200);
		}

		if (imgui->KeysDown[52]) // 4
		{
			scene->GetActiveModel()->RotateYModel(-M_PI / 200);
		}

		if (imgui->KeysDown[53]) // 5
		{
			scene->GetActiveModel()->RotateZModel(M_PI / 200);
		}

		if (imgui->KeysDown[54]) // 6
		{
			scene->GetActiveModel()->RotateZModel(-M_PI / 200);
		}

		if (imgui->KeysDown[45]) // -
		{
			scene->GetActiveModel()->ScaleModel(1 / 1.01);
		}

		if (imgui->KeysDown[61]) // +
		{
			scene->GetActiveModel()->ScaleModel(1.01);
		}

		if (imgui->KeysDown[65]) // a
		{
			scene->GetActiveModel()->TranslateModel(glm::vec3(-0.02, 0, 0));
		}

		if (imgui->KeysDown[68]) // d
		{
			scene->GetActiveModel()->TranslateModel(glm::vec3(0.02, 0, 0));
		}

		if (imgui->KeysDown[83]) // s
		{
			scene->GetActiveModel()->TranslateModel(glm::vec3(0, 0, 0.02));
		}

		if (imgui->KeysDown[87]) // w
		{
			scene->GetActiveModel()->TranslateModel(glm::vec3(0, 0, -0.02));
		}
	}

	if (!imgui->WantCaptureMouse)
	{
		if (zoomChanged)
		{
			scene->GetActiveCamera().Zoom(zoomFactor);
			zoomChanged = false;
		}
	}
}

void Cleanup()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();

	glfwDestroyWindow(window);
	glfwTerminate();
}

//-----------------------------------------------------------------------------
// Is called when the window is resized
//-----------------------------------------------------------------------------
void glfw_OnFramebufferSize(GLFWwindow* window, int width, int height)
{
	windowWidth = width;
	windowHeight = height;
	glViewport(0, 0, windowWidth, windowHeight);
	scene->GetActiveCamera().SetAspectRatio(GetAspectRatio());
}

void glfw_OnMouseScroll(GLFWwindow* window, double xoffset, double yoffset)
{
	ImGui_ImplGlfw_ScrollCallback(window, xoffset, yoffset);
	zoomFactor = glm::pow(1.1, -yoffset);
	zoomChanged = true;
}

float GetAspectRatio()
{
	return static_cast<float>(windowWidth) / static_cast<float>(windowHeight);
}

void DrawImguiMenus()
{
	ImGui::SetNextWindowPos(ImVec2(0, 20), ImGuiCond_Once);
	{
		ImGui::Begin("Scene Menu");
		if (ImGui::ColorEdit3("Clear Color", (float*)&clearColor))
		{
			glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
		}

		if (ImGui::CollapsingHeader("Cameras:"))
		{
			if (ImGui::Button("Add Camera"))
			{

				std::random_device rd;
				std::mt19937 mt(rd());
				std::uniform_real_distribution<double> dist(0, 2 * M_PI);
				std::uniform_real_distribution<double> dist2(2, 10);
				double angle = dist(mt);
				double radius = dist2(mt);

				glm::vec4 eye = glm::vec4(radius * glm::cos(angle), 0, radius * glm::sin(angle), 1);
				glm::vec4 at = glm::vec4(0, 0, 0, 1);
				glm::vec4 up = glm::vec4(0, 1, 0, 1);
				scene->AddCamera(Camera(-scene->GetActiveCamera().GetEye(), at, up, GetAspectRatio()));
			}

			const char** items;
			std::vector<std::string> cameraStrings;
			items = new const char* [scene->GetCameraCount()];
			for (int i = 0; i < scene->GetCameraCount(); i++)
			{
				std::ostringstream s;
				s << "Camera " << i;
				std::string mystring = s.str();
				cameraStrings.push_back(mystring);
			}

			for (int i = 0; i < scene->GetCameraCount(); i++)
			{
				items[i] = cameraStrings[i].c_str();
			}

			int currentCamera = scene->GetActiveCameraIndex();
			ImGui::Combo("Active Camera", &currentCamera, items, scene->GetCameraCount());

			if (currentCamera != scene->GetActiveCameraIndex())
			{
				scene->SetActiveCameraIndex(currentCamera);
				scene->GetActiveCamera().SetAspectRatio(GetAspectRatio());
			}

			delete items;

			int newProjectionType = scene->GetActiveCamera().IsPrespective() ? 0 : 1;
			ImGui::RadioButton("Prespective", &newProjectionType, 0);
			ImGui::RadioButton("Orthographic", &newProjectionType, 1);

			if (newProjectionType == 0)
			{
				float fovy;
				float zNear;
				float zFar;

				scene->GetActiveCamera().SwitchToPrespective();

				if (ImGui::SliderFloat("Fovy", &fovy, 0.0f, M_PI))
				{
					scene->GetActiveCamera().SetFovy(fovy);
				}

				if (ImGui::SliderFloat("Near", &zNear, 1.0f, 10.0f))
				{
					scene->GetActiveCamera().SetNear(zNear);
				}

				if (ImGui::SliderFloat("Far", &zFar, 1.0f, 10.0f))
				{
					scene->GetActiveCamera().SetFar(zFar);
				}
			}
			else if (newProjectionType == 1)
			{
				float height;
				float zNear;
				float zFar;

				scene->GetActiveCamera().SwitchToOrthographic();

				if (ImGui::SliderFloat("Height", &height, 0.0f, M_PI))
				{
					scene->GetActiveCamera().SetHeight(height);
				}

				if (ImGui::SliderFloat("Near", &zNear, 1.0f, 10.0f))
				{
					scene->GetActiveCamera().SetNear(zNear);
				}

				if (ImGui::SliderFloat("Far", &zFar, 1.0f, 10.0f))
				{
					scene->GetActiveCamera().SetFar(zFar);
				}
			}
		}

		if (ImGui::CollapsingHeader("Models:"))
		{
			const char** items;
			std::vector<std::string> modelStrings;
			items = new const char* [scene->GetModelCount()];
			for (int i = 0; i < scene->GetModelCount(); i++)
			{
				std::ostringstream s;
				s << scene->GetModel(i)->GetModelName();
				std::string mystring = s.str();
				modelStrings.push_back(mystring);
			}

			for (int i = 0; i < scene->GetModelCount(); i++)
			{
				items[i] = modelStrings[i].c_str();
			}

			int currentModelIndex = scene->GetActiveModelIndex();
			ImGui::Combo("Active Model", &currentModelIndex, items, scene->GetModelCount());

			if (currentModelIndex != scene->GetActiveModelIndex())
			{
				scene->SetActiveModelIndex(currentModelIndex);
			}

			delete items;

			glm::vec3 modelColor = scene->GetActiveModel()->GetColor();
			if (ImGui::ColorEdit3("Model Color", (float*)&modelColor))
			{
				scene->GetActiveModel()->SetColor(modelColor);
			}

			std::shared_ptr<MeshModel> meshModel = std::dynamic_pointer_cast<MeshModel>(scene->GetActiveModel());

			if (meshModel)
			{
				ImGui::Checkbox("Scale Model", &scale);
				ImGui::Checkbox("Translate Model", &translation);
				ImGui::Checkbox("Rotate Model", &rotate);


				ImGui::TextColored(ImVec4(1, 0, 1, 1), "Choose Your Transformain");

				if (translation == true)
				{
					if (ImGui::Button("left"))
					{
						scene->GetActiveModel()->TranslateModel(glm::vec3(-tmp, 0, 0));
					}

					if (ImGui::Button("right"))
					{
						scene->GetActiveModel()->TranslateModel(glm::vec3(tmp, 0, 0));
					}
					if (ImGui::Button("up"))
					{
						scene->GetActiveModel()->TranslateModel(glm::vec3(0, tmp, 0));
					}

					if (ImGui::Button("down"))
					{
						scene->GetActiveModel()->TranslateModel(glm::vec3(0, -tmp, 0));
					}

				}

				if (scale == true)
				{
					if (ImGui::Button("smaller"))
					{
						scene->GetActiveModel()->ScaleModel(1 / 1.2);
					}

					if (ImGui::Button("bigger"))
					{
						scene->GetActiveModel()->ScaleModel(2);
					}
				}
			}



			ImGui::ColorEdit3("ambient ", (float*)&scene->GetActiveModel()->ambientReflectance);
			ImGui::ColorEdit3("diffuse ", (float*)&scene->GetActiveModel()->diffuseReflectance);
			ImGui::ColorEdit3("specular ", (float*)&scene->GetActiveModel()->specularReflectance);
		}
		if (ImGui::CollapsingHeader("Lights:"))
		{

			ImGui::TextColored(ImVec4(1, 0, 1, 1), "Choose Light Color:");
			ImGui::ColorEdit3("ambient", (float*)&scene->GetLight(0)->ambientLightColor);
			ImGui::ColorEdit3("diffuse", (float*)&scene->GetLight(0)->diffuseLightColor);
			ImGui::ColorEdit3("specular", (float*)&scene->GetLight(0)->specularLightColor);
			ImGui::InputFloat("alpha", &scene->GetLight(0)->a, 0.1, 0.1);
			ImGui::Checkbox("Light Traslation:", &lighttrans);
			if (lighttrans == true)
			{
				ImGui::InputFloat("x", &scene->GetLight(0)->location[0], tmp, tmp);
				ImGui::InputFloat("y", &scene->GetLight(0)->location[1], tmp, tmp);
				ImGui::InputFloat("z", &scene->GetLight(0)->location[2], tmp, tmp);
			}

		}

		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}

	{
		ImGuiWindowFlags flags = ImGuiWindowFlags_NoFocusOnAppearing;
		if (ImGui::BeginMainMenuBar())
		{
			if (ImGui::BeginMenu("File"))
			{
				if (ImGui::MenuItem("Open", "CTRL+O"))
				{
					nfdchar_t* outPath = NULL;
					nfdresult_t result = NFD_OpenDialog("obj;png,jpg", NULL, &outPath);
					if (result == NFD_OKAY) {
						scene->AddModel(Utils::LoadMeshModel(outPath));
						free(outPath);
					}
					else if (result == NFD_CANCEL) {
					}
					else {
					}

				}
				ImGui::EndMenu();
			}
			ImGui::EndMainMenuBar();
		}
	}
}