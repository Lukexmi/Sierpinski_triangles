OBJECTS = main.o
CC = g++
FLAGS = -std=c++98 -w -lSDL2 -lGL -lGLU
EXEC = test

all:
	$(CC) main.cpp initializer.cpp libs.h initializer.h renderer.cpp renderer.h $(FLAGS) -o $(EXEC)
