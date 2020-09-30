#include "memory.h"
#include "ui_memory.h"

Memory::Memory(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Memory)
{
    ui->setupUi(this);
}

Memory::~Memory()
{
    delete ui;
}
