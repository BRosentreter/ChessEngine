


#include "Pieces.h"
#include "Board.h"
#include "Controller.h"
#include "opengl/gl.h"
#include "GLUT/glut.h"


using namespace std;



int main(int argc, char ** argv){


    Board b;
	Controller c;
	string s;
	while(1){
		cout << "Please enter a move: ";
		cin >> s;
		cout << c.validInput(s) << endl;
		c.destinationCoordinates(s);

	}
	return 0;
}
