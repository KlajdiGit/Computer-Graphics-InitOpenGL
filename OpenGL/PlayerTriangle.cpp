#include "PlayerTriangle.h"


PlayerTriangle::PlayerTriangle() : Mesh()
{
}

PlayerTriangle::~PlayerTriangle()
{
}

void PlayerTriangle::Create(Shader* _shader)
{
	m_vertexData = {
	 	/* Position   */  /*    RGBA Color    */
         0.2f, 0.2f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
         0.3f, 0.9f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
         0.4f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f
	 };
    Mesh::Create(_shader, m_vertexData);
}