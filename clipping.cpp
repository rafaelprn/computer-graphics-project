#include "clipping.h"

Clipping::Clipping(QList<QPoint> windowPoints)
{
    this->windowPoints = windowPoints;
}

// definir as Region Codes

void Clipping::defineRC(Point point, int regionCode[4]) {
    // top
    if(point.y > this->windowPoints[1].y()) {
           regionCode[0] = 1;
       } else {
           regionCode[0] = 0;
       }
       //Bottom
       if(point.y < this->windowPoints[0].y()) {
           regionCode[1] = 1;
       } else {
           regionCode[1] = 0;
       }
       //Right
       if(point.x > this->windowPoints[1].x()) {
           regionCode[2] = 1;
       } else {
           regionCode[2] = 0;
       }
       //Left
       if(point.x < this->windowPoints[0].x()) {
           regionCode[3] = 1;
       } else {
           regionCode[3] = 0;
       }
       //std::cout << regionCode[0] << regionCode[1] << regionCode[2] << regionCode[3] << std::endl;
    }

Line Clipping::createClippedLine(Line line, int regionCodeP1[4], int regionCodeP2[4]) {
    if(regionCodeP1[0] == 0 && regionCodeP1[1] == 0 && regionCodeP1[2] == 0 && regionCodeP1[3] == 0){
        if(regionCodeP2[0] == 1) {
            line = this->equationTop(line);
        }
        if(regionCodeP2[1] == 1) {
            line = this->equationBottom(line);
        }
        if(regionCodeP2[2] == 1) {
            line = this->equationRight(line);
        }
        if(regionCodeP2[3] == 1) {
            line = this->equationLeft(line);
        }
       return line;
    }

    if(regionCodeP2[0] == 0 && regionCodeP2[1] == 0 && regionCodeP2[2] == 0 && regionCodeP2[3] == 0){
        if(regionCodeP1[0] == 1) {
            line = this->equationTop(line);
        }
        if(regionCodeP1[1] == 1) {
            line = this->equationBottom(line);
        }
        if(regionCodeP1[2] == 1) {
            line = this->equationRight(line);
        }
        if(regionCodeP1[3] == 1) {
            line = this->equationLeft(line);
        }
        return line;
    }
    Line emptyLine;
    return emptyLine;
}

Line Clipping::equationLeft(Line line) {
    float m;
    m = (float)(line.y2 - line.y1) / (line.x2 - line.x1);
    if(line.x1 > line.x2){
        line.y2 = (m * (this->windowPoints[0].x() - line.x1) + line.y1);
        line.x2= this->windowPoints[0].x();

        return line;
    }
    line.y1 = (m * (this->windowPoints[0].x() - line.x1) + line.y1);
    line.x1= this->windowPoints[0].x();

    return line;
}

Line Clipping::equationRight(Line line) {
    float m;
    m = (float)(line.y2 - line.y1) / (line.x2 - line.x1);
    if(line.x1 > line.x2){
        line.y1 = (m * (this->windowPoints[1].x() - line.x1) + line.y1);
        line.x1 = this->windowPoints[1].x();

        return line;
    }
    line.y2 = (m * (this->windowPoints[1].x() - line.x1) + line.y1);
    line.x2 = this->windowPoints[1].x();

    return line;
}

Line Clipping::equationTop(Line line) {
    float m;
    m = (float)(line.y2 - line.y1) / (line.x2 - line.x1);
    if(line.y1 > line.y2){
        line.x1 = (line.x1) + (this->windowPoints[1].y() - line.y1) / m;
        line.y1 = this->windowPoints[1].y();
        return line;
    }
    line.x2 = (line.x1) + (this->windowPoints[1].y() - line.y1) / m;
    line.y2 = this->windowPoints[1].y();

    return line;
}

Line Clipping::equationBottom(Line line) {
    float m;
    m = (float)(line.y2 - line.y1) / (line.x2 - line.x1);
    if(line.y1 > line.y2){
        line.x2 = (line.x1) + (this->windowPoints[0].y() - line.y1) / m;
        line.y2 = this->windowPoints[0].y();
        return line;
    }
    line.x1 = (line.x1) + (this->windowPoints[0].y() - line.y1) / m;
    line.y1 = this->windowPoints[0].y();

    return line;
}

QList<Line> Clipping::doClipping(QList<Line> lines) {
    QList<Line> newList;

    for(Line line : lines) {
        int regionCodeP1[4], regionCodeP2[4];
        this->defineRC(Point(line.x1, line.y1), regionCodeP1);
        this->defineRC(Point(line.x2, line.y2), regionCodeP2);
        Line newLine = this->createClippedLine(line, regionCodeP1, regionCodeP2);

        newList.append(newLine);
    }

    return newList;
}

// verificar pontos inicial e final da reta e definir suas RC
// Caso 1: completamente contida dentro da window --> p1 e p2 são 0000
// Caso 2: completamente fora da window --> p1 e p2 não são 0000

/* Caso 3: segmento parcialmente dentro da window --> p1 ou p2 é 0000
 *
 * Esquerda: Y = m * (Xe - X1) + Y1
 * Direita: Y = m * (Xd - X1) + Y1
 * Topo: X = X1 + 1/m * (Yt - Y1)
 * Base: X = X1 + 1/m * (Yf - Y1)
 *
*/

// receber sempre as linhas do objeto e retornar novos linhas
// que serão anexados no display
