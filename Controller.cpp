#include "Controller.h"
#include <set>
#include <stdlib.h>

bool Controller::isMoveLegal(std::string move){
	
}

std::pair<int, int> Controller::destinationCoordinates(std::string move){

}


std::string Controller::validInput(std::string move){
	std::set<char> pieceSymbols = {'N','K','Q','B','R'};
	std::set<char> files = {'a','b','c','d','e','f','g','h'};
	switch(move.size()){
		case 2:
			//pawn normal move
			if(files.find(move[0]) != files.end()){
				if(atoi(&move[1]) > 0 && atoi(&move[1]) < 9){
					return "normal pawn move";
				}
			}
			break;
		case 3:
			//piece normal move
			if(pieceSymbols.find(move[0]) != pieceSymbols.end()){
				if(files.find(move[1]) != files.end()){
					if(atoi(&move[2]) > 0 && atoi(&move[2]) < 9){
						return "normal piece move";
					}
				}
			}
			//King Castle
			else if(move == "O-O"){
				return "king castle";
			}
			else{
				return "false";
			}
		case 4:
			//piece capture
			if((pieceSymbols.find(move[0]) != pieceSymbols.end()) || files.find(move[0]) != files.end()){
				if(move[1] == 'x'){
					if(files.find(move[2]) != files.end()){
						if(atoi(&move[3]) > 0 && atoi(&move[3]) < 9){
							return "piece capture";
						}
					}
				}
			}
			break;
		case 5:
			if(move == "O-O-O"){
				return "queen castle";
			}
			break;
		default:
			return "false";
			break;

	};
	return "false";
}













