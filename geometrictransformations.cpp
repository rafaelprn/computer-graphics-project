#include "geometrictransformations.h"
#include <math.h>
#include <vector>
#define PI = 3.14

GeometricTransformations::GeometricTransformations()
{
}

QList<QPoint> GeometricTransformations::Translate(QList<QPoint> points, float dX, float dY) {
    float newMatrix[3][1];
    float tMatrix[3][3];
    float pMatrix[3][1];
    QList<QPoint> translatedPoints;

    newMatrix[0][0] = 0;
    newMatrix[1][0] = 0;
    newMatrix[2][0] = 0;

    tMatrix[0][0] = 1;
    tMatrix[1][0] = 0;
    tMatrix[2][0] = 0;
    tMatrix[0][1] = 0;
    tMatrix[1][1] = 1;
    tMatrix[2][1] = 0;
    tMatrix[0][2] = dX;
    tMatrix[1][2] = dY;
    tMatrix[2][2] = 1;

    for(QPoint point : points){
        pMatrix[0][0] = point.x();
        pMatrix[1][0] = point.y();
        pMatrix[2][0] = 1;

        for(int col=0; col<3; col++){
            float pointSum = 0;
            for(int row=0; row<3; row++){
                pointSum += tMatrix[col][row] * pMatrix[row][0];
            }
            newMatrix[col][0] = pointSum;
        }
        QPoint translatedPoint(newMatrix[0][0], newMatrix[1][0]);
        translatedPoints.append(translatedPoint);
    }
    return translatedPoints;
}

QList<QPoint> GeometricTransformations::Scale(QList<QPoint> points, float sX, float sY) {

    float newMatrix[3][1];
    float sMatrix[3][3];
    float pMatrix[3][1];
    QList<QPoint> scaledPoints;

    newMatrix[0][0] = 0;
    newMatrix[1][0] = 0;
    newMatrix[2][0] = 0;

    sMatrix[0][0] = sX;
    sMatrix[1][0] = 0;
    sMatrix[2][0] = 0;
    sMatrix[0][1] = 0;
    sMatrix[1][1] = sY;
    sMatrix[2][1] = 0;
    sMatrix[0][2] = 0;
    sMatrix[1][2] = 0;
    sMatrix[2][2] = 1;

    for(QPoint point : points){
        pMatrix[0][0] = point.x();
        pMatrix[1][0] = point.y();
        pMatrix[2][0] = 1;

        for(int col=0; col<3; col++){
            float pointSum = 0;
            for(int row=0; row<3; row++){
                pointSum += sMatrix[col][row] * pMatrix[row][0];
            }
            newMatrix[col][0] = pointSum;
        }
        QPoint translatedPoint(newMatrix[0][0], newMatrix[1][0]);
        scaledPoints.append(translatedPoint);
    }
    return scaledPoints;
}

QList<QPoint> GeometricTransformations::Rotate(QList<QPoint> points, float rotationAngle){
    float initialX = points[0].x();
    float initialY = points[0].y();
    points = this->Translate(points, -initialX, -initialY);

    float newMatrix[3][1];
    float rMatrix[3][3];
    float pMatrix[3][1];
    QList<QPoint> rotatedPoints;

    newMatrix[0][0] = 0;
    newMatrix[1][0] = 0;
    newMatrix[2][0] = 0;

    rMatrix[0][0] = cos(rotationAngle);
    rMatrix[1][0] = sin(rotationAngle);
    rMatrix[2][0] = 0;
    rMatrix[0][1] = -sin(rotationAngle);
    rMatrix[1][1] = cos(rotationAngle);
    rMatrix[2][1] = 0;
    rMatrix[0][2] = 0;
    rMatrix[1][2] = 0;
    rMatrix[2][2] = 1;

    for(QPoint point : points){
        pMatrix[0][0] = point.x();
        pMatrix[1][0] = point.y();
        pMatrix[2][0] = 1;

        for(int col=0; col<3; col++){
            float pointSum = 0;
            for(int row=0; row<3; row++){
                pointSum += rMatrix[col][row] * pMatrix[row][0];
            }
            newMatrix[col][0] = pointSum;
        }
        QPoint translatedPoint(newMatrix[0][0], newMatrix[1][0]);
        rotatedPoints.append(translatedPoint);
    }
    rotatedPoints = this->Translate(rotatedPoints, initialX*2, initialY*2);
    return rotatedPoints;
}
