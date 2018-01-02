//
//  GLViewController.cpp
//  Chess
//
//  Created by Brandt J.B. Rosentreter on 12/31/17.
//  Copyright © 2017 Brandt Rosentreter. All rights reserved.
//

#include "GLViewController.h"

int GLViewController::WindowHeight = 1200;
int GLViewController::WindowWidth = 1200;
std::string GLViewController::move_string = "";
bool GLViewController::white_or_black = false;
Controller GLViewController::engine;

void GLViewController::moveInput(unsigned char key, int xmouse, int ymouse)
{
    switch (key){
        case 'w':
            glClearColor (1.0, 1.0, 1.0, 1.0);
            break;
            
        case 'r':
            glClearColor (0.5, 0.5, 0.5, 0.5);
            break;
            
        case 13:
            std::cout << "enter" << std::endl;
            std::cout << engine.validInput(move_string) << std::endl;
            move_string = "";
            break;
        case 127:
            move_string.pop_back();
            break;
        default:
            if(move_string.size()){
                move_string+=key;
            }
            else{
                move_string = key;
            }
            break;
    }
    std::cout << move_string << std::endl;
    
    if(move_string.size() > 6){
        chessboard();
        glutPostRedisplay(); }//request display() call ASAP
}

void GLViewController::chessboard()
{
    glClear(GL_COLOR_BUFFER_BIT); // Clear display window
    GLint x, y;
    char string[64];
    sprintf(string, move_string.c_str());
    printtext(50,50,string);
    for (x = 200; x <= 1200; x += 125)
    {
        for (y = 200; y <= 1200; y += 125)
        {
            drawSquare(x, y + 125, x + 125, y + 125, x + 125, y, x, y);
        }
    }
    // Process all OpenGL routine s as quickly as possible
    glFlush();
}

void GLViewController::printtext(int x, int y, std::string s)
{
    //(x,y) is from the bottom left of the window
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glLoadIdentity();
    glOrtho(0, WindowWidth, 0, WindowHeight, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glPushAttrib(GL_DEPTH_TEST);
    glDisable(GL_DEPTH_TEST);
    glRasterPos2i(x,y);
    for (int i=0; i<s.size(); i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_9_BY_15, s[i]);
    }
    glPopAttrib();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
}

void GLViewController::drawSquare(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4)
{
    // if color is 0 then draw white box and change value of color = 1
    glBegin(GL_POLYGON);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x4, y4);
    glEnd();
    if (white_or_black == 0)
    {
        glColor3f(1, 1, 1); // white color value is 1 1 1
        white_or_black = 1;
    }
    // if color is 1 then draw black box and change value of color = 0
    else
    {
        glColor3f(0, 0, 0); // black color value is 0 0 0
        white_or_black = 0;
    }
    
    char string[64];
    sprintf(string, move_string.c_str());
    printtext(x1+50,y4+50,string);
    // Draw Square
    
}

void GLViewController::init()
{
    // For displaying the window color
    glClearColor(0, 1, 1, 0);
    // Choosing the type of projection
    glMatrixMode(GL_PROJECTION);
    // for setting the transformation which here is 2D
    gluOrtho2D(0, 1000, 0,1000);
}

void GLViewController::viewMain(int argc, char ** argv){
    glutInit(&argc, argv);
    // Set display mode
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    // Set top - left display window position.
    glutInitWindowPosition(100, 100);
    // Set display window width and height
    glutInitWindowSize(1000, 1000);
    // Create display window with the given title
    glutCreateWindow("Chess Board using OpenGL in C++");
    // Execute initialization procedure
    init();
    // Send graphics to display window
    glutDisplayFunc(this->chessboard);
    glutKeyboardFunc(this->moveInput);
    
    // Display everything and wait.
    glutMainLoop();
}

GLViewController::GLViewController(){
    
}
