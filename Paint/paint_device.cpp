#include "paint_device.h"

Paint_device::Paint_device(QWidget *parent)
    : QWidget{parent}, base(new QImage(1920,1080,QImage::Format_ARGB32)),
      pen_is_active{true},is_figure_to_tie_selected{false}, figure_is_active{false},
      moving_is_active{false},removing_is_active{false},tie_is_active{false}
{
    form=new Input_form;
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
    connect(form, SIGNAL(sent_str(QString)),this, SLOT(get_saving_file_name(QString)));
    connect(form, SIGNAL(input_form_closed()), this, SLOT(save_data_function()));
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
       pen_is_active_copy=true;
       pen_is_active=false;
    }
    else if(event->button()==Qt::RightButton&&(figure_is_active||moving_is_active||tie_is_active)){
        figure_is_active_copy=figure_is_active;
        moving_is_active_copy=moving_is_active;
        tie_is_active_copy=tie_is_active;
        figure_is_active=tie_is_active=moving_is_active=false;
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

    }else if(event->button()==Qt::RightButton&&(figure_is_active_copy||moving_is_active_copy||tie_is_active_copy)){
        figure_is_active=figure_is_active_copy;
        moving_is_active=moving_is_active_copy;
        tie_is_active=tie_is_active_copy;
        figure_is_active_copy=tie_is_active_copy=moving_is_active_copy=false;
    }
    else if(pen_is_active_copy){
        pen_is_active_copy=pen_is_active;
        pen_is_active=true;
    }
}

void Paint_device::keyReleaseEvent(QKeyEvent *event) {
    if(event->key()==Qt::Key_Escape){
        figure_type=Figure::None;
        removing_is_active= removing_is_active & 1;
        figure_is_active=moving_is_active=tie_is_active=false;
        if(!removing_is_active){
        pen_is_active=true;
        }
    }
}


void Paint_device::load_data(const QString& name){
    QFile file(name);
    file.open(QIODevice::ReadOnly);
    if(!file.isOpen()){
        QMessageBox::warning(this, "Предупреждение","Файл не открыт",QMessageBox::Ok,Qt::NoButton);
    }
    QDataStream stream(&file);

    int size;
    stream>>size;
    QList<QPolygonF*> buf;
    QVector<int> figures_sizes, figure_tie_pointers_sizes;
    for(int i=0;i<size;++i){
        int a;
        stream>>a;
        figures_sizes.push_back(a);
        QTextStream(stdout)<<""<<Qt::endl<<a;
    }
    for(int figure_size:figures_sizes){
        My_Shape* poly_buf = new My_Shape;
        QPointF p;
        stream>>p;
        poly_buf->set_center(p);
        QTextStream(stdout)<<""<<Qt::endl<<p.x()<<" "<<p.y();
        for(int i=0;i<figure_size-1;++i){
            QPointF p;
            stream>>p;
            QTextStream(stdout)<<""<<Qt::endl<<p.x()<<" "<<p.y();
            *poly_buf<<p;

        }
        buf.push_back(poly_buf);
    }
    for(int i=0;i<size;++i){
        int a;
        stream>>a;
        figure_tie_pointers_sizes.push_back(a);
        QTextStream(stdout)<<""<<Qt::endl<<a;
    }
    int count=0;
    for(int figure_tie_pointers_size:figure_tie_pointers_sizes){

        for(int i=0;i<figure_tie_pointers_size;++i){
            QPointF p;
            stream>>p;
            for(QPolygonF* poly:buf){
                if(static_cast<My_Shape*>(poly)->get_center().x()==p.x()&&static_cast<My_Shape*>(poly)->get_center().y()==p.y()){
                    static_cast<My_Shape*>(buf.at(count))->acces_to_ties_pointers().push_back(poly);
                    QTextStream(stdout)<<""<<Qt::endl<<static_cast<My_Shape*>(poly)->get_center().x()<<" "<<static_cast<My_Shape*>(poly)->get_center().y();
                }
            }
        }
        QTextStream(stdout)<<""<<Qt::endl<<static_cast<My_Shape*>(buf.at(count))->acces_to_ties_pointers().size();
        ++count;
    }
    QTextStream(stdout)<<""<<Qt::endl<<"size: "<<size<<Qt::endl<<"buf size: "<<buf.size();
    QImage* img_buf=new QImage(1920,1080,QImage::Format_ARGB32);
    stream>>(*img_buf);
    base=img_buf;
    painter->end();
    painter->begin(base);
    figures_arr=buf;


    for(QPolygonF* poly: figures_arr){
        if(poly->containsPoint(last_point, Qt::FillRule::WindingFill)){
            painter->setPen(rubber);
            QList<QPolygonF*> buf2=static_cast<My_Shape*>(poly)->acces_to_ties_pointers();
            QPointF p=static_cast<My_Shape*>(poly)->get_center();
            for(QPolygonF* p2:buf2){
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

/////////////////////////////////////////////////////////////////////////////////////////////////////////

void Paint_device::save_data(){
    form->show();
    folder_name=QFileDialog::getExistingDirectory();
}


void Paint_device::save_data_function(){
    QTextStream(stdout)<<QString(folder_name+"/"+saving_file+".bin");
QFile file(folder_name+"/"+saving_file+".bin");
file.open(QIODevice::WriteOnly);
if(!file.isOpen()){
    QMessageBox::warning(this, "Предупреждение","Файл не открыт",QMessageBox::Ok,Qt::NoButton);
}
QDataStream stream(&file);
stream<<int(figures_arr.size());
for(QPolygonF* poly:figures_arr){
    stream<<int(poly->size()+1);
}
for(QPolygonF* poly:figures_arr){
    stream<<static_cast<My_Shape*>(poly)->get_center();
    for(int i=0;i<poly->size();++i){
        stream<<poly->at(i);
    }
}
for(QPolygonF* poly:figures_arr){
    stream<<int(static_cast<My_Shape*>(poly)->acces_to_ties_pointers().size());
}
for(QPolygonF* poly:figures_arr){
    for(QPolygonF* p:static_cast<My_Shape*>(poly)->acces_to_ties_pointers()){
        stream<<static_cast<My_Shape*>(p)->get_center();
    }
}
stream<<(*base);

}
