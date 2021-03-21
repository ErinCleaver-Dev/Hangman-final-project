#include "../mainwindow/mainwindow.h"

#include <QApplication>
#include "../mainwindow/splashscreen.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    SplashScreen splashScreen;
    w.show();
    return a.exec();
}
