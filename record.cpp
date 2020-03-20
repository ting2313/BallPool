#include"record.h"
#include<string>
#include<cstdlib>
#include<QFont>

Record::Record()
{
    ifstream infile("score",ios::in);
    infile>>old_record;
    infile.close();

    setPlainText(QString("Record: ")+QString::number(old_record));
    setDefaultTextColor((Qt::black));
    setFont(QFont("Calligraph421 BT",22));
    setPos(0,720);
}

void Record::upload(int record)
{
    if(record>old_record){
        ofstream outfile("score",ios::out);
        outfile<<record;
        outfile.close();
    }
    setPlainText(QString("Record: ")+QString::number(record));
    setDefaultTextColor((Qt::yellow));
}
