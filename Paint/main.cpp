//Сироткин Илья 5 группа
#include "paint.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Paint w;
    w.show();
    return a.exec();
}
