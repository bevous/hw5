// Lewis_Nordan_hw5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>
#include <vector>
#include "largeint.h"
using namespace std;

int main()
{
	largeint first;
	largeint second;
	largeint result;
	string temp = "1234567890";
	//cout << "enter your first number";
	//cin >> temp;
	first.setInt(temp);
	//cout << "enter your second number";
	//cin >> temp;
	second.setInt(temp);

	cout << first.getValue() << endl;
	cout << second.getValue() << endl;
	
	//result = first + second;
	result.setInt( (first + second) );
	cout << first.getValue() << " + " << second.getValue() << " = " << result.getValue() << endl;

	system("pause");
    return 0;
}

