#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<stdlib.h>
#include<QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //setting background
    scene = new Scene();
    QImage bg;
    bg.load(":/img/bg.png");
    scene->setBackgroundBrush(bg);
    ui->bg->setScene(scene);
    ui->bg->resize( 1299, 770 );
    scene->setSceneRect(0,0,1300,770);

    int i;
    for(i=0;i<3;i++){
        cast_nen[i] = new cast_enemy();
        cast_us[i] = new cast_user();
        scene->addItem(cast_us[i]);
        scene->addItem(cast_us[i]);
    }

    highlight.load(":/img/ball_O.png");
    buf.load(":/img/ball_Y.png");
    init();
    init_cast();

    gameresult=new QGraphicsPixmapItem;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    int i;
    for(i=0;i<5;i++){
        b_user[i]  = new ball;
        scene->addItem(b_user[i]);
        QPixmap first;
        first.load(":/img/ball_Y.png");
        first=first.scaled(114*(b_user[i]->b_size)/4,114*(b_user[i]->b_size)/4);
        b_user[i]->setPixmap(first);
        b_user[i]->setPos((1060-165*i+(144-first.width())),729-first.height());
    }

    QTimer * enetime=new QTimer;
    connect(enetime,SIGNAL(timeout()),this,SLOT(putball()));
    enetime->start(1500);

    score = new Score;
    scene->addItem(score);
    record = new Record;
    scene->addItem(record);
    MP = new Magic;
    scene->addItem(MP);
    text = new Text;
    text->draw();
    scene->addItem(text);

}

