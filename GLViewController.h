//
//  GLViewController.hpp
//  Chess
//
//  Created by Brandt J.B. Rosentreter on 12/31/17.
//  Copyright © 2017 Brandt Rosentreter. All rights reserved.
//

#ifndef GLViewController_h
#define GLViewController_h

#include <iostream>
#include "opengl/gl.h"
#include "GLUT/glut.h"
#include <string>
#include "Controller.h"

class GLViewController{
    static int WindowHeight;
    static int WindowWidth;
    static std::string move_string;
    static bool white_or_black;
    static Controller engine;
public:
    GLViewController();
    void init();
    static void drawSquare(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4);
    static void printtext(int x, int y, std::string s);
    static void chessboard();
    static void moveInput (unsigned char key, int xmouse, int ymouse);
    void viewMain(int argc, char ** argv);
};

#endif /* GLViewController_hpp */
