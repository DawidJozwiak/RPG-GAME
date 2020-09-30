#ifndef TAVERN_H
#define TAVERN_H
#include <QApplication>
#include <QMainWindow>
#include <QHBoxLayout>
#include "controls.h"
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <stack>
#include <iostream>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QLabel>
#include <ctime>
#include <QMainWindow>
#include "guess.h"

namespace Ui {
class Tavern;
}

class Tavern : public QMainWindow
{
    Q_OBJECT

public:
    explicit Tavern(QWidget *parent = nullptr);
    ~Tavern();
    static int num;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::Tavern *ui;
};

#endif // TAVERN_H
