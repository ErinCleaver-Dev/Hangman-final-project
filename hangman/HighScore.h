#pragma once
#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <set>
#include <QMap>
#include "FileMangement.h"
#include <QSet>
#include <QtAlgorithms>
using namespace std;


class HighScore
{
private:
	//assigns values to the virables 

    QMap<string, int> siMapHighScore;
	bool fileAccessed;
	FileMangement accessFile;
	int iStoreScore;
    string sfileName;
public:
    HighScore();
    // used to get the information that is curretnly in the file and put it in the map
    void accessHighScoreFile();
    //Used to add the key if it dose not already exist
    void createUser(string&);
    // Used to display the high score.  Gets the information from accessfile
    QSet<pair<int, string>> displayHighScore();
    //used to update the score of the user
    void updateHighScore(string&, int&);
    //used to update the file information.
    void updateFile();
	// Creates the map
    void createMap(QMap<string, int>& hMap);
};

