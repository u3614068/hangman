#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

// Declaration of the HangmanGame class
class HangmanGame {
public:
    // Constants for the game
    static const int MAX_WRONG_GUESSES = 6;  // Maximum number of wrong guesses allowed
    static const int NUM_DICTIONARIES = 30; // Number of dictionaries available

    // Static variables to track overall game statistics
    static int gamesPlayed;   // Total number of games played
    static int timesHanged;   // Total number of times the player was hanged (lost)
    static int timesGuessed;  // Total number of guesses made
    static int timesWon;      // Total number of games won

    // Constructor to initialize the HangmanGame object with a dictionary
    HangmanGame(const std::string& dictionaryFilename);

    // Method to play the game
    void play(int& gamesPlayed, int& timesHanged, int& timesGuessed, int& timesWon);

    // Method to check if the game is over
    bool isGameOver();

    // Static methods to save and load game statistics
    static void saveStats(int gamesPlayed, int timesHanged, int timesGuessed, int timesWon);
    static void loadStats(int& gamesPlayed, int& timesHanged, int& timesGuessed, int& timesWon);

private:
    // Private methods for internal game logic
    std::string selectRandomWord(const std::string& dictionaryFilename); // Selects a random word from the dictionary
    void displayWord();     // Displays the current state of the guessed word
    bool isWordGuessed();   // Checks if the word has been completely guessed
    void displayHangman();  // Displays the hangman figure based on the number of wrong guesses

    // Private member variables
    std::string secretWord; // The word to be guessed
    std::string guessedWord; // The current state of the guessed word
    int numWrongGuesses;    // Number of wrong guesses made by the player
    std::vector<char> guessedLetters; // Vector to store guessed letters
};

#endif // HANGMAN_H
