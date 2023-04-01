#ifndef CIRCLE_H
#define CIRCLE_H
#include <genericobject.h>


class Circle : public GenericObject
{
private:
    QPoint center;
    int radius;
public:
    Circle(QPoint center, int radius);
    virtual void draw(QPainter *painter);
};

#endif // CIRCLE_H
