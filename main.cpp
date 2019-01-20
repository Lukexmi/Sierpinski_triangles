//Sierpinski triangle fractal drawing program
//Author: Luke M
//compile:  g++ main.cpp -w -lSDL2 -lGL -lGLU OR make
//NOTE: used c++98
#include "initializer.h"
#include "renderer.h"

using namespace std;

int main(void)
{
    SDL_Event exitEvent;
    bool done = false;
    SDL_Window* window;
    SDL_GLContext context;
    int steps = 6;
    // Main program flow here:
    if(Init(&window, &context))
    {
        SDL_GL_SetSwapInterval(1);
        Vector2 vertices[3];
        GetInitialVertices(vertices);

        std::cout << vertices[1].x << std::endl;

        ClearScreen();
        //StartDrawing(window, vertices, steps);
        //SDL_GL_SwapWindow(window);
      //  DrawTriangle(vertices);
        for(int y = 0; y < 600; y++)
        {
            for(int x = 0; x < 800; x++)
            {
                if(x&y) PutPixel({x,y});
            }
        }
        //PutPixel({100,100});

        //DrawTriangle(vert1);
        SDL_GL_SwapWindow(window);

        while(!done)
        {
            while(SDL_PollEvent(&exitEvent))
            {
                switch(exitEvent.type)
                {
                    case SDL_KEYDOWN:
                        cout << "Process is done" << endl;
                        done = true;
                    break;
                }
            }
        }
    }else
    {
        std::cout << "Rendering could not be initialized" << std::endl;
    }

    EndProgram(&window);

    return 0;
}
