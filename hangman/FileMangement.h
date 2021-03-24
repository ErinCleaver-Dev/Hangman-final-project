#pragma once
#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include "StringList.h"
#include <QMap>
#include <QFile>
#include <QTextStream>

using namespace std;
class FileMangement
{
private: 

    QFile fileManagement;
	
	
    QString sFileName;
	string sCurrentTerm;
	ofstream newFile;
	bool bFileOpen;
	//checks to see if file is open
	//checks to see if file is open
	void openFile();


public:
    //A override that gets the name of the file.
    FileMangement(QString);
	
	//counts number of words in the file
    int countStrings();

	// Reads the Array of terms 
    void readFile(StringList&);
	
	//Use to create files
	void createFile(std::string& createFile);

	//Used to modifiy existing files by getting the map for 
	//high score and the the file name.
    void updateFile(std::string&, QMap<string, int>&);
    bool fileExists();

	//access the file and feeds the information into high score.
    QMap<std::string, int> AccessFile();

};

