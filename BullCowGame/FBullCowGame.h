#pragma once
#include <string>

using FString = std::string;
using int32 = int;

// All values set to zero
struct FBullCowCount {
	int32 bulls = 0;
	int32 cows = 0;
};

class FBullCowGame {
public:
	FBullCowGame();

	int getMaxTries() const;
	int getCurrentTry() const;
	void reset(); // TODO make a better return value
	bool isGameWon() const;
	bool checkGuessValidity(FString); // TODO make a better return value
	FBullCowCount submitGuess(FString);

private:
	// See constructor for initial values
	int32 myCurrentTry;
	int32 myMaxTries;
	FString myHiddenWord;
};