#ifndef BALL_ON_H
#define BALL_ON_H
#include<QGraphicsItem>
#include<QObject>
#include <QThread>
#include <QTimer>
#include<QList>

class ball_on :public QObject , public QGraphicsPixmapItem
{
    Q_OBJECT

public:
    ball_on();
    int b_size;
    QTimer *timer;
    int am_i_dead=0; //1 means dead

public slots:
    void move();

};
#endif // BALL_ON_H
