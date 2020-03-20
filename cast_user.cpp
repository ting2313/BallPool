#include"cast_user.h"
#include"ball_enemy.h"
#include"mainwindow.h"
#include<QGraphicsScene>

extern Score *score;
extern Text *text;

cast_user::cast_user()
{
    hp=1;

    QTimer *timer= new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(hurt()));
    timer->start(50);
}

void cast_user::hurt()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for (int i = 0, n = colliding_items.size(); i < n; ++i) {
        if (typeid(*(colliding_items[i])) == typeid(ball_enemy)) {
            if(hp>0){
                hp--;
                text->protect();
                score->cost(50);
            }
            if(hp<=0){
                return ;
            }
        }
    }
}
