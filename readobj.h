#ifndef READOBJ_H
#define READOBJ_H

#include <iostream>
#include <QList>
#include "line.h"
#include "point.h"
#include "window.h"


using namespace std;

class ReadOBJ
{
public:
    int x;
    QList<QPoint> objectPoints;
    QList<Line> objectLines;
    ReadOBJ(int x);
    void lerOBJ(Window window);
};

#endif // READOBJ_H
