#include "matrix.h"
#include <math.h>
#include <iostream>
#define PI 3.14

Matrix::Matrix()
{
    this->matrix[0][0] = 1;
    this->matrix[1][0] = 0;
    this->matrix[2][0] = 0;
    this->matrix[0][1] = 0;
    this->matrix[1][1] = 1;
    this->matrix[2][1] = 0;
    this->matrix[0][2] = 0;
    this->matrix[1][2] = 0;
    this->matrix[2][2] = 1;
}

Matrix Matrix::Translate(float dX, float dY){
    Matrix result;
    result.matrix[0][2] = dX;
    result.matrix[1][2] = dY;

    return result;
}

Matrix Matrix::Scale(float sX, float sY){
    Matrix result;
    result.matrix[0][0] = sX;
    result.matrix[1][1] = sY;

    return result;
}

Matrix Matrix::Rotate(float angle){
    Matrix result;
    result.matrix[0][0] = cos(angle*(PI/180));
    result.matrix[1][0] = sin(angle*(PI/180));
    result.matrix[0][1] = -sin(angle*(PI/180));
    result.matrix[1][1] = cos(angle*(PI/180));

    return result;
}

QList<QPoint> Matrix::MultiplicatePointList(QList<QPoint> points){
  float newMatrix[3][1];
  float pMatrix[3][1];
  QList<QPoint> transformedPoints;

  newMatrix[0][0] = 0;
  newMatrix[1][0] = 0;
  newMatrix[2][0] = 0;

  for(QPoint point : points){

      pMatrix[0][0] = point.x();
      pMatrix[1][0] = point.y();
      pMatrix[2][0] = 1;

      for(int col=0; col<3; col++){
          float pointSum = 0;
          for(int row=0; row<3; row++){
              pointSum += this->matrix[col][row] * pMatrix[row][0];
          }
          newMatrix[col][0] = pointSum;
      }

      QPoint transformedPoint(newMatrix[0][0], newMatrix[1][0]);
      transformedPoints.append(transformedPoint);
  }

  return transformedPoints;
}

Matrix Matrix::operator*(const Matrix& other) const {
    Matrix result;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < 3; k++) {
                result.matrix[i][j] += matrix[i][k] * other.matrix[k][j];
            }
        }
    }

    return result;
}
