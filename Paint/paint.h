//Сироткин Илья 5 группа
#ifndef PAINT_H
#define PAINT_H

#include <QMainWindow>
#include <QPixmap>
#include <QFileDialog>
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
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
private slots:

    void on_pen_action_triggered();

    void on_rect_action_triggered();

    void on_triangle_action_triggered();

    void on_circle_action_triggered();

    void on_move_action_triggered();

    void on_tie_action_triggered();

    void on_remove_action_triggered();

    void on_save_action_triggered();

    void on_load_action_triggered();

private:
    Ui::MainWindow *ui;
    Paint_device* paint_device;
};
#endif // PAINT_H
