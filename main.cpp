#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "hangPerson.h"

using namespace std;

int main() {
	string currWord;
	vector<char> indivWord;
	vector<char> dispSlots;
	vector<char> displayResults;
	vector<char> resultsType;
	char guess;
	char answer;
	int wrong_cnt = 0;
	int counter = 0;
	const int MAXwrong = 8;
	bool replay = false;
	bool found = false;

	do {
		//clear screen
		system("CLS");

		//selecting word from vector (already made)
		selectWord(currWord, indivWord, dispSlots);

		//display empty board
		display(wrong_cnt, dispSlots);

		//game loop
		while(1) {
			//checking if user input matches current word (if not, cnt increaces for the man to be hanged)
			if (!gameInput(guess, indivWord, dispSlots, displayResults)) {
				wrong_cnt++; // Increment display
				resultsType.push_back('F'); //key for each guess (whether each guess is true or false)
			}
			else {
				resultsType.push_back('T'); // current guess is true
			}
			counter = 0;
			//loop for checking whether there is a letter or a star (checking for full guess correct)
			for (int i = 0; i < dispSlots.size(); i++) {
				if (dispSlots.at(i) != '*') {
					//incrementing counter if not a star
					counter++;
				}
			}
			//if the counter is equal to the size of the current word and all guesses correct (cnt did not reach 8) display winning screen
			if (counter == dispSlots.size()) {
				system("CLS");
				display(wrong_cnt, dispSlots);
				cout << "\n\nYOU WON!" << endl;
				cout << "The word is " << currWord << endl;
				found = true;
				recordResults(displayResults, currWord, resultsType, found);
				break;
			}
			//if counter is equal to 8 (max number wrong) display losing screen
			if (wrong_cnt == MAXwrong) {
				system("CLS");
				display(wrong_cnt, dispSlots);
				cout << "\n\nWRONG ANSWER!" << endl;
				cout << "The word is " << currWord << endl;
				found = false;
				recordResults(displayResults, currWord, resultsType, found);
				break;
			}
			//clear screen
			system("CLS"); 
			display(wrong_cnt, dispSlots);
		}
		//replay loop
		cout << "\n\nPlay again? [Y/N] \n";
		cin >> answer;
		answer = toupper(answer);

		if (answer != 'Y') {
			replay = false;
			wrong_cnt = 0;
		}
		else {
			replay = true;
			wrong_cnt = 0;
			counter = 0;
			dispSlots.clear();
			displayResults.clear();
			resultsType.clear();
			indivWord.clear();
		}
	} while (replay == true);

}
