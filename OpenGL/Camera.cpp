#include "Camera.h"

Camera::Camera()
{
	m_projection = { };
	m_view = { };
	m_position = { };
}

Camera::Camera(Resolution _screenResolution)
{
	m_position = { 1, 1, 1 };

	//Projection matrix : 45 degrees Field of View, 4.3 ratio, display range : 0.1 unit <-> 100 units
	m_projection = glm::perspective(glm::radians(45.0f),
		(float)_screenResolution.m_width /
		(float)_screenResolution.m_height,
		0.1f,
		1000.0f);

	//Or, for an ortho camera:
	//glm::mat4 Projection = glm::ortho( -10.0f, 10.f, -10.0f, 10.0f, 0.0f, 100.0f) // In World coordinates

	//Camera matrix
	m_view = glm::lookAt(
		m_position, // Camera is at (2, 2, 2) in world space
		glm::vec3(0, 0, 0), // and looks at the origin
		glm::vec3(0, 1, 0)  // Head is up (set to 0, -1, 0 to look upside-down)
	);
}

Camera::~Camera()
{

}