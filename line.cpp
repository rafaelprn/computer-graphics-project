#include "line.h"

Line::Line() {

}

Line::Line(float x1, float y1, float z1, float x2, float y2, float z2)
{
    this->x1 = x1;
    this->y1 = y1;
    this->z1 = z1;
    this->x2 = x2;
    this->y2 = y2;
    this->z2 = z2;
    this->line = QLine(this->x1, this->y1, this->x2, this->y2);
}

Line::Line(QPoint point1, QPoint point2)
{
    this->x1 = point1.x();
    this->y1 = point1.y();
    this->x2 = point2.x();
    this->y2 = point2.y();
    this->line = QLine(this->x1, this->y1, this->x2, this->y2);
}

Line::Line(Point point1, Point point2)
{
    this->x1 = point1.x;
    this->y1 = point1.y;
    this->x2 = point2.x;
    this->y2 = point2.y;
    this->line = QLine(this->x1, this->y1, this->x2, this->y2);
}

QLine Line::transformLineToQLine(Line line) {
    return QLine(line.x1, line.y1, line.x2, line.y2);
}

QList<QLine> Line::transformListOfLinesToListOfQLines(QList<Line> list) {
    QList<QLine> newList;
    for(const Line &line: list) {
        newList.append(transformLineToQLine(line));
    }
    return newList;
}

void Line::draw(QPainter *painter){
    painter->drawLine(this->line);
}
