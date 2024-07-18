#include "paint_device.h"

Paint_device::Paint_device(QWidget *parent)
    : QWidget{parent}, base(new QImage(1920,1080,QImage::Format_ARGB32)), pen_is_active{true}
{
    painter=new QPainter();
    setMouseTracking(true);
    painter->begin(base);
    clr.setRgb(120,0,0,255);
    pen.setColor(clr);
    pen.setWidth(5);
    pen.setStyle(Qt::SolidLine);
    brush.setColor(clr);
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    painter->setPen(pen);
    painter->setBrush(brush);
    painter->setRenderHint(QPainter::Antialiasing, true);
    lastpoint=new QPointF(0,0);

}
Paint_device::~Paint_device(){
    painter->end();
    delete base;
    delete painter;
}
void Paint_device::mousePressEvent(QMouseEvent* event){
    if(event->button()==Qt::LeftButton&&pen_is_active){
    QPointF p1=event->pos();
    painter->drawPoint(p1);
    *lastpoint=p1;
    }
}

void Paint_device::mouseMoveEvent(QMouseEvent *event){
    if(pen_is_active){
   QPointF p1=event->pos();
    painter->drawLine(p1,*lastpoint);
   *lastpoint=p1;
    }
}

void Paint_device::mouseReleaseEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton&&pen_is_active){
    QPointF p1=event->pos();
    painter->drawPoint(p1);
    }
}
