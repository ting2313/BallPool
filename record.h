#ifndef RECORD_H
#define RECORD_H
#include<fstream>
#include <QGraphicsTextItem>

using namespace std;

class Record:public QGraphicsTextItem{
public:
    Record();
    void upload(int record);
    int old_record;
};

#endif // RECORD_H
