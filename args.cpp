#include "args.h"
#include "stdio.h"
#include "string.h"
//#include <regex>

#define DEFAULT_WIDTH 800
#define DEFAULT_HEIGHT 600
#define DEFAULT_MODE 0

bool CheckConfig(Config* conf);
bool CheckData(int i, int argc);
void DisplayHelp(Config *conf);

bool ParseParams(int argc, char** argv, Config* conf)
{
    conf->STEPS = 6;
    conf->SLEEP_TIME = 100;
    conf->SCREEN_WIDTH = DEFAULT_WIDTH;
    conf->SCREEN_HEIGHT = DEFAULT_HEIGHT;
    conf->RENDER_MODE = (renderFlags)DEFAULT_MODE;
    conf->DONE = false;
    if(argc < 2)
    {
      return true;
    }
    else
    {
        for(int i = 1; i < argc; i++)
        {
            if(strcmp(argv[i], "/?") == 0 || strcmp(argv[i], "-h") == 0)
            {
                DisplayHelp(conf);
                conf->DONE = true;
            }

            if(strcmp(argv[i], "-i") == 0)
            {
                i++;
                if(CheckData(i, argc))
                  conf->STEPS = atoi(argv[i]);
            }

            if(strcmp(argv[i], "-s") == 0)
            {
                i++;
                if(CheckData(i, argc))
                  conf->SLEEP_TIME = atoi(argv[i]);
                else
                {
                  printf("Bad parameters\n");
                  conf->DONE = true;
                }
            }

            if(strcmp(argv[i], "-d") == 0)
            {
                i++;
                if(CheckData(i, argc))
                  conf->SCREEN_WIDTH = atoi(argv[i]);
                else
                {
                  printf("Bad parameters\n");
                  conf->DONE = true;
                }
                i++;
                if(CheckData(i, argc))
                  conf->SCREEN_HEIGHT = atoi(argv[i]);
                else
                {
                  printf("Bad parameters\n");
                  conf->DONE = true;
                }
            }

            if(strcmp(argv[i], "-m") == 0)
            {
                i++;
                if(CheckData(i, argc))
                  conf->RENDER_MODE = (renderFlags)atoi(argv[i]);
                else
                {
                  printf("Bad parameters\n");
                  conf->DONE = true;
                }
            }
        }
    }

    //  -h /? for help
    //  -i for iterations a.k.a steps (how deep fractal is drawn (in recursive))
    //  -d for screen dimensions (2 params, first width, then height)
    //  -m for rendering mode (0 for recursive, 1 for AND, 2 for random)

    return CheckConfig(conf);
}

void DisplayHelp(Config* conf)
{
    printf("Hello, this is Sierpinski triangle fractal drawing program\n");
    printf("Here are the configuration keys:\n");
    printf("-h /? => Display help and exit\n");
    printf("-i => step count in recursive mode (Default 6)\n");
    printf("-d => screen dimensions, write two integers separated by space(first is screen width, second is screen height)\n");
    printf("-m => rendering mode (0 - draw triangles recursively, 1 - using & operator, 2 - using rand())\n");
}

bool CheckData(int i, int argc)
{
    if(i > argc) return false;
    else return true;
}

bool CheckConfig(Config* conf)
{
    if(conf->DONE == false)
    {
      if(conf->STEPS == 0 || conf->SCREEN_WIDTH == 0 || conf->SCREEN_HEIGHT == 0 || conf->RENDER_MODE > 3)
      {
          printf("Bad data\n");
          conf->DONE = true;
          return false;
      }
      else return true;
    }
    return false;
}
