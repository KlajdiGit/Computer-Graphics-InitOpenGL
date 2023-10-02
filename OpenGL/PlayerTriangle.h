#ifndef PLAYERTRIANGLE_H
#define PLAYERTRIANGLE_H

#include "StandardIncludes.h"
#include "Mesh.h"

class PlayerTriangle : public Mesh
{
public:
	 PlayerTriangle();
	 virtual ~PlayerTriangle();
	 void Create(Shader* _shader);
	 float GetSpeed() { return m_speed; }
	 glm::vec3 ValidateMovement();
	// void Render(glm::mat4 _wvp, glm::vec3 _pos);
	 void RenderPlayer(glm::mat4 _wvp, glm::vec3 _pos);

private:
	GLuint m_vertexBuffer;
	glm::mat4 m_world;
	vector<GLfloat> m_vertexData;
	Shader* m_shader;
	float m_speed;
	glm::vec3 m_position;
	glm::vec3 yMove;
	glm::vec3 xMove;

};

#endif // PLAYERTRIANGLE_H

