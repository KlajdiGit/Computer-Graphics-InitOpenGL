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

void Mesh::Create(Shader* _shader)
{
	m_shader = _shader;
	float a = 26.0f;
	float b = 42.0f;


	m_vertexData = { 
		/*  Position  */  /*   RGBA Color     */
		-a, 0.0f, b,  1.0f, 0.0f, 0.0f, 1.0f, 
		a, 0.0f, b,   1.0f, 0.549f, 0.0f, 1.0f,
		-a, 0.0f, -b, 1.0f, 1.0f, 0.0f, 1.0f,
		a, 0.0f, -b,  1.0f, 1.0f, 0.0f, 1.0f,
		0.0f, b, a,   0.0f, 0.0f, 0.0f, 1.0f,
		0.0f, b, -a,  0.294f, 0.0f, 0.51f, 1.0f,
		0.0f, -b, a,  0.502f, 0.0f, 0.502f, 1.0f,
		0.0f, -b, -a, 1.0f, 1.0f, 1.0f, 1.0f,
		b, a, 0.0f,   0.0f, 1.0f, 1.0f, 1.0f,
		-b, a, 0.0f,  0.0f, 1.0f, 0.0f, 1.0f,
		b, -a, 0.0f,  0.118f, 0.565, 1.0f, 1.0f,
		-b, -a, 0.0f, 0.863f, 0.078f, 0.235f, 1.0f

	};
	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(float), m_vertexData.data(), GL_STATIC_DRAW);

	m_indexData = {
		0, 6, 1, 0, 11, 6, 1, 4, 0, 1, 8, 4,
		1, 10, 8, 2, 5, 3, 2, 9, 5, 2, 11, 9,
		3, 7, 2, 3, 10, 7, 4, 8, 5, 4, 9, 0,
		5, 8, 3, 5, 9, 4, 6, 10, 1, 6, 11, 7,
		7, 10, 6, 7, 11, 2, 8, 10, 3, 9, 11, 0
	};
	glGenBuffers(1, &m_indexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_indexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_indexData.size() * sizeof(GLubyte), m_indexData.data(), GL_STATIC_DRAW);

}

void Mesh::Cleanup()
{
	glDeleteBuffers(1, &m_indexBuffer);
	glDeleteBuffers(1, &m_vertexBuffer);
}

void Mesh::Render(glm::mat4 _wvp)
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
		(void*) (3 * sizeof(float)));           // array buffer offset 
	
	//3rd attribute: WVP
	m_world = glm::rotate(m_world, 0.001f, { 0, 1, 0 });
	_wvp *= m_world;
	glUniformMatrix4fv(m_shader->GetAttrWVP(), 1, GL_FALSE, &_wvp[0][0]);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer); // Bind the vertex buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer); // Bind the index buffer
	// GL_TRIANGLES, GL_LINES, GL_LINE_STRIP
	glDrawElements(GL_TRIANGLES, m_indexData.size(), GL_UNSIGNED_BYTE, (void*)0); // Draw the triangles
	glDisableVertexAttribArray(m_shader->GetAttrVertices());
	glDisableVertexAttribArray(m_shader->GetAttrColors());

}