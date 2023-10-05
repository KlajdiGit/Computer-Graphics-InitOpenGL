#include "PlayerTriangle.h"
#include "WindowController.h"
#include "Resolution.h"
#include <iostream>
#include "Shader.h"



PlayerTriangle::PlayerTriangle() : Mesh()
{
	m_speed = 0.02f;
	m_translatePlayer = glm::vec3(0.0f, 0.0f, 0.0f);
	yMove = glm::vec3(0.0f, 0.0f, 0.0f);
	xMove = glm::vec3(0.0f, 0.0f, 0.0f);
	m_vertexBuffer = 0;
	m_world = glm::mat4(1.0f);
	m_color = 1.0f;
}



PlayerTriangle::~PlayerTriangle()
{
}

void PlayerTriangle::Create(Shader* _shader)
{
	m_vertexData = {
		/* Position   */  /*    RGBA Color    */
		 -1.0f, -1.0f, 0.0f, m_color, 0.0f, 0.0f, 1.0f,
		 1.0f, -1.0f, 0.0f, m_color, 0.0f, 0.0f, 1.0f,
		 0.0f, 1.0f, 0.0f, m_color, 0.0f, 0.0f, 1.0f
	};


	Mesh::Create(_shader, m_vertexData);
}



glm::vec3 PlayerTriangle::ValidateMovement()
{
	if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
	{
		yMove = glm::vec3(0.0f, m_speed, 0.0f);
	}

	if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
	{
		yMove = glm::vec3(0.0f, -m_speed, 0.0f);
	}

	if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
	{
		xMove = glm::vec3(m_speed, 0.0f, 0.0f);
	}

	if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
	{
		xMove = glm::vec3(-m_speed, 0.0f, 0.0f);
	}

	if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_A) == GLFW_RELEASE &&
		glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_W) == GLFW_RELEASE &&
		glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_S) == GLFW_RELEASE &&
		glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_D) == GLFW_RELEASE
		)

	{
		xMove = glm::vec3(0.0f, 0.0f, 0.0f);
		yMove = glm::vec3(0.0f, 0.0f, 0.0f);
	}

	m_translatePlayer = xMove + yMove;
	return m_translatePlayer;
}
