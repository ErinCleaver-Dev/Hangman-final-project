#include "HighScore.h"
#include <string>
#include <map>
#include <iostream>


using namespace std;

//assigns values to the variables 
HighScore::HighScore() :
    accessFile("highScroe.txt")
    {
    this->iStoreScore = 0;
    this->fileAccessed = false;
    this->sfileName = "highScroe.txt";

}


void HighScore::createMap(QMap<string, int>& hMap) {
    this->siMapHighScore = hMap;
}


//Used to add the key if it dose not already exist 
void HighScore::createUser(string& name) {

    // loading here
    if (!this->siMapHighScore.contains(name)) {
        this->siMapHighScore[name] = 0;
        cout << "testing to see if name loaded: " << siMapHighScore[name] << endl;
        this->iStoreScore = 0;
    }
    else {


        this->iStoreScore = this->siMapHighScore[name];
    }

}


// Used to display the high score.  Gets the information from accessfile
QSet<pair<int, string>> HighScore::displayHighScore() {
   
    QMap<string, int> highScore = accessFile.AccessFile();

    QSet<pair<int, string>> setHighScore;
    // Then goes's through the for loop for the map
    for (QMap<string, int>::iterator mIT = highScore.begin(); mIT != highScore.end(); ++mIT)
    {
        setHighScore.insert(pair(mIT.value(), mIT.key()));
    }
    return setHighScore;
}

// used to get the information that is curretnly in the file and put it in the map
void HighScore::accessHighScoreFile()
{
      
    fileAccessed = accessFile.fileExists(sfileName);
    if (fileAccessed ) {
      // siMapHighScore = accessFile.AccessFile(sfileName);
       cout << "testing access file: ";
        fileAccessed = true;
    }
    else {
        //accessFile.createFile(this->sfileName);
        fileAccessed = false;
    }

}

//used to update the score of the user
void HighScore::updateHighScore(string& name, int& iScore)
{

    iStoreScore = iScore + iStoreScore;
    if(this->siMapHighScore.contains(name)) {
        this->siMapHighScore[name] = iStoreScore;
        cout << "testing score update: " << this->siMapHighScore[name] << endl;
    } else {
        cout << "Failed to load information" << endl;
    }

}

//used to update the file information.
void HighScore::updateFile() {
     accessFile.updateFile(sfileName, siMapHighScore);
}
