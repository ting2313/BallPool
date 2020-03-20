#include"text.h"
#include<QFont>

void Text::clean()
{
    setPlainText(QString("  "));
    setDefaultTextColor((Qt::black));
    setFont(QFont("Calligraph421 BT",22));
    setPos(255,0);
}

void Text::draw()
{
    setPlainText(QString("Push the numeric keyboard to pick the ball."));
    setDefaultTextColor((Qt::black));
    setFont(QFont("Calligraph421 BT",22));
    setPos(255,0);
}

void Text::out()
{
    setPlainText(QString("Great! Now choose the bridge to put your ball on."));
    setDefaultTextColor((Qt::black));
    setFont(QFont("Calligraph421 BT",22));
    setPos(255,0);
}

void Text::one()
{
    setPlainText(QString("There is only one ball can be put on a bridge."));
    setDefaultTextColor((Qt::black));
    setFont(QFont("Calligraph421 BT",22));
    setPos(255,0);
}

void Text::magic()
{
    setPlainText(QString("Try to press the space keyboard!"));
    setDefaultTextColor((Qt::black));
    setFont(QFont("Calligraph421 BT",22));
    setPos(255,0);
}

void Text::protect()
{
    setPlainText(QString("Keep put the ball on to protect your castle!"));
    setDefaultTextColor((Qt::black));
    setFont(QFont("Calligraph421 BT",22));
    setPos(255,0);
}
