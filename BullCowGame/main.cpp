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
void printGameSummary();
FText getValidGuess();
bool askToPlayAgain();

FBullCowGame BCGame;	// instantiate a new game

int main() {
	//std::cout << BCGame.getCurrentTry();
	bool bPlayAgain = false;
	do {
		printIntro();
		playGame();
		bPlayAgain = askToPlayAgain();
	} while (bPlayAgain == 1);
	return 0;
}

void printIntro() {
	std::cout << std::endl << "Welcome to Bulls and Cows\n";
	std::cout << "Can you guess the " << BCGame.getHiddenWordLength() << " letter isogram I'm thinking of?\n\n";
	return;
}

void playGame() {
	BCGame.reset();
	int32 maxTries = BCGame.getMaxTries();
	while(!BCGame.isGameWon() && BCGame.getCurrentTry() <= maxTries) {
		FText guess = getValidGuess();

		// Submit valid guess to the game
		FBullCowCount bullCowCount = BCGame.submitValidGuess(guess);

		// Print number of bulls and cows
		std::cout << "Bulls = " << bullCowCount.bulls << " Cows = " << bullCowCount.cows << std::endl;
	} 
	printGameSummary();
}

FText getValidGuess() {
	EGuessStatus status = EGuessStatus::invalidStatus;
	FText guess = "";
	do {
		int32 currentTry = BCGame.getCurrentTry();
		
		std::cout << "Try " << currentTry << " Enter your guess: ";
		std::getline(std::cin, guess);

		status = BCGame.checkGuessValidity(guess);
		switch(status) {
		case EGuessStatus::wrongLength:
			std::cout << "Please enter a " << BCGame.getHiddenWordLength() << " word." << std::endl;
			break;
		case EGuessStatus::notIsogram:
			std::cout << "Please enter an Isogram. (A word without repeating letters)" << std::endl;
			break;
		case EGuessStatus::notLowerCase:
			std::cout << "Please enter all lowercase letters" << std::endl;
			break;
		default:
			return guess;
		};
		std::cout << std::endl;
	} while(status != EGuessStatus::ok);
	return guess;
}

void printGameSummary() {
	if(BCGame.isGameWon()) std::cout << "Congrats! You Won!" << std::endl;
	else std::cout << "Awkward, Suck Less Next Time!" << std::endl;
	return;
}

bool askToPlayAgain() {
	std::cout << "Do you want to play again with the same hidden word (y/n)?";
	FText response = "";
	std::getline(std::cin, response);
	return (response[0] == 'y' || response[0] == 'Y');
}