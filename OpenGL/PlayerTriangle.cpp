#include "PlayerTriangle.h"
#include "WindowController.h"
#include "Resolution.h"
#include <iostream>

PlayerTriangle::PlayerTriangle() : Mesh()
{
    m_speed = 0.01f;
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