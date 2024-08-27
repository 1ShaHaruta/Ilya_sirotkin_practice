#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMovie>
#include <chrono>
#include <thread>
#include <QThread>
#include <QTimer>
#include <random>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void BG_animation();
private:
    Ui::MainWindow *ui;
    QMovie *clouds;
    QTimer *timer;
};
#endif // MAINWINDOW_H
