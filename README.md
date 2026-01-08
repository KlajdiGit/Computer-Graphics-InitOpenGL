## Overview
InitOpenGL is a C++ graphics project developed in Visual Studio to explore the fundamentals of computer animation/graphics and real-time rendering. It leverages OpenGL to demonstrate how graphical commands are communicated from the CPU to the GPU, and how shaders, models, and rendering techniques come together to produce visual output.

The project focuses on building a foundational understanding of graphics pipelines, shader programming, and efficient rendering strategies. It includes support for custom shaders, model loading, instanced rendering, and basic lighting manipulation — all structured to simulate how modern graphics engines handle the logic and scene composition.

## Features
In this project, each feature is implemented with a focus on understanding how the GPU processes data, how shaders control visual output, and how efficient rendering strategies reduce CPU–GPU overhead. The project demonstrates how real‑time graphics applications structure their rendering flow, manage resources, and optimize draw calls.

### **OpenGL Rendering Pipeline**
Direct use of OpenGL for buffer creation, attribute binding, texture management, and draw calls. Demonstrates how vertex data flows through the pipeline and how GPU state is configured for different rendering tasks.

### **Custom Shader Programming (GLSL)**
Implementation of custom vertex and fragment shaders to control lighting, color manipulation, texture sampling, and per‑pixel effects. Includes shader compilation, linking, uniform management, and runtime updates.

### **Model Loading (ASE Format)**
Support for loading and parsing ASE (ASCII Scene Export) models. Extracts vertices, normals, UVs, and material data, then feeds them into OpenGL buffers for rendering. Demonstrates how engines convert external model formats into GPU‑ready data.

### **Instanced Rendering**
Efficient rendering of multiple copies of the same object using a single draw call. Reduces CPU overhead by batching instance transforms and sending them to the GPU as per‑instance attributes. Ideal for scenes with repeated geometry.

### **Basic Lighting Manipulation**
Shader‑based lighting calculations to simulate diffuse and ambient lighting. Shows how lighting equations are implemented in GLSL and how uniforms are used to control light color, intensity, and direction.

### **Skybox Rendering**
Implementation of a cube‑mapped skybox using a dedicated shader and depth manipulation. Demonstrates environment mapping and how background scenes are rendered without interfering with foreground geometry.

### **Post‑Processing Pipeline**
Use of framebuffer objects to apply screen‑space effects such as color grading, blurring, or edge detection. Shows how rendered scenes can be captured, processed, and re‑drawn using full‑screen quad shaders.

### **Shader Hot‑Reloading**
Ability to recompile and reload shader files at runtime without restarting the application. Useful for rapid experimentation and debugging of visual effects.

## Installation

Follow the steps below to set up and run the InitOpenGL project on your machine:

1. **Clone the repository**
   - Download the project using the **Code** button on GitHub

2. **Open the project in Visual Studio**
   - Launch **Visual Studio 2022** (recommended).
   - Open the solution file (`InitOpenGL.sln`).
   - Make sure the following components are installed:
     - Desktop development with C++
     - MSVC compiler toolset
     - Windows 10/11 SDK
     - CMake tools (optional)

3. **Configure the build environment**
   - Set the build target to **x64**.
   - Ensure your system has a GPU and drivers that support modern OpenGL.
   - Confirm that include/library paths for external dependencies (GLM, SDL2, etc.) are correctly configured if they are not bundled with the project.

4. **Verify required assets**
   - Shader files should be located in the `/shaders` directory.
   - ASE models and textures should be placed in the `/assets` folder.
   - Make sure file paths inside the code match your local directory structure.

5. **Build the project**
   - Use **Ctrl + Shift + B** to build the solution.
   - Resolve any missing dependency paths if Visual Studio reports errors.

6. **Run the application**
   - Start the program using **Local Windows Debugger**.
   - The OpenGL window should appear and begin rendering the scene.

### Important
This project **must be compiled and executed in x64 mode**.  
Running in x86 mode may cause OpenGL context failures, missing DLL errors, or unexpected crashes.

