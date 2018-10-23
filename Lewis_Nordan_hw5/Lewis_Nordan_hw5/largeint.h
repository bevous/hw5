#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class largeint
{
private:
	string myInt;
	vector<int> mydigits;
	void setdigits();

public:
	largeint();
	~largeint();

	//setter
	void setInt(string input);

	//getters
	string getValue();
	vector<int> getdigits();
	//arithmatic
	largeint& operator+(largeint& rh);

};

