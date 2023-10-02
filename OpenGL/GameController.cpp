#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"

GameController::GameController()
{
	m_shader = { };
	m_player = { };
	m_camera = { };
}

void GameController::Initialize()
{
	GLFWwindow* window = WindowController::GetInstance().GetWindow(); // Call this first, as it creates a window required by GLEW
	M_ASSERT(glewInit() == GLEW_OK, "Failed to initialize GLEW.") // Initialize GLEW
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we can capture the escape key
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f); // Black background 
	//glEnable(GL_CULL_FACE);
	//Create a default perspective camera
	m_camera = Camera(WindowController::GetInstance().GetResolution());
}

glm::vec3 position = glm::vec3(0.0f, 0.0f, 0.0f);
float speed = 0.01f;

void GameController::RunGame()
{
	m_shader = Shader(); // value object. It's cretaed on stack. No need for 'new'
	m_shader.LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

	m_player = PlayerTriangle();
	m_player.Create(&m_shader); // m_shader points to the stack because the m_stack is created on stack. Then the pointer points to the stack
	
	do
	{
		if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
		{
			position =  glm::vec3(0.0f, speed, 0.0f);
		}
		
		if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
		{
			position =  glm::vec3(0.0f, -speed, 0.0f);
		}
		
		if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
		{
			position =  glm::vec3(speed, 0.0f, 0.0f);
		}
	
		if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
		{
			position =  glm::vec3(-speed, 0.0f, 0.0f);
		}

		if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_A) == GLFW_RELEASE &&
			glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_W) == GLFW_RELEASE &&
			glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_S) == GLFW_RELEASE &&
			glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_D) == GLFW_RELEASE 
			) 
			
		{
			position = glm::vec3(0.0f, 0.0f, 0.0f);

		}
	
		glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
		m_player.Render(m_camera.GetProjection() * m_camera.GetView(), position);
		glfwSwapBuffers(WindowController::GetInstance().GetWindow()); // Swap the front and back buffers
		glfwPollEvents();

	} while (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && // Check if the ESC key was pressed
		glfwWindowShouldClose(WindowController::GetInstance().GetWindow()) == 0); // Check if the window was closed (a non-zero value means the window is closed)

	m_player.Cleanup();
	m_shader.Cleanup();
}



