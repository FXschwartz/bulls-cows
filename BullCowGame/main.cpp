/*
This is the console executable, that makes use of the BullCow class
This acts as the view in a MVC pattern, and is responsible for all user 
interaction. For game logic see the FBullCowGame class.
*/

#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void playGame();
void printIntro();
FText getGuess();
bool askToPlayAgain();

FBullCowGame BCGame;	// instantiate a new game

int main() {
	std::cout << BCGame.getCurrentTry();
	bool bPlayAgain = false;
	do {
		printIntro();
		playGame();
		bPlayAgain = askToPlayAgain();
	} while (bPlayAgain == 1);
	return 0;
}

void printIntro() {
	constexpr int word_length = 9;
	std::cout << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << word_length << " letter isogram I'm thinking of?\n\n";
	return;
}

void playGame() {
	BCGame.reset();
	int maxTries = BCGame.getMaxTries();
	for (int i = 1; i <= maxTries; i++) {
		FText guess = getGuess(); // TODO check for valid guess

		// Submit valid guess to the game
		FBullCowCount bullCowCount = BCGame.submitGuess(guess);
		// Print number of bulls and cows
		std::cout << "Bulls = " << bullCowCount.bulls << " Cows = " << bullCowCount.cows << std::endl;
		std::cout << "You guessed " << guess << std::endl;
	}
	// TODO add a game summary at end
}

FText getGuess() {
	int currentTry = BCGame.getCurrentTry();
	FText Guess = "";
	std::cout << "Try " << currentTry << " Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool askToPlayAgain() {
	std::cout << "Do you want to play again (y/n)?";
	FText response = "";
	std::getline(std::cin, response);
	return (response[0] == 'y' || response[0] == 'Y');
}