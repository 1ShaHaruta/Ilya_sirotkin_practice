#include "paint_device.h"

Paint_device::Paint_device(QWidget *parent)
    : QWidget{parent}, base(new QImage(1920,1080,QImage::Format_ARGB32))
{
    painter=new QPainter();
    setMouseTracking(true);
    painter->begin(base);

    clr.setRgb(0,0,0,255);
    pen.setColor(clr);
    pen.setWidth(7);
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
}
Paint_device::~Paint_device(){
    painter->end();
    delete base;
    delete painter;
}
void Paint_device::mousePressEvent(QMouseEvent* event){
    if(event->button()==Qt::LeftButton){
    QPointF p1=event->pos();
    painter->drawLine(p1, QPointF(1,1));
    }
}
