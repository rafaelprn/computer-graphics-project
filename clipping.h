#ifndef CLIPPING_H
#define CLIPPING_H
#include "point.h"
#include <QList>

class clipping
{
public:
    QList<Point> p, wp;
    clipping(QList<Point> p, QList<Point> wp){
        this->p = p;
        this->wp = wp;
    }


    Pinto(){


    }
};

#endif // CLIPPING_H
