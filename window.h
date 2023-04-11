#ifndef WINDOW_H
#define WINDOW_H
#include <QList>
#include <QPoint>


class Window
{
public:
    float Xvpmin, Xvpmax, Yvpmin, Yvpmax, Xwmin, Xwmax, Ywmin, Ywmax;
    float ViewportAspectX, ViewportAspectY, WindowAspectX, WindowAspectY;
    Window(float Xvpmin,float Xvpmax,float Yvpmin,float Yvpmax,float Xwmin,float Xwmax,float Ywmin,float Ywmax);
    //ponto central da window p0 (x0, y0)
    //extremos da window sao (-1, -1) (1, 1)
    float getViewportX(float x);
    float getViewportY(float y);
    QList<QPoint> getViewportPoints(QList<QPoint> points);
};

#endif // WINDOW_H
