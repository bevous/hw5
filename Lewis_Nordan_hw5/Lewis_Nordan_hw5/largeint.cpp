#include "stdafx.h"
#include "largeint.h"


largeint::largeint()
{
	myInt = "";
	mydigits;
	setdigits();
}
largeint::~largeint()
{
}

//setter
void largeint::setInt(string input) {
	for (int x = 0; x < input.length(); x++) {
		switch (input[x]) {
		case('0'): {
			//nothing
		}
		case('1'): {
			//nothing
			}
		case('2'): {
			//nothing
			}
		case('3'): {			
			//nothing
			}
		case('4'): {
			//nothing
			}
		case('5'): {
			//nothing
			}
		case('6'): {
			//nothing
			}
		case('7'): {
			//nothing
			}
		case('8'): {
			//nothing
			}
		case('9'): {
			//nothing
			}
		default: {
			input.erase(x, 1);
		}
		}
	}

	myInt = input;
}
void largeint::setdigits() {
	for (int x = myInt.length()-1; x !=0 ; x--) {
		mydigits.push_back(myInt[x]);
	}
}

//getters
string largeint::getValue() {
	return myInt;
}
vector<int> largeint::getdigits() {
	return mydigits;
}

//arithmatic
largeint& largeint::operator+(largeint& rh) {
	largeint result;
	int carryover = 0;
	int resulTemp = 0;
	string newint = "";



	result.setInt(newint);
}
