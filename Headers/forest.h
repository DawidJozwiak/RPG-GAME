#ifndef FOREST_H
#define FOREST_H

#include <QMainWindow>
#include "fight_handler.h"

namespace Ui {
class Forest;
}

class Forest : public QMainWindow
{
    Q_OBJECT

public:
    explicit Forest(QWidget *parent = nullptr);
    ~Forest();


public slots:
   void UpdateLabel(const QString text);

private slots:
   void on_pushButton_clicked();

   void on_pushButton_2_clicked();

private:
    Ui::Forest *ui;

};

#endif // FOREST_H
