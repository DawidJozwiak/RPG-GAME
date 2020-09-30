#include "charactercreation.h"
#include "ui_charactercreation.h"
#include "city.h"
#include "player.h"

CharacterCreation::CharacterCreation(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CharacterCreation)
{
    ui->setupUi(this);
}

CharacterCreation::~CharacterCreation()
{
    delete ui;
}

void CharacterCreation::on_pushButton_clicked()
{
    hide();
    City *c = new City;
    c->setAttribute(Qt::WA_DeleteOnClose);
    c->show();


}


