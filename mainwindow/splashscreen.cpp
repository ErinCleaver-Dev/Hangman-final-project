#include "splashscreen.h"
#include <string>
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>


SplashScreen::SplashScreen(QWidget& parent) :
    fileMangmenet(":/quotes.txt"),
    quotesList(fileMangmenet.countStrings())

{
   fileMangmenet.readFile(quotesList);
   for(int i = 0; i > fileMangmenet.countStrings(); i++)
   {
        cout << quotesList.getSelectedTerm(i) << endl;
   }

   // get random quote, convert type. Needs fixing.
   //int randIndex = rand() % quotesList.getSize();
   //string strQuote = quotesList.getSelectedTerm(randIndex);
   //quote = QString::fromStdString(strQuote);


   // create new splash, set properties
   QPixmap hangmanPix(":/splashIcon.png");
   hangSplash = new QSplashScreen(hangmanPix); // overload
   hangSplash->setWindowFlag(Qt::WindowStaysOnTopHint);
   hangSplash->show();


   // display required output. TODO: Eliminate manual threading.
   strMessage = "Application Ver: " + QString(APPLICATION_VER); // added a new DEFINES in .pro file.

   hangSplash->showMessage("CIS227 Assignment 8 - Hangman", Qt::AlignBottom);
   QThread::msleep(1500);
   hangSplash->showMessage("Authors: Erin, Sandra, and Dave", Qt::AlignBottom);
   QThread::msleep(1500);
   hangSplash->showMessage(strMessage, Qt::AlignBottom);
   QThread::msleep(1500);
   hangSplash->showMessage("Programming is a great way to lose your hair. -Dave", Qt::AlignBottom); // TODO: Add quote from file
   QThread::msleep(3000);

   // Wait for parent to show. No need to call individual slots.
   hangSplash->finish(&parent);
}
