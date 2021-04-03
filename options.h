#ifndef OPTIONS_H
#define OPTIONS_H

#include <QWidget>

namespace Ui {
class Options;
}

class Options : public QWidget
{
    Q_OBJECT

public:
    explicit Options(QWidget *parent = nullptr);
    ~Options();
signals:
    void getTheColor(short int);

private slots:
    void on_btnMainMenu_clicked();

    void on_btnChangeBackground_clicked();

private:
    Ui::Options *ui;
};

#endif // OPTIONS_H
