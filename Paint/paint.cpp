#include "paint.h"
#include "ui_mainwindow.h"

Paint::Paint(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), paint_device(new Paint_device())
{
    ui->setupUi(this);

}
Paint::~Paint()
{
    delete ui;
}

void Paint::mousePressEvent(QMouseEvent *event){
    paint_device->mousePressEvent(event);
    ui->display->setPixmap(QPixmap::fromImage(*paint_device->getImage()));
}

void Paint::mouseMoveEvent(QMouseEvent *event){
    paint_device->mouseMoveEvent(event);
    ui->display->setPixmap(QPixmap::fromImage(*paint_device->getImage()));
}

void Paint::mouseReleaseEvent(QMouseEvent *event){
    paint_device->mouseReleaseEvent(event);
    ui->display->setPixmap(QPixmap::fromImage(*paint_device->getImage()));
}


