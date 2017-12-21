#ifndef PIECES_H
#define PIECES_H

#include <string>
#include <vector>

enum PieceType {pawn, rook, knight, bishop, queen, king, none};

struct coordinate {
	int rank;
	int file;
};

class Piece{
protected:
	int points;
	bool colorWhite;
	coordinate current_location;
public:
	virtual bool validMove(coordinate destination);
	virtual std::vector< coordinate > coveredSquares();
	Piece();


};


class Knight : public Piece{
public:
	bool validMove(coordinate destination);
	std::vector< coordinate > coveredSquares();
	Knight();
};

class Bishop : public Piece{
public:
	bool validMove(coordinate destination);
	std::vector< coordinate > coveredSquares();
	Bishop();
};

class Rook : public Piece{
public:
	bool validMove(coordinate destination);
	std::vector< coordinate > coveredSquares();
	Rook();

};

class Queen : public Piece{
public:
	bool validMove(coordinate destination);
	std::vector< coordinate > coveredSquares();
	Queen();

};

class King : public Piece{
public:
	bool validMove(coordinate destination);
	std::vector< coordinate > coveredSquares();
	King();

};

#endif