CC=g++
CFLAGS = -Wall -std=c++11

all: Main.cpp board.o controller.o pieces.o glviewcontroller.o
	g++ -framework OpenGL -framework GLUT -Wno-deprecated Main.cpp -Wall -std=c++11 -o exe controller.o board.o pieces.o glviewcontroller.o

pieces.o: Pieces.h Pieces.cpp
	gcc Pieces.cpp -Wall -std=c++11 -c -o pieces.o

board.o: Board.h Board.cpp
	gcc Board.cpp -Wall -std=c++11 -c -o board.o

controller.o: Controller.h Controller.cpp board.o
	gcc Controller.cpp -Wall -std=c++11 -c -o controller.o

glviewcontroller.o: GLViewController.cpp GLViewController.h controller.o
	gcc GLViewController.cpp -Wall -std=c++11 -c -o glviewcontroller.o

clean:
	rm -f exe controller.o board.o pieces.o glviewcontroller.o
