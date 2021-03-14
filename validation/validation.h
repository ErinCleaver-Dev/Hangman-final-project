/*
* Name - Erin Cleaver
* Class CIS227 21/WI
* Assignment 0
* Date 1/13/21
*
* Purpose Review C++
*/

#pragma once
#include <type_traits>
#include <string>

using namespace std;

class Validation
{
private: 
	bool validateValue;

public:
	Validation();

	//Validates that the user has entered a floating point value
	bool ValidateDouble(string userInput);

	//Validates that the user has entered a postive value
	bool ValidatePostive(double dvalue);

	//Validates that the user has entered a intger
	bool ValidateInt(string userInput);

};

