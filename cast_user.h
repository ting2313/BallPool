#ifndef CASTLES_H
#define CASTLES_H
#include<QObject>
#include<QGraphicsPixmapItem>

class cast_user:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    cast_user();
    int hp;
public slots:
    void hurt();
};

#endif // CASTLES_H
