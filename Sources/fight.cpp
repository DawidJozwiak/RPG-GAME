#include "fight.h"
#include <QDebug>
#include <QCoreApplication>
#include "city.h"
#include "exceptions.h"
Fight::Fight()
{
      scene = new QGraphicsScene();
      scene->setSceneRect(0,0,1200,675);

        try {
           QImage *img = new QImage(":/images/Forest-2.png");
            if(img->isNull())
             throw ReadFail();
            }
        catch (ReadFail &ex) {
          qCritical() << ex.what();
            }

      setBackgroundBrush(QBrush(QImage(":/images/Forest-2.png")));     
      setScene(scene);
      txt = new Text();
      vw = new Text();
      vm = new Text();
      vr = new Text();
      vg = new Text();
      vd = new Text();
      vg2 = new Text();
      txt->setPos(250, 25);
      vw->setPos(250, 270);
      vd->setPos(865, 260);
      vr->setPos(27, 270);
      vm->setPos(140, 270);
      vg->setPos(740, 340);
      vg2->setPos(1015, 340);
      scene->addItem(txt);
      scene->addItem(vw);
      scene->addItem(vm);
      scene->addItem(vr);
      scene->addItem(vg);
      scene->addItem(vd);
      scene->addItem(vg2);
}

void Fight::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(3);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void Fight::Back(){
    hide();
    City * c = new City;
    c->show();
}

int Fight::Value(){
    value = 2;
    return value;
}

int Fight::value = 1;



