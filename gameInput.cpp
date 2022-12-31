#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "hangPerson.h"

using namespace std;

// getting input from user, verifying, passing to main
bool gameInput(char& guess, vector<char>& indivWord, vector<char>& dispSlots, vector<char>& displayResults) {
	int cnt = 0;
	string userinput;
	bool pain = false;


	while (pain != true) {
		//prompt
		cout << "\nLetter input: ";
		//taking user input
		cin >> userinput;
		guess = userinput[0];

		//verifying valid guess (also for repeat charecters)
		if (isalpha(guess) && guess == tolower(guess)) {
			pain = true;
		}
		else {
			cout << "Your guess was invalid. Please enter a lowercase letter." << endl;
			system("Pause");
			pain = false;
		}
		//for repeat characters
		for (int i = 0; i < displayResults.size(); i++) {
			if (guess == displayResults.at(i)) {
				cout << "You have already guessed this letter." << endl;
				system("Pause");
				pain = false;
				break;
			}
			else {
				pain = true;
			}
		}
	}
	//taking inputs and sending them to recording results function
	displayResults.push_back(guess);

	//check through the word for correct guess
	for (int i = 0; i < indivWord.size(); i++) { 
		//checks if the input word is equal to the word at i
		if (guess == indivWord.at(i)) { 
			//replaces the word on dispSlots (display vector)
			dispSlots.at(i) = guess; 
			cnt++;
		}
	}

	//to check if the word was found or not
	if (cnt > 0) {
		return true;
	}
	//word wasn't found
	return false;

}
