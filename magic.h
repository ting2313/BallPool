#ifndef MAGIC_H
#define MAGIC_H
#include <QGraphicsTextItem>

class Magic:public QGraphicsTextItem
{
public:
    Magic();
    int magic;
    void add(int value);
    void cost();

};

#endif // MAGIC_H
