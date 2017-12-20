CC=g++
CFLAGS = -Wall -std=c++11

pieces.o: Pieces.h Pieces.cpp
	gcc Pieces.cpp -Wall -std=c++11 -c -o pieces.o

board.o: Board.h Board.cpp
	gcc Board.cpp -Wall -std=c++11 -c -o board.o

controller.o: Controller.h Controller.cpp board.o
	gcc Controller.cpp -Wall -std=c++11 -c -o controller.o

all: ChessSimulator.cpp board.o controller.o pieces.o
	g++ ChessSimulator.cpp -Wall -std=c++11 -o exe controller.o board.o pieces.o

clean:
	rm -f exe controller.o board.o pieces.o