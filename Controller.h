#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Board.h"
#include "Pieces.h"
#include <string>

class Controller{
	Board black_board;
	Board white_board;
	Board full_board;
	bool current_color_turn_white;
public:
	bool isMoveLegal(std::string);
	coordinate destinationCoordinates(std::string);
	std::string validInput(std::string);
	void updateBoard(std::string);
};

#endif