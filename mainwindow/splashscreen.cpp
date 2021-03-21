#include "splashscreen.h"

SplashScreen::SplashScreen() :
    fileMangmenet("quotes.txt"),
    quotesList(fileMangmenet.countStrings())

{

}
