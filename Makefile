CC=g++
CFLAGS=-L/lib/SFML-2.5.1-Compiled/lib -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

flappy: compile move objects/Bird.o  objects/Collision.o  objects/Game.o  objects/GameState.o  objects/main.o  objects/Pipes.o 
	$(CC) objects/Bird.o  objects/Collision.o  objects/Game.o  objects/GameState.o  objects/main.o  objects/Pipes.o -o flappy $(CFLAGS)

compile:	
	$(CC) -c main.cpp classes/Bird.cpp classes/Collision.cpp classes/Game.cpp classes/GameState.cpp classes/Pipes.cpp -I/lib/SFML-2.5.1-Compiled/include

move: 
	mv Bird.o Collision.o Game.o GameState.o main.o Pipes.o objects/

.SILENT:
