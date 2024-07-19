#ifndef PAINT_DEVICE_H
#define PAINT_DEVICE_H

#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>
enum Figure {None, Rect, Triangle, Circle};

class My_Shape:public QPolygonF{
private:
    QPointF center;
public:
    My_Shape(const QPointF& p):QPolygonF(), center(p){

    }
My_Shape()=delete;
    ~My_Shape(){

    }

};

class My_Triangle:public QPolygonF{
private:
public:
};

class My_Circle:public QPolygonF{
private:
public:
};

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
    void select_pen(){
        figure_is_active=false;
        pen_is_active=true;
        figure_type=Figure::None;
    }
    void select_figure(Figure fgr){
        pen_is_active=false;
        figure_is_active=true;
        figure_type=fgr;
    }

signals:

private:
    QPainter* painter;
    QImage* base;
    QPen pen;
    QPen rubber;
    //QBrush brush;
    QColor clr;
    QColor background;
    QPointF* last_point;
    Figure figure_type;
    QList<QPolygonF> figures_arr;
    bool pen_is_active;
    bool figure_is_active;

};

#endif // PAINT_DEVICE_H
