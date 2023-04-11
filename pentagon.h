#ifndef PENTAGON_H
#define PENTAGON_H
#include "genericobject.h"


class Pentagon : public GenericObject
{
private:
    QPoint p1, p2, p3, p4, p5;

public:
    Pentagon(QList<QPoint> points);

    virtual void draw(QPainter *painter);

};

#endif // PENTAGON_H
