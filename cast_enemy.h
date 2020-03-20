#ifndef CAST_ENEMY_H
#define CAST_ENEMY_H
#include<QObject>
#include<QGraphicsPixmapItem>

class cast_enemy :public QObject,public QGraphicsPixmapItem
{   Q_OBJECT
public:
    cast_enemy();
    int hp;

public slots:
    void hurt();
};

#endif // CAST_ENEMY_H
