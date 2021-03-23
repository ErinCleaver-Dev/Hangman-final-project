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

   // get pseudorandom quote
   QFile quotesFile(":/quotes.txt");
   if (!quotesFile.open(QIODevice::ReadOnly | QIODevice::Text))
       quote = "while (true) { bloodPressure += programming }; -Dave";
   else
   {
       QTextStream input(&quotesFile);
       while(!input.atEnd())
       {
           QString line = input.readLine();
           quotesList.append(line);
       }       
       if (quotesList.count() > 0)
       {
           int upperBound = quotesList.length();
           qint32 randIndex = generator.bounded(0, upperBound);
           quote = quotesList[randIndex];
       }
   }
   quotesFile.close();

   // display required output. TODO: Eliminate manual threading.
   strMessage = "Application Ver: " + QString(APPLICATION_VER); // added a new DEFINES in .pro file.

   hangSplash->showMessage("CIS227 Assignment 8 - Hangman", Qt::AlignBottom);
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

