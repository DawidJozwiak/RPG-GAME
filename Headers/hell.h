#ifndef HELL_H
#define HELL_H

#include <QMainWindow>
#include "QLabel"
namespace Ui {
class Hell;
}

class Hell : public QMainWindow
{
    Q_OBJECT

public:
    explicit Hell(QWidget *parent = nullptr);
    ~Hell();
    QLabel * label;

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Hell *ui;
};

#endif // HELL_H
