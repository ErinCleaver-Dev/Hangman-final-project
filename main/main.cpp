#include "../mainwindow/mainwindow.h"
#include "../mainwindow/splashscreen.h"

#include <QApplication>
#include <QDebug>
#include <QDir>
#include <QFile>

// forward dec
void copyResourceToOutput(QString namedResource, QString outputFile);

int main(int argc, char *argv[])
{
    QDir::current();

    QApplication a(argc, argv);

    // copy resource files to output dir
    copyResourceToOutput(":/terms.db", "/terms.db");
    copyResourceToOutput(":/easy.txt", "/easy.txt");
    copyResourceToOutput(":/medium.txt", "/medium.txt");
    copyResourceToOutput(":/hard.txt", "/hard.txt");
    copyResourceToOutput(":/highScroe.txt", "/highScroe.txt");

    MainWindow w;
    SplashScreen splashScreen(w); // dispose on w.show
    w.show();

    a.setWindowIcon(QIcon(":/splashIcon.png"));
    return a.exec();
}

// Copy named resource to output directory.
void copyResourceToOutput(QString namedResource, QString outputFile)
{
    QString currentDir = QDir::currentPath();
    QFile fileToAppend(currentDir.append(outputFile));
    QFile resourceFileToCopy(namedResource);
    if (!fileToAppend.exists())
    {
        resourceFileToCopy.copy(currentDir);
        resourceFileToCopy.setPermissions(QFile::WriteUser);
        qDebug() << "Successfully copied " << outputFile << " to the output dir.";
    }
}
