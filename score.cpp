#include "score.h"
#include<QFont>

Score::Score()
{
    score=0;

    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor((Qt::black));
    setFont(QFont("Calligraph421 BT",22));
    setPos(0,678);
}

void Score::add(int value)
{
    for(int i=0;i<value;i++)
        score++;
        setPlainText(QString("Score: ")+QString::number(score));
}

void Score::cost(int value)
{
    for(int i=0;i<value;i++)
        score--;
    setPlainText(QString("Score: ")+QString::number(score));
}
