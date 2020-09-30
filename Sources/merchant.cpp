#include "merchant.h"
#include "ui_merchant.h"
#include "city.h"
#include "player.h"
#include "fight.h"
#include "charactercreation.h"
#include "QLabel"
Merchant::Merchant(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Merchant)
{
    Player pl;
    ui->setupUi(this);
    label = new QLabel(this);
    label->setText("Gold: " + QString::number(pl.gold));
    label->setGeometry(0, -80, 200, 200);
    label->setStyleSheet("QLabel { background : transparent; color : white;font: bold;font-size: 36px; }");


}

Merchant::~Merchant()
{
    delete ui;
}

void Merchant::on_pushButton_clicked()
{
    hide();
    City * c = new City;
    c->show();
}



void Merchant::on_pushButton_2_clicked()
{
    Player player;
    if(player.staff == false){
      if(player.gold >= 3000){
        player.staff = true;
        player.gold = player.gold - 3000;
        label->setText("Gold: " + QString::number(player.gold));
      }
    }
}

void Merchant::on_pushButton_3_clicked()
{
    Player player;
    if(player.sword == false){
      if(player.gold >= 2000){
        player.sword = true;
        player.gold = player.gold - 2000;
        label->setText("Gold: " + QString::number(player.gold));
      }
    }
}

void Merchant::on_pushButton_4_clicked()
{
    Player player;
    if(player.bow == false){
      if(player.gold >= 4000){
        player.bow = true;
        player.gold = player.gold - 4000;
        label->setText("Gold: " + QString::number(player.gold));
       }
    }
}
