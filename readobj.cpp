#include "readobj.h"
#include <fstream>
#include <string>
#include <sstream>
#include <QFile>
#include <regex>
#include <QString>
#include <QTextStream>
#include "point.h"
#include "line.h"

ReadOBJ::ReadOBJ(int x)
{
    this->x = x;
}


void ReadOBJ::lerOBJ(Window window){
    QFile file("../computer-graphics-project/eyeball.obj");
    Point p1(0, 0, 0);

    QString linha;

    regex vReg("^v .*");
    regex fReg("^f .*");

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
    QTextStream fileText(&file);

    do{
        linha = fileText.readLine().trimmed();
        if(regex_match(linha.toStdString(), vReg)){
            auto vert = linha.split(u' ');
            QList<Point> pontos = {Point(vert[1].toDouble(), vert[2].toDouble(), vert[3].toDouble())};
            QList<QPoint> pointToVp = p1.transformPointToQPoint(pontos);
            this->objectPoints.append(window.getViewportPoints(pointToVp));
        }
    }while(!linha.isNull());
    file.close();


    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return;
    }
      QTextStream fileText2(&file);

    do{
            linha = fileText2.readLine().trimmed();
            if(regex_match(linha.toStdString(), fReg)){
                auto faces = linha.split(u' ');
                for(int i = 1; i <= faces.length()-2; i++){
                    int currentPoint = faces[i].split(u'/')[0].toInt() - 1;
                    int nextPoint = faces[i+1].split(u'/')[0].toInt() - 1;
                    int firstPoint = faces[1].split(u'/')[0].toInt() - 1;



                    this->objectLines.append(Line(this->objectPoints.at(currentPoint), this->objectPoints.at(nextPoint)));
                    if(i == faces.length()-2){
                        this->objectLines.append(Line(this->objectPoints.at(nextPoint), this->objectPoints.at(firstPoint)));
                    }

                }
            }
        }while(!linha.isNull());
        file.close();


}

