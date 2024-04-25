#include "hangman.h" // Include the header file for the HangmanGame class
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Include <algorithm> header for find
using namespace std;

// hangmanFigures vector with ASCII art representations of hangman figures
const vector<string> hangmanFigures = {
    "  _____\n |     |\n |\n |\n |\n |\n_|___",
    "  _____\n |     |\n |     O\n |\n |\n |\n_|___",
    "  _____\n |     |\n |     O\n |     |\n |\n |\n_|___",
    "  _____\n |     |\n |     O\n |    /|\n |\n |\n_|___",
    "  _____\n |     |\n |     O\n |    /|\\\n |\n |\n_|___",
    "  _____\n |     |\n |     O\n |    /|\\\n |    /\n |\n_|___",
    "  _____\n |     |\n |     O\n |    /|\\\n |    / \\\n |\n_|___"
};

// Static member variable initialization
int HangmanGame::gamesPlayed = 0;
int HangmanGame::timesHanged = 0;
int HangmanGame::timesGuessed = 0;
int HangmanGame::timesWon = 0;

// Constructor definition for HangmanGame class
HangmanGame::HangmanGame(const string& dictionaryFilename) {
    secretWord = selectRandomWord(dictionaryFilename); // Select a random word from the dictionary
    guessedWord = string(secretWord.length(), '*'); // Initialize guessed word with asterisks
    numWrongGuesses = 0; // Initialize number of wrong guesses to 0
}

// Method to select a random word from the dictionary
string HangmanGame::selectRandomWord(const string &dictionaryFilename) {
    // Read words from the dictionary file
    ifstream file(dictionaryFilename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open dictionary file: " << dictionaryFilename << endl;
        exit(EXIT_FAILURE);
    }
    vector<string> words;
    string word;
    while (getline(file, word)) {
        words.push_back(word);
    }
    file.close();

    // Select a random word from the dictionary
    srand(static_cast<unsigned int>(time(nullptr)));
    int index = rand() % words.size();
    return words[index];
}
