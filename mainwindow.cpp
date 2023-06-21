#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QLine>
#include "line.h"
#include <rectangle.h>
#include <triangle.h>
#include <matrix.h>
#include <iostream>
#include <pentagon.h>
#include "window.h"
#include <readobj.h>
#include "clipping.h"
#include "matrix3d.h"

ReadOBJ objCharizard("Charizard", 0);
ReadOBJ objCubone("cubone", 0);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    objCharizard.lerOBJ();
    objCubone.lerOBJ();
}

QList<QPoint> windowPoints = {QPoint(-200, -200), QPoint(200, 200)};

float vpXMax = 400;
float vpYMax = 300;
int rx = 0;
int ry = 0;
int rz = 0;
int tx = 0;
int ty = 0;
int tz = 0;
float sx = 1;
float sy = 1;
float sz = 1;


void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(0);
    painter.setPen(pen);

    QList<GenericObject *> displayFile;

    QList<QPoint> viewportPoints = {QPoint(0, vpYMax), QPoint(vpXMax, vpYMax),QPoint(vpXMax, 0), QPoint(0, 0)};
    Rectangle viewport(viewportPoints);

    viewport.draw(&painter);

    QPen pen2;
    pen2.setColor(Qt::blue);
    pen2.setWidth(0);
    pen2.setColor(Qt::red);
    painter.setPen(pen2);

    Window window(viewportPoints, windowPoints); // (Xvpmin, Xvpmax, Yvpmin, Yvpmax, Xwmin, Xwmax, Ywmin, Ywmax)

    Matrix3d m1, m2;
    m1 = m2.Rotate(rx, ry, rz) * m2.Translate(tx, ty, tz) * m2.Scale(sx, sy, sz);

    Clipping c1(windowPoints);

    for(GenericObject *obj : displayFile){
        obj->draw(&painter);
    }

    objCharizard.objectLines = m1.Multiply3dLineList(objCharizard.objectLines);
    QList<Line> clippedLines = window.getViewportLines(c1.doClipping(objCharizard.objectLines));
    for(Line linha : clippedLines){
        linha.draw(&painter);
    }
    objCubone.objectLines = m1.Multiply3dLineList(objCubone.objectLines);
    clippedLines = window.getViewportLines(c1.doClipping(objCubone.objectLines));
    for(Line linha : clippedLines){
        linha.draw(&painter);
    }
}

//BUTTONS

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Fechar_clicked()
{
    close();
}

void MainWindow::on_pushButton_clicked()
{
    Matrix A = A.Translate(-10, 0);
    windowPoints = A.MultiplicatePointList(windowPoints);
    update();
}


void MainWindow::on_pushButton_2_clicked()
{
    Matrix A = A.Translate(10, 0);
    windowPoints = A.MultiplicatePointList(windowPoints);
    update();
}


void MainWindow::on_pushButton_3_clicked()
{
    Matrix A = A.Translate(0, 10);
    windowPoints = A.MultiplicatePointList(windowPoints);
    update();
}


void MainWindow::on_pushButton_4_clicked()
{
    Matrix A = A.Translate(0, -10);
    windowPoints = A.MultiplicatePointList(windowPoints);
    update();
}


void MainWindow::on_pushButton_5_clicked() //x +
{
    vpXMax += 50;
    update();
}


void MainWindow::on_pushButton_6_clicked() //y +
{
    vpYMax += 50;
    update();
}


void MainWindow::on_pushButton_7_clicked() //resetar vp
{
    vpXMax = 400;
    vpYMax = 300;
    update();
}


void MainWindow::on_pushButton_8_clicked()
{
    if(windowPoints[0].x() < 50 && windowPoints[1].x() < 50){
        return;
    }
    Matrix A = A.Scale(0.5,0.5); //diminui
    windowPoints = A.MultiplicatePointList(windowPoints);
    update();
}


void MainWindow::on_pushButton_9_clicked()
{
    Matrix A = A.Scale(1.5,1.5); //aumenta
    windowPoints = A.MultiplicatePointList(windowPoints);
    update();
}

void MainWindow::on_horizontalSlider_3_sliderMoved(int pos) //rx
{
    rx = pos;
    update();
}

void MainWindow::on_horizontalSlider_2_sliderMoved(int pos) //ry
{
    ry = pos;
    update();
}

void MainWindow::on_horizontalSlider_sliderMoved(int pos) //rz
{
    rz = pos;
    update();
}

void MainWindow::on_pushButton_13_clicked() //tx-
{
    tx = -10;
    update();
}


void MainWindow::on_pushButton_10_clicked() //tx+
{
    tx = 10;
    update();
}


void MainWindow::on_pushButton_14_clicked() //ty-
{
    ty = -10;
    update();
}


void MainWindow::on_pushButton_11_clicked() //ty+
{
    ty = 10;
    update();
}


void MainWindow::on_pushButton_15_clicked() //tz-
{
    tz = -10;
    update();
}


void MainWindow::on_pushButton_12_clicked() //tz+
{
    tz = 10;
    update();
}


void MainWindow::on_pushButton_20_clicked() //sx-
{
    sx = 0.8;
    update();
}


void MainWindow::on_pushButton_21_clicked() //sx+
{
    sx = 1.2;
    update();
}


void MainWindow::on_pushButton_18_clicked() //sy-
{
    sy = 0.8;
    update();
}


void MainWindow::on_pushButton_16_clicked() //sy+
{
    sy = 1.2;
    update();
}


void MainWindow::on_pushButton_19_clicked() //sz-
{
    sz = 0.8;
    update();
}


void MainWindow::on_pushButton_17_clicked() //sz+
{
    sz = 1.2;
    update();
}

