OBJECTS = main.o
CC = g++
FLAGS = -std=c++98 -w -lSDL2 -lGL -lGLU
EXEC = test

all:
	$(CC) main.cpp initializer.cpp initializer.h renderer.cpp renderer.h args.h args.cpp $(FLAGS) -o $(EXEC)
