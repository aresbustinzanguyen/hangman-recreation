#pragma once
#include <vector>
using namespace std;

void selectWord(string& currWord, vector<char>& indivWord, vector<char>& dispSlots);
bool gameInput(char& guess, vector<char>& indivWord, vector<char>& dispSlots, vector<char>& recordResults);
void display(int cnt, vector<char>& dispSlots);
void recordResults(vector<char> displayResults, string& currWord, vector<char>& resultsType, bool counter);
