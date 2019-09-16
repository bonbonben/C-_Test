main:main.o mine.o gametime.o
	g++ -o main main.o mine.o gametime.o -lncurses
main.o : main.cpp gametime.h mine.h
	g++ -c main.cpp
mine.o:mine.cpp mine.h
	g++ -c mine.cpp
gametime.o:gametime.cpp gametime.h
	g++ -c gametime.cpp
