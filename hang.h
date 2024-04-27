#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
#include <vector>

// Declaration of the HangmanGame class
class HangmanGame {
public:
    // Constants for the game
    static const int max_wrong_guesses = 6;  // Maximum number of wrong guesses allowed
    static const int num_dictionaries = 30; // Number of dictionaries available

    // Static variables to track overall game statistics
    static int played;   // Total number of games played
    static int hanged;   // Total number of times the player was hanged (lost)
    static int guessed;  // Total number of guesses made
    static int won;      // Total number of games won

    // Constructor to initialize the HangmanGame object with a dictionary
    HangmanGame(const std::string& dictionaryFilename);

    // Method to play the game
    void Play(int& played, int& hanged, int& guessed, int& won);

    // Method to check if the game is over
    bool IsGameOver();

    // Static methods to save and load game statistics
    static void SaveStats(int played, int hanged, int guessed, int won);
    static void LoadStats(int& played, int& hanged, int& guessed, int& won);

private:
    // Private methods for internal game logic
    std::string SelectRandomWord(const std::string& dictionary_filename); // Selects a random word from the dictionary
    void DisplayWord();     // Displays the current state of the guessed word
    bool IsWordGuessed();   // Checks if the word has been completely guessed
    void DisplayHangman();  // Displays the hangman figure based on the number of wrong guesses

    // Private member variables
    std::string secret_word; // The word to be guessed
    std::string guessed_word; // The current state of the guessed word
    int num_wrong_guesses;    // Number of wrong guesses made by the player
    std::vector<char> guessed_letters; // Vector to store guessed letters
};

#endif // HANGMAN_H
