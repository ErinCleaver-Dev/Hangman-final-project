#include "../mainwindow/mainwindow.h"
#include "../mainwindow/splashscreen.h"

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QFile>

//call functions to copy text files into buildQTFolder from assignment7 master folder
void makeEasyText();
void makeMediumText();
void makeHardText();
void makeHighScore();

int main(int argc, char *argv[])
{
    QDir::current();

    QApplication a(argc, argv);

    makeEasyText();//call functions to make txt files
    makeMediumText();
    makeHardText();
    makeHighScore();

    MainWindow w;
    SplashScreen splashScreen(w); // dispose on w.show
    w.show();

    a.setWindowIcon(QIcon(":/splashIcon.png"));
    return a.exec();
}
//copy easy textfile
void makeEasyText(){

    qDebug() << QDir::currentPath().append("/easy.txt");
    QString name = QDir::currentPath();
    //get destination of file and append the name to it
    QFile file(name.append("/easy.txt"));
    QFile fileEasy(":/easy.txt");
    //check if file does not exist, if it doesn't it will copy it
       if (!file.exists())
       {
          // QFile::remove(name);
           fileEasy.copy(name);
           //allow perrmission to write into file
           file.setPermissions(QFile::WriteUser);
           qDebug()<< "Easy.txt created";
       }

}

void makeMediumText(){

    qDebug() << QDir::currentPath().append("/medium.txt");
    QString name = QDir::currentPath();

    QFile file(name.append("/medium.txt"));
    QFile fileMed(":/medium.txt");

       if (!file.exists())
       {
           fileMed.copy(name);
            file.setPermissions(QFile::WriteUser);
           qDebug()<< "Medium.txt created";
       }
}

void makeHardText(){

    qDebug() << QDir::currentPath().append("/hard.txt");
    QString name = QDir::currentPath();

    QFile file(name.append("/hard.txt"));
    QFile fileEasy(":/hard.txt");

       if (!file.exists())
       {
           fileEasy.copy(name);
           file.setPermissions(QFile::WriteUser);
           qDebug()<< "hard.txt created";
       }

}

void makeHighScore(){

    qDebug() << QDir::currentPath().append("/highScroe.txt");
    QString name = QDir::currentPath();

    QFile file(name.append("/highScroe.txt"));
    QFile fileHighScore(":/highScroe.txt");

       if (!file.exists())
       {
           fileHighScore.copy(name);
           file.setPermissions(QFile::WriteUser);
           qDebug()<< "highscore.txt created";
       }

}
