#ifndef MEMORY_H
#define MEMORY_H

#include <QMainWindow>

namespace Ui {
class Memory;
}

class Memory : public QMainWindow
{
    Q_OBJECT

public:
    explicit Memory(QWidget *parent = nullptr);
    ~Memory();

private:
    Ui::Memory *ui;
};

#endif // MEMORY_H