void MainWindow::init_cast()
{
    int i;
    for(i=0;i<3;++i){
        scene->addItem(cast_nen[i]);
        scene->addItem(cast_us[i]);
    }

    QPixmap cast;
    cast.load(":/img/sticker/e_0.png");
    cast_nen[0]->setPixmap(cast);
    cast_nen[0]->setPos(3,89);

    cast.load(":/img/sticker/e_1.png");
    cast_nen[1]->setPixmap(cast);
    cast_nen[1]->setPos(3,229);

    cast.load(":/img/sticker/e_2.png");
    cast_nen[2]->setPixmap(cast);
    cast_nen[2]->setPos(3,425);

    cast.load(":/img/sticker/u_0.png");
    cast_us[0]->setPixmap(cast);
    cast_us[0]->setPos(1137,93);

    cast.load(":/img/sticker/u_1.png");
    cast_us[1]->setPixmap(cast);
    cast_us[1]->setPos(1137,230);

    cast.load(":/img/sticker/u_2.png");
    cast_us[2]->setPixmap(cast);
    cast_us[2]->setPos(1137,424);

    QTimer * timer =new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(check()));
    connect(timer,SIGNAL(timeout()),this,SLOT(endgame()));
    timer->start(50);

    QTimer * checking = new QTimer;
    connect(timer,SIGNAL(timeout()),this,SLOT(remind_magic()));
    timer->start(500);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{    
    if((event->key()==Qt::Key_1)||(event->key()==Qt::Key_2)||(event->key()==Qt::Key_3)||(event->key()==Qt::Key_4)||(event->key()==Qt::Key_5)){
        if(flag_teached_digit==0){
            flag_teached_digit=1;
            text->out();
        }
        if(buffer!=5){
            buf=buf.scaled(114*(b_user[buffer]->b_size)/4,114*(b_user[buffer]->b_size)/4);
            b_user[buffer]->setPixmap(buf);
        }
        switch (event->key()) {
            case Qt::Key_1:
                highlight=highlight.scaled(114*(b_user[4]->b_size)/4,114*(b_user[4]->b_size)/4);
                b_user[4]->setPixmap(highlight);
                buffer=4;
                break;
            case Qt::Key_2:
                highlight=highlight.scaled(114*(b_user[3]->b_size)/4,114*(b_user[3]->b_size)/4);
                b_user[3]->setPixmap(highlight);
                buffer=3;
                break;
            case Qt::Key_3:
                highlight=highlight.scaled(114*(b_user[2]->b_size)/4,114*(b_user[2]->b_size)/4);
                b_user[2]->setPixmap(highlight);
                buffer=2;
                break;
            case Qt::Key_4:
                highlight=highlight.scaled(114*(b_user[1]->b_size)/4,114*(b_user[1]->b_size)/4);
                b_user[1]->setPixmap(highlight);
                buffer=1;
                break;
            case Qt::Key_5:
                highlight=highlight.scaled(114*(b_user[0]->b_size)/4,114*(b_user[0]->b_size)/4);
                b_user[0]->setPixmap(highlight);
                buffer=0;
                break;
            default:
                break;
        }
    }
    else if((event->key()==Qt::Key_A)||(event->key()==Qt::Key_S)||(event->key()==Qt::Key_D)){
        if(flag_teached_en==0){
            flag_teached_en=1;
            text->clean();
        }
        if (buffer!=5){
            switch (event->key()) {
            case Qt::Key_A:
                    if((is_the_first_new[0]==0)){
                        is_the_first_new[0]=1;
                        b_bridge[0]=new ball_on;
                        score->cost(b_user[buffer]->b_size);
                        b_bridge[0]->b_size=b_user[buffer]->b_size;
                        scene->addItem(b_bridge[0]);
                        buf=buf.scaled(114*(b_user[buffer]->b_size)/4,114*(b_user[buffer]->b_size)/4);
                        b_bridge[0]->setPixmap(buf);
                        b_bridge[0]->setPos(1140-buf.width(),182-buf.height());
                    }
                    else if((b_bridge[0]->am_i_dead)==1){
                        delete b_bridge[0];
                        b_bridge[0]=new ball_on;
                        score->cost(b_user[buffer]->b_size);
                        scene->addItem(b_bridge[0]);
                       b_bridge[0]->b_size=b_user[buffer]->b_size;
                       buf=buf.scaled(114*(b_user[buffer]->b_size)/4,114*(b_user[buffer]->b_size)/4);
                       b_bridge[0]->setPixmap(buf);
                       b_bridge[0]->setPos(1140-buf.width(),182-buf.height());
                       text->clean();
                    }
                    else{
                        text->one();
                    }
                break;
            case Qt::Key_S:
                if((is_the_first_new[1]==0)){
                    is_the_first_new[1]=1;
                    b_bridge[1]=new ball_on;
                    score->cost(b_user[buffer]->b_size);
                    b_bridge[1]->b_size=b_user[buffer]->b_size;
                    scene->addItem(b_bridge[1]);
                    buf=buf.scaled(114*(b_user[buffer]->b_size)/4,114*(b_user[buffer]->b_size)/4);
                    b_bridge[1]->setPixmap(buf);
                    b_bridge[1]->setPos(1140-buf.width(),374-buf.height());
                }
                else if((b_bridge[1]->am_i_dead)==1){
                    delete b_bridge[1];
                    b_bridge[1]=new ball_on;
                    score->cost(b_user[buffer]->b_size);
                    scene->addItem(b_bridge[1]);
                    b_bridge[1]->b_size=b_user[buffer]->b_size;
                    buf=buf.scaled(114*(b_user[buffer]->b_size)/4,114*(b_user[buffer]->b_size)/4);
                    b_bridge[1]->setPixmap(buf);
                    b_bridge[1]->setPos(1140-buf.width(),374-buf.height());
                    text->clean();
                }
                else{
                    text->one();
                }
                break;
            case Qt::Key_D:
                if((is_the_first_new[2]==0)){
                    is_the_first_new[2]=1;
                    b_bridge[2]=new ball_on;
                    score->cost(b_user[buffer]->b_size);
                    b_bridge[2]->b_size=b_user[buffer]->b_size;
                    scene->addItem(b_bridge[2]);
                    buf=buf.scaled(114*(b_user[buffer]->b_size)/4,114*(b_user[buffer]->b_size)/4);
                    b_bridge[2]->setPixmap(buf);
                    b_bridge[2]->setPos(1140-buf.width(),564-buf.height());
                }
                else if((b_bridge[2]->am_i_dead)==1){
                    delete b_bridge[2];
                    b_bridge[2]=new ball_on;
                    score->cost(b_user[buffer]->b_size);
                    scene->addItem(b_bridge[2]);
                    b_bridge[2]->b_size=b_user[buffer]->b_size;
                    buf=buf.scaled(114*(b_user[buffer]->b_size)/4,114*(b_user[buffer]->b_size)/4);
                    b_bridge[2]->setPixmap(buf);
                    b_bridge[2]->setPos(1140-buf.width(),564-buf.height());
                    text->clean();
                }
                else{
                    text->one();
                }
                break;
            default:
                break;
            }
            scene->removeItem(b_user[buffer]);
            b_user[buffer]->iniz();
            QPixmap first;
            first.load(":/img/ball_Y.png");
            first=first.scaled(114*(b_user[buffer]->b_size)/4,114*(b_user[buffer]->b_size)/4);
            b_user[buffer]->setPixmap(first);
            b_user[buffer]->setPos((1060-165*buffer+(144-first.width())),729-first.height());
            scene->addItem(b_user[buffer]);
            buffer=5;
        }
    }
    if((event->key())==Qt::Key_Space&&((MP->magic)>=10)){
        if(flag_magic==0){
            flag_magic=1;
            text->clean();
        }
        MP->cost();
        QPixmap big;
        big.load(":/img/ball_Y.png");
        if((is_the_first_new[0]==1)&&((b_bridge[0]->am_i_dead)==0)){
            (b_bridge[0]->b_size)=(b_bridge[0]->b_size)+2;
            big=big.scaled(114*(b_bridge[0]->b_size)/4,114*(b_bridge[0]->b_size)/4);
            b_bridge[0]->setPixmap(big);
            b_bridge[0]->setPos(b_bridge[0]->x(),182-big.height());
            scene->addItem(b_bridge[0]);
        }
        if((is_the_first_new[1]==1)&&((b_bridge[1]->am_i_dead)==0)){
            (b_bridge[1]->b_size)=(b_bridge[1]->b_size)+2;
            big=big.scaled(114*(b_bridge[1]->b_size)/4,114*(b_bridge[1]->b_size)/4);
            b_bridge[1]->setPixmap(big);
            b_bridge[1]->setPos(b_bridge[1]->x(),374-big.height());
        }
        if((is_the_first_new[2]==1)&&((b_bridge[2]->am_i_dead)==0)){
                (b_bridge[2]->b_size)=(b_bridge[2]->b_size)+2;
                big=big.scaled(114*(b_bridge[2]->b_size)/4,114*(b_bridge[2]->b_size)/4);
                b_bridge[2]->setPixmap(big);
                b_bridge[2]->setPos(b_bridge[2]->x(),564-big.height());
        }
    }
}

