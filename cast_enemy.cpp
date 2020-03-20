#include"cast_enemy.h"
#include"ball_on.h"
#include"mainwindow.h"
#include<QList>
#include<QGraphicsScene>

extern Score *score;

cast_enemy::cast_enemy()
{
    hp=1;

    QTimer *timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(hurt()));
    timer->start(50);
}

void cast_enemy::hurt()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(ball_on)) {
            if(hp>0){
                hp--;
                score->add(50);
            }
            if(hp<=0){
                return ;
            }
        }
    }
}
