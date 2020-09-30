#include "forest.h"
#include "ui_forest.h"
#include "city.h"

Forest::Forest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Forest)
{
    ui->setupUi(this);
}

Forest::~Forest()
{
    delete ui;
}

void Forest::UpdateLabel(const QString text){
    ui->label->setText(text);
}

void Forest::on_pushButton_clicked()
{
    hide();
    fight_handler();
}

void Forest::on_pushButton_2_clicked()
{
    hide();
    City * c = new City;
    c -> show();
}
