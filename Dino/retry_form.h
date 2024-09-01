#ifndef RETRY_FORM_H
#define RETRY_FORM_H

#include <QWidget>
#include <QPixmap>

namespace Ui {
class Retry_form;
}

class Retry_form : public QWidget
{
    Q_OBJECT

public:
    explicit Retry_form(QWidget *parent = nullptr);
    ~Retry_form();
private slots:

    void on_pushButton_clicked();

signals:

private:
    Ui::Retry_form *ui;
};

#endif // RETRY_FORM_H
