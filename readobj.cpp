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


void ReadOBJ::lerOBJ(){
    QFile file("../computer-graphics-project/Charizard.obj"); //endereco do arquivo
    Point p1(0, 0, 0);

    QString linha;

    regex vReg("^v .*"); //regex vertice
    regex fReg("^f .*"); //regex face

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        return; //caso nao abra
    }

    QTextStream fileText(&file);//abrindo arquivo

    do{
        linha = fileText.readLine().trimmed(); //le a linha tirando espaco
        if(regex_match(linha.toStdString(), vReg)){ //se atende o regex
            auto vert = linha.split(u' '); //divide nos espacos
            QList<Point> pontos = {Point(vert[1].toDouble() * 100, vert[2].toDouble() * 100, vert[3].toDouble() * 100)}; //pega os 3 pontos
            QList<QPoint> pointToVp = p1.transformPointToQPoint(pontos); //transforma eles em qpoint
            this->objectPoints.append(pointToVp); //passa pra coordenada de viewport e salva na lista de pontos

            //std::cout << "oi" << std::endl;
        }
    }while(!linha.isNull()); //ate o fim do arquivo
    file.close(); //fecha


    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){ //se nao abrir o arquivo fecha
        return;
    }
    QTextStream fileText2(&file); //abrindoa arquivo

    do{
        linha = fileText2.readLine().trimmed();
            if(regex_match(linha.toStdString(), fReg)){ //se atende o regex de face
                auto faces = linha.split(u' ');
                for(int i = 1; i <= faces.length()-2; i++){ //temos f 1/1/1 2/2/2 3/3/3 , queremos o primeiro de cada
                    int currentPoint = faces[i].split(u'/')[0].toInt() - 1; //fica no item atual
                    int nextPoint = faces[i+1].split(u'/')[0].toInt() - 1; //vai servir pra percorrer ate o ultimo
                    int firstPoint = faces[1].split(u'/')[0].toInt() - 1; //fica no primeiro
                                                                            //pq tem q conectar todos entre si

                    //objectLines = lista de linhas
                    this->objectLines.append(Line(this->objectPoints.at(currentPoint), this->objectPoints.at(nextPoint))); //faz uma linha do atual ao prox
                    if(i == faces.length()-2){ //quando o current for o ultimo
                        this->objectLines.append(Line(this->objectPoints.at(nextPoint), this->objectPoints.at(firstPoint))); //liga o ultimo no primeiro
                    } //pega a lista de linhas e liga os pontos
                }
            }
        }while(!linha.isNull()); //ate o final do arquivo
        file.close(); //fecha
}
