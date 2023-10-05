#include "NpcTriangle.h"
#include "WindowController.h"
#include "Resolution.h"
#include "PlayerTriangle.h"
#include <time.h>
#include <iostream>
#include <cstdlib>





NpcTriangle::NpcTriangle() : Mesh()
{
    
    m_speedNpc = 0.01f;
    m_translateNpc = glm::vec3(0.0f, 0.0f, 0.0f);
    yMove = glm::vec3(0.0f, 0.0f, 0.0f);
    xMove = glm::vec3(0.0f, 0.0f, 0.0f);
	m_player = { };
    m_colorNpc = { 0.0f, 1.0f };          
}

NpcTriangle::~NpcTriangle()
{
}

void NpcTriangle::Create(Shader* _shader)
{

    float sign = static_cast<float>(rand() % 2);
    if (sign == 0.0f)
        sign = -1.0f;

    float _point = static_cast<float>(((rand() % 9) + 2) * sign);


    m_vertexData = {
        /* Position   */  /*    RGBA Color    */
         _point, _point, 0.0f, 0.0f, m_colorNpc[1], m_colorNpc[0], 1.0f,
         _point + 2.0f, _point, 0.0f, 0.0f, m_colorNpc[1], m_colorNpc[0], 1.0f,
         _point + 1.0f, _point + 2.0f, 0.0f, 0.0f, m_colorNpc[1], m_colorNpc[0], 1.0f
    };

    Mesh::Create(_shader, m_vertexData);
}

glm::vec3 NpcTriangle::ValidateMovement(Shader* _shader, glm::vec3 _player)
{

    glm::vec3 direction = _player - m_translateNpc;

    float distance = glm::distance(_player, m_translateNpc);

    
    float speed = m_speedNpc;

    if (distance < 10.0f)
    {
        speed = m_speedNpc;
        m_translateNpc += speed * direction;

    }
    else if (distance > 11.0f) {
        speed = -m_speedNpc;
        m_translateNpc += speed * direction;

    }
    else if (distance == 10.0f)
    {
        m_translateNpc += glm::vec3(0.0f, 0.0f, 0.0f);

    }
    else if (distance < 1.0f)
    {
        m_colorNpc[0] = 1.0f;
        m_colorNpc[1] = 0.0f;
        this->Cleanup();
        m_vertexData = {
            /* Position   */  /*    RGBA Color    */
             this->GetPlayerPos().x,  this->GetPlayerPos().y,  this->GetPlayerPos().z, 0.0f, m_colorNpc[1], m_colorNpc[0], 1.0f,
             this->GetPlayerPos().x + 2.0f,  this->GetPlayerPos().y,  this->GetPlayerPos().z, 0.0f, m_colorNpc[1], m_colorNpc[0], 1.0f,
             this->GetPlayerPos().x + 1.0f,  this->GetPlayerPos().y + 2.0f,  this->GetPlayerPos().z, 0.0f, m_colorNpc[1], m_colorNpc[0], 1.0f
        };

        Mesh::Create(_shader, m_vertexData);

       // m_colorNpc = { 0.0f, 1.0f };
      
    }
   
    return m_translateNpc;
}
/* Rotation idea:
* Use the GetPlayerPos() to get the position of NpcTriangle and the player
* Find the dot product between them so I can get the cos value by converting
* the dot product result in radians. And then, rotate it by the z axis.
*/