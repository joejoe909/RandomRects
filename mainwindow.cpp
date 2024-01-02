#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "QImage"
#include <QPainter>
#include <QColor>
#include <random>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> rnd_color(0, 255);
    std::uniform_int_distribution<int> rnd_x(0, 1920);
    std::uniform_int_distribution<int> rnd_y(0, 1080);
    std::uniform_int_distribution<int> rnd_w(0, 500);
    std::uniform_int_distribution<int> rnd_h(0, 200);

    for(int i = 0; i < 1200; ++i)
    {
        QPainter painter(this);
        painter.setPen(QColor(rnd_color(gen), rnd_color(gen), rnd_color(gen), 255));
        //painter.drawRoundedRect(QRect(rnd_x(gen),rnd_y(gen),rnd_w(gen),rnd_h(gen)), 8.0, 8.0, Qt::AbsoluteSize);
        painter.drawRoundedRect(QRect(rnd_x(gen),rnd_y(gen),rnd_w(gen),rnd_h(gen)), 0.0, 0.0, Qt::AbsoluteSize);
    }



}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    repaint();
}

