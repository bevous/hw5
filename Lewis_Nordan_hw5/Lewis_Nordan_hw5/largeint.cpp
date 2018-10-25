#include "stdafx.h"
#include "largeint.h"


largeint::largeint()
{
	myInt = "";
	mydigits;
}
largeint::~largeint()
{
}

//setter
void largeint::setInt(string input) {
	for (int x = 0; abs(x) < input.length(); x++) {
		if (input[x] == '0') {
			//nothing
			//cout << "found it" << endl;
		}
		else if (input[x] == '1') {
			//cout << "found it" << endl;
			//nothing
			}
		else if (input[x] == '2') {
			
			//cout << "found it" << endl;//nothing
			}
		else if (input[x] == '3') {			
			//nothing
			//cout << "found it" << endl;
			}
		else if (input[x] == '4') {
			//nothing
			//cout << "found it" << endl;
			}
		else if (input[x] == '5') {
			//nothing
			//cout << "found it" << endl;
			}
		else if (input[x] == '6') {
			//nothing
			//cout << "found it" << endl;
			}
		else if (input[x] == '7') {
			//nothing
			//cout << "found it" << endl;
			}
		else if (input[x] == '8') {
			//nothing
			//cout << "found it" << endl;
			}
		else if (input[x] == '9') {
			//nothing
			//cout << "found it" << endl;
			}
		else {
			//cout << "not here" << endl;
			input.erase(x, 1);
			if (x >= 0) {
				x -= 1;
			}
		}
		
	}

	myInt = input;
	setdigits();
}
void largeint::setdigits() {
	mydigits.empty();
	for (int x = 0; x < myInt.length(); x++) {
		mydigits.push_back(myInt[x]-48);
		//cout << "digits" << mydigits.back() << endl;
	}
	/*for (int x = 0; x < mydigits.size(); x++) {
		cout << mydigits[x] << endl;
	}*/
}

//getters
string largeint::getValue() {
	return myInt;
}
vector<int> largeint::getdigits() {
	return mydigits;
}

//arithmatic
string largeint::operator+(largeint& rh) {
	largeint result;
	int carryover = 0;
	int resulTemp = 0;
	vector<int> tempaddition;
	string newint = "";
	
	
	for (int x = 0; x < mydigits.size() || x < rh.getdigits().size(); x++) {
		
		cout << "leftside = " << mydigits[mydigits.size() - 1 - x] << endl;
		cout << "rightside = " << rh.getdigits()[rh.getdigits().size() - 1 - x] << endl;
		cout << "carry = " << carryover << endl;
		resulTemp = (mydigits[mydigits.size()-1 - x] + rh.getdigits()[rh.getdigits().size()-1 - x] + carryover);
		cout << "--- result = " << resulTemp << '\n' << endl;
		
		tempaddition.push_back(resulTemp % 10);
		cout << "this place = " << resulTemp % 10 << endl;

		carryover = (resulTemp - tempaddition[tempaddition.size() - 1]) / 10;
		cout << "carry = " << carryover << endl;

		if (x + 1 == mydigits.size() || x + 1 == rh.getdigits().size() && carryover != 0) {
			
			while (carryover != 0) {
				if (x + 1 == mydigits.size()) {
					resulTemp = rh.getdigits()[rh.getdigits().size() - x] + carryover;
					tempaddition.push_back(resulTemp % 10);
					carryover = (resulTemp - tempaddition[tempaddition.size() - 1]) / 10;
					cout << "carry = " << carryover << endl;

					if (carryover == 0 && x+1 < mydigits.size()) {
						for (int y = x + 1; y < mydigits.size(); y++) {
							cout << "finishing up" << endl;
							tempaddition.push_back(mydigits[mydigits.size() - y]);
						}
					}

				}
				else if (x + 1 == rh.getdigits().size()) {
					resulTemp = mydigits[mydigits.size() - x] + carryover;
					tempaddition.push_back(resulTemp % 10);
					carryover = (resulTemp - tempaddition[tempaddition.size() - 1]) / 10;
					cout << "carry = " << carryover << endl;
					if (carryover == 0 && x + 1 < mydigits.size()) {
						for (int y = x + 1; y < rh.getdigits().size(); y++) {
							cout << "finishing up" << endl;
							tempaddition.push_back(rh.getdigits()[rh.getdigits().size() - y]);
						}
					}

				}
			}
		}
	}
	
	for (int x = tempaddition.size()-1; x >= 0 ; x--) {
		newint += to_string(tempaddition[x]);
		cout << "new number" << newint << endl;
	}

	result.setInt(newint);
	return newint;
}
//void largeint::operator=(largeint& rh) {
//	myInt = rh.getValue();
//}
