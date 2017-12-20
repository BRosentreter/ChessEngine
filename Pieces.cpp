#include "Pieces.h"

std::vector< std::pair<int, int> > Pawn::coveredSquares(){
	std::vector< std::pair<int, int> > output;
	std::pair<int, int> left, right;
	int flip_board_coordinates = 1;
	if(!this->colorWhite){
		flip_board_coordinates *= -1;
	}
	left = std::make_pair(this->coordinates.first + flip_board_coordinates, this->coordinates.second - 1);
	right = std::make_pair(this->coordinates.first + flip_board_coordinates, this->coordinates.second + 1);

	output.push_back(left);
	output.push_back(right);
	return output;
}