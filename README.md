# hangman
COMP2113 Course Project (Group 32)

Group members:
UID: `Cheung Ka Yam (3036140686)` , `CHEUNG Chun Yin (3036260709)` , `Hau Yuen Man (3036140727)` , `Tang Wai In (3036260723)` , `Wong Chun Ho (3036140739)`


`Description:`

The Hangman game is a word-guessing game where the player needs to guess a secret word by suggesting letters within a certain number of attempts. The game features random word selection from a dictionary, ASCII art for the hangman figure, game statistics tracking, and more.


`Game rules:`

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


`Features:`

1. Display game status: ASCII Art
2. Display game menu: ASCII Art
3. Pick a dictionary of words: a dictionary out of 30 dictionaries is randomly chosen
4. Random Word Selection: The SelectRandomWord function dynamically allocates memory to store the words read from the dictionary file. The words are stored in a vector<string> called words, which grows dynamically as new words are added.
5. Save game status: a file is saved to store the game status
6. Display guessed letters: STL(vector) is used to store guessed letters 
7. Display farewell message: ASCII Art
8. Game Statistics: The game keeps track of the statistics using such as the number of games played, how many times the stickman was hanged, how many guesses the player made and the number of game won using file input and output
9. Seperate compilation: Codes were stored in different files, namely hangman.cpp, hangman.h, main.cpp, dictionaries and Makefile.


`Non-standard libraries:`
None

`Compilation and execution instructions:`

1. Ensure that you have a C++ compiler installed on your system.
2. Open a terminal or command prompt.
3. Navigate to the directory where the source code files are located.
4. Run the following command to compile the game:
   1. make all
   2. ./main
5. Follow the on-screen instructions to play the game.


`Game demostration:`

Part 1: https://github.com/u3614068/hangman/assets/168083449/395c6901-767f-4cbc-8e74-ef06fc431c10

Part 2: https://github.com/u3614068/hangman/assets/168083449/77c9ffdf-d4b2-45bc-ad6e-fedff9bd82f7
