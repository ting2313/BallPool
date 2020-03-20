#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include<QKeyEvent>
#include"ball.h"
#include"ball_on.h"
#include"ball_enemy.h"

 class Scene :public QGraphicsScene
 {
public:
     void init(); //includes music,the balls on the ground,
 };

#endif // SCENE_H
