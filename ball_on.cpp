#include"ball_on.h"
#include"ball_enemy.h"
#include<ctime>
#include<stdlib.h>
#include<QGraphicsScene>
#include<QtGlobal>
#include<QTimer>
#include<QWaitCondition>
#include<QList>
#include<QDebug>

ball_on::ball_on():QObject(),QGraphicsPixmapItem()
{
    timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);
}

void ball_on::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(ball_enemy)) {
            int h=b_size;
            b_size--;
            if(b_size==0){
                am_i_dead=1;
                timer->stop();
                scene()->removeItem(this);
                return ;
            }
            QPixmap smaller;
            smaller.load(":/img/ball_Y.png");
            smaller=smaller.scaled(114*(b_size)/4,114*(b_size)/4);
            this->setPixmap(smaller);
            float moving=20/(b_size);
            setPos(x()-moving/b_size,y()+114*(h-b_size)/4);
        }
    }
    float moving=20/(b_size);
    if(x()>160)setPos(x()-moving,y());
    if(x()<=160){
        int h=b_size;
        b_size--;
        if(b_size==0){
            am_i_dead=1;
            timer->stop();
            scene()->removeItem(this);
            return ;
        }
        QPixmap smaller_c;
        smaller_c.load(":/img/ball_Y.png");
        smaller_c=smaller_c.scaled(114*(b_size)/4,114*(b_size)/4);
        this->setPixmap(smaller_c);
        setPos(x()+10*moving,y()+114*(h-b_size)/4);
    }

}

