#include "magic.h"
#include<QFont>

Magic::Magic()
{
        magic=0;

        setPlainText(QString("MP: ")+QString::number(magic));
        setDefaultTextColor((Qt::black));
        setFont(QFont("Calligraph421 BT",22));
        setPos(0,0);
}

void Magic::add(int value)
{
    magic+=value;
    setPlainText(QString("MP: ")+QString::number(magic));
    if(magic>=10){
    setDefaultTextColor((Qt::blue));
    }
}

void Magic::cost()
{
    magic-=10;
    setPlainText(QString("MP: ")+QString::number(magic));
    if(magic<10){
    setDefaultTextColor((Qt::black));
    }
}
