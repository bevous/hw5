// Lewis_Nordan_hw5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include "largeint.h"
using namespace std;
bool YorN() {
	char undo;
	bool test = false;
	do {
		cin >> undo;
		cout << undo << endl;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "enter y/n" << endl;
		}
		switch (undo) {
		case ('y'): {
			test = true;
			break;
		}
		case ('Y'): {
			test = true;
			break;
		}
		case ('n'): {
			test = false;
			break;
		}
		case ('N'): {
			test = false;
			break;
		}
		default: {
			cout << "enter y/n" << endl;
			test = false;
			break;
		}
		}


	} while (cin.fail() && test == false);
	return test;
}
int main()
{
	largeint first;
	largeint second;
	largeint result;
	string temp = "999";
	string temp2 = "1";
	bool loop = true;
	while (loop) {
		cout << "enter your first number";
		cin >> temp;
		first.setInt(temp);
		cout << "enter your second number";
		cin >> temp;
		second.setInt(temp);

		cout << first.getValue() << endl;
		cout << second.getValue() << endl;

		result.setInt((first + second));
		cout << first.getValue() << " + " << second.getValue() << " = " << result.getValue() << '\n' << endl;
		loop = YorN();
	}
	system("pause");
    return 0;
}

