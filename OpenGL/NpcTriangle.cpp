#include "NpcTriangle.h"
#include "WindowController.h"
#include "Resolution.h"
#include <iostream>
#include <cstdlib>
//
//NpcTriangle::NpcTriangle() : Mesh()
//{
//    m_speed = 0.01f;
//}
//
//NpcTriangle::~NpcTriangle()
//{
//}
//
//void NpcTriangle::Create(Shader* _shader)
//{
//    float num = static_cast<float>(rand() % 10);
//    m_vertexData = {
//        /* Position   */  /*    RGBA Color    */
//           num,         num, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
//         num + 2.0f,  num, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
//         num - 1.0f,  num + 2.0f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f
//    };
//
//
//    Mesh::Create(_shader, m_vertexData);
//}

NpcTriangle::NpcTriangle() : Mesh()
{
    m_speed = 0.01f;
}

NpcTriangle::~NpcTriangle()
{
}

/*
float x1 = dist_x(rng); // First vertex x coordinate
float y1 = dist_y(rng); // First vertex y coordinate
float x2 = dist_x(rng); // Second vertex x coordinate
float y2 = dist_y(rng); // Second vertex y coordinate
float x3 = dist_x(rng); // Third vertex x coordinate
float y3 = dist_y(rng); // Third vertex y coordinate
*/

void NpcTriangle::Create(Shader* _shader)
{
#include <random>
    //// Create a pseudo-random number generator
    //std::mt19937 rng;
    //// Set the seed
    //rng.seed(std::random_device()());
    //// Create a uniform distribution for x
    //std::uniform_real_distribution<float> dist_x(2.0f, 10.0f);
    //// Create a uniform distribution for y
    //std::uniform_real_distribution<float> dist_y(-10.0f, -2.0f);

    // Generate random floats for each vertex coordinate
    float x1 = dist_x(rng); // First vertex x coordinate
    float y1 = dist_y(rng); // First vertex y coordinate
    float x2 = x1 + 2.0f; // Second vertex x coordinate
    if (x2 > 10.0f) // Check if out of range
        x2 -= 4.0f; // Adjust by subtracting 4.0f
    float y2 = y1; // Second vertex y coordinate
    float x3 = x1 - 1.0f; // Third vertex x coordinate
    if (x3 < 2.0f) // Check if out of range
        x3 += 4.0f; // Adjust by adding 4.0f
    float y3 = y1 + 2.0f; // Third vertex y coordinate
    if (y3 > -2.0f) // Check if out of range
        y3 -= 4.0f; // Adjust by subtracting 4.0f

    // Create a vector of Vertex structs to store the vertex data
   
    m_vertexData = {
                /* Position   */  /*    RGBA Color    */
                   x1, y1, 0.0f, 1.0f, 0.0f, 1.0f,
                   x2, y2, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f,
                   x3, y3, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f
            };
    
    Mesh::Create(_shader, m_vertexData);

}
