#include "hangman.h" // Include the header file for the HangmanGame class
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm> // Include <algorithm> header for find
using namespace std;

// hangmanFigures vector with ASCII art representations of hangman figures
const vector<string> hangman_figures = {
    "  _____\n |     |\n |\n |\n |\n |\n_|___",
    "  _____\n |     |\n |     O\n |\n |\n |\n_|___",
    "  _____\n |     |\n |     O\n |     |\n |\n |\n_|___",
    "  _____\n |     |\n |     O\n |    /|\n |\n |\n_|___",
    "  _____\n |     |\n |     O\n |    /|\\\n |\n |\n_|___",
    "  _____\n |     |\n |     O\n |    /|\\\n |    /\n |\n_|___",
    "  _____\n |     |\n |     O\n |    /|\\\n |    / \\\n |\n_|___"
};

// Static member variable initialization
int HangmanGame::played = 0;
int HangmanGame::hanged = 0;
int HangmanGame::guessed = 0;
int HangmanGame::won = 0;

// Constructor definition for HangmanGame class
HangmanGame::HangmanGame(const string& dictionary_filename) {
    secret_word = SelectRandomWord(dictionary_filename); // Select a random word from the dictionary
    guessed_word = string(secret_word.length(), '*'); // Initialize guessed word with asterisks
    num_wrong_guesses = 0; // Initialize number of wrong guesses to 0
}

// Method to select a random word from the dictionary
string HangmanGame::SelectRandomWord(const string& dictionary_filename) {
    // Read words from the dictionary file
    ifstream file(dictionary_filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open dictionary file: " << dictionary_filename << endl;
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

void HangmanGame::Play(int& played, int& hanged, int& guessed, int& won) {

    while (!IsGameOver()) {
        DisplayWord(); 
        DisplayHangman();
        cout << "Guessed letters: ";
        for (char letter : guessed_letters) {
            cout << letter << " ";
        }
        cout << endl;

        char guess;
        cout << "Enter your guess: ";
        cin >> guess;

        if (find(guessed_letters.begin(), guessed_letters.end(), guess) != guessed_letters.end()) {
            cout << "\n____You have already guessed this letter. Please try a new one.____" << endl;
            continue;
        }

        guessed_letters.push_back(guess); // Add the guessed letter to the vector of guessed letters

        bool correct_guess = false;
        for (size_t i = 0; i < secret_word.length(); ++i) {
            if (secret_word[i] == guess) {
                guessed_word[i] = guess; // Update the guessed word with the correct guess
                correct_guess = true;
            }
        }

        if (correct_guess) {
            cout << "\n____________________________Keep it up!____________________________" << endl;
        }
        
        if (!correct_guess) {
            cout << "\n__________________________A wrong guess!___________________________" << endl;
            ++num_wrong_guesses; // Increment the number of wrong guesses
        }

        if (IsWordGuessed()) {
            cout << "\n\nCongratulations! You guessed the word: " << secret_word << endl;
            played++;
            guessed += guessed_letters.size();
            won++;
            return;
        }
    }

    cout << "\n\nSorry, you ran out of guesses. The word was: " << secret_word << endl;
    DisplayHangman();
    played++;
    hanged++;
    guessed += guessed_letters.size();
}

// Method: Displaying the current guessed word state
void HangmanGame::DisplayWord(){
    cout<<"\n\nCurrent word: " << guessed_word << endl;
}

// Method: Check if the word has been guessed correctly
bool HangmanGame::IsWordGuessed(){
    return secret_word == guessed_word;
}

// Method: Display the hangman figure according to the number of incorrect guesses
void HangmanGame::DisplayHangman() {
    cout << "Hangman figure: " << endl;
    cout << hangman_figures[num_wrong_guesses] << endl;
}

// Method: Check if the game is over
bool HangmanGame::IsGameOver(){
    return num_wrong_guesses >= max_wrong_guesses || IsWordGuessed();
}

// Method: Save game statistics to file
void HangmanGame::SaveStats(int played, int hanged, int guessed, int won){
    ofstream file("stats.txt");
    if (file.is_open()){
        file<< played << " " << hanged << " " << guessed << " " << won;
        file.close();
    }
}

//Method: Load game statistics from file
void HangmanGame::LoadStats(int& played, int& hanged, int& guessed, int& won){
    ifstream file("stats.txt");
    if (file.is_open()){
        file >> played >> hanged >> guessed >> won;
        file.close();
    } else {
        played = 0;
        hanged = 0;
        guessed = 0;
        won = 0;
    }
}











