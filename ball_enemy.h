#ifndef BALL_ENEMY_H
#define BALL_ENEMY_H
#include<QGraphicsItem>
#include<QObject>
#include <QThread>
#include <QTimer>
#include<QList>

class ball_enemy :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    ball_enemy();
    int b_size;
    int am_i_dead=0;//1 means dead
public slots:
    void move();
};

#endif // BALL_ENEMY_H
