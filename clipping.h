#ifndef CLIPPING_H
#define CLIPPING_H
#include <iostream>
#include "point.h"
#include <QList>
#include <QPoint>
#include <line.h>
#include "window.h"


class Clipping
{
private:
    QList<QPoint> windowPoints;
public:
    Clipping(QList<QPoint> windowPoints);
    void defineRC(Point point, int regionCode[4]);
    Line createClippedLine(Line line, int regionCodeP1[4], int regionCodeP2[4]);
    Line equationLeft(Line line);
    Line equationRight(Line line);
    Line equationTop(Line line);
    Line equationBottom(Line line);
    QList<Line> doClipping(QList<Line> lines);
};

#endif // CLIPPING_H
