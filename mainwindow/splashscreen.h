#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H
#include <QPixmap>
#include <QSplashScreen>
#include <QThread>
#include <QTextStream>
#include <QFile>
#include "../hangman/FileMangement.h"
#include "../hangman/StringList.h"
#include <QRandomGenerator>

class SplashScreen
{
private:
    QSplashScreen *hangSplash;
    FileMangement fileMangmenet;
    QString strMessage;
    QString quote;
    StringList quotesList;
public:
    SplashScreen(QWidget&);
};

#endif // SPLASHSCREEN_H
