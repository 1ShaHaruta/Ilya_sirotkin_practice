#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    game_is_started=false;
    is_jumping=false;
    cloud2_is_flying=false;
    cloud3_is_flying=false;
    cactus_is_selected=false;
    ui->setupUi(this);

    ui->background->setPixmap(QPixmap::fromImage(QImage("../Presets/background.png")));
    ui->background->showFullScreen();

    form=new Retry_form();
connect(this, SIGNAL(cactus_was_touched()), form, SLOT(show()));
    ///////dinosaur////////
    dino.setFileName("../Presets/dino_50.gif");
    dino.start();
    dino.setPaused(true);
    ui->dinosaur->setMovie(&dino);
    ui->dinosaur->resize(dino.frameRect().size());
    ui->dinosaur->setGeometry(120,ground_level-ui->dinosaur->height(), ui->dinosaur->width(),ui->dinosaur->height());
    dino.setPaused(true);

    cacti=new QImage[3]();
    for(int i=0;i<3;i++){
        QString str;
        str=QString("../Presets/cactus")+QString::fromStdString(std::to_string(i+1))+QString(".png");
        cacti[i].load(str);
    }
    ///////cactus1////////
    ui->cactus1->setPixmap(QPixmap::fromImage(cacti[0]));
    ui->cactus1->resize(cacti[0].rect().size());
    ///////cactus2////////
    ui->cactus2->setPixmap(QPixmap::fromImage(cacti[1]));
    ui->cactus2->resize(cacti[1].rect().size());
    ///////cactus3////////
    ui->cactus3->setPixmap(QPixmap::fromImage(cacti[2]));
    ui->cactus3->resize(cacti[2].rect().size());

    cactus_vec.push_back(ui->cactus1);
    cactus_vec.push_back(ui->cactus2);
    cactus_vec.push_back(ui->cactus3);
    cactus_vec.push_back(ui->cactus_null);

for(QLabel* cts:cactus_vec){
    cts->setGeometry(1920,ground_level-cts->height(),cts->width(),cts->height());
    QTextStream(stdout)<<cts->width()<<" "<<cts->height()<<Qt::endl;
}

    clouds=new QImage[3]();
    for(int i=0;i<3;i++){
        QString str;
        str=QString("../Presets/cloud")+QString::fromStdString(std::to_string(i+1))+QString(".png");
        clouds[i].load(str);
    }
    ///////cloud1////////
    ui->cloud1->setPixmap(QPixmap::fromImage(clouds[0]));
    ui->cloud1->resize(clouds[0].rect().size());
    ///////cloud2////////
    ui->cloud2->setPixmap(QPixmap::fromImage(clouds[1]));
    ui->cloud2->resize(clouds[1].rect().size());
    ///////cloud3////////
    ui->cloud3->setPixmap(QPixmap::fromImage(clouds[2]));
    ui->cloud3->resize(clouds[2].rect().size());

    timer2 = new QTimer(this);

    timer1 = new QTimer(this);
    connect(timer1, &QTimer::timeout, this, &MainWindow::clouds_animation);
    timer1->start(clouds_speed);

    timer3 =new QTimer(this);
    connect(this, SIGNAL(cactus_was_touched()), timer3, SLOT(stop()));
    connect(timer3, &QTimer::timeout, this, &MainWindow::counter_raise);

    timer4=new QTimer(this);
    connect(timer4, &QTimer::timeout, this, &MainWindow::cacti_animation);
    timer4->start(cacti_speed);
}

