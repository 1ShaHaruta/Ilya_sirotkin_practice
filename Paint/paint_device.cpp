#include "paint_device.h"

Paint_device::Paint_device(QWidget *parent)
    : QWidget{parent}, base(new QImage(1920,1080,QImage::Format_ARGB32)),
      pen_is_active{true},is_figure_to_tie_selected{false}, figure_is_active{false},
      moving_is_active{false},removing_is_active{false},tie_is_active{false}
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

    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing, true);

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
        last_point=current_point;
    if(pen_is_active){
    painter->drawPoint(current_point);
    }
    if(tie_is_active){
    for(QPolygonF* poly: figures_arr){
        if(poly->containsPoint(current_point, Qt::FillRule::WindingFill)){
            if(!is_figure_to_tie_selected){
            figure_to_tie=static_cast<My_Shape*>(poly);
            is_figure_to_tie_selected=true;
            }else if(figure_to_tie!=poly){
               is_figure_to_tie_selected=false;
               painter->drawLine(QLineF(static_cast<My_Shape*>(poly)->get_center(),figure_to_tie->get_center()));
               static_cast<My_Shape*>(poly)->acces_to_ties_pointers().push_back(figure_to_tie);
               figure_to_tie->acces_to_ties_pointers().push_back(poly);
            }
            break;
        }
    }
    }
    if(removing_is_active){
      for(QPolygonF* poly: figures_arr){
          if(poly->containsPoint(last_point, Qt::FillRule::WindingFill)){
              painter->setPen(rubber);
              QList<QPolygonF*> buf=static_cast<My_Shape*>(poly)->acces_to_ties_pointers();
              QPointF p=static_cast<My_Shape*>(poly)->get_center();
              for(QPolygonF* p2:buf){
                  if(p2!=nullptr)
                  painter->drawLine(p,static_cast<My_Shape*>(p2)->get_center());
              }
              painter->drawPolyline(*poly);
              figures_arr.removeOne(poly);
              delete static_cast<My_Shape*>(poly);
              painter->setPen(pen);
              for(QPolygonF* p2:figures_arr){
                 painter->drawPolyline(*p2);
              }
          }
      }
      }
    if(moving_is_active){
        for(QPolygonF* poly: figures_arr){
            if(poly->containsPoint(last_point, Qt::FillRule::WindingFill)){
                figure_to_move=static_cast<My_Shape*>(poly);
            }
        }
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
    painter->drawLine(current_point,last_point);
    last_point=current_point;
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
             QPolygonF* rect = new My_Shape(QPointF((current_point.x()+(last_point).x())/2, ((last_point).y()+current_point.y())/2));
             *rect<<last_point<<QPointF(current_point.x(),(last_point).y())
                <<current_point<<QPointF((last_point).x(),current_point.y())<<last_point;
             painter->drawPolyline(*rect);
             figures_arr.append(rect);
             QTextStream(stdout)<<figures_arr.size();
             break;
         }
         case Figure::Triangle :{
             QPolygonF* triangle =new My_Shape(QPointF((current_point.x()+(last_point).x())/2, ((last_point).y()+current_point.y())/2));
             *triangle<<QPointF((last_point).x(),current_point.y())
                    <<QPointF((current_point.x()+(last_point).x())/2,(last_point).y())
                   <<current_point<<QPointF((last_point).x(),current_point.y());
             painter->drawPolyline(*triangle);
             figures_arr.append(triangle);
             QTextStream(stdout)<<figures_arr.size();
             break;
         }
         case Figure::Circle :{
             double center_x=(current_point.x()+(last_point).x())/2;
             double center_y=(current_point.y()+(last_point).y())/2;
             double a=center_x-(last_point).x();
             double b=center_y-(last_point).y();
             int steps = 200;
             QPolygonF* circle =new My_Shape(QPointF(center_x,center_y));
             for (int i = 0; i < steps; ++i) {
                 double theta = 2.0 * M_PI * double(i) / double(steps);//угол
                 double x = center_x + a * cos(theta);
                 double y = center_y + b * sin(theta);
                 *circle << QPoint(x, y);
             }
             painter->drawPolyline(*circle);
             figures_arr.append(circle);
             QTextStream(stdout)<<figures_arr.size();
             break;
         }
         case Figure::None :{

             break;
         }
         }
     }
     if(moving_is_active){
         double x_offset=current_point.x()-figure_to_move->get_center().x();
         double y_offset=current_point.y()-figure_to_move->get_center().y();
         painter->setPen(rubber);
         QList<QPolygonF*> buf=figure_to_move->acces_to_ties_pointers();
         QPointF p=figure_to_move->get_center();
         for(QPolygonF* p2:buf){
             if(p2!=nullptr)
             painter->drawLine(p,static_cast<My_Shape*>(p2)->get_center());
         }
         painter->drawPolyline(*figure_to_move);
         painter->setPen(pen);
         figure_to_move->change_coordinates(x_offset,y_offset);
         for(QPolygonF* p2:figures_arr){
            painter->drawPolyline(*p2);
         }
         painter->drawPolyline(*figure_to_move);
         for(QPolygonF* poly:figure_to_move->acces_to_ties_pointers()){
             painter->drawLine(figure_to_move->get_center(),static_cast<My_Shape*>(poly)->get_center());
         }

     }

    }else if(!figure_is_active){
        pen_is_active=true;
    }
}
