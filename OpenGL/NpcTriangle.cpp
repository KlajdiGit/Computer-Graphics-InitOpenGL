#include "NpcTriangle.h"
#include "WindowController.h"
#include "Resolution.h"
#include <iostream>
#include <cstdlib>
#include "PlayerTriangle.h"

NpcTriangle::NpcTriangle() : Mesh()
{
    m_speedNpc = 0.02f;
    m_shader = nullptr;
    m_position = glm::vec3(0.0f, 0.0f, 0.0f);
    yMove = glm::vec3(0.0f, 0.0f, 0.0f);
    xMove = glm::vec3(0.0f, 0.0f, 0.0f);
	m_player = { };
}

NpcTriangle::~NpcTriangle()
{
}



void NpcTriangle::Create(Shader* _shader)
{
    m_vertexData = {
        /* Position   */  /*    RGBA Color    */
		 -1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
		 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f
    };


    Mesh::Create(_shader, m_vertexData);
}

glm::vec3 NpcTriangle::ValidateMovement()
{
	/*if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_W) == GLFW_PRESS)
	{
		yMove = glm::vec3(0.0f, m_speedNpc, 0.0f);
	}

	if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_S) == GLFW_PRESS)
	{
		yMove = glm::vec3(0.0f, -m_speedNpc, 0.0f);
	}

	if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_D) == GLFW_PRESS)
	{
		xMove = glm::vec3(m_speedNpc, 0.0f, 0.0f);
	}

	if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_A) == GLFW_PRESS)
	{
		xMove = glm::vec3(-m_speedNpc, 0.0f, 0.0f);
	}

	if (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_A) == GLFW_RELEASE &&
		glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_W) == GLFW_RELEASE &&
		glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_S) == GLFW_RELEASE &&
		glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_D) == GLFW_RELEASE
		)

	{
		xMove = glm::vec3(0.0f, 0.0f, 0.0f);
		yMove = glm::vec3(0.0f, 0.0f, 0.0f);
	}*/
	float pos = static_cast<float>(rand() % 9 + 2);


	m_position = glm::vec3(pos, pos, pos);
	return m_position;

}


















//
//NpcTriangle::NpcTriangle() : Mesh()
//{
//    m_speed = 0.01f;
//}
//
//NpcTriangle::~NpcTriangle()
//{
//}
//
//void NpcTriangle::Create(Shader* _shader)
//{
//    float num = static_cast<float>(rand() % 10);
//    m_vertexData = {
//        /* Position   */  /*    RGBA Color    */
//           num,         num, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
//         num + 2.0f,  num, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
//         num - 1.0f,  num + 2.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f
//    };
//
//
//    Mesh::Create(_shader, m_vertexData);
//}

//NpcTriangle::NpcTriangle() : Mesh()
//{
//    m_speed = 0.01f;
//}
//
//NpcTriangle::~NpcTriangle()
//{
//}

/*
float x1 = dist_x(rng); // First vertex x coordinate
float y1 = dist_y(rng); // First vertex y coordinate
float x2 = dist_x(rng); // Second vertex x coordinate
float y2 = dist_y(rng); // Second vertex y coordinate
float x3 = dist_x(rng); // Third vertex x coordinate
float y3 = dist_y(rng); // Third vertex y coordinate
*/
 
/*

void NpcTriangle::Create(Shader* _shader)
{
#include <random>
    
    float x1 = dist_x(rng); // First vertex x coordinate
    float y1 = dist_y(rng); // First vertex y coordinate
    float x2 = x1 + 2.0f; // Second vertex x coordinate
    if (x2 > 10.0f) // Check if out of range
        x2 -= 4.0f; // Adjust by subtracting 4.0f
    float y2 = y1; // Second vertex y coordinate
    float x3 = x1 - 1.0f; // Third vertex x coordinate
    if (x3 < 2.0f) // Check if out of range
        x3 += 4.0f; // Adjust by adding 4.0f
    float y3 = y1 + 2.0f; // Third vertex y coordinate
    if (y3 > -2.0f) // Check if out of range
        y3 -= 4.0f; // Adjust by subtracting 4.0f
} 
*/