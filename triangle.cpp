#include "triangle.h"

Triangle::Triangle(QPoint p1, QPoint p2, QPoint p3)
{
    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
}

void Triangle::draw(QPainter *painter){
    painter->drawLine(this->p1, this->p2);
    painter->drawLine(this->p1, this->p3);
    painter->drawLine(this->p2, this->p3);
}
