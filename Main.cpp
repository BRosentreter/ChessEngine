


#include "Pieces.h"
#include "Board.h"
#include "Controller.h"
#include "opengl/gl.h"
#include "GLViewController.h"
#include "GLUT/glut.h"


using namespace std;


int main(int argc, char ** argv){

    GLViewController gl_view_controller;
    gl_view_controller.viewMain(argc, argv);

	return 0;
}
