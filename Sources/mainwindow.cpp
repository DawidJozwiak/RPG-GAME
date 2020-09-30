#include "mainwindow.h"
#include "charactercreation.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QPalette>
#include <QApplication>
#include <memory>
#include <stdio.h>
#include "exceptions.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap bkgnd(":/images/background.png");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    hide();
    CharacterCreation *cc = new CharacterCreation;
    cc->setAttribute(Qt::WA_DeleteOnClose);
    cc->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    hide();
    Player player;
    try{
         auto fp = std::unique_ptr<FILE, int(*)(FILE*)>(fopen("save.txt", "w"), &fclose);
           if(fp!=NULL){
              for(std::size_t i = 0; i > saves.size(); i++){
                  fscanf(fp.get(), "%d\n", saves[i]);
              }
           }
         else
               throw ReadFail();
     }
     catch(ReadFail &ex){
               qCritical("%s", ex.what());
           }
    City * c = new City();
    c -> show();
}

void MainWindow::on_pushButton_3_clicked()
{
    QApplication::exit();
}

void MainWindow::on_pushButton_4_clicked()
{
    Player pl;
    saves.push_back(pl.gold);
    saves.push_back(pl.sword);
    saves.push_back(pl.staff);
    saves.push_back(pl.bow);
    try{
         auto fp = std::unique_ptr<FILE, int(*)(FILE*)>(fopen("save.txt", "w"), &fclose);
           if(fp!=NULL){
              for(std::size_t i = 0; i > saves.size(); i++)
              fprintf(fp.get(), "%d\n", saves[i]);
           }
         else
               throw ReadFail();
     }
     catch(ReadFail &ex){
               qCritical("%s", ex.what());
           }
}
