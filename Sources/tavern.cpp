#include "tavern.h"
#include "ui_tavern.h"
#include "memory.h"
#include "controls.h"
#include "city.h"

Tavern::Tavern(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Tavern)
{
    ui->setupUi(this);
}

Tavern::~Tavern()
{
    delete ui;
}

void Tavern::on_pushButton_clicked()
{
        Memory * window = new Memory();

        window->setWindowTitle(QString::fromUtf8("Memory Game"));
        window->resize(1200, 675);

        QWidget *centralWidget = new QWidget(window);

    vector<QString> wordsVec = {"std::unique_ptr","std::sharder_ptr","thread","template","memory","vector","list","STL Container","STL Iterator",
                                 "mutex","atomic","try","catch","throw","std::cout","std::cout","std::unique_ptr","std::sharder_ptr","thread","template","memory","throw","vector","list",
                               "STL Container","STL Iterator","mutex","atomic","try","catch"};

    srand(time(NULL));



    stack<QString> wordsStack ;
    Controls* group = new Controls(centralWidget);
    int size  = wordsVec.size();
    for(int i= 0 ; i<size ; i++){
        int index = rand()%size;
        wordsStack.push(wordsVec[index]);
        wordsVec.erase(wordsVec.begin() + index);
        i=-1 ;
        size-- ;
    }


    QTableWidget *table = new QTableWidget();
    Controls::table1 = table ;
    QTableWidgetItem *tableItem ;
    table->verticalHeader()->setVisible(false);
    table->horizontalHeader()->setVisible(false);
    table->horizontalHeader()->setDefaultSectionSize(200);
    table->verticalHeader()->setDefaultSectionSize(50);
        table->setRowCount(9);
        table->setColumnCount(6);

        table->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

        for (int i = 0; i < 3; ++i) {
            tableItem= new QTableWidgetItem();
            table->setItem(i,5,tableItem);
        }

        Controls::timeKeeper = time(NULL);



        QLabel *score=new QLabel("Score");
        QLabel *time=new QLabel("Time(secs)");
        QLabel *player1=new QLabel("Player1");

        QLabel *gameNo=new QLabel("Game no: "+ QString::number(Controls::gameNumber));


        for (int i = 0; i < 2; ++i) {
            tableItem= new QTableWidgetItem();
           table->setItem(i+1,0,tableItem);
           tableItem= new QTableWidgetItem();
           table->setItem(0,i+1,tableItem);
        }

        table->setCellWidget(1,0,score);
        table->setCellWidget(2,0,time);
        table->setCellWidget(0,1,player1);

        table->setCellWidget(0,4,gameNo);

    for(int i=0 ; i<5 ; i++){
        for(int j=0 ; j<6 ; j++){
            QPushButton * buttonX = new QPushButton("?",centralWidget);
            tableItem= new QTableWidgetItem();

            Controls::st[i][j] = wordsStack.top(); //
            wordsStack.pop();

            Controls::arr[i][j] = buttonX ;


            table->setItem(i+4,j,tableItem);
            table->setCellWidget(i+4, j, buttonX);
            group->addButton(buttonX);

            if(wordsStack.empty())
                break;

        }
    }

    window->setCentralWidget(table);

    window->show();

}

void Tavern::on_pushButton_2_clicked()
{
    Guess * g = new Guess();
    g->show();
}

int Tavern::num = 0;

void Tavern::on_pushButton_3_clicked()
{
    hide();
    City * city = new City();
    city->show();
}
