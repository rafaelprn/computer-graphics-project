#include "window.h"

Window::Window(QList<QPoint> viewport, QList<QPoint> windowPoints)
{
    this->Xwmin = windowPoints[0].x();
    this->Ywmin = windowPoints[0].y();
    this->WindowAspectX = windowPoints[1].x() - this->Xwmin;
    this->ViewportAspectX = viewport[1].x();
    this->WindowAspectY = windowPoints[1].y() - this->Ywmin;
    this->ViewportAspectY = viewport[0].y();

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

QList<Line> Window::getViewportLines(QList<Line> lines){
    QList<Line> newLines;
    for(Line line : lines){
        QList<QPoint> linePoints;
        linePoints.append(QPoint(line.x1, line.y1));
        linePoints.append(QPoint(line.x2, line.y2));
        linePoints = this->getViewportPoints(linePoints);
        newLines.append(Line(linePoints[0], linePoints[1]));
    }
    return newLines;
}
