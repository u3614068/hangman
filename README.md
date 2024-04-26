# hangman
COMP2113 Course Project

Group members:
UID: `Cheung Ka Yam (3036140686)` , `CHEUNG Chun Yin (3036260709)` , 




```diff
-[Description]
```

The Hangman game is a word-guessing game where the player needs to guess a secret word by suggesting letters within a certain number of attempts. The game features random word selection from a dictionary, ASCII art for the hangman figure, game statistics tracking, and more.


Game rules:

At the start of the game, the player is presented with a number of blank spaces representing the letters of a word.
The game selects a secret word at random from a provided dictionary file.
The player needs to guess the word by suggesting letters.
The player guesses one letter at a time.
The player has a limited number of attempts to guess the word.
If the player guesses a correct letter, it is revealed in the word.
If the player guesses an incorrect letter or the guessed letter is not in the word, the hangman figure is gradually drawn.
The game ends when the player either guesses the word correctly or the hangman figure is complete.


`How to play:`
1. The game starts and a word is randomly selected from the dictionary. For example, let's say the word is "hangman". The player sees a series of asterisks representing the letters of the word:

    ```
    Current word: ********
    ```

2. The player guesses a letter. For example, they guess 'a' (your input):

    ```
    Enter your guess: a
    ```

3. The guessed letter 'a' is in the word, so the word is redisplayed with 'a' in its correct positions:

    ```
    Current word: *a***a*
    ```

4. The player guesses another letter, for example 'e' (your input):

    ```
    Enter your guess: e
    ```

5. The guessed letter 'e' is not in the word (incorrect), so one element of the hangman is drawn:

    ```
    Hangman figure:
      _____
     |     |
     |
     |
     |
     |
    _|___
    ```

6. The game continues in this manner until the player completes the word or the hangman is fully drawn. If the player completes the word (guesses a correct letter successfully within the limited number of attempts):

    ```
    Congratulations! You guessed the word: hangman
    ```

    Or if the hangman is fully drawn (failed to guess a correct letter within the limited number of attempts):

    ```
    Sorry, you ran out of guesses. The word was: hangman
    Hangman figure:
      _____
     |     |
     |     O
     |    /|\
     |    / \
     |
    _|___
    ```

This is a basic example of how the game might progress. The actual game will include more features such as displaying game statistics and more functions will be demonstrated, allowing the player to play multiple games in one session.


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

