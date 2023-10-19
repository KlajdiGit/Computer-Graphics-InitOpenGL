#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"

GameController::GameController()
{
	m_shaderRgbYuv = { };
	m_camera = { };
	m_mesh = { };
}

void GameController::Initialize()
{
	GLFWwindow* window = WindowController::GetInstance().GetWindow(); // Call this first, as it creates a window required by GLEW
	M_ASSERT(glewInit() == GLEW_OK, "Failed to initialize GLEW.") // Initialize GLEW
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we can capture the escape key
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // Black background 
	glEnable(GL_DEPTH_TEST);

	//Create a default perspective camera
	m_camera = Camera(WindowController::GetInstance().GetResolution());
}

void GameController::RunGame()
{
	OpenGL::ToolWindow^ window = gcnew OpenGL::ToolWindow();
	window->Show();

	// Create and compile our GLSL program from the shaders
	m_shaderRgbYuv = Shader(); // value object. It's cretaed on stack. No need for 'new'
	m_shaderRgbYuv.LoadShaders("Color.vertexshader", "Color.fragmentshader");


	//Create meshes
	m_mesh = Mesh();
	m_mesh.Create(&m_shaderRgbYuv);

	m_mesh.SetPosition({ 1.0f, 0.5f, 0.5f });
	m_mesh.SetScale({ 1.0f, 1.0f, 1.0f });


	do
	{
		System::Windows::Forms::Application::DoEvents();

		GLfloat loc = glGetUniformLocation(m_shaderRgbYuv.GetProgramID(), "Y");
		glUniform1f(loc, (float)OpenGL::ToolWindow::trackBarYvalue / 100);
		loc = glGetUniformLocation(m_shaderRgbYuv.GetProgramID(), "U");
		glUniform1f(loc, (float)OpenGL::ToolWindow::trackBarUvalue / 100);
		loc = glGetUniformLocation(m_shaderRgbYuv.GetProgramID(), "V");
		glUniform1f(loc, (float)OpenGL::ToolWindow::trackBarVvalue / 100);

		GLint loc2 = glGetUniformLocation(m_shaderRgbYuv.GetProgramID(), "RenderInvert");
		glUniform1i(loc2, (int)OpenGL::ToolWindow::RenderInvertColors);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen
		m_mesh.Render(m_camera.GetProjection() * m_camera.GetView());

		glfwSwapBuffers(WindowController::GetInstance().GetWindow()); // Swap the front and back buffers
		glfwPollEvents();

	} while (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && // Check if the ESC key was pressed
		glfwWindowShouldClose(WindowController::GetInstance().GetWindow()) == 0); // Check if the window was closed (a non-zero value means the window is closed)

	m_mesh.Cleanup();
	m_shaderRgbYuv.Cleanup();
}