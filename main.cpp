#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <ctime>
#include "hangman.h"
using namespace std;

// display game status
void DisplayStats(int played, int hanged, int guessed, int won) {
  cout << "\n----------------------------------------\n";
  cout << "|               Game Status             |\n";
  cout << "----------------------------------------\n";
  cout << "| Games Played:   " << played << "\t\t\t|\n";
  cout << "| Times Hanged:   " << hanged << "\t\t\t|\n";
  cout << "| Times Guessed:  " << guessed << "\t\t\t|\n";
  cout << "| Games Won:      " << won << "\t\t\t|\n";
  cout << "----------------------------------------\n";
}

// display menu
int DisplayMenu() {
  int choice;
  do {
    cout << "\n+-------------------------+\n";
    cout << "|           Menu          |\n";
    cout << "+-------------------------+\n";
    cout << "| 1. Start New Game       |\n";
    cout << "| 2. Exit                 |\n";
    cout << "+-------------------------+\n";
    cout << "Enter your choice (1 or 2):  ";
    cin >> choice;

    // handle no inputs
    if (cin.fail()) {
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // check if input is valid
    if (choice != 1 && choice != 2) {
      cout << "\n\nInvalid input. Please enter 1 or 2.\n";
    }
  } while (choice != 1 && choice != 2);
  return choice;
}

int main() {
  // Seed for generating random number
  srand(static_cast<unsigned int>(time(nullptr)));

  int played, hanged, guessed, won;
  // load previous record
  HangmanGame::LoadStats(played, hanged, guessed, won);

  // display welcome page and status
  cout << "\n----------------------------------------\n";
  cout << "|         Welcome to HANGMAN ~          |\n";
  cout << "----------------------------------------\n";
  DisplayStats(played, hanged, guessed, won);

  int choice;
  do {
    // display menu
    choice = DisplayMenu();

    if (choice == 1) {
      cout << "\n\n___________________________Let's go!_____________________________" << endl;
      // starting a new game by randomly picking a dictionary file
      int dict_index = rand() % HangmanGame::dict_num + 1;
      string file_name = "dictionaries/dictionary_" + to_string(dict_index) + ".txt";
      // creat game object
      HangmanGame hangman(file_name);
      // play the game
      hangman.Play(played, hanged, guessed, won);
    }
  // loop until 2 is chosen
  } while (choice != 2);

  // Save game
  HangmanGame::SaveStats(played, hanged, guessed, won);

  // Farewell the player and display game status
  cout << "\n\n----------------------------------------\n";
  cout << "|              See you soon~            |\n";
  cout << "----------------------------------------\n";
  DisplayStats(played, hanged, guessed, won);

  return 0;
}
