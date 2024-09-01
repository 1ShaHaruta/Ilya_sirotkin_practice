#include "retry_form.h"
#include "ui_retry_form.h"

Retry_form::Retry_form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Retry_form)
{
    ui->setupUi(this);
    ui->f_background->setPixmap(QPixmap::fromImage(QImage("../Presets/form_background.png")));
    ui->f_background->showFullScreen();
}

Retry_form::~Retry_form()
{
    delete ui;
}

void Retry_form::on_pushButton_clicked()
{
    this->close();
}

