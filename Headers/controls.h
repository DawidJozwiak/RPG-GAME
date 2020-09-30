#ifndef CONTROLS_H
#define CONTROLS_H
#include <QButtonGroup>
#include <QPushButton>
#include <QMessageBox>
#include <string>
#include <QString>
#include <unistd.h>
#include <QApplication>
#include <QTableWidget>
#include <QLabel>
#include <ctime>
#include <random>
#include <QWidget>
#include <time.h>
#include <iostream>
#include "player.h"
#include "tavern.h"

using namespace std;

class Controls: public QButtonGroup
{
  Q_OBJECT
  public:
    static QPushButton * arr[5][6];
    static QString st[5][6];
    static vector<QPushButton *> butVec ;
    static QString prev ;
    static int prevId1, prevId2 ;
    static bool clicked ;
    static int playerId ;
    static int player1Score ;
    static int player2Score ;
    static QTableWidget * table1 ;
    static QPushButton * prevResults ;
    static QPushButton * nextResults ;
    static size_t timeKeeper ;
    static int player1Time ;
    static int player2Time ;
    static int gameNumber;
    static QWidget * _parent;
    static bool gameOverFlag ;


    Controls(QWidget* parent)
    {
      this->setParent(parent);
      connect(this , SIGNAL(buttonClicked(QAbstractButton*)),this,SLOT(buttonClick(QAbstractButton*)));

    };
    ~ Controls(){};


  public slots:

    void buttonClick(QAbstractButton* but);

};

#endif // CONTROLS_H
