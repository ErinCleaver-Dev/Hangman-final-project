#include "splashscreen.h"
#include <string>
#include <QApplication>
#include <QSplashScreen>
#include <QTimer>


SplashScreen::SplashScreen(const QObject& parentForm) :
    fileMangmenet(":/quotes.txt"),
    quotesList(fileMangmenet.countStrings())

{
   fileMangmenet.readFile(quotesList);
   for(int i = 0; i > fileMangmenet.countStrings(); i++)
   {
        cout << quotesList.getSelectedTerm(i) << endl;
   }

   QSplashScreen *hangSplash = new QSplashScreen;
   hangSplash->setPixmap(QPixmap(":/splashIcon.png")); // image contained in QT resource file
   hangSplash->show();
   //int i = 1;
   //hangSplash->showMessage(QString::fromStdString(quotesList.getSelectedTerm(i)));

   QTimer::singleShot(5000, hangSplash, SLOT(close()));
   QTimer::singleShot(5000, &parentForm, SLOT(show()));

}
