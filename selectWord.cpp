#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "hangPerson.h"

using namespace std;

//selecting word from text file randomly
void selectWord(string& currWord, vector<char>& indivWord, vector<char>& dispSlots) {
	int SIZE = 30;
	string line;
	//creating a place for the words from text file to exist
	vector<string> words;
	
	//opening words file 
	ifstream inFile;
	inFile.open("words_1.txt");

	//putting text file into vector
	while (!inFile.eof()) {
		getline(inFile, line);
		words.push_back(line);
	}

	//randomly picking #
	srand(time(NULL));
	int randomNum = rand() % words.size();

	//# corresponds to a word in vector for rand #
	currWord = words.at(randomNum);

	//taking current word and creating a vector of characters (stars) to fill the space to hide the word
	for (int i = 0; i < currWord.length(); i++) {
		indivWord.push_back(currWord[i]);
		dispSlots.push_back('*');
	}

}
