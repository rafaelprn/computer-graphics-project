#ifndef MATRIX3D_H
#define MATRIX3D_H
#include <QList>
#include <QPoint>
#include <vector>
#include "line.h"

class Matrix3d
{
public:
    float matrix[4][4];
    Matrix3d();

    Matrix3d Translate(float dX, float dY, float dZ);
    Matrix3d Scale(float sX, float sY, float sZ);
    Matrix3d Rotate(float angleX, float angleY, float angleZ);
    QList<Line> Multiply3dLineList(const QList<Line>& lines) ;
    Matrix3d operator*(const Matrix3d& other) const;
};

#endif // MATRIX3D_H
