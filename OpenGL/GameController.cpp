#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"
#include "Fonts.h"

GameController::GameController()
{
	m_shaderColor = { };
	m_shaderDiffuse = { };
	m_camera = { };
	m_meshBox = { };
	m_meshes.clear();
}

void GameController::Initialize()
{
	GLFWwindow* window = WindowController::GetInstance().GetWindow(); // Call this first, as it creates a window required by GLEW
	M_ASSERT(glewInit() == GLEW_OK, "Failed to initialize GLEW.") // Initialize GLEW
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we can capture the escape key
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f); // Grey background 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	glFrontFace(GL_CW);

	// glEnable(GL_CULL_FACE);
	// glCullFace(GL_FRONT);
	srand((unsigned int)time(0));

	//Create a default perspective camera
	m_camera = Camera(WindowController::GetInstance().GetResolution());
}

void GameController::RunGame()
{
	// Create and compile our GLSL program from the shaders
	m_shaderColor = Shader(); // value object. It's cretaed on stack. No need for 'new'
	m_shaderColor.LoadShaders("Color.vertexshader", "Color.fragmentshader");
	m_shaderDiffuse = Shader();
	m_shaderDiffuse.LoadShaders("Diffuse.vertexshader", "Diffuse.fragmentshader");
	m_shaderFont = Shader();
	m_shaderFont.LoadShaders("Font.vertexshader", "Font.fragmentshader");

	//Create meshes
	Mesh m = Mesh();
	m.Create(&m_shaderColor, "../Assets/Models/teapot.obj");
	m.SetPosition({ 1.0f, 0.0f, 0.0f });
	m.SetColor({ 1.0f, 1.0f, 1.0f });
	m.SetScale({ 0.01f, 0.01f, 0.01f });
	Mesh::Lights.push_back(m);

	/*Mesh teapot = Mesh();
	teapot.Create(&m_shaderDiffuse, "../Assets/Models/teapot.obj");
	teapot.SetCameraPosition(m_camera.GetPosition());
	teapot.SetScale({ 0.02f, 0.02f, 0.02f });
	teapot.SetPosition({ 0.0f, 0.0f, 0.0f });
	m_meshes.push_back(teapot);*/

	Mesh box = Mesh();
	box.Create(&m_shaderDiffuse, "../Assets/Models/Cube.obj");
	box.SetCameraPosition(m_camera.GetPosition());
	box.SetScale({ 0.5f, 0.5f, 0.5f });
	box.SetPosition({ -1.0f, -1.0f, -1.0f });
	m_meshes.push_back(box);

	/*Mesh plane = Mesh();
	plane.Create(&m_shaderDiffuse, "../Assets/Models/Plane.obj");
	plane.SetCameraPosition(m_camera.GetPosition());
	plane.SetScale({ 0.3f, 0.3f, 0.3f });
	plane.SetPosition({ 0.0f, 0.0f, 0.0f });
	m_meshes.push_back(plane);*/

	/*Mesh window = Mesh();
	window.Create(&m_shaderDiffuse, "../Assets/Models/Window.obj");
	window.SetCameraPosition(m_camera.GetPosition());
	window.SetScale({ 0.1f, 0.1f, 0.1f });
	window.SetPosition({ 0.0f, 0.0f, 0.0f });
	m_meshes.push_back(window);*/

	Fonts f = Fonts();
	f.Create(&m_shaderFont, "arial.ttf", 100);
	do
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen
		//m_meshBox.Render(m_camera.GetProjection() * m_camera.GetView());
		for (unsigned int count = 0; count < m_meshes.size(); count++)
		{
			m_meshes[count].Render(m_camera.GetProjection() * m_camera.GetView());
		}

		for (int count = 0; count < Mesh::Lights.size(); count++)
		{
			Mesh::Lights[count].Render(m_camera.GetProjection() * m_camera.GetView());
		}

		f.RenderText("Testing text", 10, 500, 0.5f, { 1.0f, 1.0f, 0.0f });
		glfwSwapBuffers(WindowController::GetInstance().GetWindow()); // Swap the front and back buffers
		glfwPollEvents();

	} while (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && // Check if the ESC key was pressed
		glfwWindowShouldClose(WindowController::GetInstance().GetWindow()) == 0); // Check if the window was closed (a non-zero value means the window is closed)

	

	for (int count = 0; count < Mesh::Lights.size(); count++)
	{
		Mesh::Lights[count].Cleanup();
	}

	for (unsigned int count = 0; count < m_meshes.size(); count++)
	{
		m_meshes[count].Cleanup();
	}
	m_shaderDiffuse.Cleanup();
	m_shaderColor.Cleanup();
}