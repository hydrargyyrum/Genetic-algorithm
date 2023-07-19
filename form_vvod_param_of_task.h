#ifndef FORM_VVOD_PARAM_GA_H
#define FORM_VVOD_PARAM_GA_H

#include <QWidget>

namespace Ui {
class Form_vvod_param_of_task;
}

class Form_vvod_param_of_task : public QWidget
{
    Q_OBJECT

public:
    explicit Form_vvod_param_of_task(QVector<double> Params, QWidget *parent = nullptr);
    ~Form_vvod_param_of_task();

private:
    Ui::Form_vvod_param_of_task *ui;
    QVector<double> Params_GA;

public:
    void obnovit_params(QVector<double>);

signals:
     void transmit_param_of_task(QVector<double>); // к этой вещи функция не пишется; объявление производится в "emit .."

private slots:
    void on_save_n_quit_clicked();
    void on_sbrosit_parametry_clicked();
};

#endif // FORM_VVOD_PARAM_GA_H
