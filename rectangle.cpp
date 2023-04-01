#include "rectangle.h"

Rectangle::Rectangle(QList<QPoint> points)
{
    this->p1 = points[0];
    this->p2 = points[1];
    this->p3 = points[2];
    this->p4 = points[3];
}

void Rectangle::draw(QPainter *painter){
    painter->drawLine(this->p1, this->p2);
    painter->drawLine(this->p2, this->p3);
    painter->drawLine(this->p3, this->p4);
    painter->drawLine(this->p4, this->p1);
}
