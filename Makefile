FLAGS = -pedantic-errors -std=c++11

main: main.cpp hangman.cpp
	g++ $(FLAGS) -o $@ $^

clean:
	rm -f main
