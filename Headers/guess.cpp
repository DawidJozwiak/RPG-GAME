#include "guess.h"
#include "ui_guess.h"
#include "stdlib.h"
#include "tavern.h"
#include "city.h"

Guess::Guess(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Guess)
{
    Tavern t;
    ui->setupUi(this);
    label = new QLabel(this);
    label->setText("Number: " + QString::number(t.num));
    label->setGeometry(500, 200, 300, 300);
    label->setStyleSheet("QLabel { background : transparent; color : white;font: bold;font-size: 36px; }");
}

Guess::~Guess()
{
    delete ui;
}

void Guess::game(){

}


void Guess::on_pushButton_clicked()
{
    fight = new Fight();
    Tavern tavern;
    tavern.num  += rand() % 8 + 1;
    if(tavern.num == 20){
        Player player;
        player.gold += 50;
        label->setText("Number: " + QString::number(tavern.num) + "\nYou won 50 gold!");
        fight ->delay();
        fight ->delay();
        tavern.num = rand() % 7 + 1;
        hide();

    }
    if(tavern.num  > 20){
        Player player;
        player.gold -= 20;
        label->setText("Number: " + QString::number(tavern.num) + + "\nYou lost 20 gold!");
        fight ->delay();
        fight ->delay();
        tavern.num = rand() % 7 + 1;
        hide();

    }
    else{
        label->setText("Number: " + QString::number(tavern.num));
    }
}

void Guess::on_pushButton_2_clicked()
{
    fight = new Fight();
    Tavern tavern;
    tavern.num  += rand() % 7 + 4;
    if(tavern.num  == 20){
        Player player;
        player.gold += 50;
        label->setText("Number: " + QString::number(tavern.num) + "\nYou won 50 gold!");
        fight ->delay();
        fight ->delay();
        tavern.num = rand() % 7 + 1;
        hide();


    }
    if(tavern.num  > 20){
        Player player;
        player.gold -= 20;
        label->setText("Number: " + QString::number(tavern.num) + "\nYou lost 20 gold!");
        fight ->delay();
        fight ->delay();
        tavern.num = rand() % 7 + 1;
        hide();

    }
    else{
        label->setText("Number: " + QString::number(tavern.num));
    }
}


void Guess::on_pushButton_3_clicked()
{
    Tavern tavern;
    tavern.num = rand() % 7 + 1;
    hide();
}
