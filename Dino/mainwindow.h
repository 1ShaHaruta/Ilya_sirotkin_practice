#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QEvent>
#include <QMouseEvent>
#include <QMovie>
#include <chrono>
#include <thread>
#include <QThread>
#include <QTimer>
#include <random>
#include <QVector>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
protected:
    void keyReleaseEvent(QKeyEvent *event) override;
private slots:
    void clouds_animation();
    void cacti_animation();
    void dino_jumping_up();
    void dino_jumping_down();
    void counter_raise();//эта функция заменяет QSpinBox::stepUp чтобы устранить выделение цифр
private:
    Ui::MainWindow *ui;
    QImage *clouds;
    QImage *cacti;
    QVector<QLabel*> cactus_vec;
    QLabel* current_cactus;
    QMovie dino;
    QTimer *timer1, *timer2, *timer3, *timer4;
    bool game_is_started;
    bool is_jumping;
    bool cloud2_is_flying;
    bool cloud3_is_flying;
    bool cactus_is_selected;
    const int ground_level=805;
    const int jump_level=305;
    const int display_center_x=960;
    //////speed/////
    const int dinosaur_speed=3;
    const int clouds_speed=54;
    int cacti_speed=4;
    const int counter_speed=100;

};
#endif // MAINWINDOW_H
