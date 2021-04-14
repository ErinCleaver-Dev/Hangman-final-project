#pragma once
#include "wordControler.h"
#include "StringList.h"
#include "Hint.h"
#include "HighScore.h"
#include <iostream>
#include <QMainWindow>


using namespace std;
class Hangman : public HighScore
{
private:  
    int iIncorrectLetterCount;
    unsigned iPointcounter;
	WordControler wordControler;
    string sUserName;
    Hint hint;
    int iPos;
	HighScore highscore;
    string sHint;
    string sGuess;
    string sCurrentTerm;
    bool bIncremented;

public:
	// gets the map for the highscore

    Hangman();
	//starts up the game
    void setName(string);
    string getName();
    void setTerm (StringList&,unsigned int&);
    void startGame();
	//used to display the highscore
    string getIncorrectLetters();
    string getCurrentPoints ();
    string getCurrentTerm ();
    string getHint();
    void setGuess(string& sGuest);
    bool scoreIncremented();
};

