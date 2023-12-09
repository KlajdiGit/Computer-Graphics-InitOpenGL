#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"
#include "Fonts.h"
#include <glm/gtx/string_cast.hpp>

GameController::GameController()
{
	m_shaderColor = { };
	m_shaderDiffuse = { };
	m_shaderPost = { };
	m_camera = { };
	m_skyBox = { };
	m_meshes.clear();
	m_spherePos = { 0.0f, 0.0f, 0.1f };
	m_fighterPos = { 0.0f, 0.0f, 0.0f };
	m_simpleShader = { };
	m_shaderSkyBox = { };
}

double xpos = 0.0f;
double ypos = 0.0f;
double zpos = 0.0f;
glm::vec3 targetPos;
float speedFactor;
bool leftButtonPressed = false;
bool middleButtonPressed = false;

double lastX = 0.0, lastY = 0.0;


static void mouse_callback(GLFWwindow* window, int button, int action, int mods)
{
	int width, height;

	glfwGetWindowSize(window, &width, &height);
	if (button == GLFW_MOUSE_BUTTON_LEFT)
	{
		if (action == GLFW_PRESS)
		{
			leftButtonPressed = true;
			glfwGetCursorPos(window, &xpos, &ypos);

			float x = (xpos / width) * 2.0f - 1.0f;
			float y = 1.0 - (ypos / height) * 2.0f;
			targetPos = glm::vec3(x, y, targetPos.z);
		} 
		else
			leftButtonPressed = false;
	}
	if (button == GLFW_MOUSE_BUTTON_MIDDLE)
	{
		if(action == GLFW_PRESS)
		{
			middleButtonPressed = true;
			glfwGetCursorPos(window, nullptr, &lastY);
		}
		else
		{
			middleButtonPressed = false;
			lastY = 0.0f;
		}

		if (middleButtonPressed)
		{
			double y;
			glfwGetCursorPos(window, nullptr, &y);

			if (lastY != 0.0f)
			{
				double yOffset = lastY - y;
				targetPos.z += yOffset * 0.1f;
			}
			lastY = y;
		}	
	}
} 






void GameController::Initialize()
{
	GLFWwindow* window = WindowController::GetInstance().GetWindow(); // Call this first, as it creates a window required by GLEW
	M_ASSERT(glewInit() == GLEW_OK, "Failed to initialize GLEW.") // Initialize GLEW
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we can capture the escape key
	glClearColor(0, 0, 0, 1); // Black background 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	srand((unsigned int)time(0));
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	//Create a default perspective camera
	Resolution r = WindowController::GetInstance().GetResolution();
	glViewport(0, 0, r.m_width, r.m_height);
	m_camera = Camera(r);
	glfwSetMouseButtonCallback(WindowController::GetInstance().GetWindow(), mouse_callback);
}

