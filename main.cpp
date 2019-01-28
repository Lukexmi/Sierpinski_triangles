//Sierpinski triangle fractal drawing program
//Author: Luke M
//compile:  g++ main.cpp -w -lSDL2 -lGL -lGLU OR make
//NOTE: used c++98
#include "initializer.h"
#include "renderer.h"
#include "args.h"

using namespace std;

int main(int argc, char** args)
{
    Config conf;

    ParseParams(argc, args, &conf);
    std::cout << conf.DONE << std::endl;
    SDL_Event exitEvent;
    SDL_Window* window;
    SDL_GLContext context;
    // Main program flow here:
    if(conf.DONE == false && Init(&window, &context, conf))
    {
        SDL_GL_SetSwapInterval(1);
        Vector2 vertices[3];
        GetInitialVertices(vertices);
        ClearScreen();

        if(conf.RENDER_MODE == Recursive)
        {
            std::cout << "Drawing recursively" << std::endl;
            StartDrawing(window, vertices, conf.STEPS);
        }
        else if(conf.RENDER_MODE == And)
        {
            std::cout << "Drawing AND" << std::endl;
            for(int y = 0; y < conf.SCREEN_WIDTH; y++)
            {
                for(int x = 0; x < conf.SCREEN_HEIGHT; x++)
                {
                    if(x&y)
                    {
                      glColor3f(0,0,0);
                      PutPixel({x,y});
                    }
                    else{
                      glColor3f(1,1,1);
                      PutPixel({x,y});
                    }
                }
            }
        }

        SDL_GL_SwapWindow(window);

        while(!conf.DONE)
        {
            while(SDL_PollEvent(&exitEvent))
            {
                switch(exitEvent.type)
                {
                    case SDL_KEYDOWN:
                        cout << "Process is done" << endl;
                        conf.DONE = true;
                    break;
                }
            }
        }
    }else if(conf.DONE == false)
    {
        std::cout << "Rendering could not be initialized" << std::endl;
    }

    EndProgram(&window);

    return 0;
}
