#include"ball.h"
#include<ctime>
#include<stdlib.h>
#include<QtGlobal>
#include<QTime>

ball::ball(){
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    b_size=rand()%4+1;
}

void ball::iniz(){
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    b_size=rand()%4+1;
}



