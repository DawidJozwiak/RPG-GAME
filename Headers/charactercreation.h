#ifndef CHARACTERCREATION_H
#define CHARACTERCREATION_H

#include <QMainWindow>

namespace Ui {
class CharacterCreation;
}

class CharacterCreation : public QMainWindow
{
    Q_OBJECT

public:
    QString wname;
    explicit CharacterCreation(QWidget *parent = nullptr);
    ~CharacterCreation();

public slots:

    void on_pushButton_clicked();

private:
    Ui::CharacterCreation *ui;
};

#endif // CHARACTERCREATION_H
