#ifndef NPCTRIANFLE_H
#define NPCTRIANGLE_H

#include "StandardIncludes.h"
#include "Mesh.h"
#include "PlayerTriangle.h"

class NpcTriangle : public Mesh
{
public:
	NpcTriangle();
	virtual ~NpcTriangle();
	void Create(Shader* _shader);
	float GetSpeed() { return m_speedNpc; }
	glm::vec3 ValidateMovement();
	void SetPlayer(PlayerTriangle _player) { m_player = _player; }


private:
	vector<GLfloat> m_vertexData;
	Shader* m_shader;
	float m_speedNpc;
	glm::vec3 m_position;
	glm::vec3 yMove;
	glm::vec3 xMove;
	PlayerTriangle m_player;

};


#endif //NPCTRIANGLE

