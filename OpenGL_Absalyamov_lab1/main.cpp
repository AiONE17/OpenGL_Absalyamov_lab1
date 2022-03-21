#include <GLFW/glfw3.h>
#define _USE_MATH_DEFINES_
#include <cmath>
#include <iostream>
#include <Windows.h>

POINTFLOAT vertices[] = {
    {0,0},
    {1,0},
    {1,1},
    {0,1}
};

float newcoordinates[] = { 1,1,-3, -1,0,-3, 1,-1,-3 };

float pyramid[] = { 0,0,2, 1,1,0, 1,-1,0, -1,-1,0, -1,1,0, 1,1,0 };
float pyramidnorm[] = { 0,0,1, 0,0,1, 0,0,1, 0,0,1 };

float CUBE[] = { -1,-1,1, 1,-1,1, 1,1,1, -1,1,1,
                 1,-1,-1 - 1,-1,-1 - 1,1,-1, 1,1,-1,
                 -1,-1,-1, -1,-1,1, -1,1,1, -1,1,-1,
                 1,-1,1, 1,-1,-1, 1,1,-1, 1,1,1,
                 -1,-1,1, 1,-1,1, 1,-1,-1, -1,-1,-1,
                 -1,1,1, 1,1,1, 1,1,-1, -1,1,-1
};

float floorcoord[] = { 1,1,0, 1,-1,0, -1,-1, 0, -1,1,0 };
POINTFLOAT colors[] = { 1,0,0, 0,1,0, 0,0,1, 1,1,0 };


GLuint indexes[] = { 1,2,3, 3,0,1 };

float xangle = 20;
float zangle = 0;

void DrawFloor()
{
    /*glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_NORMAL_ARRAY);*/
    //glVertexPointer(3, GL_FLOAT, 0, &floorcoord);
    //glNormalPointer(GL_FLOAT, 0, &pyramidnorm);
    //for (int i = -5; i < 5; i++)
    //{
    //    for (int j = -5; j < 5; j++)
    //    {
    //        glPushMatrix();
    //        if ((i + j) % 2 == 0) glColor3f(1, 0, 0);
    //        else glColor3f(0, 1, 0);
    //        glTranslatef(i * 2, j * 2, 0);
    //        glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    //        glPopMatrix();
    //    }
    //}
    //glVertexPointer(3, GL_FLOAT, 0, &pyramid);
    //glColor3f(0, 0, 1);
    //glDrawArrays(GL_TRIANGLE_FAN,0,6);
    //glPushMatrix();
    //glTranslatef(2, 2, 0);
    //glColor3f(1,1,0);
    //glDrawArrays(GL_TRIANGLE_FAN, 0, 6);
    //glPopMatrix();

    //glVertexPointer(3, GL_FLOAT, 0, &CUBE);
    //glEnableClientState(GL_VERTEX_ARRAY);
    //glColor3f(0, 0, 1);
    //glDrawArrays(GL_QUADS, 0, 24);

   // glDisableClientState(GL_VERTEX_ARRAY);
  //  glDisableClientState(GL_NORMAL_ARRAY);

}

void MoveCamera()
{
    if (GetKeyState(VK_LEFT) < 0) xangle = ++xangle > 180 ? 180 : xangle;
    if (GetKeyState(VK_RIGHT) < 0) xangle = --xangle > 0 ? 0 : xangle;
    glRotatef(-xangle, 0, 0, 1);
}

void MoveCamera1()
{
    if (GetKeyState(VK_UP) < 0) xangle = ++xangle > 180 ? 180 : xangle;
    if (GetKeyState(VK_DOWN) < 0) xangle = --xangle > 0 ? 0 : xangle;
    if (GetKeyState(VK_LEFT) < 0) zangle++;
    if (GetKeyState(VK_RIGHT) < 0) zangle--;
    glRotatef(-xangle, 1, 0, 0);
    glRotatef(-zangle, 0, 0, 1);
    glTranslatef(0, 0, -5);
}


