// MADE WITH LOVE HOSSEIN 6 / 19 / 2026 :) ENJOY!!!
// Include libaries and namespace
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
// Functions
void showWelcome() {
	cout << "================================\nWELCOME TO NUMBER GUESSING GAME\n================================\n\nI'm thinking of a number between 1 and 100 you should guess it.\n\n";
}

int chooseDifficulty(int &attempts) {
	int selection;
	cout << "Choose Difficulty:\n\n1. Easy (10 attempts)\n2. Medium (5 attempts)\n3. Hard (3 attempts)\n\nWhats your choice?(1 , 2 , 3):";
again:
	cin >> selection;
	switch (selection) {
	case 1:
		cout << "you choosed the Easy difficulty!\n";
		attempts = 10;
		break;
	case 2:
		cout << "you choosed the Medium difficulty!!\n";
		attempts = 5;
		break;
	case 3:
		cout << "you choosed the Hard difficulty!!!\n";
		attempts = 3;
		break;
	default:
		cout << "Are you kidding me? choose between (1 , 2 , 3)\n";
		goto again;
	}
	return attempts;
}

int playGame(int a, int r) {
	int guess , at = 1;
	cout << "LETS START!\nso what is your first guess?: ";
	for (register int i = a; ;) {
		cin >> guess;
		gameover:
				if (guess == r) {
					cout << "Congratulations! You guessed the correct number in " << at << " attempts.\n\n";
					return a;
		}
		 else if (a == 0) {
			cout << "GAME OVER!!! I WON :)\n\n";
			return a;
		}
		 else	if (guess > r) {
			--a;
			++at;
			cout << "Incorrect!The number is less than " << guess << ".\n\n";
			if (a == 0) {
				goto gameover;
			}
			cout << "your remaining attempts is " << a << " Enter your No." << at << " guess: ";
		}
		else if (guess < r) {
			--a;
			++at;
			cout << "Incorrect!The number is greater than " << guess << ".\n\n";
			if (a == 0) {
				goto gameover;
			}
			cout << "your remaining attempts is " << a << " Enter your No." << at << " guess: ";
		}
	}
}

// Main code
int main() {
	again:
	srand(time (0));
	int random = (rand() % 100) + 1;
	int attempts;
	char countinue;
	showWelcome();
	chooseDifficulty(attempts);
	playGame(attempts, random);
	cout << "You want to play again?(y or n)\n";
	cin >> countinue;
	if (countinue == 'y' ||countinue == 'Y') {
		cout << "Okay :) lets play again here let me restart the program!!!\n\n";
		goto again;
	}
	if (countinue == 'n' || countinue == 'N') {
		cout << "ok bye :(";
		return 0;
	}
}