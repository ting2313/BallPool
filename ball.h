#ifndef BALL_H
#define BALL_H
#include<QGraphicsItem>
#include<QObject>

class ball :public QObject , public QGraphicsPixmapItem
{

public:
    ball();
    void iniz();
    int b_size;

};
        
#endif // BALL_H
