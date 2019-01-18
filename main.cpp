//Sierpinski triangle fractal drawing program
//Author: Luke M
//compile:  g++ main.cpp -w -lSDL2 -lGL -lGLU OR make
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

        //std::cout << vertices[1].x << std::endl;

        ClearScreen();
        StartDrawing(window, vertices, steps);


      /*  Vector2 vert1[3];
        Vector2 line[2];
        line[0] = vertices[0];
        line[1] = vertices[1];
        Vector2 v1 = GetMidPoint(line);
        line[0] = vertices[2];
        line[1] = vertices[1];
        Vector2 v2 = GetMidPoint(line);
        line[0] = vertices[0];
        line[1] = vertices[2];
        Vector2 v3 = GetMidPoint(line);
        vert1[0] = v1;
        vert1[1] = v2;
        vert1[2] = v3;

        std::cout << vert1[0].x << ";" << vert1[0].y << std::endl;
        std::cout << vert1[1].x << ";" << vert1[1].y << std::endl;
        std::cout << vert1[2].x << ";" << vert1[2].y << std::endl;*/



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
