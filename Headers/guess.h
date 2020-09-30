#ifndef GUESS_H
#define GUESS_H

#include <QMainWindow>
#include "player.h"
#include "QLabel"
#include "fight.h"
namespace Ui {
class Guess;
}

class Guess : public QMainWindow
{
    Q_OBJECT

public:
    explicit Guess(QWidget *parent = nullptr);
    ~Guess();
    void game();
    static int x;
    Guess *g;
    QString st;
    QLabel *label;
    Fight * fight;

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Guess *ui;
};

#endif // GUESS_H
