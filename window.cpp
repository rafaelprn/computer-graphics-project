#include "window.h"

Window::Window(float Xvpmin,float Xvpmax,float Yvpmin,float Yvpmax,float Xwmin,float Xwmax,float Ywmin,float Ywmax)
{
    this->Xwmin = Xwmin;
    this->Ywmin = Ywmin;
    this->WindowAspectX = Xwmax - this->Xwmin;
    this->ViewportAspectX = Xvpmax - Xvpmin;
    this->WindowAspectY = Ywmax - this->Ywmin;
    this->ViewportAspectY = Yvpmax - Yvpmin;

}

float Window::getViewportX(float x){
    return ((x - this->Xwmin) / this->WindowAspectX) * this->ViewportAspectX;
}

float Window::getViewportY(float y){
    return (1 - (y - this->Ywmin) / this->WindowAspectY) * this->ViewportAspectY;
}

QList<QPoint> Window::getViewportPoints(QList<QPoint> points){
    QList<QPoint> newPoints;
    for(QPoint point : points){
        newPoints.append(QPoint(this->getViewportX(point.x()),this->getViewportY(point.y())));
    }
    return newPoints;
}
