#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "StandardIncludes.h"
#include "Mesh.h"
#include "Shader.h"
#include "SkyBox.h"
#include "WindowController.h"
#include "Camera.h"

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

private:
	Shader m_shaderColor;
	Shader m_shaderDiffuse;
	Shader m_shaderFont;
	Shader m_shaderSkyBox;
	Camera m_camera;
	vector<Mesh> m_meshes;
	SkyBox m_skyBox;
	glm::vec3 m_spherePos;
};

#endif // GAME_CONTROLLER_H

