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
//removes all invalid characters
void largeint::setInt(string input) {
	for (int x = 0; abs(x) < input.length(); x++) {
		if (input[x] == '0') {
			if (x == 0) {
				input.erase(x, 1);
			}
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
	
	
	for (int x = 0; x < mydigits.size() && x < rh.getdigits().size(); x++) {
		// does all adition up to where the length of the numbers differs or there is leffovers to carry over
		
		resulTemp = (mydigits[mydigits.size()-1 - x] + rh.getdigits()[rh.getdigits().size()-1 - x] + carryover);
		cout << "digits at pos" << x+1 << ":  " << mydigits[mydigits.size() - 1 - x] << " + " << rh.getdigits()[rh.getdigits().size() - 1 - x] << " + " << carryover << " = " << resulTemp << endl;

		tempaddition.push_back(resulTemp % 10);
		cout << "this place = " << resulTemp % 10 << endl;

		carryover = (resulTemp - tempaddition[tempaddition.size() - 1]) / 10;
		cout << "carry = " << carryover <<'\n'<< endl;
		// logic for numbers of differing length / extra carryover
		int y = x + 1;
		if ((x + 1 == mydigits.size() || x + 1 == rh.getdigits().size() && carryover != 0)) {
			
			cout << "in block 2" << endl;
			while (carryover != 0 || y + 1 < mydigits.size() || y + 1 < rh.getdigits().size() ) { //check this for error
				
				cout << "in the loop" << '\n' << "x= " << x << '\n' << "y=" << y << endl;
				if (mydigits.size() == rh.getdigits().size()) {
					tempaddition.push_back(carryover);
					carryover = 0;
				}
				// if number 2 is larger than number 1
				else if (rh.getdigits().size() > mydigits.size()) { //check this ligic
					cout << "part 1" << endl;
					if (y < rh.getdigits().size()) {
						resulTemp = rh.getdigits()[rh.getdigits().size() - y] + carryover;
						cout << "digits at pos" << y + 1 << ":  " << rh.getdigits()[rh.getdigits().size() - y] << " + " << carryover << " = " << resulTemp << endl;
						y += 1;
						tempaddition.push_back(resulTemp % 10);
						cout << "this place = " << resulTemp % 10 << endl;

						carryover = (resulTemp - tempaddition[tempaddition.size() - 1]) / 10;
						cout << "carry = " << carryover << endl;
					}
					// fix this
					if (carryover == 0 && y+1 < mydigits.size()) {
						for (int y = x + 1; y < mydigits.size(); y++) {
							cout << "finishing up" << endl;
							tempaddition.push_back(mydigits[mydigits.size() - y]);
						}
					}

				}
				// number 1 is larger than number 2
				else if (x + 1 == rh.getdigits().size()) {
					cout << "part 2" << endl;
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
	newint = "";
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
