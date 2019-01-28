#ifndef RENDERER_H
#define RENDERER_H

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include "stdio.h"
#include <ctime>
#include <math.h>

typedef struct Vector2
{
    float x;
    float y;
};

typedef struct Vector3
{
    float x;
    float y;
    float z;
};

void ClearScreen(); // Call glClear
void DrawTriangle(struct Vector2 vertices[]); // Draw a triangle with specific vertice coordinates
void DrawSubTriangle(SDL_Window* window, int n, int depth, Vector2 vertices[]);// Draw a sub triangle
void StartDrawing(SDL_Window *window, struct Vector2 vertices[], int depth);
//These functions may go to another file
void PutPixel(Vector2 coordinates);
void DrawLine(Vector2 p1, Vector2 p2);
Vector2 GetMidPoint(Vector2 p1, Vector2 p2); //Calculate midpoint
void GetInitialVertices(struct Vector2 *x);


#endif
