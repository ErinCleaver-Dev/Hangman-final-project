#include "options.h"
#include "ui_options.h"
#include "../assingment7-master/mainwindow/mainwindow.h"

Options::Options(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Options)

{
    ui->setupUi(this);


}

Options::~Options()
{
    delete ui;
}
//close this form
void Options::on_btnMainMenu_clicked()
{
    //MainWindow *mainWindow = new MainWindow();
       // mainWindow->show();
        close();
}
//alert the window form to change background
void Options::on_btnChangeBackground_clicked()
{


        short int iColor;

    if(ui->radBlue->isChecked()){
        iColor = 0;
       emit getTheColor(iColor);
         qDebug() << iColor;

    }
    else if (ui->radPurple->isChecked()){
        iColor = 1;
        emit getTheColor(iColor);
        qDebug() << iColor;

    }
    else if (ui->radBlack->isChecked()){
        iColor =2;
         emit getTheColor(iColor);
        qDebug() << iColor;
    }
}
