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

void DrawLine(Vector2 p1, Vector2 p2)
{
  glBegin(GL_LINES);
    glVertex2f(p1.x, p1.y);
    glVertex2f(p2.x, p2.y);
  glEnd();
}

void PutPixel(Vector2 coordinates)
{
  glPointSize(1);
  glBegin(GL_POINTS);
    glVertex2i((int)coordinates.x, (int)coordinates.y);
  glEnd();
}

void StartDrawing(SDL_Window* window, struct Vector2 vertices[], int depth)
{
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1,1,1);

    SDL_GL_SwapWindow(window);
    SDL_Delay(1000);

    Vector2 temp[3];

    DrawTriangle(vertices);

    temp[0].x = (vertices[0].x + vertices[1].x) / 2;
    temp[0].y = (vertices[0].y + vertices[1].y) / 2;

    temp[1].x = (vertices[0].x + vertices[2].x) / 2;
    temp[1].y = (vertices[0].y + vertices[2].y) / 2;

    temp[2].x = (vertices[1].x + vertices[2].x) / 2;
    temp[2].y = (vertices[1].y + vertices[2].y) / 2;

    DrawSubTriangle(window,1, depth, temp);
    std::cout << "DONE" << std::endl;
}

void DrawSubTriangle(SDL_Window* window, int n, int depth, Vector2 vertices[])
{
    //DrawTriangle(vertices);

    DrawLine(vertices[0], vertices[1]);
    DrawLine(vertices[0], vertices[2]);
    DrawLine(vertices[1], vertices[2]);

    Vector2 temp[3];
    if(n <= depth)
    {
        //recalculate vertices for first triangle

        temp[0].x = (vertices[0].x + vertices[1].x) / 2 + (vertices[1].x - vertices[2].x) / 2;
        temp[0].y = (vertices[0].y + vertices[1].y) / 2 + (vertices[1].y - vertices[2].y) / 2;

        temp[1].x = (vertices[0].x + vertices[1].x) / 2 + (vertices[0].x - vertices[2].x) / 2;
        temp[1].y = (vertices[0].y + vertices[1].y) / 2 + (vertices[0].y - vertices[2].y) / 2;

        temp[2].x = (vertices[0].x + vertices[1].x) / 2;
        temp[2].y = (vertices[0].y + vertices[1].y) / 2;

        DrawSubTriangle(window, n+1, depth, temp);
        //recalculate vertices for second triangle

        temp[0].x = (vertices[2].x + vertices[1].x) / 2 + (vertices[1].x - vertices[0].x) / 2;
        temp[0].y = (vertices[2].y + vertices[1].y) / 2 + (vertices[1].y - vertices[0].y) / 2;

        temp[1].x = (vertices[2].x + vertices[1].x) / 2 + (vertices[2].x - vertices[0].x) / 2;
        temp[1].y = (vertices[2].y + vertices[1].y) / 2 + (vertices[2].y - vertices[0].y) / 2;

        temp[2].x = (vertices[2].x + vertices[1].x) / 2;
        temp[2].y = (vertices[2].y + vertices[1].y) / 2;

        DrawSubTriangle(window, n+1, depth, temp);
        //recalculate vertices for third triangle

        temp[0].x = (vertices[0].x + vertices[2].x) / 2 + (vertices[2].x - vertices[1].x) / 2;
        temp[0].y = (vertices[0].y + vertices[2].y) / 2 + (vertices[2].y - vertices[1].y) / 2;

        temp[1].x = (vertices[0].x + vertices[2].x) / 2 + (vertices[0].x - vertices[1].x) / 2;
        temp[1].y = (vertices[0].y + vertices[2].y) / 2 + (vertices[0].y - vertices[1].y) / 2;

        temp[2].x = (vertices[0].x + vertices[2].x) / 2;
        temp[2].y = (vertices[0].y + vertices[2].y) / 2;

        DrawSubTriangle(window, n+1, depth, temp);
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
