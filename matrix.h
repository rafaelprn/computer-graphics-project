#ifndef MATRIX_H
#define MATRIX_H
#include <QList>
#include <QPoint>
#include <vector>

class Matrix
{
public:
    float matrix[3][3];
    Matrix();

    Matrix Translate(float dX, float dY);
    Matrix Scale(float sX, float sY);
    Matrix Rotate(float angle);
    QList<QPoint> MultiplicatePointList(QList<QPoint> points);
    Matrix operator*(const Matrix& other) const;
};

#endif // MATRIX_H
