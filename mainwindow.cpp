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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void MainWindow::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::blue);
    pen.setWidth(0);
    painter.setPen(pen);

    QList<GenericObject *> displayFile;

    Window window(0, 800, 0, 600, -300, 100, -200, 200);
//    std::cout << window.getViewportX(0) << std::endl;
//    std::cout << window.getViewportY(0) << std::endl;

    QList<QPoint> points = {QPoint(0, 0), QPoint(100, 0),QPoint(100, -100), QPoint(0, -100)};

    Rectangle rectangle1(window.getViewportPoints(points));

    Matrix B;
    //Matrix A = B.Translate(10, 10).Scale(2, 2).Rotate(30) * B.Translate(100, 100);

    /*
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
    displayFile.append(&rectangle1);
    //displayFile.append(&rectangle2);



    for(GenericObject *obj : displayFile){
        obj->draw(&painter);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    close();
}

