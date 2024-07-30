#include "input_form.h"
//Данная формочка используется для ввода пользователем имени сохраняемого файла
Input_form::Input_form(QWidget* pwgt):QDialog(pwgt) {
    line=new QLineEdit;
    label=new QLabel("Введите имя файла ");
    Ok=new QPushButton("&Ввести");
    Close=new QPushButton("&Закрыть");
    connect(Ok, SIGNAL(clicked()), this, SLOT(emit_str()));
    connect(Close, SIGNAL(clicked()), this, SLOT(emit_closed()));
    QGridLayout* Layout = new QGridLayout;

    Layout->addWidget(label, 0, 0);
    Layout->addWidget(Ok, 1, 1);
    Layout->addWidget(line, 0, 1);
    Layout->addWidget(Close,1,0);
    this->setLayout(Layout);
}
  Input_form::~Input_form(){
        delete line;
        delete Ok;
      delete label;
      delete Close;
    }
