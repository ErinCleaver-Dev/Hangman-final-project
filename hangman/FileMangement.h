#pragma once
#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include "TermsList.h"
#include <QMap>

using namespace std;
class FileMangement
{
private: 

	fstream fsOpenFile;
	
	
	string sFileName;
	string sCurrentTerm;
	ofstream newFile;
	bool bFileOpen;
	//checks to see if file is open
	void openFile(std::string&);
	//checks to see if file is open
	void openFile();


public:
	//A override that assigns the name of the file.

	FileMangement();

	//A override that gets the name of the file.
	FileMangement(std::string&);
	
	//counts number of words in the file
	int countWords();

	// Reads the Array of terms 
	void readFile(TermsList&);
	
	//Use to create files
	void createFile(std::string& createFile);

	//Used to modifiy existing files by getting the map for 
	//high score and the the file name.
    void updateFile(std::string&, QMap<string, int>&);
	bool fileExists(std::string& sFilename);

	//access the file and feeds the information into high score.
    QMap<std::string, int> AccessFile(string sFilename);

};

