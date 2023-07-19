#ifndef FORM_OF_TASK_PARAMETERS_H
#define FORM_OF_TASK_PARAMETERS_H

#include <QWidget>

namespace Ui {
class form_of_task_parameters;
}

class form_of_task_parameters : public QWidget
{
    Q_OBJECT

public:
    explicit form_of_task_parameters(QVector<double> Params, QWidget *parent = nullptr);
    ~form_of_task_parameters();

private:
    Ui::form_of_task_parameters *ui;
    QVector<double> params_of_task;

public:
    void update_params(QVector<double> params_of_task);

signals:
    void transmit_param_of_task(QVector<double> params_of_task); // к этой вещи функция не пишется; объявление производится в "emit .."

private slots:
    void on_pushButton_save_n_quit_clicked();
    void on_pushButton_to_default_clicked();
};

#endif // FORM_OF_TASK_PARAMETERS_H
