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
	glm::vec3 ValidateMovement(Shader* _shader,glm::vec3 _player);
	void SetPlayer(PlayerTriangle _player) { m_player = _player; }
	string GetClass() { return "NPC"; }

private:
	vector<GLfloat> m_vertexData;
	float m_speedNpc;
	glm::vec3 m_translateNpc;
	glm::vec3 yMove;
	glm::vec3 xMove;
	PlayerTriangle m_player;
	float m_point;
	std::vector<GLfloat> m_colorNpc;

};
#endif //NPCTRIANGLE

