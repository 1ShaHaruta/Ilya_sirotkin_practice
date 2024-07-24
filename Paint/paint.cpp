#include "paint.h"
#include "ui_mainwindow.h"

Paint::Paint(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow), paint_device(new Paint_device())
{
    ui->setupUi(this);
    ui->display->setPixmap(QPixmap::fromImage(*paint_device->getImage()));

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

void Paint::keyReleaseEvent(QKeyEvent *event) {
    paint_device->keyReleaseEvent(event);
}


void Paint::on_pen_action_triggered()
{
    paint_device->select_pen();
}


void Paint::on_rect_action_triggered()
{
    paint_device->select_figure(Figure::Rect);
}


void Paint::on_triangle_action_triggered()
{
    paint_device->select_figure(Figure::Triangle);
}


void Paint::on_circle_action_triggered()
{
    paint_device->select_figure(Figure::Circle);
}


void Paint::on_move_action_triggered()
{
    paint_device->select_moving();
}


void Paint::on_tie_action_triggered()
{
    paint_device->select_tie();
}


void Paint::on_remove_action_triggered()
{
    paint_device->select_removing();
}


void Paint::on_save_action_triggered()
{
paint_device->save_data();
}


void Paint::on_load_action_triggered()
{
QString name=QFileDialog::getOpenFileName();
 paint_device->load_data(name);
 ui->display->setPixmap(QPixmap::fromImage(*paint_device->getImage()));
}

