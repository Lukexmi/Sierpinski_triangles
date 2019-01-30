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
#include "initializer.h"

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
void DrawSubTriangle(SDL_Window* window, int n, int depth, Vector2 vertices[]);// Draw a sub triangle
void StartDrawing(SDL_Window *window, struct Vector2 vertices[], int depth); // Recursive method
void AndDraw(SDL_Window *window, Config conf); // And Method drawing
void RandomDraw(int pixels, SDL_Window* window, Config config);
void GetInitialVertices(struct Vector2 *x);
//These functions may go to another file
void DrawTriangle(struct Vector2 vertices[]); // Draw a triangle with specific vertice coordinates
void PutPixel(Vector2 coordinates);
void DrawLine(Vector2 p1, Vector2 p2);
Vector2 GetMidPoint(Vector2 p1, Vector2 p2); //Calculate midpoint



#endif
