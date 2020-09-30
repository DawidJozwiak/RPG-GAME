#ifndef MERCHANT_H
#define MERCHANT_H
#include "player.h"
#include <QMainWindow>
#include "text.h"
#include "QLabel"
namespace Ui {
class Merchant;
}

class Merchant : public QMainWindow{
    Q_OBJECT

public:
    explicit Merchant(QWidget *parent = nullptr);
    ~Merchant();
    Text * gol;
    QLabel *label;
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Merchant *ui;
};

#endif // MERCHANT_H
