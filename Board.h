#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <vector>
#include "Pieces.h"




class Board{
	int board_size;
	std::vector< std::vector< Piece > > board;
public:
	void updateBoard(std::string);
	Board();


};

#endif