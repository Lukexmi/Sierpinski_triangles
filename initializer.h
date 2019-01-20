#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>

void EndProgram(SDL_Window** window); // quit SDL and delete all windows and renderers
bool Init(SDL_Window** window, SDL_GLContext context); //Create new window, add gl context to it, return false if failed
bool InitGL(); // Initialize openGL inside SDL. Should be used inside Init() function

#endif
