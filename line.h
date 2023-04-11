#ifndef LINE_H
#define LINE_H
#include <QLine>
#include "point.h"
#include <QList>
#include "genericobject.h"


class Line: public QLine, public QPoint, public GenericObject
{
public:
    float x1, y1, z1, x2, y2, z2;
    QLine line;
    Line();
    Line(float x1, float y1, float z1, float x2, float y2, float z2);
    Line(float x1, float y1, float x2, float y2);

    Line(Point point1, Point point2);
    QLine transformLineToQLine(Line line);
    QList<QLine> transformListOfLinesToListOfQLines(QList<Line> list);
    virtual void draw(QPainter *painter);
};

#endif // LINE_H
