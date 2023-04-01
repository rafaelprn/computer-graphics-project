#ifndef GEOMETRICTRANSFORMATIONS_H
#define GEOMETRICTRANSFORMATIONS_H
#include <QList>
#include <QPoint>

class GeometricTransformations
{
public:
    GeometricTransformations();

    QList<QPoint> Translate(QList<QPoint> points, float dX, float dY);
    QList<QPoint> Scale(QList<QPoint> points, float sX, float sY);
    QList<QPoint> Rotate(QList<QPoint> points, float rotationAngle);

    //float MatrixCalculation(float matrix1[][], float matrix2[][]);
};

#endif // GEOMETRICTRANSFORMATIONS_H
