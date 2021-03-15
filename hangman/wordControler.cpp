#include "wordControler.h"
#include "iostream"

//
WordControler::WordControler()
{
	
	this->bWordUpdated = false;
}

WordControler::~WordControler() {
	
}


// sets the current term for the selected term to be guessed.
void WordControler::setTerm(string sWord)
{

	// goes through a for loop to get the charchters for the words
	for  (char cValue : sWord)
	{
		//Adds the letters to the vector for the current word that was selected
		vCurrentWord.push_back(cValue);
		//Adds the letters to the vector for the current word that is being displayed
		vCurrentlyDisplayed.push_back('_');
	}

}

// displays the letters that are currently know
string WordControler::displayKnowLetters()
{
	string sTerm;
	int iSize = vCurrentlyDisplayed.size();
	// displays the currently know letters
	for (int i = 0; i < iSize; i++) {
		sTerm += vCurrentlyDisplayed[i];
		sTerm += " ";
	}
	

    return sTerm;
}



// Lets the user guess a value for a speific space.
void WordControler::getGuess(char& cGuess, int& iValue)
{
	
	iValue -= iValue;
	setbWordUpdated(false);


	// Make sure that the value is within range for values
	if (iValue < vCurrentlyDisplayed.size() && iValue >= 0) {
		//Checks to make sure the letter is found in the current word
		if (vCurrentWord[iValue] == cGuess) {
			//Checks to see if the value is not already in the display word
			if (vCurrentlyDisplayed[iValue] != cGuess) {
				// Adds the value to the guess
				updateCurrentlyDisplayed(cGuess, iValue);
				// Becomes true if the value is updated.
				setbWordUpdated(true);
			}
		}
	}

	

}

bool WordControler::runHangman()
{
	
	
	return vCurrentlyDisplayed == vCurrentWord;
	
}

bool WordControler::getbWordupdate()
{
	return bWordUpdated;
}

void WordControler::clearOutWord()
{
	if (vCurrentlyDisplayed == vCurrentWord) {
		while (!vCurrentWord.empty()) {
			vCurrentWord.pop_back();
		}
		while (!vCurrentlyDisplayed.empty()) {
			vCurrentlyDisplayed.pop_back();
		}
	}
}

// Gets the value of rather the wor has been updated.
bool WordControler::getUpdate()
{


	return bWordUpdated;
}

// Lets the user guess in gernal if a letter exist.  
void WordControler::getGuess(char& cGuess)
{
	//Sets to false before starting the for loop
	setbWordUpdated(false);

	// Goes through a for loop until the victory reachs 0
	for (int iValue = 0; iValue < vCurrentlyDisplayed.size(); iValue++) {
		// checks to see if the value provided is found in the array
		if (vCurrentWord[iValue] == cGuess) {
			//Checks to see if the value already exists for the letters that are currently displayed
			if (vCurrentlyDisplayed[iValue] != cGuess) {
				updateCurrentlyDisplayed(cGuess, iValue);
				// Becomes true
				setbWordUpdated(true);
			} 
		} 
	}
}


// Used to update current letters being displayed.
void WordControler::updateCurrentlyDisplayed(char& cGuess, int& iValue)
{
	vCurrentlyDisplayed[iValue] = cGuess;
}

// Used to set rather the value has been updated or not.  
void WordControler::setbWordUpdated(bool bValue)
{
	this->bWordUpdated = bValue;
}
string WordControler::giveHint(int& iHint) {
    string sHint = "";
    switch (iHint)
    {
    case 0:
        sHint = "A place for a break.";
        break;
    case 1:
        sHint =  "A very common red fruit.";
        break;
    case 2:
        sHint = "Right on the mark.";
        break;
    case 3:
        sHint = "Double ________";
        break;
    case 4:
        sHint = "Highly improbable.";
        break;
    case 5:
        sHint = "Pull the ____";
        break;
    case 6:
        sHint = "They live in a colony.";
        break;
    case 7:
        sHint = "Put the peices together.";
        break;
    case 8:
        sHint = "A sweet and delicious fruit.";
        break;
    case 9:
        sHint = "A fruit known for its small sweet and sour taste.";
        break;
    case 10:
        sHint = "The Darkside has them.";
        break;
    case 11:
        sHint = "A tropical fruit of sweetness.";
        break;
    default:
        sHint = "Boo";
        break;
    }
    return sHint;

}
