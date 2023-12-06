#ifndef MESH_H
#define MESH_H

#include "StandardIncludes.h"
#include "Texture.h"
#include "OBJ_Loader.h"

class Shader;

using namespace std;
class Mesh
{
public:
	// Constructors / Destructors
	Mesh();
	virtual ~Mesh();

	//Accessors / Mutators
	void SetPosition(glm::vec3 _position) { m_position = _position; }
	glm::vec3 GetPosition() { return m_position; }
	void SetScale(glm::vec3 _scale) { m_scale = _scale; }
	void SetColor(glm::vec3 _color) { m_color = _color; }
	glm::vec3 GetColor() { return m_color; }
	void SetCameraPosition(glm::vec3 _cameraPosition) { m_cameraPosition = _cameraPosition; }

	//void SetLightPosition(glm::vec3 _lightPosition) { m_lightPosition = _lightPosition; }
	//void SetLightColor(glm::vec3 _lightColor) { m_lightColor = _lightColor; }

	// Methods
	void Create(Shader* _shader, string _file, int _instanceCount = 1);
	void Cleanup();
	void CalculateTransform();
	void Render(glm::mat4 _pv);

	//Members
	static vector<Mesh> Lights;

private:

	//Methods
	void SetShaderVariables(glm::mat4 _pv);
	void BindAttributes();
	string Concat(string _s1, int _index, string _s2);
	string RemoveFolder(string _map);
	void  CalculateTangents(vector<objl::Vertex> _vertices, objl::Vector3& _tangent, objl::Vector3& _bitangent);
	bool EndsWith(std::string const& _fullString, std::string const& _ending);


	Shader* m_shader;
	Texture m_textureDiffuse;
	Texture m_textureSpecular;
	Texture m_textureNormal;
	GLuint m_vertexBuffer; // GPU buffer
	GLuint m_indexBuffer; // GPU buffer
	GLuint m_instanceBuffer; // GPU buffer
	std::vector<GLfloat> m_vertexData; // Store vertex data in RAM
	std::vector<GLubyte> m_indexData; // Store index data in RAM
	std::vector<GLfloat> m_instanceData; // Store instance data inRAM
	bool m_enableNormalMap;
	int m_instanceCount;
	bool m_enableInstancing;
	int m_elementSize;

	//Transform
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::vec3 m_scale;
	glm::mat4 m_world;
	glm::vec3 m_cameraPosition;
	glm::vec3 m_color;

	//Lights
	//glm::vec3 m_lightPosition;
	//glm::vec3 m_lightColor;
};

#endif // MESH_H