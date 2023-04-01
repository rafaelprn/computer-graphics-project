#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <genericobject.h>

class Triangle : public GenericObject
{
private:
    QPoint p1, p2, p3;
public:
    Triangle(QPoint p1, QPoint p2, QPoint p3);
    virtual void draw(QPainter *painter);
};

#endif // TRIANGLE_H
