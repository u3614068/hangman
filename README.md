# hangman
COMP2113 Course Project

Group members:
UID: 3036140686    Cheung Ka Yam, CHEUNG Chun Yin (3036260709)




Description:

The Hangman game is a word-guessing game where the player needs to guess a secret word by suggesting letters within a certain number of attempts. The game features random word selection from a dictionary, ASCII art for the hangman figure, game statistics tracking, and more.


Game rules:

The game selects a secret word at random from a provided dictionary file.
The player needs to guess the word by suggesting letters.
The player has a limited number of attempts to guess the word.
If the player guesses a correct letter, it is revealed in the word.
If the player guesses an incorrect letter, the hangman figure is gradually drawn.
The game ends when the player either guesses the word correctly or the hangman figure is complete.



Features:

1. Display game status
2. Display game menu
3. Pick a dictionary of words: a dictionary out of 30 dictionaries is randomly chosen
4. Save game status: a file is saved to store the game status
5. Display guessed letters:STL(vector) is used to store guessed letters 
6. Display farewell message
7. Random Word Selection: The game selects a secret word at random from a provided dictionary file, which ensures a different gameplay experience each time.
8. ASCII Art: The game uses ASCII art to visually represent the hangman figure
9. Game Statistics: The game will keep track of statistics such as the number of games played, times the player was hanged, times the player guessed the word, and times the player won.




Non-standard libraries:
None

Compilation and execution instructions:

1. Ensure that you have a C++ compiler installed on your system.
2. Open a terminal or command prompt.
3. Navigate to the directory where the source code files are located.
4. Run the following command to compile the game:
   g++ -std=c++11 -Wall -Werror -o hangman main.cpp hangman.cpp
   This command will compile the game and generate an executable file named "hangman".
5. Run the following command to execute the game:
   ./hangman
   This command will start the Hangman game.
6. Follow the on-screen instructions to play the game.

Game demostration:

