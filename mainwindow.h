#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    virtual void paintEvent(QPaintEvent *event);
    ~MainWindow();

private slots:
    void on_Fechar_clicked();

    void on_Translate_clicked(float X1, float X2);

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
