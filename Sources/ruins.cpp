#include "ruins.h"
#include "ui_ruins.h"
#include "city.h"
#include "fight_handler.h"

Ruins::Ruins(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Ruins)
{
    ui->setupUi(this);
    label = new QLabel(this);
    label->setText("You and your companions traveled to long lost elven ruins to find its treasure.\n"
                   "After fighting lots of spiders and undead spirit, you thought that it's gone\n"
                   "In the main hall you've encountered old keeper defending chest with gold.\n"
                   "Are you brave enough to confront him?");
    label->setGeometry(240, -160, 1000, 500);
    label->setStyleSheet("QLabel { background : transparent; color : white;font: bold;font-size: 17px; }");
}

Ruins::~Ruins()
{
    delete ui;
}

void Ruins::on_pushButton_3_clicked()
{
    hide();
    City * city = new City();
    city->show();
}

void Ruins::on_pushButton_4_clicked()
{
    hide();
    FightHandlerRuins();
}
