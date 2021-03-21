/*Assignment - 2
*Date - 1/31/21
*Name: Erin Cleaver, Sandra Khoury
*Purpose - For user to a pick a word from a fixed set of words
* Class Number: CIS227.6800.W21
*/

#pragma once
#include <string>
#include <deque>
using namespace std;
class StringList
{
private:

	deque<string> dTerms;
	bool bNewList;
	bool getNewTermsList();

public:

	// constructors 
    StringList();
	// A override that get the number of terms 
    StringList(int);

	// Destructors
    ~StringList();

	void setNewTermsList(bool);
	


	void setTerms(int iPos, string& sValue);
	// Selects the current term
	string getSelectedTerm(int&);

	// Gets the Size of the Array.  
	int getSize();

};


