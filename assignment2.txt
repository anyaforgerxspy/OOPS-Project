#include <iostream>
using  namespace std;
class GuessTheNumber {
private:
    int computerGeneratedNumber;
    int userGuessedNumber;

public:
    void generateRandomNumber() {
        computerGeneratedNumber = 67;
    }

    void startGame() {
        cout << "Welcome to Guess The Number Game!\n";
        cout << "Try to guess the number between 1 and 100.\n";

        do {
           cout << "Enter your guess: ";
          cin >> userGuessedNumber;

            if (userGuessedNumber < computerGeneratedNumber) {
               cout << "The number is too low . Guess again!\n";
            } else if (userGuessedNumber > computerGeneratedNumber) {
               cout << "The number is too high .Guess again!\n";
            } else {
               cout << "Congratulations! You guessed the number right!\n";
            }
        } while (userGuessedNumber != computerGeneratedNumber);
    }
};

int main() {
    GuessTheNumber game;

    game.generateRandomNumber();

     game.startGame();

    return 0;
}