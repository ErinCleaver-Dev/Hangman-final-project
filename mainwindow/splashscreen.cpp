#include "splashscreen.h"
#include <string>


SplashScreen::SplashScreen(QWidget& parent) :
    fileMangmenet(":/quotes.txt"),
    quotesList(fileMangmenet.countStrings())

{
    // create new splash, set properties
    QPixmap hangmanPix(":/splashIcon.png");
    hangSplash = new QSplashScreen(hangmanPix); // overload
    hangSplash->setWindowFlag(Qt::WindowStaysOnTopHint);
    hangSplash->show();

    fileMangmenet.readFile(quotesList);

    // Generate random quote
    srand(time(0)); // seed
    int upperBound = quotesList.getSize();
    int randIndex = rand() % upperBound + 1;
    quote =  QString::fromStdString(quotesList.getSelectedTerm(randIndex));

   // display required output. TODO: Eliminate manual threading.
   strMessage = "Application Ver: " + QString(APPLICATION_VER); // added a new DEFINES in .pro file.
   hangSplash->showMessage("CIS227 Assignment 9 - Hangman", Qt::AlignBottom);
   QThread::msleep(1500);
   hangSplash->showMessage("Authors: Erin, Sandra, and Dave", Qt::AlignBottom);
   QThread::msleep(1500);
   hangSplash->showMessage(strMessage, Qt::AlignBottom);
   QThread::msleep(1500);
   hangSplash->showMessage(quote, Qt::AlignBottom); // TODO: Add quote from file
   QThread::msleep(3000);

   // Wait for parent widget to show. No need to call individual slots.
   hangSplash->finish(&parent);
}
