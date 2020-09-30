#include <controls.h>
#include "fight.h"


void Controls::buttonClick(QAbstractButton* but )
{

   for(int i=0 ; i<5 ; i++){
       for(int j=0 ; j<6 ; j++){
           if(but==arr[i][j])
           {
               if(prevId1 == i && prevId2 == j){
                   break;
               }
               if(!clicked){
               but->setText(st[i][j]);
               clicked = !clicked ;
               prev = st[i][j];
               prevId1 = i ;
               prevId2 = j ;
               }
               else{
                   clicked = !clicked ;
                   if(prev.compare(st[i][j]) == 0 ){
                      if(playerId == 1){
                           player1Score++;
                       }
                       else{
                           player2Score++;
                       }
                       but->setText("");
                       but->setEnabled(false);
                       arr[prevId1][prevId2]->setEnabled(false);
                        arr[prevId1][prevId2]->setText("");
                   }
                   else{
                       if(playerId==1){
                           playerId = 2;
                           size_t now = time(NULL);
                           player1Time +=  (int) (now - timeKeeper);
                           timeKeeper = time(NULL);

                       }
                       else {
                           playerId = 1 ;
                           size_t now = time(NULL);
                           player2Time +=  (int) (now - timeKeeper);
                           timeKeeper = time(NULL);
                       }

                       but->setText(st[i][j]);
                       QApplication::processEvents();
                       Fight * fight = new Fight();
                       fight ->delay();
                     //  usleep(500000);
                       but->setText("?");
                       if(prevId1 != -1 && prevId2 != -1)
                            arr[prevId1][prevId2]->setText("?");
                       prev = " ";

                   }
                    prevId1 = -1 ;
                    prevId2 = -1 ;
               }
           }
       }
   }

   table1->setCellWidget(1,1,new QLabel(QString::fromStdString(to_string(player1Score))));
   table1->setCellWidget(1,2,new QLabel(QString::fromStdString(to_string(player2Score))));

   if(playerId == 1){
       table1->item(0, 1)->setBackground(Qt::red);
       table1->item(0, 2)->setBackground(Qt::white);
   }
   else{
       table1->item(0, 2)->setBackground(Qt::red);
       table1->item(0, 1)->setBackground(Qt::white);
   }

   table1->setCellWidget(2,1,new QLabel(QString::fromStdString(to_string(player1Time))));
   table1->setCellWidget(2,2,new QLabel(QString::fromStdString(to_string(player2Time))));

   if((player1Score + player2Score) == 15){
       QMessageBox::information((QWidget *)this->parent(),"Game Over","Game Over");
       Player pl;
       pl.gold -= 50;
       Tavern *t = new Tavern();
       t->show();
   }

}

QPushButton *Controls::arr[5][6] ;
bool Controls::clicked = false ;
int Controls::prevId1 = -1;
int Controls::prevId2 = -1;
QString Controls::st[5][6];
QString Controls::prev = "";
vector<QPushButton *> Controls::butVec ;
int Controls::playerId = 1 ;
int Controls::player1Score = 0 ;
int Controls::player2Score = 0 ;
QPushButton * Controls::prevResults ;
QPushButton * Controls::nextResults ;
QTableWidget * Controls::table1 ;
size_t Controls::timeKeeper = 0 ;
int Controls::player1Time = 0 ;
int Controls::player2Time= 0 ;
int Controls::gameNumber = 1 ;
bool Controls::gameOverFlag = false ;
