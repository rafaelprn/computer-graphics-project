#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <genericobject.h>


class Rectangle : public GenericObject
{
private:
    QPoint p1, p2, p3, p4;

public:
    Rectangle(QList<QPoint> points);
    virtual void draw(QPainter *painter);
};

#endif // RECTANGLE_H
