/*Assignment - 7
*Date - 3/14/21
*Name: Erin Cleaver, Sandra Khoury
*Purpose - For user to a pick a word from a fixed set of words
* Class Number: CIS227.6800.W21
*/


using namespace std;
#include "StringList.h"


bool StringList::getNewTermsList()
{
	return this->bNewList;
}

// A constructor for the termsArry class.  It assigns values to ther terms array.  
// This is the default for when they do not get the terms from a file.
StringList::StringList()
{	// Removed because this information will be moved to a file

	this->bNewList = false;
	this-> dTerms.resize(12);
	this->dTerms[0] ="home";
	this->dTerms [1] = "apple";
	this->dTerms [2] = "accurate";
	this->dTerms [3] = "trouble";
	this->dTerms [4] = "random";
	this->dTerms [5] = "triger";
	this->dTerms [6] = "ant";
	this->dTerms [7] = "puzle";
	this->dTerms [8] = "apple";
	this->dTerms [9] = "blueberries";
	this->dTerms [10] = "cookies";
	this->dTerms [11] = "pineapple";


}

// used to get the size of the file.
StringList::StringList(unsigned int iSize)
{
	this->dTerms.resize(iSize);
}

// A override that gets the number of terms.


// Destructors
StringList::~StringList()
{
}

void StringList::setNewTermsList(bool bValue)
{
	
	this->bNewList = bValue;
	
}

// Function to get terms from file
void StringList::setTerms(unsigned int iPos, string& sValue)
{
	this->dTerms[iPos] = sValue;

}



// Selects the current term
string StringList::getSelectedTerm(unsigned int &iPos)
{

	return dTerms.at(iPos);

}

int StringList::getSize()
{
	return dTerms.size();
}

// Gets the Size of the Array.  


