#ifndef MATRIX3D_H
#define MATRIX3D_H
#include <QList>
#include <QPoint>
#include <vector>

class Matrix3d
{
public:
    float matrix[4][4];
    Matrix3d();

    Matrix3d Translate(float dX, float dY, float dZ);
    Matrix3d Scale(float sX, float sY, float sZ);
    Matrix3d RotateX(float angle);
    Matrix3d RotateY(float angle);
    Matrix3d RotateZ(float angle);
    QList<QPoint> Multiplicate3dPointList(QList<QPoint> points);
    Matrix3d operator*(const Matrix3d& other) const;
};

#endif // MATRIX3D_H
