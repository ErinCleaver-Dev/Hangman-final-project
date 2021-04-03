#include "changeterms.h"
#include "ui_changeterms.h"
#include "../assingment7-master/mainwindow/mainwindow.h"
#include <QMessageBox>

ChangeTerms::ChangeTerms(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ChangeTerms)
{
    ui->setupUi(this);
    //signal to change lblterms and txtEditword whenever a word in combobox is selected
    connect(ui->comboBoxTerms, SIGNAL(currentIndexChanged(int)),this, SLOT(indexChanged()));
}

ChangeTerms::~ChangeTerms()
{
    delete ui;
}

//Overwrite file of selected difficulty
void ChangeTerms::OverWriteFile(QString fileName){

    QFile file(fileName);
    QString sWord = ui ->txtEditTerms -> text();
    QStringList itemsInComboBox;
    //add items of combobox to list
    for (unsigned short int index = 0; index < ui->comboBoxTerms->count(); index++){
        itemsInComboBox << ui->comboBoxTerms->itemText(index);
}
    //open file and replace file to put the terms in
    if (file.open(QIODevice::ReadWrite |QIODevice::Truncate| QIODevice::Text)){
                    QTextStream out(&file);

            for(unsigned short int i = 0; i < itemsInComboBox.count(); i++){

                  if (itemsInComboBox[i].contains(ui -> lblTerms -> text()))
                    {
                     itemsInComboBox[i] = sWord + "\n";
                      qDebug() << "found you." + itemsInComboBox[i];


                   }
                  out << itemsInComboBox[i];
                  qDebug() << itemsInComboBox[i];
            }

        }
    file.close();
     QMessageBox::information(this,tr("Kudos"), tr("File saved, click Read file to continue changing terms"));

}
//read the selected radio button either easy, medium, and or hard
void ChangeTerms::GetChckedRad(QString fileName){
    QFile file(fileName);
        QString line;

        if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
                QTextStream stream(&file);
                while (!stream.atEnd()){

                line = (stream.readLine()+"\n");

                ui->comboBoxTerms ->addItem(line);

                }

                qDebug() << "File opened.";
            }
            file.close();
           qDebug() << "File Closed.";


}
//change the selected term depending on comboxbox index and put it in label and text
void ChangeTerms::indexChanged(){

    QString value = ui -> comboBoxTerms -> currentText();
       ui -> lblTerms -> setText(value);
       ui -> txtEditTerms -> setText(value);

}

//Access the desired file to call function to read it
void ChangeTerms::on_btnReadFile_clicked()
{
    ui -> comboBoxTerms -> clear();
           if (ui -> radEasy ->isChecked()){
               GetChckedRad("easy.txt");

           }
           else if (ui -> radMedium ->isChecked()){
               GetChckedRad("medium.txt");
           }
           else if(ui -> radHard ->isChecked()){
               GetChckedRad("hard.txt");
           }
}
//Access the right file to call function to overwrite it
void ChangeTerms::on_btnWriteFile_clicked()
{
    if (ui -> radEasy ->isChecked() && !ui -> txtEditTerms ->text().isEmpty()){
              OverWriteFile("easy.txt");

          }
          else if (ui -> radMedium ->isChecked() && !ui -> txtEditTerms ->text().isEmpty()){
              OverWriteFile("medium.txt");
          }
          else if(ui -> radHard ->isChecked() && !ui -> txtEditTerms ->text().isEmpty()){
              OverWriteFile("hard.txt");
          }
          else if (ui -> txtEditTerms ->text().isEmpty()){
              QMessageBox::warning(this,tr("Alert"), tr("Text Field cannot be empty"));


          }

}
//go back to main page
void ChangeTerms::on_btnMainMenu_clicked()
{
   // MainWindow *mainWindow = new MainWindow();
        //mainWindow->show();
        close();

}
