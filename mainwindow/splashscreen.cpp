#include "splashscreen.h"
#include <string>

SplashScreen::SplashScreen() :
    fileMangmenet("../mainwindow/quotes.txt"),
    quotesList(fileMangmenet.countStrings())

{
   fileMangmenet.readFile(quotesList);

   for(int i = 0; i > fileMangmenet.countStrings(); i++)
   {
        cout << quotesList.getSelectedTerm(i) << endl;
   }
}
