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
	vector<int> tempaddition;
	string newint = "";
	
	
	for (int x = 0; x < mydigits.size() || x < rh.getdigits().size(); x++) {
		resulTemp = (mydigits[mydigits.size() - x] + rh.getdigits()[rh.getdigits().size() - x] + carryover);
		tempaddition.push_back(resulTemp % 10);
		carryover = resulTemp - tempaddition[tempaddition.size() - 1];
		if (x++ == mydigits.size() || x++ == rh.getdigits().size() && carryover != 0) {
			while (carryover != 0) {
				if (x++ == mydigits.size()) {
					resulTemp = rh.getdigits()[rh.getdigits().size() - x] + carryover;
					tempaddition.push_back(resulTemp % 10);
					carryover = resulTemp - tempaddition[tempaddition.size() - 1];

					if (carryover == 0 && x++ < mydigits.size()) {
						for (int y = x++; y < mydigits.size(); y++) {
							tempaddition.push_back(mydigits[mydigits.size() - y]);
						}
					}

				}
				else if (x++ == rh.getdigits().size()) {
					resulTemp = mydigits[mydigits.size() - x] + carryover;
					tempaddition.push_back(resulTemp % 10);
					carryover = resulTemp - tempaddition[tempaddition.size() - 1];

					if (carryover == 0 && x++ < mydigits.size()) {
						for (int y = x++; y < rh.getdigits().size(); y++) {
							tempaddition.push_back(rh.getdigits()[rh.getdigits().size() - y]);
						}
					}

				}
			}
		}
	}
	
	for (int x = 0; x < tempaddition.size(); x++) {
		newint += to_string(tempaddition[x]);
	}

	result.setInt(newint);
}
