all: main

main: main.cpp hangman.cpp
	g++ -pedantic-errors -std=c++11 -o $@ $^

clean:
	rm -f main
