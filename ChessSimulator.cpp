#include "Pieces.h"
#include "Board.h"
#include "Controller.h"

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
	cout << "Test" << endl;
	return 0;
}