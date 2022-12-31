#include <cstdlib>
#include <string>
#include <ctime>
#include <vector>
#include <iostream>

using namespace std;

void display(int cnt, vector<char>& dispSlots) {
	//clear screen
	system("CLS");
	//header title
	cout << " [ H A N G M A N ]" << endl;
	//switch statment for gallows
	switch (cnt) {
	case 0:
		cout << "+"            << endl;
		cout << "|"            << endl;
		cout << "|"            << endl;
		cout << "|"            << endl;
		cout << "|"            << endl;
		cout << "|"            << endl;
		break;
	case 1:
		cout << "+--------+"   << endl;
		cout << "|"            << endl;
		cout << "|"            << endl;
		cout << "|"            << endl;
		cout << "|"            << endl;
		cout << "|"            << endl;
		break;
	case 2:
		cout << "+--------+"   << endl;
		cout << "|        |"   << endl;
		cout << "|"            << endl;
		cout << "|"            << endl;
		cout << "|"            << endl;
		cout << "|"            << endl;
		break;
	case 3:
		cout << "+--------+"   << endl;
		cout << "|        |"   << endl;
		cout << "|        O"   << endl;
		cout << "|"            << endl;
		cout << "|"            << endl;
		cout << "|"            << endl;
		break;
	case 4:
		cout << "+--------+"   << endl;
		cout << "|        |"   << endl;
		cout << "|        O"   << endl;
		cout << "|        |"   << endl;
		cout << "|        |"   << endl;
		cout << "|"            << endl;
		break;
	case 5:
		cout << "+--------+"   << endl;
		cout << "|        |"   << endl;
		cout << "|        O"   << endl;
		cout << "|       \\|"  << endl;
		cout << "|        |"   << endl;
		cout << "|" << endl;
		break;
	case 6:
		cout << "+--------+"   << endl;
		cout << "|        |"   << endl;
		cout << "|        O"   << endl;
		cout << "|       \\|/" << endl;
		cout << "|        |"   << endl;
		cout << "|" << endl;
		break;
	case 7:
		cout << "+--------+"   << endl;
		cout << "|        |"   << endl;
		cout << "|        O"   << endl;
		cout << "|       \\|/" << endl;
		cout << "|        |"   << endl;
		cout << "|       /"    << endl;
		break;
	case 8:
		cout << "+--------+"   << endl;
		cout << "|        |"   << endl;
		cout << "|        O"   << endl;
		cout << "|       \\|/" << endl;
		cout << "|        |"   << endl;
		cout << "|       / \\" << endl;
		break;
	default:
		break;
	}
	//consistent part of board
	cout << "|" << endl;
	cout << "+----------------" << endl;
	cout << endl;

	//cout spaces and underscores under the hidden word
	for (int i = 0; i < dispSlots.size(); i++) {
		cout << dispSlots.at(i) << " ";
	}
	cout << endl;
	for (int i = 0; i < dispSlots.size(); i++) {
		cout << "_ ";
	}
	cout << endl;
}
