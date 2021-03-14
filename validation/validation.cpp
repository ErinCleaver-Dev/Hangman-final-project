/*
* Name - Erin Cleaver
* Class CIS227 21/WI
* Assignment 0
* Date 1/13/21
*
* Purpose Review C++
*/

#include "validation.h"
#include <iostream>
#include <regex>

using namespace std;
Validation::Validation()
{
	this->validateValue = false;
}

//Validates that the user has entered a floating point value
bool Validation::ValidateDouble(string sUserInput)
{
	//Makes sure that validate value is equal to false
	validateValue = false;

	//a regex for checking if the user entered a double point number
	regex regDoublePointNumber("[0-9]*[.][0-9]*");

	//Checks if the number is a double or a intger
	if (regex_match(sUserInput, regDoublePointNumber) || ValidateInt(sUserInput)) {
		//changes the value to true if it is a double or an intger
		validateValue = true;
	}

	//Returns the value
	return validateValue;
}

//Validates that the user has entered a postive value
bool Validation::ValidatePostive(double dValue)
{
	//Makes sure that validate value is equal to false
	validateValue = false;

	//Checks to make sure that the doulbe value is greater then 0
	if (dValue > 0)
	{
		//Changes the value to true if greater then 0
		validateValue = true;
	}

	//Returns the value
	return validateValue;
}

//Validates that the user has entered a intger
bool Validation::ValidateInt(string sUserInput)
{	
	//Makes sure that validate value is equal to false 
	validateValue = false;

	//Created regex for making sure the users is entering an intger 
	regex regIntger("[0-9]*");

	//Checks to make sure that the userInput is a intger
	if (regex_match(sUserInput, regIntger)) {

		//Changes to true if it is a valid intger
		validateValue = true;
	}

	//Returns the value
	return validateValue;
}

