#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "StandardIncludes.h"
#include "Mesh.h"
#include "Shader.h"
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

private:
	Shader m_shaderColor;
	Shader m_shaderDiffuse;
	Mesh m_meshBox;
	Camera m_camera;
	vector<Mesh> m_meshBoxes;
};

#endif // GAME_CONTROLLER_H

