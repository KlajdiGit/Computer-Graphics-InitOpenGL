#include "PostProcessor.h"
#include "WindowController.h"
#include "Shader.h"

PostProcessor::PostProcessor()
{
	m_framebuffer = 0;
	m_textureColorbuffer = 0;
	m_renderBufferObject = 0;
	m_postShader = 0;
	m_vertexBuffer = 0;
}

PostProcessor::~PostProcessor()
{
}

void PostProcessor::Cleanup()
{
	glDeleteFramebuffers(1, &m_framebuffer);
	glDeleteTextures(1, &m_textureColorbuffer);
	glDeleteRenderbuffers(1, &m_renderBufferObject);
}

void PostProcessor::Create(Shader* _postShader)
{
	m_postShader = _postShader;
	CreateBuffers();
	CreateVertices();

}