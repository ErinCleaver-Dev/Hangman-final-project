#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <QPixmap>
#include <QSplashScreen>
#include <QTimer>
#include "../hangman/FileMangement.h"
#include "../hangman/StringList.h"
#include <ctime>

class SplashScreen
{
private:
    FileMangement fileMangmenet;
    StringList quotesList;
public:
    SplashScreen(const QObject&);
};

#endif // SPLASHSCREEN_H
