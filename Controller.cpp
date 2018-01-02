#include "Controller.h"
#include <stdlib.h>


//Controller::Controller(){
//	current_color_turn_white = true;
//}

Controller::Controller(){
    pieceSymbols = {'N','K','Q','B','R'};
    files = {'a','b','c','d','e','f','g','h'};
}

bool Controller::isMoveLegal(std::string move){
    return false;

}

coordinate Controller::destinationCoordinates(std::string move){
	coordinate output;
	switch(move[move.size()-2]){
		case 'a':
			output = {atoi(&move[move.size()-1])-1, 0};
			break;
		case 'b':
			output = {atoi(&move[move.size()-1])-1, 1};
			break;
		case 'c':
			output = {atoi(&move[move.size()-1])-1, 2};
			break;
		case 'd':
			output = {atoi(&move[move.size()-1])-1, 3};
			break;
		case 'e':
			output = {atoi(&move[move.size()-1])-1, 4};
			break;
		case 'f':
			output = {atoi(&move[move.size()-1])-1, 5};
			break;
		case 'g':
			output = {atoi(&move[move.size()-1])-1, 6};
			break;
		case 'h':
			output = {atoi(&move[move.size()-1])-1, 7};
			break;
		default:
			output = {-1,-1};
			break;
	}
	std::cout << output.file <<  " " << output.rank << std::endl;
	return output;
}


std::string Controller::validInput(std::string move){

    switch(move.size()){
        case 3:
            if(move == "O-O"){
                std::cout <<"tete" << std::endl;
                return "King castle";
            }
            else{
                return "false";
            }
        case 4:
            if(files.find(move[0]) != files.end()){
                if(atoi(&move[1]) > 0 && atoi(&move[1]) < 9){

                    if(files.find(move[2]) != files.end()){

                        if(atoi(&move[3]) > 0 && atoi(&move[3]) < 9){

                            return "Normal pawn move";
                        }
                    }
                }
            }
        case 5:
            if(move == "O-O-O"){
                return "Queen castle";
            }
            if(pieceSymbols.find(move[0]) != pieceSymbols.end()){
                if(files.find(move[1]) != files.end()){
                    if(atoi(&move[2]) > 0 && atoi(&move[2]) < 9){
                        if(files.find(move[3]) != files.end()){
                            if(atoi(&move[4]) > 0 && atoi(&move[4]) < 9){
                                return "Normal piece move";
                            }
                        }
                    }
                }
            }
        default:
            return "false";
    };

}

void Controller::updateBoard(std::string move){
	if(current_color_turn_white){
		white_board.updateBoard(move);
	}	
	else{
		black_board.updateBoard(move);
	}
	return;
}











