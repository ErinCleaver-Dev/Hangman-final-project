#pragma once
#include "wordControler.h"
#include "StringList.h"
#include "Hint.h"
#include "HighScore.h"
#include "dbproxy.h"
#include <iostream>
#include <QMainWindow>


using namespace std;
class Hangman : public HighScore
{
private:  
    unsigned int iIncorrectLetterCount;
    unsigned int iPointcounter;
	WordControler wordControler;
    string sUserName;
    Hint hint;
    unsigned int iPos;
    QString table;
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
    void setTerm(QString&, unsigned int&); // method overload for db access
    void startGame();
	//used to display the highscore
    string getIncorrectLetters();
    string getCurrentPoints ();
    string getCurrentTerm ();
    string getHint();
    string getHintDb();
    void setGuess(string& sGuest);
    bool scoreIncremented();
};

