#include "PlayerTriangle.h"
#include "WindowController.h"
#include "Resolution.h"
#include <iostream>
#include "Shader.h"



PlayerTriangle::PlayerTriangle() : Mesh()
{
    m_speed = 0.01f;
	m_shader = nullptr;
	m_position = glm::vec3(0.0f, 0.0f, 0.0f);
    yMove = glm::vec3(0.0f, 0.0f, 0.0f);
	xMove = glm::vec3(0.0f, 0.0f, 0.0f);
	m_vertexBuffer = 0;
	m_world = glm::mat4(1.0f);
}

PlayerTriangle::~PlayerTriangle()
{
}

void PlayerTriangle::Create(Shader* _shader)
{   

	m_vertexData = {
	 	/* Position   */  /*    RGBA Color    */
         -1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
         1.0f, -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
         0.0f, 1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f
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

	m_position = xMove + yMove;
	return m_position;
}

void PlayerTriangle::RenderPlayer(glm::mat4 _wvp, glm::vec3 _pos)
{
	glUseProgram(m_shader->GetProgramID()); // Use our shader

	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(m_shader->GetAttrVertices());
	glVertexAttribPointer(m_shader->GetAttrVertices(), // The attribute we want to configure
		3,                   // size
		GL_FLOAT,            // type 
		GL_FALSE,           // normalized?
		7 * sizeof(float),  // stride (7 floats per vertex definition)
		(void*)0);            // array buffer offset 


	// 2nd attribute buffer : colors
	glEnableVertexAttribArray(m_shader->GetAttrColors());
	glVertexAttribPointer(m_shader->GetAttrColors(), // The attribute we want to configure
		4,                   // size ( 4 components per color value)
		GL_FLOAT,            // type 
		GL_FALSE,            // normalized?
		7 * sizeof(float),   // stride (7 floats per vertex definition)
		(void*)(3 * sizeof(float)));           // array buffer offset 

	//3rd attribute: WVP
	m_world = glm::translate(m_world, _pos);
	_wvp *= m_world;
	glUniformMatrix4fv(m_shader->GetAttrWVP(), 1, GL_FALSE, &_wvp[0][0]);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer); // Bind the vertex buffer
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer); // Bind the index buffer
	//glDrawElements(GL_TRIANGLES, m_indexData.size(), GL_UNSIGNED_BYTE, (void*)0); // Draw the triangles
	// GL_TRIANGLE_STRIP, GL_LINES, GL_LINE_STRIP
	glDrawArrays(GL_TRIANGLES, 0, m_vertexData.size() / 7);
	glDisableVertexAttribArray(m_shader->GetAttrVertices());
	glDisableVertexAttribArray(m_shader->GetAttrColors());

}