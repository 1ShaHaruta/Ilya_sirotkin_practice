#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clouds=new QMovie[3]();
    for(int i=0;i<3;i++){
        QString str;
        str=QString("../Presets/cloud")+QString::fromStdString(std::to_string(i+1))+QString(".gif");
        clouds[i].setFileName(str);
        clouds[i].start();
    }
    ///////cloud1////////
    ui->cloud1->setMovie(&clouds[0]);
    ui->cloud1->resize(clouds[0].frameRect().size());
    ///////cloud2////////
    ui->cloud2->setMovie(&clouds[1]);
    ui->cloud2->resize(clouds[1].frameRect().size());
    ///////cloud3////////
    ui->cloud3->setMovie(&clouds[2]);
    ui->cloud3->resize(clouds[2].frameRect().size());

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::BG_animation);
    timer->start(15);
}

void MainWindow::BG_animation(){
    const int display_center_x=960;
    std::random_device dev;
    std::uniform_int_distribution<int> eng1(30,169),eng2(5,8);

    if (ui->cloud1->geometry().center().x()>0&&ui->cloud2->geometry().center().x()>0&&ui->cloud3->geometry().center().x()>0) {
        QPointF pos1 = ui->cloud1->pos();
        QPointF pos2 = ui->cloud2->pos();
        QPointF pos3 = ui->cloud3->pos();
        pos1 -= QPointF(eng2(dev),0);
        ui->cloud1->move(pos1.toPoint());
        if(ui->cloud1->x()<display_center_x||ui->cloud2->x()<display_center_x){
        pos2 -= QPointF(eng2(dev),0);
        ui->cloud2->move(pos2.toPoint());
        }
        if(ui->cloud2->x()<display_center_x||ui->cloud3->x()<display_center_x){
        pos3 -= QPointF(eng2(dev),0);
        ui->cloud3->move(pos3.toPoint());
        }
    }
    else if(ui->cloud1->geometry().center().x()<=0) {
        ui->cloud1->move(1920, eng1(dev));
    }
    else if(ui->cloud2->geometry().center().x()<=0) {
        ui->cloud2->move(1920, eng1(dev));
    }
    else if(ui->cloud3->geometry().center().x()<=0) {
        ui->cloud3->move(1920, eng1(dev));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] clouds;
}

