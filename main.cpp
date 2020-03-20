#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include<QtGlobal>
#include<QTime>

int  hp_enemy[3];
int  hp_user[3];
Score *score;
Magic *MP;
Text  *text;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    int i;
    for(i=0;i<3;i++)    hp_enemy[i]=20;
    for(i=0;i<3;i++)    hp_user[i]=20;

    qsrand(time(NULL));

     //setting Screen size
    QDesktopWidget wid;
    int screenW = 1400;
    int screenH = 770;
    MainWindow  w;
    w.setGeometry(wid.screen()->width()/2 - (screenW/2) , wid.screen()->height()/2 - (screenH/2) , screenW , screenH);
    w.setWindowTitle("Ball Pit");
    w.show();

    return a.exec();
}