void GameController::RunGame()
{
	OpenGL::ToolWindow^ window = gcnew OpenGL::ToolWindow();
	window->Show();

#pragma region SetupShaders
	// Create and compile our GLSL program from the shaders
	m_shaderColor = Shader(); // value object. It's cretaed on stack. No need for 'new'
	m_shaderColor.LoadShaders("Color.vertexshader", "Color.fragmentshader");
	m_shaderDiffuse = Shader();
	m_shaderDiffuse.LoadShaders("Diffuse.vertexshader", "Diffuse.fragmentshader");
	m_shaderFont = Shader();
	m_shaderFont.LoadShaders("Font.vertexshader", "Font.fragmentshader");
	m_shaderPost = Shader();
	m_shaderPost.LoadShaders("PostProcessor.vertexshader", "PostProcessor.fragmentshader");
	m_simpleShader = Shader();
	m_simpleShader.LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");
	m_shaderSkyBox = Shader();
	m_shaderSkyBox.LoadShaders("SkyBox.vertexshader", "SkyBox.fragmentshader");
	
#pragma endregion SetupShaders

#pragma region CreateMeshes
    //Create meshes
	Mesh m = Mesh();
	m.Create(&m_shaderColor, "../Assets/Models/MoveSphere.obj");
	m.SetPosition(m_spherePos);
	m.SetColor({ 1.0f, 1.0f, 1.0f });
	m.SetScale({ 0.005f, 0.005f, 0.005f });
	Mesh::Lights.push_back(m);

	Mesh fighter = Mesh();
	fighter.Create(&m_shaderDiffuse, "../Assets/Models/Fighter3.ase");
    //fighter.Create(&m_shaderDiffuse, "../Assets/Models/Fish.ase");
	fighter.SetCameraPosition(m_camera.GetPosition());
	fighter.SetScale({ 0.0008f, 0.0008f, 0.0008f });
	//fighter.SetScale({ 0.008f, 0.008f, 0.008f });
	fighter.SetPosition(m_fighterPos);
	//m_meshes.push_back(fighter);

	Mesh fish = Mesh();
	fish.Create(&m_shaderDiffuse, "../Assets/Models/Fish.ase");
	fish.SetCameraPosition(m_camera.GetPosition());
	fish.SetScale({ 0.05f, 0.05f, 0.05f });
	fish.SetPosition(m_fighterPos);

	Mesh asteroid = Mesh();
	asteroid.Create(&m_shaderDiffuse, "../Assets/Models/Asteroid.ase");
	asteroid.SetPosition({0.0f, 0.0f, 0.6f});
	asteroid.SetScale({ 0.005f, 0.005f, 0.005f });

	SkyBox skyBox = SkyBox();
	skyBox.Create(&m_shaderSkyBox, "../Assets/Models/SkyBox.obj",
		{
			"../Assets/Textures/Skybox/right.jpg",
			"../Assets/Textures/Skybox/left.jpg",
			"../Assets/Textures/Skybox/top.jpg",
			"../Assets/Textures/Skybox/bottom.jpg",
			"../Assets/Textures/Skybox/front.jpg",
			"../Assets/Textures/Skybox/back.jpg"
		});

#pragma endregion CreateMeshes

	Fonts f = Fonts();
	f.Create(&m_shaderFont, "arial.ttf", 100);
	m_postProcessor = PostProcessor();
	m_postProcessor.Create(&m_shaderPost);

	glm::vec3 spherePos = GetSpherePos();
	glm::vec3 fighterPos = GetFighterPos();
	glm::vec3 fighterRotate = { -45.0f, 0.0f, 0.0f };
	glm::vec3 fighterScaleVec = { 0.0f, 0.0f, 0.0f };
	float mouseDeltaX = 0.0f;
	float mouseDeltaY = 0.0f;

	double lastTime = glfwGetTime();
	int fps = 0;
	string fpsS = "0";
	string mousePosition  ="";
	string leftButton = "";
	string middleButton = "";
	string fighterRotation = "";
	string fighterPosition = "";
	string fighterScale = "";
	do
	{
		System::Windows::Forms::Application::DoEvents();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen
		
		//m_postProcessor.Start();
		/*for (unsigned int count = 0; count < m_meshes.size(); count++)
		{
			m_meshes[count].Render(m_camera.GetProjection() * m_camera.GetView());
		}*/

		if (OpenGL::ToolWindow::moveLightChannel)
		{
			fighter.SetShader(&m_shaderDiffuse);
			fighter.Render(m_camera.GetProjection() * m_camera.GetView(), 0.04f);

			for (int count = 0; count < Mesh::Lights.size(); count++)
			{
				if (!OpenGL::ToolWindow::resetLightChannel)
				{
					if (glm::length(targetPos - spherePos) > 0.1)
					{
						glm::vec3 direction = glm::normalize(targetPos - spherePos);
						speedFactor = glm::length(targetPos) / glm::length(glm::vec3(100.0f, 100.0f, 100.0f));

						spherePos += direction * speedFactor;
						Mesh::Lights[count].SetPosition(spherePos);
					}
				}
				else
				{
					Mesh::Lights[count].SetPosition({ 0.0f, 0.0f, 0.1f });
					targetPos = { 0.0f, 0.0f, 0.1f };
					spherePos = { 0.0f, 0.0f, 0.1f };
					OpenGL::ToolWindow::resetLightChannel = false;
				}

				Mesh::Lights[count].Render(m_camera.GetProjection() * m_camera.GetView());
			}
		}
		else if (OpenGL::ToolWindow::transformChannel)
		{
			fighter.SetRotation(fighterRotate);

			if (OpenGL::ToolWindow::resetTansformChannel)
			{
				fighter.SetPosition({ 0.0f, 0.0f, 0.0f });
				fighter.SetRotation({ -45.0f, 0.0f, 0.0f });
				fighter.SetScale({ 0.0008f, 0.0008f, 0.0008f });
				OpenGL::ToolWindow::resetTansformChannel = false;
			}


			for (int count = 0; count < Mesh::Lights.size(); count++)
			{
				Mesh::Lights[count].SetPosition({ 0.0f, 0.0f, 2.0f });
			}


			if (OpenGL::ToolWindow::translateChannel)
			{
				if (leftButtonPressed)
				{
					if (glm::length(targetPos - fighterPos) > 0.1)
					{
						glm::vec3 direction = glm::normalize(targetPos - fighterPos);
						speedFactor = glm::length(targetPos) / glm::length(glm::vec3(100.0f, 100.0f, 100.0f));

						fighterPos += direction * speedFactor;
						fighter.SetPosition(fighterPos);
					}
				}
			}
			if (OpenGL::ToolWindow::rotateChannel)
			{
				
				double mouseX, mouseY;
				glfwGetCursorPos(WindowController::GetInstance().GetWindow(), &mouseX, &mouseY);

				double deltaX = mouseX - lastX;
				double deltaY = mouseY - lastY;

				lastX = mouseX;
				lastY = mouseY;


				int leftState = glfwGetMouseButton(WindowController::GetInstance().GetWindow(), GLFW_MOUSE_BUTTON_LEFT);
				if (leftState == GLFW_PRESS)
				{
					fighterRotate.y += deltaX * 0.1f; 
					fighterRotate.x -= deltaY * 0.1f; 
				}

				int middleState = glfwGetMouseButton(WindowController::GetInstance().GetWindow(), GLFW_MOUSE_BUTTON_MIDDLE);
				if (middleState == GLFW_PRESS)
				{
					fighterRotate.z += deltaY * 0.1f; 
				}

				fighter.SetRotation(fighterRotate);
			}
			if (OpenGL::ToolWindow::scaleChannel)
			{
				fighterScaleVec = fighter.GetScale();

				double deltaScaleX;
				double deltaScaleY;
				double mouseX, mouseY;
				glfwGetCursorPos(WindowController::GetInstance().GetWindow(), &mouseX, &mouseY);

				deltaScaleX = mouseX - lastX;
				deltaScaleY = mouseY - lastY;

				int leftState = glfwGetMouseButton(WindowController::GetInstance().GetWindow(), GLFW_MOUSE_BUTTON_LEFT);
				if (leftState == GLFW_PRESS)
				{
					fighterScaleVec.x += deltaScaleX * 0.00001f;
					fighterScaleVec.y += deltaScaleY * 0.00001f;

				}
				int middleState = glfwGetMouseButton(WindowController::GetInstance().GetWindow(), GLFW_MOUSE_BUTTON_MIDDLE);
				if (middleState == GLFW_PRESS)
				{
					fighterScaleVec.z += deltaScaleY * 0.00001f;

				}
				lastX = mouseX;
				lastY = mouseY;
				fighter.SetScale(fighterScaleVec);
			}



			fighter.Render(m_camera.GetProjection() * m_camera.GetView());
			//fish.Render(m_camera.GetProjection()* m_camera.GetView());
		}
		else if (OpenGL::ToolWindow::spaceSceneChannel)
		{
			m_camera.SetCameraPosition({ 0, 0, 0 });
			m_camera.Rotate();
			glm::mat4 view = glm::mat4(glm::mat3(m_camera.GetView()));
			skyBox.Render(m_camera.GetProjection() * view);
			

			for (int count = 0; count < Mesh::Lights.size(); count++)
			{
				Mesh::Lights[count].SetPosition({ 0.0f, 2.0f, 0.0f });
				Mesh::Lights[count].Render(m_camera.GetProjection()* m_camera.GetView());

			}

			asteroid.Render(m_camera.GetProjection()* m_camera.GetView(), 0.04f);
			fighter.SetPosition({ 0.4f, 0.0f, -0.7f });
			fighter.SetScale({ 0.0002f, 0.0002f, 0.0002f });
			fighter.SetRotation({ -45.0f, 0.0f, 0.0f });
			fighter.Render(m_camera.GetProjection()* m_camera.GetView());

		}

		double currentTime = glfwGetTime();
		fps++;
		if (currentTime - lastTime >= 1.0)
		{
			fpsS = "FPS: " + to_string(fps);
			fps = 0;
			lastTime = currentTime;
		}
		//m_postProcessor.End();
#pragma region fontRendering
		f.RenderText(fpsS, 100, 100, 0.3, { 1.0, 1.0, 0.0 });

		mousePosition = "Mouse Pos: " + to_string((int)xpos) + "   " + to_string((int)ypos);
		f.RenderText(mousePosition, 100, 150, 0.3, { 1.0, 1.0, 0.0 });
		
		if(leftButtonPressed)
			 leftButton = "Left Button: Down";
		else
			leftButton = "Left Button: UP";
		f.RenderText(leftButton, 100, 200, 0.3, { 1.0, 1.0, 0.0 });

		if (middleButtonPressed)
			middleButton = "Middle Button: Down";
		else
			middleButton = "Middle Button: UP";	
		f.RenderText(middleButton, 100, 250, 0.3, { 1.0, 1.0, 0.0 });

		fighterPosition = "Fighter Position: {" + glm::to_string(fighter.GetPosition()) + "}";
		f.RenderText(fighterPosition, 100, 300, 0.3, { 1.0, 1.0, 0.0 });
		fighterRotation = "Fighter Rotation: {" + glm::to_string(fighter.GetRotation()) + "}";
		f.RenderText(fighterRotation, 100, 350, 0.3, { 1.0, 1.0, 0.0 });
		fighterScale = "Fighter Scale: {" + glm::to_string(fighter.GetScale()) + "}";
		f.RenderText(fighterScale, 100, 400, 0.3, { 1.0, 1.0, 0.0 });
		f.RenderText("Asteroid:" + glm::to_string(asteroid.GetPosition()), 100, 450, 0.3, {1.0, 1.0, 0.0});
		f.RenderText("Asteroid:" + glm::to_string(asteroid.GetRotation()), 100, 500, 0.3, { 1.0, 1.0, 0.0 });

#pragma endregion fontRendering 

		glfwSwapBuffers(WindowController::GetInstance().GetWindow()); // Swap the front and back buffers
		glfwPollEvents();

	} while (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && // Check if the ESC key was pressed
		glfwWindowShouldClose(WindowController::GetInstance().GetWindow()) == 0); // Check if the window was closed (a non-zero value means the window is closed)

	

	for (int count = 0; count < Mesh::Lights.size(); count++)
	{
		Mesh::Lights[count].Render(m_camera.GetProjection()* m_camera.GetView());

	}

	for (unsigned int count = 0; count < m_meshes.size(); count++)
	{
		m_meshes[count].Cleanup();
	}
	skyBox.Cleanup();
	fighter.Cleanup();
	f.Cleanup();
	m_postProcessor.Cleanup();
	m_shaderDiffuse.Cleanup();
	m_shaderColor.Cleanup();
	m_shaderPost.Cleanup();
	m_shaderSkyBox.Cleanup();
}