#include "GameController.h"
#include "WindowController.h"
#include "ToolWindow.h"
#include "Fonts.h"

GameController::GameController()
{
	m_shaderColor = { };
	m_shaderDiffuse = { };
	m_camera = { };
	m_skyBox = { };
	m_boxes.clear();
	m_spherePos = { 0.0f, 0.0f, 0.1f };
	m_teapotPos = { 0.0f, 0.0f, 0.0f };
	m_colorByPosition = { };

	m_simpleShader = { };
}

double xpos = 0.0f;
double ypos = 0.0f;
glm::vec3 targetPos;
float speedFactor;
static void mouse_callback(GLFWwindow* window, int button, int action, int mods)
{
	int width, height;
	glfwGetWindowSize(window, &width, &height);
	
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		glfwGetCursorPos(window, &xpos, &ypos);

		float x = (xpos / width) * 2.0f - 1.0f;
		float y = 1.0 - (ypos / height) * 2.0f;
		targetPos = glm::vec3(x, y, 0.0f);

	}

}

void GameController::Initialize()
{

	GLFWwindow* window = WindowController::GetInstance().GetWindow(); // Call this first, as it creates a window required by GLEW
	M_ASSERT(glewInit() == GLEW_OK, "Failed to initialize GLEW.") // Initialize GLEW
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we can capture the escape key
	glClearColor(0.1f, 0.1f, 0.1f, 0.0f); // Grey background 
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	srand((unsigned int)time(0));

	//Create a default perspective camera
	m_camera = Camera(WindowController::GetInstance().GetResolution());
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
	m_shaderSkyBox = Shader();
	m_shaderSkyBox.LoadShaders("SkyBox.vertexshader", "SkyBox.fragmentshader");
	m_shaderFont = Shader();
	m_shaderFont.LoadShaders("Font.vertexshader", "Font.fragmentshader");
	m_colorByPosition = Shader();
	m_colorByPosition.LoadShaders("ColorByPosition.vertexShader", "ColorByPosition.fragmentShader");

	m_simpleShader = Shader();
	m_simpleShader.LoadShaders("SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader");


#pragma endregion SetupShaders

#pragma region CreateMeshes
	//Create meshes
	Mesh m = Mesh();
	m.Create(&m_shaderColor, "../Assets/Models/Sphere.obj");
	m.SetPosition(m_spherePos);
	m.SetColor({ 1.0f, 1.0f, 1.0f });
	m.SetScale({ 0.01f, 0.01f, 0.01f });
	Mesh::Lights.push_back(m);

	Mesh teapotMesh = Mesh();
	teapotMesh.Create(&m_shaderDiffuse, "../Assets/Models/teapotSpc.obj");
	teapotMesh.SetCameraPosition(m_camera.GetPosition());
	teapotMesh.SetScale({ 0.05f, 0.05f, 0.05f });
	teapotMesh.SetPosition(m_teapotPos);

	//m_meshes.push_back(teapotMesh);

	Mesh sphereOut3 = Mesh();
	sphereOut3.Create(&m_shaderDiffuse, "../Assets/Models/SphereOut3.obj");
	sphereOut3.SetCameraPosition(m_camera.GetPosition());
	sphereOut3.SetScale({ 0.03f, 0.03f, 0.03f });
	sphereOut3.SetPosition({ 0.0f, 0.0f, 0.0f });


#pragma endregion CreateMeshes

	Fonts f = Fonts();
	std::string mousePosition = "";
	f.Create(&m_shaderFont, "arial.ttf", 100);

	Fonts fpsFont = Fonts();
	std::string fpsString = "";
	int fps = 0;
	double lastTime = glfwGetTime();
	fpsFont.Create(&m_shaderFont, "arial.ttf", 100);

	Fonts cubes = Fonts();
	std::string cubesCount = "";
	cubes.Create(&m_shaderFont, "arial.ttf", 100);

	glm::vec3 spherePos = GetSpherePos();
	glm::vec3 teapotPos = GetTeapotPos();
	
	do
	{
		System::Windows::Forms::Application::DoEvents();

		double currentTime = glfwGetTime();
		fps++;
		if (currentTime - lastTime >= 1.0)
		{
			fpsString = "FPS: " + to_string(fps);
			fps = 0;
			lastTime += 1.0;
		}
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear the screen

		if (OpenGL::ToolWindow::moveLightChannel)
		{

			for (int count = 0; count < Mesh::Lights.size(); count++)
			{
				if (!OpenGL::ToolWindow::resetLightButton)
				{
					if (glm::length(targetPos - spherePos) > 0.01f)
					{
						glm::vec3 direction = glm::normalize(targetPos - spherePos);
						speedFactor = glm::length(targetPos) / glm::length(glm::vec3((100.0f, 100.0f, 100.0f)));

						spherePos += direction * speedFactor;
						Mesh::Lights[count].SetPosition(spherePos);
					}
			    }
			    else
			    {
					Mesh::Lights[count].SetPosition({ 0.0f, 0.0f, 0.1f });
					targetPos = { 0.0f, 0.0f, 0.1f };
					spherePos = { 0.0f, 0.0f, 0.1f };
					OpenGL::ToolWindow::resetLightButton = false;
			    }

			Mesh::Lights[count].Render(m_camera.GetProjection() * m_camera.GetView());
		    }
			teapotMesh.SetShader(&m_shaderDiffuse);

			//glDisable(GL_DEPTH_TEST);
			teapotMesh.Render(m_camera.GetProjection() * m_camera.GetView());
			//glEnable(GL_DEPTH_TEST);

		}
		else if (OpenGL::ToolWindow::colorByPositionChannel)
		{
			teapotMesh.SetShader(&m_colorByPosition);

			if (!OpenGL::ToolWindow::resetTeapotButton)
			{

				if (glm::length(targetPos - teapotPos) > 0.01f)
				{
					glm::vec3 direction = glm::normalize(targetPos - teapotPos);
					speedFactor = glm::length(targetPos) / glm::length(glm::vec3((100.0f, 100.0f, 100.0f)));
					teapotPos += direction * speedFactor;
					teapotMesh.SetPosition(teapotPos);
				}
			}
			else
			{
				teapotMesh.SetPosition({ 0.0f, 0.0f, 0.0f });
				targetPos = { 0.0f, 0.0f, 0.0f };
				teapotPos = { 0.0f, 0.0f, 0.0f };
				OpenGL::ToolWindow::resetTeapotButton = false;
			}
			teapotMesh.Render(m_camera.GetProjection() * m_camera.GetView());
		}
		else if (OpenGL::ToolWindow::moveCubesChannel)
		{
			if (m_boxes.size() == 0)
			{
				cubesCount = "Cubes: ";
			}
			else
			{
				cubesCount = "Cubes: " + to_string(m_boxes.size());
			}
			cubes.RenderText(cubesCount, 30, 110, 0.2f, { 1.0f, 1.0f, 0.0f });

			//glDisable(GL_DEPTH_TEST);
			Mesh::Lights[0].Render(m_camera.GetProjection() * m_camera.GetView());
			//glDisable(GL_DEPTH_TEST);

			sphereOut3.Render(m_camera.GetProjection() * m_camera.GetView());
			//glEnable(GL_DEPTH_TEST);

			int state = glfwGetMouseButton(WindowController::GetInstance().GetWindow(), GLFW_MOUSE_BUTTON_LEFT);
			if (state == GLFW_PRESS)
			{

				Mesh box = Mesh();
				box.Create(&m_shaderDiffuse, "../Assets/Models/Box.obj");
				box.SetCameraPosition(m_camera.GetPosition());
				box.SetScale({ 0.01f, 0.01f, 0.01f });
				box.SetPosition(
					{ static_cast<float>(rand()) / RAND_MAX * 3 - 2,
					  static_cast<float>(rand()) / RAND_MAX * 3 - 2,
					  static_cast<float>(rand()) / RAND_MAX - 1
					  //0.0f
					});
				m_boxes.push_back(box);

			}
			for (unsigned int count = 0; count < m_boxes.size(); count++)
			{

				
				if (glm::length(sphereOut3.GetPosition() - m_boxes[count].GetPosition()) > 0.01f)
				{
					glm::vec3 direction = glm::normalize(sphereOut3.GetPosition() - m_boxes[count].GetPosition());
					glm::vec3 boxPos = m_boxes[count].GetPosition() + direction * 0.001f;
					m_boxes[count].SetPosition(boxPos);

				}
				else
				{
				    m_boxes.erase(m_boxes.begin() + count);
				}
			}
			
			for (unsigned int i = 0; i < m_boxes.size(); i++)
			{
				m_boxes[i].Render(m_camera.GetProjection()* m_camera.GetView());
			}

		}
		
	
	mousePosition = "Mouse Pos: " + to_string((int)xpos) + "   " + to_string((int)ypos);
	f.RenderText(mousePosition, 30, 80, 0.2f, { 1.0f, 1.0f, 0.0f });
	fpsFont.RenderText(fpsString, 30, 50, 0.2f, { 1.0f, 1.0f, 0.0f });

	glfwSwapBuffers(WindowController::GetInstance().GetWindow()); // Swap the front and back buffers
	glfwPollEvents();

	} while (glfwGetKey(WindowController::GetInstance().GetWindow(), GLFW_KEY_ESCAPE) != GLFW_PRESS && // Check if the ESC key was pressed
		glfwWindowShouldClose(WindowController::GetInstance().GetWindow()) == 0); // Check if the window was closed (a non-zero value means the window is closed)

	

	for (int count = 0; count < Mesh::Lights.size(); count++)
	{
		Mesh::Lights[count].Cleanup();
	}

	for (unsigned int count = 0; count < m_boxes.size(); count++)
	{
		m_boxes[count].Cleanup();
	}
	teapotMesh.Cleanup();
	m_shaderDiffuse.Cleanup();
	m_shaderSkyBox.Cleanup();
	m_shaderColor.Cleanup();
}