#include "FBullCowGame.h"

using int32 = int;

FBullCowGame::FBullCowGame() { reset(); }

int32 FBullCowGame::getMaxTries() const { return myMaxTries; }
int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }

void FBullCowGame::reset() {
	constexpr int32 max_tries = 8;
	myMaxTries = max_tries;
	const FString hidden_word = "planet";
	myHiddenWord = hidden_word;
	myCurrentTry = 1;
	return;
}

bool FBullCowGame::isGameWon() const {
	return false;
}

bool FBullCowGame::checkGuessValidity(FString) {
	return false;
}

// Recieves a valid guess, increments turn, and returns count;
FBullCowCount FBullCowGame::submitGuess(FString guess) {
	myCurrentTry++;
	FBullCowCount bullCowCount;
	int32 hiddenWordCount = myHiddenWord.length();
	int32 guessWordCount = guess.length();
	for(int32 i = 0; i < hiddenWordCount; i++) {
		for(int32 j = 0; j < guessWordCount; j++) {
			if(myHiddenWord[i] == guess[j]) {
				if(i == j) bullCowCount.bulls++;
				else bullCowCount.cows++;
			}
		}
	}
	return bullCowCount;
}
