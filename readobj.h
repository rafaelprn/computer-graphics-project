#ifndef READOBJ_H
#define READOBJ_H

#include <iostream>
#include <QList>
#include "line.h"
#include "point.h"
#include "window.h"
#include <QString>


using namespace std;

class ReadOBJ
{
public:
    QString fileName;
    int x; //pos inicial
    QList<QPoint> objectPoints; //lista de todos os pontos do obj
    QList<Line> objectLines; //lista de todas as linhas do obj

    ReadOBJ(QString fileName, int x); //construtor
    void lerOBJ(); //vai ler o objeto
};

#endif // READOBJ_H
