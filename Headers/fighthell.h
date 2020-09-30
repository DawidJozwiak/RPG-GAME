#ifndef FIGHTHELL_H
#define FIGHTHELL_H
#include "QGraphicsScene"
#include "QGraphicsView"
#include "QWidget"
#include "text.h"
#include "QKeyEvent"
#include "QtGui"
#include "QPushButton"
#include <QDebug>
#include <QCoreApplication>

class FightHell : public QGraphicsView
{
public:
    FightHell();
    QGraphicsScene *scene;
    Text * ex;
    Text * txt;
    Text * vw;
    Text * vm;
    Text * vr;
    Text * vg;
    Text * vd;
    Text * vg2;
    void delay();
    void Back();
};

#endif // FIGHTHELL_H
