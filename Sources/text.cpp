#include "text.h"
#include "QFont"

Text::Text(QGraphicsItem *parent){
   setPlainText("");
   setFont(QFont("Helvetica",18));
}

void Text::Update(QString stri){
    setPlainText(stri);
}


void Text::Variables(int value, bool stat){
    if(stat == 0){
        if(value > 0){
           setPlainText("Health: " + QString::number(value));
        }
        else
            setPlainText("Health: 0");
    }
    if(stat == 1){
        if(value > 0){
        setPlainText("Health: " + QString::number(value) + "\n  Stunned");
     }
     else
         setPlainText("Health: 0\n  Stunned");
    }
 }

template< class Text > void MainWindow( Text& a) {
    setPlainText(a);
 }

template< class Text > void Forest( Text& a) {
    setPlainText(a);
 }

template< class Text > void City( Text& a) {
    setPlainText(a);
 }

void Text::Gold(int value){
    setPlainText("Gold: " + QString::number(value));
}

