//Сироткин Илья 5 группа
#ifndef INPUT_FORM_H
#define INPUT_FORM_H
#include <QLineEdit>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include <QString>
class Input_form:public QDialog{//Данная формочка используется для ввода пользователем имени сохраняемого файла
    Q_OBJECT
private:
    QLineEdit* line;
    QPushButton *Ok;
    QPushButton *Close;
    QLabel* label;
    QString str;
private slots:
    void emit_str(){
        str=line->text();
        if(!str.isEmpty())
        emit sent_str(str);
    }
    void emit_closed(){
        emit input_form_closed();
        this->close();
    }
    signals:
    void sent_str(QString);
    void input_form_closed();
public:
    Input_form(QWidget* pwgt = 0);
    ~Input_form();
};

#endif // INPUT_FORM_H
