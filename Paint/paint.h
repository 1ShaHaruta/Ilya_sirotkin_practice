#ifndef PAINT_H
#define PAINT_H

#include <QMainWindow>
#include <QPixmap>
#include "paint_device.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class Paint : public QMainWindow
{
    Q_OBJECT

public:
    Paint(QWidget *parent = nullptr);
    ~Paint();
protected:
    void mousePressEvent(QMouseEvent *event) override;
    //void mouseMoveEvent(QMouseEvent *event) override;
    //void mouseReleaseEvent(QMouseEvent *event) override;
    //void keyReleaseEvent(QKeyEvent *event) override;
private:
    Ui::MainWindow *ui;
    Paint_device* paint_device;
    QEvent* _event;
};
#endif // PAINT_H
