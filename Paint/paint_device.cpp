#include "paint_device.h"

Paint_device::Paint_device(QWidget *parent)
    : QWidget{parent}, base(new QImage(1920,1080,QImage::Format_ARGB32)), pen_is_active{true}
{
    painter=new QPainter();
    painter->begin(base);
    setMouseTracking(true);

    background.setRgb(255,255,255,255);
    base->fill(background);

    clr.setRgb(0,0,0,255);
    pen.setColor(clr);
    pen.setWidth(5);
    pen.setStyle(Qt::SolidLine);

    rubber.setColor(background);
    rubber.setWidth(7);
    rubber.setStyle(Qt::SolidLine);

    //brush.setColor(clr);
    //brush.setStyle(Qt::BrushStyle::SolidPattern);
    painter->setPen(pen);
    //painter->setBrush(brush);
    painter->setRenderHint(QPainter::Antialiasing, true);
    last_point=new QPointF(0,0);

}
Paint_device::~Paint_device(){
    painter->end();
    delete base;
    delete painter;
}
void Paint_device::mousePressEvent(QMouseEvent* event){
    if(event->button()==Qt::LeftButton){
        QPointF current_point=event->pos();
        current_point-=QPointF(0,20);
        *last_point=current_point;
    if(pen_is_active){
    painter->drawPoint(current_point);
    }

    }
    else if(pen_is_active){
       pen_is_active=false;
    }
}

void Paint_device::mouseMoveEvent(QMouseEvent *event){
    if(pen_is_active){
    QPointF current_point=event->pos();
    current_point-=QPointF(0,20);
    painter->drawLine(current_point,*last_point);
    *last_point=current_point;
    }
}

void Paint_device::mouseReleaseEvent(QMouseEvent *event){
    if(event->button()==Qt::LeftButton){
        QPointF current_point=event->pos();
        current_point-=QPointF(0,20);
     if(pen_is_active){
    painter->drawPoint(current_point);
    }
     if(figure_is_active){
         switch(figure_type){
         case Figure::Rect :{
             My_Shape rect(QPointF((current_point.x()+(*last_point).x())/2, ((*last_point).y()+current_point.y())/2));
             rect<<*last_point<<QPointF(current_point.x(),(*last_point).y())
                <<current_point<<QPointF((*last_point).x(),current_point.y())<<*last_point;
             painter->drawPolyline(rect);
             figures_arr.append(rect);
             QTextStream(stdout)<<figures_arr.size();
             break;
         }
         case Figure::Triangle :{
             My_Shape triangle(QPointF((current_point.x()+(*last_point).x())/2, ((*last_point).y()+current_point.y())/2));
             triangle<<QPointF((*last_point).x(),current_point.y())
                    <<QPointF((current_point.x()+(*last_point).x())/2,(*last_point).y())
                   <<current_point<<QPointF((*last_point).x(),current_point.y());
             painter->drawPolyline(triangle);
             figures_arr.append(triangle);
             QTextStream(stdout)<<figures_arr.size();
             break;
         }
         case Figure::Circle :{
             double center_x=(current_point.x()+(*last_point).x())/2;
             double center_y=(current_point.y()+(*last_point).y())/2;
             double a=center_x-(*last_point).x();
             double b=center_y-(*last_point).y();
             My_Shape circle(QPointF(center_x,center_y));
             int steps = 200;
             for (int i = 0; i < steps; ++i) {
                 double theta = 2.0 * M_PI * double(i) / double(steps);//угол
                 double x = center_x + a * cos(theta);
                 double y = center_y + b * sin(theta);
                 circle << QPoint(x, y);
             }
             painter->drawPolyline(circle);
             figures_arr.append(circle);
             QTextStream(stdout)<<figures_arr.size();
             break;
         }
         case Figure::None :{

             break;
         }
         }
     }
    }else if(!figure_is_active){
        pen_is_active=true;
    }
}
