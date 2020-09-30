#include "hell.h"
#include "ui_hell.h"
#include "city.h"
#include "fight_handler.h"

Hell::Hell(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Hell)
{
    ui->setupUi(this);
    label = new QLabel(this);
    label->setText("Entering through portal, weird energy draws you and your team into a flame land\n"
                   "After long walk through seas of lava, piles of magma and running from dragons\n"
                   "You've encountered enemies sleeping on pile of gold.\n"
                   "Are you brave enough to try reach it?");
    label->setGeometry(240, -160, 1000, 500);
    label->setStyleSheet("QLabel { background : transparent; color : white;font: bold;font-size: 17px; }");
}

Hell::~Hell()
{
    delete ui;
}

void Hell::on_pushButton_3_clicked()
{
    hide();
    City *c = new City();
    c->show();
}

void Hell::on_pushButton_4_clicked()
{
    hide();
    FightHellHandler();
}
