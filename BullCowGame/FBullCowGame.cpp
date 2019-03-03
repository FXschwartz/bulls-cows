#include "FBullCowGame.h"
#include <map>
#define TMap std::map

using int32 = int;

FBullCowGame::FBullCowGame() { reset(); }

int32 FBullCowGame::getMaxTries() const { return myMaxTries; }
int32 FBullCowGame::getCurrentTry() const { return myCurrentTry; }
int32 FBullCowGame::getHiddenWordLength() const { return myHiddenWord.length(); }
bool FBullCowGame::isGameWon() const { return bGameIsWon; }

void FBullCowGame::reset() {
	const FString hidden_word = "clear";
	constexpr int32 max_tries = 8;
	myMaxTries = max_tries;
	myHiddenWord = hidden_word;
	bGameIsWon = false;
	myCurrentTry = 1;

	return;
}

EGuessStatus FBullCowGame::checkGuessValidity(FString guess) const {
	if(!isIsogram(guess)) {
		return EGuessStatus::notIsogram;
	}
	else if(guess.length() != getHiddenWordLength()) {
		return EGuessStatus::wrongLength;
	}
	else if(false) {
		return EGuessStatus::notLowerCase;
	}
	else {
		return EGuessStatus::ok;
	}
	//return EGuessStatus::wrongLength;

}

// Recieves a VALID guess, increments turn, and returns count;
FBullCowCount FBullCowGame::submitValidGuess(FString guess) {
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
	if(bullCowCount.bulls == hiddenWordCount) bGameIsWon = true;
	else bGameIsWon = false;
	return bullCowCount;
}

bool FBullCowGame::isIsogram(FString guess) const {
	if(guess.length() <= 1) return true;
	TMap<char, bool> currentLetter;
	for(auto letter : guess) {
		letter = tolower(letter);
		if(currentLetter[letter]) return false;
		else {
			currentLetter[letter] = true;
		}
	}

	return true;
}
