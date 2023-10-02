#include "Mesh.h"
#include "Shader.h"

Mesh::Mesh()
{
	m_shader = nullptr;
	m_vertexBuffer = 0;
	m_indexBuffer = 0;
	m_world = glm::mat4(1.0f);
}

Mesh::~Mesh()
{
}

void Mesh::Create(Shader* _shader, vector<GLfloat> _vertexData)
{
	m_shader = _shader;
	m_vertexData = _vertexData;

	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(float), m_vertexData.data(), GL_STATIC_DRAW);

}

void Mesh::Cleanup()
{
	glDeleteBuffers(1, &m_indexBuffer);
	glDeleteBuffers(1, &m_vertexBuffer);
}

void Mesh::Render(glm::mat4 _wvp, glm::vec3 _pos)
{
	glUseProgram(m_shader->GetProgramID()); // Use our shader

	// 1st attribute buffer : vertices
	glEnableVertexAttribArray(m_shader->GetAttrVertices());
	glVertexAttribPointer(m_shader->GetAttrVertices(), // The attribute we want to configure
		3,                   // size
		GL_FLOAT,            // type 
		GL_FALSE,           // normalized?
		7 * sizeof(float),  // stride (7 floats per vertex definition)
		(void*)0);            // array buffer offset 


	// 2nd attribute buffer : colors
	glEnableVertexAttribArray(m_shader->GetAttrColors());
	glVertexAttribPointer(m_shader->GetAttrColors(), // The attribute we want to configure
		4,                   // size ( 4 components per color value)
		GL_FLOAT,            // type 
		GL_FALSE,            // normalized?
		7 * sizeof(float),   // stride (7 floats per vertex definition)
		(void*)(3 * sizeof(float)));           // array buffer offset 

	//3rd attribute: WVP
	m_world = glm::translate(m_world, _pos);
	_wvp *= m_world;

	glUniformMatrix4fv(m_shader->GetAttrWVP(), 1, GL_FALSE, &_wvp[0][0]);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer); // Bind the vertex buffer
	glDrawArrays(GL_TRIANGLES, 0, m_vertexData.size() / 7);
	glDisableVertexAttribArray(m_shader->GetAttrVertices());
	glDisableVertexAttribArray(m_shader->GetAttrColors());
}Te