#ifndef PIECES_H
#define PIECES_H

#include <string>
#include <vector>

class Piece{
protected:
	int points;
	bool colorWhite;
	int max_horizontal_move;
	int max_vertical_move;
	std::pair<int, int> coordinates;
public:
	virtual bool validMove(std::pair<int, int> destination);
	virtual std::vector< std::pair<int, int> > coveredSquares();


};

class Pawn : Piece{
public:
	bool validMove(std::pair<int, int> destination);
	std::vector< std::pair<int, int> > coveredSquares();
};

class Knight : Piece{
public:
	bool validMove(std::pair<int, int> destination);
	std::vector< std::pair<int, int> > coveredSquares();
};

class Bishop : Piece{
public:
	bool validMove(std::pair<int, int> destination);
	std::vector< std::pair<int, int> > coveredSquares();
};

class Rook : Piece{
public:
	bool validMove(std::pair<int, int> destination);
	std::vector< std::pair<int, int> > coveredSquares();

};

class Queen : Piece{
public:
	bool validMove(std::pair<int, int> destination);
	std::vector< std::pair<int, int> > coveredSquares();

};

class King : Piece{
public:
	bool validMove(std::pair<int, int> destination);
	std::vector< std::pair<int, int> > coveredSquares();

};

#endif