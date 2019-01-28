#ifndef INITIALIZER_H
#define INITIALIZER_H

#include <iostream>
#include <SDL2/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "args.h"

enum renderFlags{ Recursive = 0, And = 1};

struct Config
{
    bool  DONE;
    int   STEPS;
    int   SLEEP_TIME;
    int   SCREEN_WIDTH;
    int   SCREEN_HEIGHT;
    enum renderFlags RENDER_MODE;
};

void EndProgram(SDL_Window** window); // quit SDL and delete all windows and renderers
bool Init(SDL_Window** window, SDL_GLContext context, Config config); //Create new window, add gl context to it, return false if failed
bool InitGL(enum renderFlags flags); // Initialize openGL inside SDL. Should be used inside Init() function

#endif
