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
    ui->label->setPixmap(QPixmap::fromImage(*paint_device->getImage()));
    ui->label->showFullScreen();
}
