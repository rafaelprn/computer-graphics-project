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

Matrix3d Matrix3d::Rotate(float angleX, float angleY, float angleZ)
{
    Matrix3d result;

    float radianX = angleX * (PI / 180);
    float radianY = angleY * (PI / 180);
    float radianZ = angleZ * (PI / 180);

    result.matrix[0][0] = cos(radianY)*cos(radianZ);
    result.matrix[0][1] = -cos(radianY)*sin(radianZ);
    result.matrix[0][2] = sin(radianY);
    result.matrix[0][3] = 0;
    result.matrix[1][0] = (sin(radianX)*sin(radianY)*cos(radianZ)) + (cos(radianX)*sin(radianZ));
    result.matrix[1][1] = (cos(radianX)*cos(radianZ)) - (sin(radianX)*sin(radianY)*sin(radianZ));
    result.matrix[1][2] = -sin(radianX)*cos(radianY);
    result.matrix[1][3] = 0;
    result.matrix[2][0] = (sin(radianX)*sin(radianZ)) - (cos(radianX)*sin(radianY)*cos(radianZ));
    result.matrix[2][1] = (cos(radianX)*sin(radianY)*sin(radianZ)) + (sin(radianX)*cos(radianZ));
    result.matrix[2][2] = cos(radianX)*cos(radianY);
    result.matrix[2][3] = 0;
    result.matrix[3][0] = 0;
    result.matrix[3][1] = 0;
    result.matrix[3][2] = 0;
    result.matrix[3][3] = 1;

    result = (*this) * result;

    return result;
}

QList<Line> Matrix3d::Multiply3dLineList(const QList<Line>& lines) {
  QList<Line> transformedLines;

  for (const Line& line : lines) {
    Line transformedLine;

    // Multiplying point 1
    float pMatrix1[4][1] = {{line.x1}, {line.y1}, {line.z1}, {1}};
    float newMatrix1[4][1] = {{0}, {0}, {0}, {0}};

    for (int row = 0; row < 4; row++) {
      float pointSum = 0;
      for (int col = 0; col < 4; col++) {
        pointSum += this->matrix[row][col] * pMatrix1[col][0];
      }
      newMatrix1[row][0] = pointSum;
    }

    transformedLine.x1 = newMatrix1[0][0];
    transformedLine.y1 = newMatrix1[1][0];
    transformedLine.z1 = newMatrix1[2][0];

    // Multiplying point 2
    float pMatrix2[4][1] = {{line.x2}, {line.y2}, {line.z2}, {1}};
    float newMatrix2[4][1] = {{0}, {0}, {0}, {0}};

    for (int row = 0; row < 4; row++) {
      float pointSum = 0;
      for (int col = 0; col < 4; col++) {
        pointSum += this->matrix[row][col] * pMatrix2[col][0];
      }
      newMatrix2[row][0] = pointSum;
    }

    transformedLine.x2 = newMatrix2[0][0];
    transformedLine.y2 = newMatrix2[1][0];
    transformedLine.z2 = newMatrix2[2][0];

    transformedLines.append(transformedLine);
  }
  return transformedLines;
}


Matrix3d Matrix3d::operator*(const Matrix3d& other) const {
    Matrix3d result;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            result.matrix[i][j] = 0;
            for (int k = 0; k < 4; k++) {
                result.matrix[i][j] += this->matrix[i][k] * other.matrix[k][j];
            }
        }
    }

    return result;
}
