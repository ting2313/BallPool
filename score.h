#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>

class Score :public QGraphicsTextItem{
public:
    Score();
    void add(int value);
    void cost(int value);
    int score;
};

#endif // SCORE_H
