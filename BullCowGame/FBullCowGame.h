#pragma once
#include <string>

// Make syntax Unreal friendly
using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 bulls = 0;
	int32 cows = 0;
};

enum class EGuessStatus {
	invalidStatus,
	ok,
	notIsogram,
	notLowerCase,
	wrongLength,
};

class FBullCowGame {
public:
	FBullCowGame();

	int32 getMaxTries() const;
	int32 getCurrentTry() const;
	int32 getHiddenWordLength() const;
	bool isGameWon() const;

	void reset();
	EGuessStatus checkGuessValidity(FString) const;
	FBullCowCount submitValidGuess(FString);

private:
	// See constructor for initial values
	int32 myCurrentTry;
	FString myHiddenWord;
	bool bGameIsWon;

	bool isIsogram(FString) const;
	bool isLowerCase(FString) const;
};