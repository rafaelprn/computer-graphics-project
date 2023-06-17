#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QLine>
#include <rectangle.h>
#include <triangle.h>
#include <geometrictransformations.h>
#include <matrix.h>
#include <iostream>
#include <pentagon.h>
#include "window.h"
#include <readobj.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

QList<QPoint> windowPoints = {QPoint(-200, -200), QPoint(200, 200)};

float vpXMax = 400;
float vpYMax = 300;

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
//    std::cout << window.getViewportX(0) << std::endl;
//    std::cout << window.getViewportY(0) << std::endl;

    QList<QPoint> points = {QPoint(0, 0), QPoint(100, 0),QPoint(100, -100), QPoint(0, -100)};

    Rectangle rectangle1(window.getViewportPoints(points));
    displayFile.append(&rectangle1);

    for(GenericObject *obj : displayFile){
        obj->draw(&painter);
    }


    ReadOBJ objetobola(0);

    objetobola.lerOBJ(window);
    for(Line linha : objetobola.objectLines){
        linha.draw(&painter);
    }



    /*Matrix B;
    Matrix A = B.Translate(10, 10).Scale(2, 2).Rotate(30) * B.Translate(100, 100);
    points = A.MultiplicatePointList(points);
    Rectangle rectangle2(points);
    std::cout << points[1].y() << std::endl;

        // Print the result
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                std::cout << A.matrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    */

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


void MainWindow::on_pushButton_5_clicked()
{
    vpXMax += 50;
    update();
}


void MainWindow::on_pushButton_6_clicked()
{
    vpYMax += 50;
    update();
}


void MainWindow::on_pushButton_7_clicked()
{
    vpXMax = 400;
    vpYMax = 300;
    update();
}


void MainWindow::on_pushButton_8_clicked()
{
    Matrix A = A.Scale(0.5,0.5);
    windowPoints = A.MultiplicatePointList(windowPoints);
    update();
}


void MainWindow::on_pushButton_9_clicked()
{
    Matrix A = A.Scale(1.5,1.5);
    windowPoints = A.MultiplicatePointList(windowPoints);
    update();
}

