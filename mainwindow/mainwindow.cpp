#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPalette>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      accessFile(":/easy.txt"),
      termsFromFile(accessFile.countStrings())

{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
   // ui-stackedW
    //hangman.createMap(gMap);
    hangman.accessHighScoreFile();


    // time spent playing the game
    playTimer = new QTimer(this);
    playTimer->setTimerType(Qt::CoarseTimer);
    connect(playTimer, SIGNAL(timeout()), this, SLOT(PlayTimerSlot()));

    //timer used to change color every minute
    timer = new QTimer(this);
    timer->setTimerType(Qt::CoarseTimer);
    connect(timer, SIGNAL(timeout()),this, SLOT(MyTimerSlot()));


    // set up event to monitor for selected widget changes
    connect(ui->stackedWidget, SIGNAL(currentChanged(int)), this, SLOT(on_stack_changed()));



    // set up event to monitor for selected widget changes
    connect(ui->stackedWidget, SIGNAL(currentChanged(int)), this, SLOT(on_stack_changed()));

    //connect to window form and change color with signal
    connect(&options, SIGNAL(getTheColor(short int)),this, SLOT(getColors(short int)));



    
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Play timer start/stop control. Tied to stackedWidget currentChanged signal.
void MainWindow::on_stack_changed()
{
    bool bPlaying = ui->stackedWidget->currentIndex() == ui->stackedWidget->indexOf(ui->Hangman);
    if (bPlaying){
        playTimer->start(1000);
        timer->start(60000);
    }
    else {
        playTimer->stop();
        timer->stop();
        ui->lcdPlayTime->display(0);
        ui -> Hangman -> setStyleSheet("background-color: rgb(37, 41, 109);");

    }
}


// Exit the application
void MainWindow::on_pushButton_clicked()
{
    QCoreApplication::quit();
}

// Goes to the game form
void MainWindow::on_btHangman_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

// Gets the information from the user.
void MainWindow::on_bnSubmitName_clicked()
{

    // A if statement to check to makeing sure that the user provided all of the information
    if(!ui->txGetName->text().isEmpty() && !ui->txGetNumber->text().isEmpty()) {
        string sNumber;
        string sName;
        sNumber = ui->txGetNumber->text().toStdString();

        // Validates that it is a number.
        if(validation.ValidateInt(sNumber)) {
            this->iFirstValue =stoi(sNumber);
            // makes sure it is between 1 and 12.
            if(iFirstValue > 0 && iFirstValue <= 12) {
                //Checks to make sure that  option was clicked.
                if(ui->rbMixed->isChecked()) {
                    iFirstValue-=1;
                    hangman.setTerm(termslist, iFirstValue);
                }
                //Checks to make sure that  option was clicked.
                else if(ui->rbEasy->isChecked()) {
                    accessFile.readFile(termsFromFile);
                    hangman.setTerm(termsFromFile, iFirstValue);
                } else if(ui->rbMedium->isChecked()) {
                    accessFile.setFileName(":/medium.txt");
                    accessFile.readFile(termsFromFile);
                    hangman.setTerm(termsFromFile, iFirstValue);
                } else if(ui->rbHard->isChecked()) {
                    accessFile.setFileName(":/hard.txt");
                    accessFile.readFile(termsFromFile);
                    hangman.setTerm(termsFromFile, iFirstValue);
                }
                // Gets the information from the text box
                sName = ui->txGetName->text().toStdString();
                // sets the name
                hangman.setName(sName);
                //creates the user in the highscore application
                hangman.createUser(sName);
                //fills the information into the labels.
                ui->lbGetUserName->setText(QString::fromStdString(sName));
                ui->lbPoints->setText("0");
                ui->lbIncorrect->setText("0");
                ui->lbhint->setText("");
                ui->lbKnowWord->setText(QString::fromStdString(hangman.getCurrentTerm()));
                //makes sure that the fields are blank
                ui->txGuess->setText("");
                ui->txGetName->setText("");
                ui->stackedWidget->setCurrentIndex(2);
            } else {
                errorBox("Please provide a value between 1 and 12");
            }
        } else {
            errorBox("Please provide a number");
        }

    } else {
       errorBox("Please fill in all of the fields and select one of the choses for how to load Terms");
    }
}

void MainWindow::on_bnBackToMain_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_btHighScore_clicked()
{
    // was made to map the file information to the table, currently is not working.
    QList<pair<int, string>> setHighScore= hangman.displayHighScore().values();

    //Adding the sort algorthim for displaying high scores.
    std::sort(setHighScore.begin(), setHighScore.end());
    std::reverse(setHighScore.begin(), setHighScore.end());
    int c =0;
    int r=0;
    for(auto const& setPair : setHighScore) {

        string sInt = to_string(setPair.first);
        c =0;
        QString qsValue  = QString::fromStdString(sInt);
        auto it = new QTableWidgetItem(qsValue);
        ui->tbHighScoreTable->setItem(r,c, it);
        c++;
        qsValue = QString::fromStdString(setPair.second);
        it = new QTableWidgetItem(qsValue);
        ui->tbHighScoreTable->setItem(r,c, it);
        r++;
        if(r > 9) {
            break;
        }
    }

    ui->stackedWidget->setCurrentIndex(3);
}

// Button for getting back to menu
void MainWindow::on_bnBackToMain_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// to dispaly errors when the user enters incorrect input.
void MainWindow::errorBox(string errorMessage) {
    QMessageBox errorBox;


    errorBox.setWindowTitle("Error");
    errorBox.setText(QString::fromStdString(errorMessage));
    errorBox.addButton("exit", QMessageBox::YesRole);
    errorBox.exec();
}

void MainWindow::CorrectGuessBox() {
    QMessageBox correctBox;
    correctBox.setWindowTitle("Congrats!");
    correctBox.setText("Your guess was correct!");
    correctBox.addButton("I rock!", QMessageBox::YesRole);
    correctBox.exec();
}

//Function used for getting guess from the user
void MainWindow::on_bnGuess_clicked()
{
    // makes sure the field is not empty
    if(!ui->txGuess->text().isEmpty()) {


        string sGuess = ui->txGuess->text().toStdString();
        // sets the guess to the hangman application
        hangman.setGuess(sGuess);
        // starts up the hangman game
        hangman.startGame();

        // used to fill in the values into the lables
        ui->lbKnowWord->setText(QString::fromStdString(hangman.getCurrentTerm()));
        ui->lbPoints->setText(QString::fromStdString(hangman.getCurrentPoints()));
        ui->lbIncorrect->setText(QString::fromStdString(hangman.getIncorrectLetters()));

        // TODO: Implement settings file to turn this off if the user wants to.
        if(hangman.scoreIncremented()) { CorrectGuessBox(); }

        // Checks to see if the user has won
        if(stoi(hangman.getCurrentPoints()) > 10) {

            // used to fill in the values into labels
            ui->lbGameOver->setText("You Win");
            ui->lbGetScore->setText(QString::fromStdString(hangman.getCurrentPoints()));
            ui->lbGetIncorrect->setText(QString::fromStdString(hangman.getIncorrectLetters()));
            ui->lbGameOver->setStyleSheet("background-color: rgb(231, 229, 240); font: 28pt 'MS Shell Dlg 2'; qproperty-alignment: AlignCenter; red; border: 2px solid black; border-radius: 3px;");
            // Goes to the game over screen
            ui->stackedWidget->setCurrentIndex(4);
            // Checks to see if the user lost
        } else if(stoi(hangman.getIncorrectLetters()) >= 10) {
            // fills in values into labels
            ui->lbGameOver->setText("You Lose");
            ui->lbGameOver->setStyleSheet("background-color: rgb(231, 229, 240); font: 28pt 'MS Shell Dlg 2'; qproperty-alignment: AlignCenter; blue; border: 2px solid black; border-radius: 3px;");
            // Goes to the game over screen
            ui->stackedWidget->setCurrentIndex(4);
        }
    }
}

// Gits a hint
void MainWindow::on_btGetHint_clicked()
{
    ui->lbhint->setText(QString::fromStdString(hangman.getHint()));

}

// goes back to the main menu
void MainWindow::on_bnBackToMain3_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// goes to a new game
void MainWindow::on_bnNewGame_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

// exits the game
void MainWindow::on_bnExit_clicked()
{
    QCoreApplication::quit();
}

void MainWindow::on_actionMain_menu_triggered()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_actionHangman_triggered()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_actionHighscore_triggered()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_actionExit_triggered()
{
    QCoreApplication::quit();
}
// updates the LCD widget on the game window
void MainWindow::PlayTimerSlot() {
    int iVal = ui->lcdPlayTime->intValue();
    iVal++;
    ui->lcdPlayTime->display(iVal);
}
//Calls the function to switch colors with timer of 1 minute
void MainWindow::MyTimerSlot()
{


    if (iValCount1 == 0){
         ui -> Hangman -> setStyleSheet("background-color: rgb(85, 72, 200);");
         iValCount1++;
    }
    else if (iValCount1 == 1){
         ui -> Hangman -> setStyleSheet("background-color: rgb(85, 143, 205);");
         iValCount1++;
    }
    else{
         ui -> Hangman -> setStyleSheet("background-color: rgb(110, 72, 237);");
         iValCount1 *= 0;
    }


}
//Go to Edit terms page
void MainWindow::on_btnChangeTerms_clicked()
{
        changeterms.show();
        //close();
}

void MainWindow::on_btnOptions_clicked()
{
    options.show();
   // hide();

}
//change background on user demand
void MainWindow::getColors(short int iColor )
{
    if(iColor == 0){
    ui->stackedWidget->setStyleSheet("background-color: rgb(37, 41, 109);");
    }
    else if (iColor == 1){
        ui->stackedWidget->setStyleSheet("background-color: rgb(139,0,139);");
    }
    else if (iColor == 2){
        ui->stackedWidget->setStyleSheet("background-color: rgb(0, 0, 0);");
    }

}
