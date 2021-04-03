#include "../mainwindow/mainwindow.h"
#include "../mainwindow/splashscreen.h"

#include <QApplication>
#include <QDir>

int main(int argc, char *argv[])
{
    QDir::current();

    QApplication a(argc, argv);
    MainWindow w;
    SplashScreen splashScreen(w); // dispose on w.show
    w.show();

    a.setWindowIcon(QIcon(":/splashIcon.png"));
    //a.setQuitOnLastWindowClosed(false);
    return a.exec();
}
