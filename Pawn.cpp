#include "Pawn.h"

std::vector< coordinate > Pawn::coveredSquares(){
	std::vector< coordinate > output;
	coordinate left;
	coordinate right;
	int flip_board_coordinates = 1;
	if(!this->colorWhite){
		flip_board_coordinates *= -1;
	}
	left = {current_location.rank + flip_board_coordinates, current_location.file - 1};
	right = {current_location.rank + flip_board_coordinates, current_location.file + 1};

	output.push_back(left);
	output.push_back(right);
	return output;
}

Pawn::Pawn(){
	has_moved = false;
}

bool Pawn::validMove(coordinate destination){
	int vertical_move = std::fabs(destination.rank - current_location.rank);
	int horizontal_move = std::fabs(destination.file - current_location.file);
	if(vertical_move == 1 && horizontal_move <= 1){
		return true;
	}
	if(!has_moved){
		if(vertical_move == 2 && horizontal_move == 0){
			return true;
		}
	}
	return false;
}
