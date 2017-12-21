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

}