#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <QPixmap>
#include <QSplashScreen>
#include <QTimer>
#include <QThread>
#include "../hangman/FileMangement.h"
#include "../hangman/StringList.h"
#include <ctime>
#include <random>

class SplashScreen
{
private:
    QSplashScreen *hangSplash;
    QString strMessage;
    QString quote;
    FileMangement fileMangmenet;
    StringList quotesList;
public:
    SplashScreen(QWidget&);
};

#endif // SPLASHSCREEN_H
