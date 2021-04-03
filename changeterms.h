#ifndef CHANGETERMS_H
#define CHANGETERMS_H

#include <QWidget>
#include <QFile>


namespace Ui {
class ChangeTerms;
}

class ChangeTerms : public QWidget
{
    Q_OBJECT

public:
    explicit ChangeTerms(QWidget *parent = nullptr);
    ~ChangeTerms();
private slots:

    void GetChckedRad(QString);

    void indexChanged();

     void OverWriteFile(QString);

     void on_btnReadFile_clicked();

     void on_btnWriteFile_clicked();

     void on_btnMainMenu_clicked();

private:
    Ui::ChangeTerms *ui;



};

#endif // CHANGETERMS_H
