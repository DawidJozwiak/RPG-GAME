#ifndef TEXT_H
#define TEXT_H
#include <QGraphicsTextItem>

class Text : public QGraphicsTextItem
{
public:
    Text(QGraphicsItem *parent = 0);
    void Update(QString stri);
    void Variables(int value, bool stat);
    void Gold(int value);
    template< class Text > void MainWindow( Text& a);
    template< class Text > void Forest( Text& a);
    template< class Text > void City( Text& a);
};

#endif // TEXT_H
