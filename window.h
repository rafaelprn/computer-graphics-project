#ifndef WINDOW_H
#define WINDOW_H
#include <QList>
#include <QPoint>
//#include <QLine>
#include "line.h"


class Window
{
public:
    float Xvpmin, Xvpmax, Yvpmin, Yvpmax, Xwmin, Xwmax, Ywmin, Ywmax;
    float ViewportAspectX, ViewportAspectY, WindowAspectX, WindowAspectY;
    Window(QList<QPoint> viewport, QList<QPoint> windowPoints);
    //ponto central da window p0 (x0, y0)
    //extremos da window sao (-1, -1) (1, 1)
    float getViewportX(float x);
    float getViewportY(float y);
    QList<QPoint> getViewportPoints(QList<QPoint> points);
    QList<Line> getViewportLines(QList<Line> lines);
};

#endif // WINDOW_H