void MainWindow::putball()
{
    int i;
    i=rand()%3;
    QPixmap first;
    first.load(":/img/ball_P.png");
    if(win_count[0]!=2&&win_count[1]!=2){
        switch (i) {
        case 0:
            if(game_finish[0]==0){
                ball_ene[0]  = new ball_enemy;
                scene->addItem(ball_ene[0]);
                first=first.scaled(114*(ball_ene[0]->b_size)/4,114*(ball_ene[0]->b_size)/4);
                ball_ene[0]->setPixmap(first);
                ball_ene[0]->setPos(160,182-first.height());
            }
            break;
        case 1:
            if(game_finish[1]==0){
                ball_ene[1]  = new ball_enemy;
                scene->addItem(ball_ene[1]);
                first=first.scaled(114*(ball_ene[1]->b_size)/4,114*(ball_ene[1]->b_size)/4);
                ball_ene[1]->setPixmap(first);
                ball_ene[1]->setPos(160,374-first.height());
            }
            break;
        case 2:
            if(game_finish[2]==0){
                ball_ene[2]  = new ball_enemy;
                scene->addItem(ball_ene[2]);
                first=first.scaled(114*(ball_ene[2]->b_size)/4,114*(ball_ene[2]->b_size)/4);
                ball_ene[2]->setPixmap(first);
                ball_ene[2]->setPos(160,564-first.height());
            }
            break;
        default:
            break;
        }
    }
}

void MainWindow::check()
{
    QPixmap dis;
    if(game_finish[0]==0){
        if((cast_nen[0]->hp)<=0){
            dis.load(":/img/sticker/e_0_dis.png");
            cast_nen[0]->setPixmap(dis);
            cast_nen[0]->setPos(0,89);
            ++win_count[0];
            game_finish[0]=1;
        }
        if((cast_us[0]->hp)==0){
            dis.load(":/img/sticker/u_0_dis.png");
            cast_us[0]->setPixmap(dis);
            cast_us[0]->setPos(1138,93);
            ++win_count[1];
            game_finish[0]=1;
        }
    }
    if(game_finish[1]==0){
        if((cast_nen[1]->hp)==0){
            dis.load(":/img/sticker/e_1_dis.png");
            cast_nen[1]->setPixmap(dis);
            cast_nen[1]->setPos(0,229);
            ++win_count[0];
            game_finish[1]=1;
        }
        if((cast_us[1]->hp)==0){
            dis.load(":/img/sticker/u_1_dis.png");
            cast_us[1]->setPixmap(dis);
            cast_us[1]->setPos(1138,230);
            ++win_count[1];
            game_finish[1]=1;
        }
    }
    if(game_finish[2]==0){
        if((cast_nen[2]->hp)==0){
            dis.load(":/img/sticker/e_2_dis.png");
            cast_nen[2]->setPixmap(dis);
            cast_nen[2]->setPos(0,425);
            ++win_count[0];
            game_finish[2]=1;
        }
    if((cast_us[2]->hp)==0){
            dis.load(":/img/sticker/u_2_dis.png");
            cast_us[2]->setPixmap(dis);
            cast_us[2]->setPos(1138,424);
            ++win_count[1];
            game_finish[2]=1;
        }
    }
}

void MainWindow::endgame()
{
    if(win_count[0]!=2&&win_count[1]!=2) return;
    if(win_count[0]==2){
        QPixmap finally;
        finally.load(":/img/YouWin.png");
        record->upload(score->score);
        scene->addItem(gameresult);
        gameresult->setPixmap(finally);
        gameresult->setPos(60,0);
    }
    if(win_count[1]==2){
        QPixmap finally;
        finally.load(":/img/Gameover.png");
        scene->addItem(gameresult);
        gameresult->setPixmap(finally);
        gameresult->setPos(60,0);
    }
}

void MainWindow::remind_magic()
{
    if((MP->magic)>=10 && flag_magic==0)
        text->magic();
}
