#include "matrix3d.h"
#include <math.h>
#include <iostream>
#define PI 3.14

Matrix3d::Matrix3d()
{
    this->matrix[0][0] = 1;
    this->matrix[1][0] = 0;
    this->matrix[2][0] = 0;
    this->matrix[3][0] = 0;

    this->matrix[0][1] = 0;
    this->matrix[1][1] = 1;
    this->matrix[2][1] = 0;
    this->matrix[3][1] = 0;

    this->matrix[0][2] = 0;
    this->matrix[1][2] = 0;
    this->matrix[2][2] = 1;
    this->matrix[3][2] = 0;

    this->matrix[0][3] = 0;
    this->matrix[1][3] = 0;
    this->matrix[2][3] = 0;
    this->matrix[3][3] = 1;
}

Matrix3d Matrix3d::Translate(float dX, float dY, float dZ){
    Matrix3d result;
    result.matrix[0][3] = dX;
    result.matrix[1][3] = dY;
    result.matrix[2][3] = dZ;

    result = result * (*this);

    return result;
}

Matrix3d Matrix3d::Scale(float sX, float sY, float sZ){
    Matrix3d result;
    result.matrix[0][0] = sX;
    result.matrix[1][1] = sY;
    result.matrix[2][2] = sZ;

    result = result * (*this);

    return result;
}

Matrix3d Matrix3d::RotateZ(float angle){
    Matrix3d result;
    result.matrix[0][0] = cos(angle*(PI/180));
    result.matrix[1][0] = sin(angle*(PI/180));
    result.matrix[0][1] = -sin(angle*(PI/180));
    result.matrix[1][1] = cos(angle*(PI/180));

    result = result * (*this);

    return result;
}

Matrix3d Matrix3d::RotateX(float angle){
    Matrix3d result;
    result.matrix[1][1] = cos(angle*(PI/180));
    result.matrix[2][1] = sin(angle*(PI/180));
    result.matrix[1][2] = -sin(angle*(PI/180));
    result.matrix[2][2] = cos(angle*(PI/180));

    result = result * (*this);

    return result;
}

Matrix3d Matrix3d::RotateY(float angle){
    Matrix3d result;
    result.matrix[0][0] = cos(angle*(PI/180));
    result.matrix[0][2] = sin(angle*(PI/180));
    result.matrix[2][0] = -sin(angle*(PI/180));
    result.matrix[2][2] = cos(angle*(PI/180));

    result = result * (*this);

    return result;
}

QList<QPoint> Matrix3d::Multiplicate3dPointList(QList<QPoint> points){
  float newMatrix[4][1];
  float pMatrix[4][1];
  QList<QPoint> transformedPoints;

  newMatrix[0][0] = 0;
  newMatrix[1][0] = 0;
  newMatrix[2][0] = 0;
  newMatrix[3][0] = 0;

  for(QPoint point : points){

      pMatrix[0][0] = point.x();
      pMatrix[1][0] = point.y();
      //pMatrix[2][0] = point.z();
      pMatrix[3][0] = 1;

      for(int col=0; col<4; col++){
          float pointSum = 0;
          for(int row=0; row<4; row++){
              pointSum += this->matrix[col][row] * pMatrix[row][0];
          }
          newMatrix[col][0] = pointSum;
      }

      QPoint transformedPoint(newMatrix[0][0], newMatrix[1][0]);
      transformedPoints.append(transformedPoint);
  }

  return transformedPoints;
}

Matrix3d Matrix3d::operator*(const Matrix3d& other) const {
    Matrix3d result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }

    return result;
}
