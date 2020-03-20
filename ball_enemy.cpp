#include<ball_enemy.h>
#include"ball_on.h"
#include"mainwindow.h"
#include<ctime>
#include<stdlib.h>
#include<QGraphicsScene>
#include<QtGlobal>
#include<QTimer>
#include<QTime>
#include<QWaitCondition>
#include<QList>

extern Score *score;
extern Magic *MP;

ball_enemy::ball_enemy():QObject(),QGraphicsPixmapItem()
{
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    b_size=rand()%4+1;

    QTimer *timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);
}

void ball_enemy::move()
{
    int count=0;
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(ball_on)) {
            int h=b_size;
            b_size--;
            count++;
            if(b_size==0){
                scene()->removeItem(this);
                score->add(count);
                MP->add(count);
                delete this;
                return ;
            }
            QPixmap smaller;
            smaller.load(":/img/ball_P.png");
            smaller=smaller.scaled(114*(b_size)/4,114*(b_size)/4);
            this->setPixmap(smaller);
            float moving=15/(b_size);
            setPos(x()-moving/b_size,y()+114*(h-b_size)/4);
        }
    }
    float moving;
    if (b_size!=0)  moving=15/(b_size);
    if((x()+114*b_size/4)<1140)    setPos(x()+moving,y());
    if((x()+114*b_size/4)>=1140){
        int h=b_size;
        b_size--;
        if(b_size==0){
            am_i_dead=1;
            scene()->removeItem(this);
            delete this;
            return ;
        }
        QPixmap smaller_c;
        smaller_c.load(":/img/ball_P.png");
        smaller_c=smaller_c.scaled(114*(b_size)/4,114*(b_size)/4);
        this->setPixmap(smaller_c);
        setPos(x()+smaller_c.width()-10*moving,y()+114*(h-b_size)/4);
    }
}

