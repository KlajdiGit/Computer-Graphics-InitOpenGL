#ifndef NPCTRIANFLE_H
#define NPCTRIANGLE_H

#include "StandardIncludes.h"
#include "Mesh.h"

class NpcTriangle : public Mesh
{
public:
	NpcTriangle();
	virtual ~NpcTriangle();
	void Create(Shader* _shader);
	float GetSpeed() { return m_speedNpc; }

private:
	vector<GLfloat> m_vertexData;
	Shader* m_shader;
	float m_speedNpc;
};


#endif //NPCTRIANGLE

