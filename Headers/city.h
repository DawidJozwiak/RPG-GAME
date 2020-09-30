#ifndef CITY_H
#define CITY_H

#include <QMainWindow>
#include "ally.h"
#include "enemy.h"
#include "text.h"
#include "mainwindow.h"
#include "QLabel"
#include <list>
#include "hell.h"

namespace Ui {
class City;
}

class City : public QMainWindow
{
    Q_OBJECT

public:
    explicit City(QWidget *parent = nullptr);
    ~City();
    Text * g;
    QLabel * label;


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

private:
    Ui::City *ui;
};

#endif // CITY_H
