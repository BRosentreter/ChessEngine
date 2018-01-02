#ifndef PAWN_H
#define PAWN_H

#include "Pieces.h"

class Pawn : public Piece{
	bool has_moved;
public:
	bool validMove(coordinate destination);
	std::vector< coordinate > coveredSquares();
	Pawn();
};

#endif