void MainWindow::cacti_animation(){
    if(game_is_started){
     std::random_device dev;
     std::uniform_int_distribution<int> eng_cactus(0,3);
     if(!cactus_is_selected){
     current_cactus=cactus_vec.at(eng_cactus(dev));
     cactus_is_selected=true;
     if(ui->counter->value()>=200&&cacti_speed==4){
         cacti_speed=3;
         timer4->start(cacti_speed);
     }
     if(ui->counter->value()>=400&&cacti_speed==3){
         cacti_speed=2;
         timer4->start(cacti_speed);
         dino.setFileName("../Presets/dino_40.gif");
         dino.start();
     }
     }
     if(current_cactus->geometry().center().x()>0){
         QPointF pos=current_cactus->pos();
         pos-=QPointF(5,0);
         current_cactus->move(pos.toPoint());
         if((current_cactus->geometry().contains(ui->dinosaur->geometry().center())
            ||current_cactus->geometry().contains(ui->dinosaur->geometry().center()+QPoint(0,ui->dinosaur->height()/2))
            ||current_cactus->geometry().contains(ui->dinosaur->geometry().center()+QPoint(ui->dinosaur->width()/2,0))
            ||current_cactus->geometry().contains(ui->dinosaur->geometry().center()-QPoint(0,ui->dinosaur->height()/2))
            ||current_cactus->geometry().contains(ui->dinosaur->geometry().center()+QPoint(ui->dinosaur->width()/2,-(ui->dinosaur->height()/2))))
            &&current_cactus!=ui->cactus_null
           ){
                emit cactus_was_touched();
             current_cactus->move(1920,current_cactus->y());
             current_cactus=nullptr;
             cactus_is_selected=false;
             ui->cloud1->move(1920,100);
             ui->cloud2->move(1920,100);
             ui->cloud3->move(1920,220);
             cacti_speed=4;
             timer4->start(cacti_speed);
             if(ui->counter_2->value()<ui->counter->value()){
                 ui->counter_2->setValue(ui->counter->value());
             }
ui->press_button->show();
             ui->counter->setValue(0);
             dino.setFileName("../Presets/dino_50.gif");
             dino.start();
             dino.setPaused(true);
             game_is_started=is_jumping=cloud2_is_flying=cloud3_is_flying=false;
          }

     }else{
         cactus_is_selected=false;
         current_cactus->move(1920,ground_level-current_cactus->height());
         current_cactus=nullptr;
         QTextStream(stdout)<<""<<Qt::endl;
     }

    }

}

void MainWindow::clouds_animation(){
    if(game_is_started){
    std::random_device dev;
    std::uniform_int_distribution<int> eng1(12,68), eng2(3,5), eng3(4,6);

    if (ui->cloud1->geometry().center().x()>0&&ui->cloud2->geometry().center().x()>0&&ui->cloud3->geometry().center().x()>0) {
        QPointF pos1 = ui->cloud1->pos();
        QPointF pos2 = ui->cloud2->pos();
        QPointF pos3 = ui->cloud3->pos();
        pos1 -= QPointF(eng2(dev),0);
        ui->cloud1->move(pos1.toPoint());
        if(ui->cloud1->x()<display_center_x||cloud2_is_flying){
            cloud2_is_flying=true;
        pos2 -= QPointF(eng3(dev),0);
        ui->cloud2->move(pos2.toPoint());
        }
        if(ui->cloud2->x()<display_center_x||cloud3_is_flying){
            cloud3_is_flying=true;
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
}

void MainWindow::counter_raise(){
    ui->counter->setValue(ui->counter->value()+1);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event){
    if(!game_is_started){
    game_is_started=true;
    timer3->start(counter_speed);
    current_cactus=ui->cactus_null;
    ui->press_button->hide();
    cactus_is_selected=true;
    dino.setPaused(false);
form->setGeometry(560,240,form->width(),form->height());
    }
    if(event->key()==Qt::Key_Space&&!is_jumping){
        dino.setPaused(true);
        is_jumping=true;
        if(ui->dinosaur->geometry().center().y()>jump_level){
        connect(timer2, &QTimer::timeout, this, &MainWindow::dino_jumping_up);
        timer2->start(dinosaur_speed);
        }

    }
}

void MainWindow::dino_jumping_up(){
    if(ui->dinosaur->geometry().center().y()<=(jump_level+ground_level)/2-20){
    QPoint pos=ui->dinosaur->pos();
    pos-=QPoint(0,3);
    ui->dinosaur->move(pos);
    }else{
        QPoint pos=ui->dinosaur->pos();
        pos-=QPoint(0,5);
        ui->dinosaur->move(pos);
    }
    if(ui->dinosaur->geometry().center().y()<=jump_level){
        disconnect(timer2, &QTimer::timeout, this, &MainWindow::dino_jumping_up);
        connect(timer2, &QTimer::timeout, this, &MainWindow::dino_jumping_down);
    }
}

void MainWindow::dino_jumping_down(){
    if(ui->dinosaur->geometry().center().y()<=(jump_level+ground_level)/2-20){
    QPoint pos=ui->dinosaur->pos();
    pos+=QPoint(0,3);
    ui->dinosaur->move(pos);
    }else{
        QPoint pos=ui->dinosaur->pos();
        pos+=QPoint(0,5);
        ui->dinosaur->move(pos);
    }
    if(ui->dinosaur->geometry().y()+ui->dinosaur->height()>=ground_level){
        disconnect(timer2, &QTimer::timeout, this, &MainWindow::dino_jumping_down);
        timer2->stop();
        is_jumping=false;
        dino.setPaused(false);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete[] clouds;
    delete timer1;
    delete timer2;
    delete timer3;
    delete current_cactus;
    delete[] cacti;
}

