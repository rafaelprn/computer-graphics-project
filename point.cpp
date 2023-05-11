#include "point.h"

Point::Point(float x, float y)
{
    this->x = x;
    this->y = y;
    this->point = QPoint(x, y);
}

Point::Point(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->point = QPoint(x, y);
}


QList<QPoint> Point::transformPointToQPoint(QList<Point> list) {
    QList<QPoint> newList;
    for(const Point &point : list) {
        newList.append(transformPointToQPoint(point));
    }
    return newList;
}


QPoint Point::transformPointToQPoint(Point point) {
    return QPoint(point.x, point.y);
}


void Point::draw(QPainter *painter){
    painter->drawPoint(this->point);
}
