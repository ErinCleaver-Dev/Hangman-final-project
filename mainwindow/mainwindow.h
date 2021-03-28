#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../hangman/StringList.h"
#include "../hangman/FileMangement.h"
#include "../hangman/hangman.h"
#include <QMessageBox>
#include "../validation/validation.h"
#include <QTimer>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Added Timer
    QTimer *timer;
    //Used to switch color of Hangman form
    short unsigned iValCount1 = 0;

//Call on timer to switch colors
public slots:
    void MyTimerSlot();

private slots:
    void on_pushButton_clicked();

    void on_btHangman_clicked();

    void on_bnSubmitName_clicked();

    void on_bnBackToMain_clicked();

    void on_btHighScore_clicked();

    void on_bnBackToMain_2_clicked();

    void errorBox (string errorMessage);

    void CorrectGuessBox();

    void on_bnGuess_clicked();

    void on_btGetHint_clicked();

    void on_bnBackToMain3_clicked();

    void on_bnNewGame_clicked();

    void on_bnExit_clicked();

    void on_actionMain_menu_triggered();

    void on_actionHangman_triggered();

    void on_actionHighscore_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainWindow *ui;
    Hangman hangman;
    FileMangement accessFile;
    StringList termslist;
    QMap<string, int> gMap;
    StringList termsFromFile;
    string sValue;
    int iFirstValue;
    Validation validation;
    HighScore highscore;
};
#endif // MAINWINDOW_H
