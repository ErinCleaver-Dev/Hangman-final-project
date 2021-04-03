#include "FileMangement.h"

//A override that assigns the name of the file.
//used when a file name is not provided.

//A override that assigns the name of the file.
//used when a file name is provided.
FileMangement::FileMangement(QString sFileName)
{
	this->sFileName = sFileName;

}

//counts number of words in the file
int FileMangement::countStrings()
{
	openFile();
	int iValue = 0;
    QTextStream input(&fileManagement);

    if (bFileOpen) {

        while(!input.atEnd()){
            input.readLine();
			iValue++;

		}
    } else {
        cout << "File failed to open to supply count" << endl;
    }

	this->fileManagement.close();

	return iValue;
}


// Reads the Array of terms 
void FileMangement::readFile(StringList& termsArray)
{
	
	openFile();
	
	int iValue = 0;
    QTextStream input(&fileManagement);
    QString sTemp = "";
    if (!input.atEnd()) {

        while (!input.atEnd()) {
            QString sTemp = input.readLine();
            sCurrentTerm = sTemp.toStdString();
            termsArray.setTerms(iValue, sCurrentTerm);
			iValue ++;
		}

    } else {
        cout << "String list failed to load terms" << endl;
    }

	this->fileManagement.close();

}

//Used to update the file name.
void FileMangement::setFileName(QString sFileName) {
    this->sFileName = sFileName;
}

//Use to open files in gernal 
void FileMangement::openFile()
{
    fileManagement.setFileName(sFileName);

    if (    fileManagement.open(QIODevice::ReadOnly | QIODevice::Text)) {
        this->bFileOpen = true;
    } else {
        cout << "File failed to open." << endl;
    }
}

//Use to create files
void FileMangement::createFile(std::string& createFile)
{
    openFile();
	// Verifiys that the file was not already created and then creates the file
	if (!bFileOpen) {
	}
}

//Used to modifiy existing files by getting the map for high score and the the file name.
void FileMangement::updateFile(QMap<std::string, int>& mValue)
{
	//checks to make sure hte file is open


    if (fileManagement.open(QFile::WriteOnly | QFile::Text)) {
        QTextStream input(&fileManagement);
		//getts the information from the map and places it in the file.
        for (QMap<string, int>::iterator mFile = mValue.begin(); mFile != mValue.end(); ++mFile) {
            QString sTemp = QString::fromStdString(mFile.key()) + "\n" + QString::number(mFile.value())  + "\n";
            input << sTemp;
		}
	}

	newFile.close();
}

//used to check to see if the file exists 
bool FileMangement::fileExists()
{
    openFile();
    if (fileManagement.open(QIODevice::ReadOnly | QIODevice::Text)) {
		bFileOpen = true;
	}
	fileManagement.close();
	return bFileOpen;
}

//access the file and feeds the information into high score.
QMap<std::string, int> FileMangement::AccessFile()
{

    openFile();
    QTextStream input(&fileManagement);

    QMap<std::string, int> mFile;
	std::string sline;
	std::string sKey;
	int iValue;
    if (bFileOpen){
        //gets the information from the file
        while (!input.atEnd()) {
            sKey = input.readLine().toStdString();
            iValue = input.readLine().toInt();
            mFile[sKey] = iValue;
		}
		fileManagement.close();
        openFile();
        QTextStream input(&fileManagement);
		//make sure that the map only has the highscores from the file
        while (!input.atEnd()) {
            sKey = input.readLine().toStdString();
            iValue = input.readLine().toInt();
            if (mFile[sKey] < iValue) {
                mFile[sKey] = iValue;
                std::cout << mFile[sKey] << endl;
			}
		}
	}
	fileManagement.close();

	return mFile;
}



