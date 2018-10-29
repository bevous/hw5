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
				x -= 1;
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
	mydigits.clear();
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
	
	
	//logic for numbers of the same size
		// compare sizes enter if they are ==
	if (mydigits.size() == rh.getdigits().size()) {
		// iterate through till the last digit
		cout << "the numbers are the same size" << endl;
		for (int x = 0; x < mydigits.size(); x++) {
			//maths
			resulTemp = mydigits[mydigits.size() -1 - x] + rh.getdigits()[rh.getdigits().size() - 1 - x] + carryover;
			cout << "digits at pos" << x + 1 << ":  "<< mydigits[mydigits.size() - 1 - x] << " + " << rh.getdigits()[rh.getdigits().size() - 1 - x] << " + " << carryover << " = " << resulTemp << endl;
			tempaddition.push_back(resulTemp % 10);
			cout << "this place = " << resulTemp % 10 << endl;
			carryover = (resulTemp - tempaddition[tempaddition.size() - 1]) / 10;
			cout << "carry = " << carryover << endl;
		}
		//check for extra carryover
		if (carryover != 0) {
			//if there is carryover drop that number into its new place
			tempaddition.push_back(carryover);
			carryover = 0;
		}
		//exit
	}
	//logic for numbers of different sizes
		//compare sizes enter if they are not ==
	else if (mydigits.size() != rh.getdigits().size()) {
		//iterate till the end of the shorter number
		if (mydigits.size() < rh.getdigits().size()) {
			cout << "number one is shorter than the second number" << endl;
			for (int x = 0; x < mydigits.size(); x++) {
				//maths
				resulTemp = mydigits[mydigits.size() - 1 - x] + rh.getdigits()[rh.getdigits().size() - 1 - x] + carryover;
				cout << "digits at pos" << x + 1 << ":  " << mydigits[mydigits.size() - 1 - x] << " + " << rh.getdigits()[rh.getdigits().size() - 1 - x] << " + " << carryover << " = " << resulTemp << endl;
				tempaddition.push_back(resulTemp % 10);
				cout << "this place = " << resulTemp % 10 << endl;
				carryover = (resulTemp - tempaddition[tempaddition.size() - 1]) / 10;
				cout << "carry = " << carryover << endl;
			}
			cout << "finised with primary sddition" << endl;
		}
		else if (mydigits.size() > rh.getdigits().size()) {
			cout << "number one is shorter than the second number" << endl;
			for (int x = 0; x < rh.getdigits().size(); x++) {
				//maths
				resulTemp = mydigits[mydigits.size() - 1 - x] + rh.getdigits()[rh.getdigits().size() - 1 - x] + carryover;
				cout << "digits at pos" << x + 1 << ":  " << mydigits[mydigits.size() - 1 - x] << " + " << rh.getdigits()[rh.getdigits().size() - 1 - x] << " + " << carryover << " = " << resulTemp << endl;
				tempaddition.push_back(resulTemp % 10);
				cout << "this place = " << resulTemp % 10 << endl;
				carryover = (resulTemp - tempaddition[tempaddition.size() - 1]) / 10;
				cout << "carry = " << carryover << endl;
			}
		}
		//continue addition with the numbers left over
		if (mydigits.size() < rh.getdigits().size()) {
				for (int x = mydigits.size() ; x < rh.getdigits().size(); x++) {
					resulTemp = rh.getdigits()[rh.getdigits().size() - 1 - x] + carryover;
					cout << "digits at pos" << x + 1 << ":  " << rh.getdigits()[rh.getdigits().size() -1 - x] << " + " << carryover << " = " << resulTemp << endl;
					
					tempaddition.push_back(resulTemp % 10);
					cout << "this place = " << resulTemp % 10 << endl;
					carryover = (resulTemp - tempaddition[tempaddition.size() - 1]) / 10;
					cout << "carry = " << carryover << endl;
				}
				
		}
		else if (mydigits.size() > rh.getdigits().size()) {
			for (int x = rh.getdigits().size(); x < mydigits.size(); x++) {
				resulTemp = mydigits[mydigits.size() - 1 - x] + carryover;
				cout << "digits at pos" << x + 1 << ":  " << mydigits[mydigits.size() - 1 - x] << " + " << carryover << " = " << resulTemp << endl;
				tempaddition.push_back(resulTemp % 10);
				cout << "this place = " << resulTemp % 10 << endl;
				carryover = (resulTemp - tempaddition[tempaddition.size() - 1]) / 10;
				cout << "carry = " << carryover << endl;
			}
		}
		//if pos == end of larger number && carryover != 0
		if (carryover != 0) {
			//drop it down into its new place
			tempaddition.push_back(carryover);
			carryover = 0;
		}	

	//exit
	}
	newint = "";
	for (int x = tempaddition.size()-1; x >= 0 ; x--) {
		newint += to_string(tempaddition[x]);
		if (x % 3==0 && x != tempaddition.size() - 1) {
			newint += " , ";
		}
	}
	cout << "new number" << newint << endl;
	result.setInt(newint);
	return newint;
}
//void largeint::operator=(largeint& rh) {
//	myInt = rh.getValue();
//}
