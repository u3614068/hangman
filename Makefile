FLAGS = -pedantic-errors -std=c++11

all: main

main: main.cpp hangman.cpp
	g++ $(FLAGS) -o $@ $^

clean:
	rm -f main
