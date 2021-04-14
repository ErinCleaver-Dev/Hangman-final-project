#pragma once
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
class WordControler
{
private:
	vector<char> vCurrentWord;
	vector<char> vCurrentlyDisplayed;
	bool bWordUpdated;
    void updateCurrentlyDisplayed(char&, unsigned int& );
	// sets the boolen value based on rather or not it is set
	void setbWordUpdated(bool bValue);
	bool getUpdate();



public: 
	WordControler();
	~WordControler();
	// Sets the current term as selected by user
	void setTerm(string);

	//Displays the current information that has been guessed correctly
	string displayKnowLetters();
	
    void getGuess(char&, unsigned int&);
	void getGuess(char& cGuess);
	//Used to get the rather the term was found or not.
	bool runHangman();
	bool getbWordupdate();

	void clearOutWord();
    string giveHint(unsigned int&);
    int getLenght();

};

