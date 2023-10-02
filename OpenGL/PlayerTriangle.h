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

private:
	vector<GLfloat> m_vertexData;
	Shader* m_shader;


};

#endif // PLAYERTRIANGLE_H

