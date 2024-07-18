//Сироткин Илья 5группа 5 лаба вариант 8 "Цветочный магазин"
#include "mainwindow.h"
#include "input_device.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
