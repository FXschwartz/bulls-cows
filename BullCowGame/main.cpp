#include <iostream>
#include <string>

using namespace std;

void playGame();
void printIntro();
string getGuess();
bool askToPlayAgain();

int main() {
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
	cout << "Welcome to Bulls and Cows\n";
	cout << "Can you guess the " << word_length << " letter isogram I'm thinking of?\n\n";
	return;
}

void playGame() {
	constexpr int number_of_turns = 5;
	for (int i = 1; i <= number_of_turns; i++) {
		string guess = getGuess();
		cout << "You guessed " << guess << endl;
	}
	return;
}

string getGuess() {
	string Guess = "";
	cout << "Enter your guess: ";
	getline(cin, Guess);
	return Guess;
}

bool askToPlayAgain() {
	cout << "Do you want to play again (y/n)?";
	string response = "";
	getline(cin, response);
	return (response[0] == 'y' || response[0] == 'Y');
}