void DrawRoad()
{
    glBegin(GL_TRIANGLES);             // Drawing Using Triangles 
    glColor3f(0, 0, 0);
    glVertex2f(0, 0); // Top 
    glColor3f(0, 0, 0.1);
    glVertex2f(0.70, -1); // Bottom Right 
    glColor3f(0, 0, 0.1);
    glVertex2f(-0.70, -1); // Bottom Left 
    glEnd();
}

void DrawRoadLines()
{
    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(-0.05, -1, 0.0);
    glColor3f(1, 1, 1);
    glVertex3f(0.05, -1, 0.0);
    glColor3f(1, 1, 1);
    glVertex3f(0.025, -0.7, 0.0);
    glColor3f(1, 1, 1);
    glVertex3f(-0.025, -0.7, 0.0);
    glEnd();
}

void DrawSky()
{
    glBegin(GL_POLYGON);
    glColor3f(1,0.7,0.6);
    glVertex3f(-1, 0, 0.0);
    glColor3f(1, 0.70, 0.85);
    glVertex3f(-1, 1, 0.0);
    glColor3f(1, 0.70, 0.85);
    glVertex3f(1, 1, 0.0);
    glColor3f(1, 0.70, 0.85);
    glVertex3f(1, 0, 0.0);
    glEnd();
}

void DrawGrass()
{
    glBegin(GL_POLYGON);
    glColor3f(0.46666, 0.86328125, 0.46666);
    glVertex3f(-1, 0, 0.0);
    glColor3f(0.46666, 0.86328125, 0.46666);
    glVertex3f(-1, -1, 0.0);
    glColor3f(0.46666, 0.86328125, 0.46666);
    glVertex3f(1, -1, 0.0);
    glColor3f(0.46666, 0.86328125, 0.46666);
    glVertex3f(1, 0, 0.0);
    glEnd();
}

void DrawRoadDK()
{
    glBegin(GL_TRIANGLES);             // Drawing Using Triangles 
    glColor3f(0.4, 0.4, 0.4);
    glVertex2f(0, 0); // Top 
    glColor3f(0.737, 0.745, 0.7529);
    glVertex2f(-0.70, -1); // Bottom Left 
    glColor3f(0.737, 0.745, 0.7529);
    glVertex2f(-0.9, -1); // Bottom Right 
    glEnd();
}

