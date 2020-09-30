#ifndef FIGHT_H
#define FIGHT_H
#include "QGraphicsScene"
#include "QGraphicsView"
#include "QWidget"
#include "text.h"
#include "QKeyEvent"
#include "QtGui"
#include "QPushButton"

class Fight : public QGraphicsView
{
public:
    Fight();
    QGraphicsScene *scene;
    Text * ex;
    Text * txt;
    Text * vw;
    Text * vm;
    Text * vr;
    Text * vg;
    Text * vd;
    Text * vg2;
    static int value;
    void delay();
    void Back();
public slots:
    int Value();

};

#endif // FIGHT_H
