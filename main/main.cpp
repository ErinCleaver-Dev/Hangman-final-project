#include "../mainwindow/mainwindow.h"
#include "../mainwindow/splashscreen.h"

#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QDir::current();

    QApplication a(argc, argv);
    MainWindow w;
    SplashScreen splashScreen(w); // execution returns to parent form

    return a.exec();
}
