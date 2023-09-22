#ifndef STANDARD_INCLUDES_H
#define STANDARD_INCLUDES_H


// Includes standard headers
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

// Windows specific includes and defines
#ifdef WIN32
#include <Windows.h>
#define M_ASSERT(_cond, _msg) \
    if (!(_cond)) { OutputDebugStringA(_msg); std::abort(); glfwTerminate(); }
#endif

// Openg GL/Helper headers
#include <GL/glew.h>     // Include GLEW
#include <GLFW/glfw3.h>  // Include GLFW
#include <glm/glm.hpp>   // Include GLM
#include <glm/ext.hpp>   // Open Experimental to_string
#include <glm/gtx/string_cast.hpp>
#include "Singleton.h"

#define GLM_ENABLE_EXPERIMENTAL

using namespace std;

#endif //STANDARD_INCLUDES_H
