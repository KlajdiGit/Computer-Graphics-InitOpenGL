#ifndef GAME_CONTROLLER_H
#define GAME_CONTROLLER_H

#include "StandardIncludes.h"
#include "Mesh.h"
#include "Shader.h"
#include "WindowController.h"
#include "Camera.h"
#include "PlayerTriangle.h"
#include "NpcTriangle.h"

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
	Shader m_shader;
	PlayerTriangle m_player;
	vector<NpcTriangle> m_npc; // Store vertex data in RAM
	Camera m_camera;
	float m_playerSpeed;

};

#endif // GAME_CONTROLLER_H

