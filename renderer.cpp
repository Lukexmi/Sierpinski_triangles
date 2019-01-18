#include "renderer.h"

void ClearScreen()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void DrawTriangle(struct Vector2 vertices[])
{
    glBegin(GL_TRIANGLES);
        glVertex2f(vertices[0].x, vertices[0].y);
        glVertex2f(vertices[1].x, vertices[1].y);
        glVertex2f(vertices[2].x, vertices[2].y);
    glEnd();
}

void SwitchColor(struct Vector3* col)
{
    col->y = 0;
    if(col->x == 1)
    {
        col->x = 0;
        col->z = 1;
    }
    else
    {
        col->z = 0;
        col->x = 1;
    }
}

Vector3 color = {1,0,0};

void StartDrawing(SDL_Window* window, struct Vector2 vertices[], int depth)
{
    //DrawTriangle(vertices);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1,1,1);
    SDL_GL_SwapWindow(window);
    SDL_Delay(1000);
    DrawSubTriangle(window,1, depth, vertices);
    std::cout << "DONE" << std::endl;
}

void DrawSubTriangle(SDL_Window* window, int n, int depth, Vector2 vertices[])
{
    DrawTriangle(vertices);

    Vector2 tr1[3];
    Vector2 tr2[3];
    Vector2 tr3[3];

    tr1[0].x = (vertices[0].x + vertices[1].x) / 2; //+ (vertices[1].x - vertices[2].x) / 2;
    tr1[0].y = (vertices[0].y + vertices[1].y) / 2; //+ (vertices[1].y - vertices[2].y) / 2;
    tr1[1].x = (vertices[0].x + vertices[2].x) / 2; //+ (vertices[0].x - vertices[2].x) / 2;
    tr1[1].y = (vertices[0].y + vertices[2].y) / 2; //+ (vertices[0].y - vertices[2].y) / 2;
    tr1[2].x = (vertices[1].x + vertices[2].x) / 2;
    tr1[2].y = (vertices[1].y + vertices[2].y) / 2;

    tr2[0].x = (tr1[0].x + vertices[1].x) / 2;
    tr2[0].y = (tr1[0].y + vertices[1].y) / 2;
    tr2[1].x = (tr1[0].x + tr1[2].x) / 2;
    tr2[1].y = (tr1[0].y + tr1[2].y) / 2;
    tr2[2].x = (tr1[2].x + vertices[1].x) / 2;
    tr2[2].y = (tr1[2].y + vertices[1].y) / 2;

    tr3[0].x = (tr1[0].x + vertices[0].x) / 2;
    tr3[0].y = (tr1[0].y + vertices[0].y) / 2;
    tr3[1].x = (tr1[0].x + tr1[1].x) / 2;
    tr3[1].y = (tr1[0].y + tr1[1].y) / 2;
    tr3[2].x = (tr1[1].x + vertices[0].x) / 2;
    tr3[2].y = (tr1[1].y + vertices[0].y) / 2;

    if(n <= depth)
    {
        DrawSubTriangle(window, n+1, depth, tr1);
        DrawSubTriangle(window, n+1, depth, tr2);
        DrawSubTriangle(window, n+1, depth, tr3);
    }
}

void GetInitialVertices(struct Vector2 *x)
{
    x[0].x = -1;
    x[0].y = -1;
    x[1].x = 1;
    x[1].y = -1;
    x[2].x = 0;
    x[2].y = 1;
}

Vector2 GetMidPoint(Vector2 p1, Vector2 p2)
{
      // M = ((x1+x2)/2; (y1+y2)/2)
      float x = (p1.x + p2.x) / 2;
      float y = (p1.y + p2.y) / 2;
      return {x,y};
}
