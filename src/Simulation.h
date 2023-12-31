#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Shader/shader.h>
#include <Camera/camera.h>
#include <ModelLoader/model.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#include <iostream>

#include <imgui/imconfig.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

#include <TextRenderer/TextRenderer.h>
#include <ModelHandler/ModelHandler.h>
#include <SkyBox/Skybox.h>



class Simulation
{
public:
	Simulation(GLFWwindow* window, int WINDOW_WIDTH, int WINDOW_HEIGHT);

	void update(float deltaTime, int FPS, Camera camera);
	void render();

	float getCameraSpeed();
	bool getViewMode();

private:
	//Window
	GLFWwindow* window;
	int WINDOW_WIDTH;
	int WINDOW_HEIGHT;

	//Text
	TextRenderer* textRenderer;
	int fontSize;

	//Shader
	Shader screenShader;
	Shader textShader;

	Shader cubeMapShader;
	Shader cubeShader;

	//Matrizen
	glm::mat4 projection;
	glm::mat4 view;
	

	//TIMING
	float deltaTime;
	float FPS;
	
	int counter;

	int lastDirection;

	//World objects

	ModelHandler* testCube;

	Camera camera;

	//Settings
	float cameraSpeed;

	bool viewMode;
	bool start;

	ImVec4 dirLightColor;
	glm::vec3 dirLightPos;

	bool startKeyPressed;
	bool settingsKeyPressed;
	bool shadingKeyPressed;

	//Buffer
	unsigned int screenVAO;
	unsigned int screenVBO;
	unsigned int framebuffer;
	unsigned int texColorBuffer;
	unsigned int rbo;

	//Vertices
	float* quadVertices;

	//Skybox
	Skybox *oceanBox;
	Skybox *spaceBox;
	Skybox* forestBox;
	Skybox* cityBox;
	int skyBoxChoice;
	int shadingChoice;
	std::vector<std::string> ocean
	{
			R"(resources\textures\skybox\right.jpg)",
			R"(resources\textures\skybox\left.jpg)",
			R"(resources\textures\skybox\top.jpg)",
			R"(resources\textures\skybox\bottom.jpg)",
			R"(resources\textures\skybox\front.jpg)",
			R"(resources\textures\skybox\back.jpg)"
	};

	std::vector<std::string> space
	{
			R"(resources\textures\skybox\space_1_right.jpg)",
			R"(resources\textures\skybox\space_1_left.jpg)",
			R"(resources\textures\skybox\space_1_top.jpg)",
			R"(resources\textures\skybox\space_1_bottom.jpg)",
			R"(resources\textures\skybox\space_1_front.jpg)",
			R"(resources\textures\skybox\space_1_back.jpg)"
	};
	std::vector<std::string> forest
	{
			R"(resources\textures\skybox\forest_1_right.jpg)",
			R"(resources\textures\skybox\forest_1_left.jpg)",
			R"(resources\textures\skybox\forest_1_top.jpg)",
			R"(resources\textures\skybox\forest_1_bottom.jpg)",
			R"(resources\textures\skybox\forest_1_front.jpg)",
			R"(resources\textures\skybox\forest_1_back.jpg)"
	};
	std::vector<std::string> city
	{
			R"(resources\textures\skybox\city_2_right.jpg)",
			R"(resources\textures\skybox\city_2_left.jpg)",
			R"(resources\textures\skybox\city_2_top.jpg)",
			R"(resources\textures\skybox\city_2_bottom.jpg)",
			R"(resources\textures\skybox\city_2_front.jpg)",
			R"(resources\textures\skybox\city_2_back.jpg)"
	};



	//Inits------------------------------------------------------------------------------

	void initVertices();
	void initBuffer();
	void initShader();
	void initVariables();
	void initModels();

	//Input------------------------------------------------------------------------------

	void processInput(float deltaTime);

	//Helper------------------------------------------------------------------------------

	int random(int range, int start);


	//Updates------------------------------------------------------------------------------

	void updateSimulation();

	//Rendering------------------------------------------------------------------------------

	void DrawSimulation();
	void DrawSettings();
	void DrawScreen();
	void DrawText();
	void DrawSkyBox();
};

