#ifndef POINT_H
#define POINT_H
#include <QPoint>
#include <QList>
#include "genericobject.h"

class Point: public GenericObject, public QPoint
{
public:
    float x, y, z;
    QPoint point;
    Point(float x, float y);
    Point(float x, float y, float z);

    QPoint transformPointToQPoint(Point point);
    QList<QPoint> transformPointToQPoint(QList<Point> list);
    virtual void draw(QPainter *painter);
};

#endif // POINT_H
