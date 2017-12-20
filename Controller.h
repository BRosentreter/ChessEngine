#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Board.h"
#include "Pieces.h"
#include <string>

class Controller{
	Board black_board;
	Board white_board;
	Board full_board;
public:
	bool isMoveLegal(std::string);
	std::pair<int, int> destinationCoordinates(std::string);
	std::string validInput(std::string);
};

#endif