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
	/*void ValidateMovement(Mesh _mesh, float _speed);
	void ValidateMovementNpc(Mesh _mesh, float _speed);*/

private:
	Shader m_shader;
	//Mesh m_mesh;
	PlayerTriangle m_player;
	NpcTriangle m_npc;
	Camera m_camera;
};

#endif // GAME_CONTROLLER_H

