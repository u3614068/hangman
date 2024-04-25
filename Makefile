CXX = g++
CXXFLAGS = -std=c++11 -Wall -Werror

all: main

main: main.cpp hangman.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f main
