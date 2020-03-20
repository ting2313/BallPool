#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include<QGraphicsView>
#include <QLabel>
#include<QKeyEvent>
#include"scene.h"
#include"cast_enemy.h"
#include"cast_user.h"
#include"score.h"
#include"record.h"
#include"magic.h"
#include"text.h"

extern Score *score;
extern Magic *MP;
extern Text *text;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    Scene *scene;
    Record *record;
    cast_enemy * cast_nen[3];
    cast_user * cast_us[3];
    void init();    //initialize b_user
    void init_cast();
    void keyPressEvent(QKeyEvent *event);
    int win_count[2]={0};   //[0] for user
    int game_finish[3]={0};  //[]for each bridge,1 means finish
    QTimer * enetime;

public slots:
    void putball();
    void check();
    void endgame();
    void remind_magic();

private:
    Ui::MainWindow *ui;
    ball * b_user[5];
    ball_on * b_bridge[3];
    ball_enemy * ball_ene[3];
    int buffer=5;
    int first_ball[3]={0};
    QPixmap highlight;
    QPixmap buf;
    QGraphicsPixmapItem * gameresult;
    int is_the_first_new[3]={0}; //0 means the first
    int flag_teached_digit=0; //0 means the have not
    int flag_teached_en=0;
    int flag_magic=0;
};

#endif // MAINWINDOW_H
