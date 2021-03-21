#include "FileMangement.h"

//A override that assigns the name of the file.
//used when a file name is not provided.

//A override that assigns the name of the file.
//used when a file name is provided.
FileMangement::FileMangement(std::string sFileName)
{
	this->sFileName = sFileName;
}

//counts number of words in the file
int FileMangement::countStrings()
{
	openFile();
	int iValue = 0;

	if (this->fsOpenFile.is_open()) {

		while (std::getline(fsOpenFile, sCurrentTerm)) {
			
			iValue++;

		}



	}

	this->fsOpenFile.close();

	return iValue;
}


// Reads the Array of terms 
void FileMangement::readFile(StringList& termsArray)
{
	
	openFile();
	
	int iValue = 0;

	if (this->fsOpenFile.is_open()) {

		while (std::getline(fsOpenFile, sCurrentTerm)) {
			termsArray.setTerms(iValue, sCurrentTerm);
			iValue ++;
		}

	}

	this->fsOpenFile.close();

}

//Use to open files in gernal 


//Use to open files in gernal 
void FileMangement::openFile()
{
    if(fileExists(this->sFileName)) {
        cout << sFileName << endl;
        this->bFileOpen = true;
        this->fsOpenFile.open(this->sFileName);
    }
}

//Use to create files
void FileMangement::createFile(std::string& createFile)
{
    openFile();
	// Verifiys that the file was not already created and then creates the file
	if (!bFileOpen) {
		fsOpenFile.open(createFile, std::ios::out | std::ios::app);
		fsOpenFile.close();
	}
}

//Used to modifiy existing files by getting the map for high score and the the file name.
void FileMangement::updateFile(std::string& openFile, QMap<std::string, int>& mValue)
{
    newFile.open(openFile, std::ios::out | ios::app);
	//checks to make sure hte file is open
	if (newFile.good()) {
		//getts the information from the map and places it in the file.
        for (QMap<string, int>::iterator mFile = mValue.begin(); mFile != mValue.end(); ++mFile) {

            newFile <<  mFile.key() << "\n" << mFile.value() << "\n";
		}
	}

	newFile.close();
}

//used to check to see if the file exists 
bool FileMangement::fileExists(std::string& sFileName)
{
    this->sFileName = sFileName;
    this->fsOpenFile.open(sFileName);
	if (this->fsOpenFile.is_open()) {
		bFileOpen = true;
	}
	fsOpenFile.close();
	return bFileOpen;
}

//access the file and feeds the information into high score.
QMap<std::string, int> FileMangement::AccessFile()
{

    openFile();

    QMap<std::string, int> mFile;
	std::string sline;
	std::string sKey;
	int iValue;
    if (bFileOpen){
        cout << sFileName << endl;
        //gets the information from the file
        while (getline(fsOpenFile, sline)) {
            cout << "testing while loop" << endl;
			sKey = sline;
            cout << sKey << endl;
			getline(fsOpenFile, sline);
            iValue = stoi(sline);
            cout << iValue << endl;
            mFile[sKey] = iValue;
		}
		fsOpenFile.close();
        openFile();
		//make sure that the map only has the highscores from the file
        while (getline(this->fsOpenFile, sline)) {
			sKey = sline;
            getline(this->fsOpenFile, sline);
			iValue = stoi(sline);
            if (mFile[sKey] < iValue) {
                mFile[sKey] = iValue;
                std::cout << mFile[sKey] << endl;
			}
		}
	}
	fsOpenFile.close();

	return mFile;
}