void DrawHouse()
{
    glLineWidth(2.5);

    glBegin(GL_POLYGON);
    glColor3f(0.529, 0.8078, 0.92156);
    glVertex3f(-0.05248, 0.0448, 0.0);
    glColor3f(0.529, 0.8078, 0.92156);
    glVertex3f(-0.02368, 0.0256, 0.0);
    glColor3f(0.529, 0.8078, 0.92156);
    glVertex3f(-0.02368, -0.0256, 0.0);
    glColor3f(0.529, 0.8078, 0.92156);
    glVertex3f(-0.05248, -0.0576, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.529, 0.8078, 0.92156);
    glVertex3f(-0.064, 0.0448, 0.0);
    glColor3f(0.529, 0.8078, 0.92156);
    glVertex3f(-0.05248, 0.0448, 0.0);
    glColor3f(0.529, 0.8078, 0.92156);
    glVertex3f(-0.05248, -0.0576, 0.0);
    glColor3f(0.529, 0.8078, 0.92156);
    glVertex3f(-0.064, -0.0576, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1, 1, 1);
    glVertex3f(-0.0352, 0.0224, 0.0);
    glColor3f(1, 1, 1);
    glVertex3f(-0.0256, 0.01728, 0.0);
    glColor3f(1, 1, 1);
    glVertex3f(-0.0256, -0.00896, 0.0);
    glColor3f(1, 1, 1);
    glVertex3f(-0.0352, -0.016, 0.0);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.847, 0.749, 0.47);
    glVertex3f(-0.048, 0.0288, 0.0);
    glColor3f(0.847, 0.749, 0.47);
    glVertex3f(-0.0384, 0.02368, 0.0);
    glColor3f(0.847, 0.749, 0.47);
    glVertex3f(-0.0384, -0.0384, 0.0);
    glColor3f(0.847, 0.749, 0.47);
    glVertex3f(-0.048, -0.048, 0.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(-0.064, 0.0448, 0.0);
    glColor3f(0, 0, 0);
    glVertex3f(-0.05248, 0.0448, 0.0);
    glColor3f(0, 0, 0);
    glVertex3f(-0.05248, -0.0576, 0.0);
    glColor3f(0, 0, 0);
    glVertex3f(-0.064, -0.0576, 0.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(-0.05248, 0.0448, 0.0);
    glColor3f(0, 0, 0);
    glVertex3f(-0.02368, 0.0256, 0.0);
    glColor3f(0, 0, 0);
    glVertex3f(-0.02368, -0.0256, 0.0);
    glColor3f(0, 0, 0);
    glVertex3f(-0.05248, -0.0576, 0.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(-0.0352, 0.0224, 0.0);
    glColor3f(0, 0, 0);
    glVertex3f(-0.0256, 0.01728, 0.0);
    glColor3f(0, 0, 0);
    glVertex3f(-0.0256, -0.00896, 0.0);
    glColor3f(0, 0, 0);
    glVertex3f(-0.0352, -0.016, 0.0);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3f(0, 0, 0);
    glVertex3f(-0.048, 0.0288, 0.0);
    glColor3f(0, 0, 0);
    glVertex3f(-0.0384, 0.02368, 0.0);
    glColor3f(0, 0, 0);
    glVertex3f(-0.0384, -0.0384, 0.0);
    glColor3f(0, 0, 0);
    glVertex3f(-0.048, -0.048, 0.0);
    glEnd();
}
void DrawCircle()
{
    GLfloat theta;
    GLfloat pi = acos(-1.0);
    GLfloat radius = 0.2f; // ðàäèóñ
    GLfloat step = 3.0f; // ÷åì áîëüøå øàã òåì õóæå äèñê

    // ðèñóåì äèñê ïî ÷àñîâîé ñòðåëêè GL_CW
    glTranslatef(0, 0.70, 0);
    glBegin(GL_TRIANGLE_FAN);
    for (GLfloat a = 0.0f; a < 360.0f; a += step) {
        theta = 2.0f * pi * a / 180.0f;
        glColor3f(0.737 + a / 1100, 1 - a / 1600, 0.3);
        glVertex3f(radius * cos(theta), radius * sin(theta), 0.0f);
    }
    glEnd();
}



int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1024, 720, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    //glEnable(GL_DEPTH_TEST); //ÁÓÔÅÐ ÃËÓÁÈÍÛ
    //glMatrixMode(GL_PROJECTION);

    //glLoadIdentity();
    //glFrustum(-1,1, -1,1, 0.2,1000); //ÏÅÐÑÏÅÊÒÈÂÍÀß ÏÐÎÅÊÖÈß
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    //glEnable(GL_DEPTH_TEST);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    //glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_BLEND);
    //glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClearColor(1, 1, 0.1, 0);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        DrawSky();
        glLoadIdentity();

        //MoveCamera();
       // DrawCircle();
       // glLoadIdentity();

        DrawGrass();
        glLoadIdentity();


        DrawRoad();
        DrawRoadLines();
        DrawRoadDK();
        for (int i = 0; i < 10; i = i++)
        {
            glScalef(0.5, 0.5, 1);
            DrawRoadLines();
        }
        glLoadIdentity();
        glRotatef(180,0,-0.5,0);
        DrawRoadDK();

        glLoadIdentity();
        DrawHouse();

        glLoadIdentity();
        for (int i = 0; i < 3; i = i++)
        {
            glScalef(2.5, 2.5, 1);
            DrawHouse();
        }

        glLoadIdentity();
        glRotatef(180, 0, -0.5, 0);
        DrawHouse();
        for (int i = 0; i < 3; i = i++)
        {
            glScalef(2.7, 2.7, 1);
            DrawHouse();
        }
        glLoadIdentity();


        //glPushMatrix();
        //float lightpos[] = {0,0,1,0};
        //glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
        //MoveCamera1();
        //DrawFloor();
        //glPopMatrix();
        //Swap front and back buffers ;

        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}