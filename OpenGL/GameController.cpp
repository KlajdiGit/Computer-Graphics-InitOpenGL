#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"
#include <iostream>
#include "Mesh.h"

GameController::GameController()
{
	m_shader = { };
	m_player = { };
	m_camera = { };
	m_playerSpeed = 0.02f;
}

void GameController::Initialize()
{
	GLFWwindow* window = WindowController::GetInstance().GetWindow(); // Call this first, as it creates a window required by GLEW
	M_ASSERT(glewInit() == GLEW_OK, "Failed to initialize GLEW.") // Initialize GLEW
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we can capture the escape key
	glClearColor(0.0f, 0.0f, 1.0f, 0.0f); // Black background 
	m_camera = Camera(WindowController::GetInstance().GetResolution());
}

void GameController::RunGame()
{
	m_shader = Shader(); // value object. It's cretaed on stack. No need for 'new'
	m_shader.LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");

	m_player = PlayerTriangle();
	m_player.Create(&m_shader);
	
	for (int i = 0; i < 10; i++)
	{
		NpcTriangle npc = NpcTriangle();
		m_npc.push_back(npc);
		m_npc[i].Create(&m_shader);
	}

	do
	{
		glClear(GL_COLOR_BUFFER_BIT); // Clear the screen;

		for (int i = 0; i < m_npc.size(); i++)
		{
			if (i == 0)
			{
				m_player.Render(m_camera.GetProjection() * m_camera.GetView(), m_player.ValidateMovement());
				//std::cout << m_player.GetClass() << m_player.Mesh::GetPlayerPos().x << " " << m_player.Mesh::GetPlayerPos().y << " " << m_player.Mesh::GetPlayerPos().z << endl;
				m_npc[i].Render(m_camera.GetProjection() * m_camera.GetView(), m_npc[i].ValidateMovement(&m_shader, m_player.GetPlayerPos()));

			}
			else
			{
				m_npc[i].Render(m_camera.GetProjection() * m_camera.GetView(), m_npc[i].ValidateMovement(&m_shader, m_player.GetPlayerPos()));
				//std::cout << m_npc[i].GetClass() << m_npc[i].Mesh::GetPlayerPos().x << " " << m_npc[i].Mesh::GetPlayerPos().y << " " << m_npc[i].Mesh::GetPlayerPos().z << endl;
			}
		}

		glfwSwapBuffers(WindowController::GetInstance().GetWindow()); // Swap the front and back buffers
		glfwPollEvents();

	} while (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && // Check if the ESC key was pressed
		glfwWindowShouldClose(WindowController::GetInstance().GetWindow()) == 0); // Check if the window was closed (a non-zero value means the window is closed)

	m_player.Cleanup();
	for (int i = 0; i < 10; i++)
	{
		m_npc[i].Cleanup();
	}
	m_shader.Cleanup();
}
