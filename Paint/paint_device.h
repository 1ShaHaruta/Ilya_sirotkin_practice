// Сироткин Илья 5 группа
// Данный класс отвечаает за все функции рисовании, он содержит ссылку на QImagе, в котором и отрисовываются все фигуры и карандаш;
// My_Shape класс, который наследуется от QPolygonF и объектами этого класса являются и прямоугольники и овалы, и треугольники;
// QList<QPolygonF*> figures_arr лист, содержащий все добавленные фигуры;
// При сохранении вышеуказанное изображение и лист сериализуются в бинарный файл, а при загрузке десириализуються
#ifndef PAINT_DEVICE_H
#define PAINT_DEVICE_H

#include <QWidget>
#include <QPainter>
#include <QEvent>
#include <QMouseEvent>
#include <QFile>
#include <QMessageBox>
#include <QFileDialog>
#include "input_form.h"

enum Figure {None, Rect, Triangle, Circle};

class My_Shape:public QPolygonF{
    // Q_OBJECT
private:
    QPointF center;// центр фигуры
QList<QPolygonF*> ties_pointers;// лист, содержащий фигуры, с которыми связана данная фигура
public:
    My_Shape(const QPointF& p):QPolygonF(), center(p){
    }
    My_Shape()=default;

void set_center(const QPointF& p){
    center=p;
}

void change_coordinates(double _x_offset, double _y_offset){//При перемещении функция изменяет координаты всех точек
    // фигуры с учетом смещения (offset)
    center.setX(center.x()+_x_offset);
    center.setY(center.y()+_y_offset);
    for(QPointF& p:(*this)){
        p+=QPointF(_x_offset,_y_offset);
    }
}
const QPointF& get_center() const {
    return center;
}

QList<QPolygonF*>& acces_to_ties_pointers(){//функция получает доступ к ties_pointers
    return ties_pointers;
}

My_Shape& operator=(const My_Shape& s){
    center=s.center;
    ties_pointers=s.ties_pointers;
    return *this;
}
   ~My_Shape(){
    for(QPolygonF* poly:ties_pointers){
    static_cast<My_Shape*>(poly)->ties_pointers.removeOne(this);
    }
}

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
    void keyReleaseEvent(QKeyEvent *event) override;
    QImage* getImage()const{
        return base;
    }
    void select_pen(){
        figure_is_active=moving_is_active=removing_is_active=tie_is_active=false;
        pen_is_active=true;
        figure_type=Figure::None;
    }
    void select_figure(Figure fgr){
        pen_is_active=moving_is_active=removing_is_active=tie_is_active=false;
        figure_is_active=true;
        figure_type=fgr;
    }
    void select_moving(){
        figure_is_active=pen_is_active=removing_is_active=tie_is_active=false;
        moving_is_active=true;
        figure_type=Figure::None;
    }
    void select_tie(){
        figure_is_active=moving_is_active=removing_is_active=pen_is_active=false;
        tie_is_active=true;
        figure_type=Figure::None;
    }
    void select_removing(){
        figure_is_active=moving_is_active=pen_is_active=tie_is_active=false;
        removing_is_active=true;
        figure_type=Figure::None;
    }
    void load_data(const QString& name);
    void save_data();
signals:

private slots:
    void get_saving_file_name(QString str){
        saving_file=str;
    }
    void save_data_function();
private:
    Input_form* form;//формочка для сохранения изображения
    QPainter* painter;
    QImage* base;//хранит под собой изображение. на котором происходит рисование
    QPen pen;//класс содержащий все атрибуты рисования
    QPen rubber;//класс содержащий все атрибуты удаления фигур
    QColor clr;//цвет pen
    QColor background;//цвет заднего фона
    QPointF last_point;//Последняя выбранная точка
    My_Shape* figure_to_tie;//выбранная фигура для связывания
    My_Shape* figure_to_move;//выбранная фигура для перемещения
    bool is_figure_to_tie_selected;//переменная показывает выбрана ли фигура для связывания
    Figure figure_type;
    QList<QPolygonF*> figures_arr;
    QString saving_file;
    QString folder_name;
    //Булевые переменные  показывающие какое действие выбрал пользователь
    bool pen_is_active;
    bool figure_is_active;
    bool moving_is_active;
    bool removing_is_active;
    bool tie_is_active;
    bool figure_is_active_copy, pen_is_active_copy, moving_is_active_copy,tie_is_active_copy;
};

#endif // PAINT_DEVICE_H
