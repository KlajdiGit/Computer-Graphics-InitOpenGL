#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "StandardIncludes.h"
#include "Mesh.h"
#include "Shader.h"
#include "SkyBox.h"
#include "WindowController.h"
#include "Camera.h"
#include "PostProcessor.h"

class GameController: public Singleton<GameController>
{
public:
	//Constructors /Destructors
	GameController();
	virtual ~GameController() { }

	//Methods
	void Initialize();
	void RunGame();
	glm::vec3 GetSpherePos() { return m_spherePos; }
	glm::vec3 GetFighterPos() { return m_fighterPos; }

private:
	Shader m_shaderColor;
	Shader m_shaderDiffuse;
	Shader m_shaderFont;
	Shader m_shaderPost;
	Camera m_camera;
	PostProcessor m_postProcessor;
	vector<Mesh> m_meshes;
	SkyBox m_skyBox;
	GLuint vao;

	glm::vec3 m_spherePos;
	glm::vec3 m_fighterPos;
	Shader m_simpleShader;
};

#endif // GAME_CONTROLLER_H

