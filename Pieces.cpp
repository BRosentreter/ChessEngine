#include "Pieces.h"
#include <cmath>

Knight::Knight(){}

bool Knight::validMove(coordinate destination){
	int vertical_move = std::fabs(destination.rank - current_location.rank);
	int horizontal_move = std::fabs(destination.file - current_location.file);
	if(vertical_move == 2 && horizontal_move == 1){
		return true;
	}
	if(vertical_move == 1 && horizontal_move == 2){
		return true;
	}
	return false;
}
std::vector< coordinate > Knight::coveredSquares(){
	std::vector< coordinate > output;
	return output;
}



Rook::Rook(){}

bool Rook::validMove(coordinate destination){
	int vertical_move = std::fabs(destination.rank - current_location.rank);
	int horizontal_move = std::fabs(destination.file - current_location.file);
	if(vertical_move > 0 && horizontal_move == 0){
		return true;
	}
	if(vertical_move == 0 && horizontal_move > 0){
		return true;
	}
	return false;

}
std::vector< coordinate > Rook::coveredSquares(){
	std::vector< coordinate > output;
	return output;
}

Bishop::Bishop(){}

bool Bishop::validMove(coordinate destination){
	int vertical_move = std::fabs(destination.rank - current_location.rank);
	int horizontal_move = std::fabs(destination.file - current_location.file);
	if(vertical_move > 0){
		if(vertical_move == horizontal_move){
			return true;
		}
	}
	return false;
}
std::vector< coordinate > Bishop::coveredSquares(){
	std::vector< coordinate > output;
	return output;
}

King::King(){
	has_moved = false;
}

bool King::validMove(coordinate destination){
	int vertical_move = std::fabs(destination.rank - current_location.rank);
	int horizontal_move = std::fabs(destination.file - current_location.file);

	if(vertical_move == 1 || vertical_move == 0){
		if(horizontal_move == 1 || vertical_move == 0){
			return true;
		}
	}
	if(!has_moved){
		if(horizontal_move == 2 && vertical_move == 0){
			return true;
		}
	}
	return false;
}
std::vector< coordinate > King::coveredSquares(){
	std::vector< coordinate > output;
	return output;
}

Queen::Queen(){}

bool Queen::validMove(coordinate destination){
	int vertical_move = std::fabs(destination.rank - current_location.rank);
	int horizontal_move = std::fabs(destination.file - current_location.file);
	

}
std::vector< coordinate > Queen::coveredSquares(){
	std::vector< coordinate > output;
	return output;
}

Piece::Piece(){}
bool Piece::validMove(coordinate destination){
	return false;
}
std::vector< coordinate > Piece::coveredSquares(){
	std::vector< coordinate > output;
	return output;
}

