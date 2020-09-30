#ifndef RUINS_H
#define RUINS_H

#include <QMainWindow>
#include <QLabel>
namespace Ui {
class Ruins;
}

class Ruins : public QMainWindow
{
    Q_OBJECT

public:
    explicit Ruins(QWidget *parent = nullptr);
    ~Ruins();
    QLabel * label;

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Ruins *ui;
};

#endif // RUINS_H
