#include "initializer.h"

void EndProgram(SDL_Window** window)
{
    SDL_DestroyWindow(*window);
    SDL_Quit();
}

bool Init(SDL_Window** window, SDL_GLContext context, Config config)
{
    if( SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        std::cout << "SDL Could not be initialized! " << SDL_GetError() << std::endl;
        return false;
    }
    else
    {
        //Set openGL 2.1 and flags for rgb channels, turn double buffer on
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
        SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 5);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

        //Create Window here:
        *window = SDL_CreateWindow("Sierpinski", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
        config.SCREEN_WIDTH,config.SCREEN_HEIGHT,SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

        if(window == NULL)
        {
            std::cout << "Window could not be created! " << SDL_GetError() << std::endl;
            return false;
        }
        else
        {
            context = SDL_GL_CreateContext(*window);
            if(context == NULL)
            {
                std::cout << "OpenGL context could not be created! " << SDL_GetError() << std::endl;
                return false;
            }
            else
            {
                if(SDL_GL_SetSwapInterval(1) < 0)
                {
                    std::cout << "Warning: Vsync is off: " << SDL_GetError() << std::endl;
                }

                if(!InitGL(config.RENDER_MODE))
                {
                    std::cout << "Unable to initialize OpenGL..." << SDL_GetError() << std::endl;
                    return false;
                }
            }
        }
    }
    return true;
}

bool InitGL(enum renderFlags flags)
{
    GLenum error = GL_NO_ERROR;

    glMatrixMode(GL_PROJECTION); // Set current matrix

    if(flags == Recursive)
    {
        std::cout << "initgl recursive" << std::endl;
        glLoadIdentity(); // Replace current matrix into identity matrix
    }
    if(flags == And)
    {
        std::cout << "initgl and" << std::endl;
        gluOrtho2D( 0.0, 1024.0, 1024.0,0.0 );
    }

    error = glGetError();
    if(error != GL_NO_ERROR)
    {
        std::cout << "Error initializing openGL! " << gluErrorString(error) << std::endl;
        return false;
    }
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    error = glGetError();
    if(error != GL_NO_ERROR)
    {
        std::cout << "Error initializing openGL! " << gluErrorString(error) << std::endl;
        return false;
    }

    glClearColor(0.f, 0.f, 0.f, 1.f);
    error = glGetError();
    if(error != GL_NO_ERROR)
    {
        std::cout << "Error initializing openGL! " << gluErrorString(error) << std::endl;
        return false;
    }
    else
    {
        return true;
    }
}
