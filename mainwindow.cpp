#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QLine>
#include <rectangle.h>
#include <triangle.h>
#include <geometrictransformations.h>
#include <matrix.h>
#include <iostream>

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

    QList<QPoint> points = {QPoint(50, 50), QPoint(100, 50), QPoint(100, 100), QPoint(50, 100)};

    Rectangle rectangle1(points);

    Matrix B;
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


    displayFile.append(&rectangle1);
    displayFile.append(&rectangle2);

    for(GenericObject *obj : displayFile){
        obj->draw(&painter);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

