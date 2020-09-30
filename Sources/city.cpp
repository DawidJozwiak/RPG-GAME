#include "city.h"
#include "ui_City.h"
#include "forest.h"
#include "merchant.h"
#include <QLabel>
#include "player.h"
#include "charactercreation.h"
#include <list>
#include "tavern.h"
#include "ruins.h"

City::City(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::City)
{
    Player pl;
    ui->setupUi(this);
    label = new QLabel(this);
    label->setText("Gold: " + QString::number(pl.gold));
    label->setGeometry(500, -80, 200, 200);
    label->setStyleSheet("QLabel { background : transparent; color : white;font: bold;font-size: 36px; }");
}

City::~City()
{
    delete ui;
}

void City::on_pushButton_clicked()
{
    hide();
    Forest *f = new Forest;
    f->setAttribute(Qt::WA_DeleteOnClose);
    f->show();
}

void City::on_pushButton_2_clicked()
{
    hide();
    Merchant * m = new Merchant;
    m->setAttribute(Qt::WA_DeleteOnClose);
    m->show();
}

void City::on_pushButton_4_clicked()
{
    hide();
    MainWindow * mw = new MainWindow;
    mw ->setAttribute(Qt::WA_DeleteOnClose);
    mw->show();
}

void City::on_pushButton_3_clicked()
{

}

void City::on_pushButton_5_clicked()
{
    hide();
    Tavern * t = new Tavern();
    t ->setAttribute(Qt::WA_DeleteOnClose);
    t ->show();
}

void City::on_pushButton_6_clicked()
{
    hide();
    Hell * h = new Hell();
    h ->setAttribute(Qt::WA_DeleteOnClose);
    h ->show();
}

void City::on_pushButton_7_clicked()
{
    hide();
    Ruins * r = new Ruins();
    r ->setAttribute(Qt::WA_DeleteOnClose);
    r ->show();
}
