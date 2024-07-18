#ifndef PAINT_DEVICE_H
#define PAINT_DEVICE_H

#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>
class Paint_device : public QWidget
{
    Q_OBJECT
public:
    explicit Paint_device(QWidget *parent = nullptr);
    ~Paint_device();
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
   // void keyReleaseEvent(QKeyEvent *event) override;
    QImage* getImage()const{
        return base;
    }

signals:

private:
    QPainter* painter;
    QImage* base;
    QPen pen;
    QBrush brush;
    QColor clr;
    QPointF* lastpoint;
    bool pen_is_active;
};

#endif // PAINT_DEVICE_H
