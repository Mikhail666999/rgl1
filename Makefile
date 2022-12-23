FILE=scr/Main.cpp
LIB=-lncurses

all: compile launch

compile:
	g++ $(FILE) $(LIB) -o game

launch:
	@./game