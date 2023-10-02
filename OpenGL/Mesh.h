#ifndef MESH_H
#define MESH_H

#include "StandardIncludes.h"
class Shader;

using namespace std;
class Mesh
{
public:
	// Constructors / Destructors
	Mesh();
	virtual ~Mesh();

	// Methods
	void Create(Shader* _shader, vector<GLfloat> _vertexData);
	void Cleanup();
	void Render(glm::mat4 _wvp, glm::vec3 _pos);

private:
	Shader* m_shader;
	GLuint m_vertexBuffer;
	GLuint m_indexBuffer; // GPU buffer
	vector<GLfloat> m_vertexData; // Store vertex data in RAM
	std::vector<GLubyte> m_indexData; // Store index data in RAM
	glm::mat4 m_world;
};

#endif // MESH_H