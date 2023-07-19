#include "form_of_task_parameters.h"
#include "ui_form_of_task_parameters.h"

form_of_task_parameters::form_of_task_parameters(QVector<double> Params, QWidget *parent) : params_of_task(Params),
    QWidget(parent),
    ui(new Ui::form_of_task_parameters)
{
    ui->setupUi(this);
}

form_of_task_parameters::~form_of_task_parameters()
{
    delete ui;
}

void form_of_task_parameters::update_params(QVector<double> params_of_task)
{
    ui->lineEdit_PPPM->setText(QString::number(params_of_task[0]));
    ui->lineEdit_max_angle->setText(QString::number(params_of_task[1]));
    ui->lineEdit_sector_angle->setText(QString::number(params_of_task[2]));
    ui->lineEdit_weight_ZZP->setText(QString::number(params_of_task[3]));
    ui->lineEdit_weight_angle_broke->setText(QString::number(params_of_task[4]));

}

void form_of_task_parameters::on_pushButton_save_n_quit_clicked()
{
    if (! ui->lineEdit_PPPM->text().isEmpty())
        params_of_task[0] = ui->lineEdit_PPPM->text().toInt();
    if (! ui->lineEdit_max_angle->text().isEmpty())
        params_of_task[1] = ui->lineEdit_max_angle->text().toDouble();
    if (! ui->lineEdit_sector_angle->text().isEmpty())
        params_of_task[2] = ui->lineEdit_sector_angle->text().toDouble();
    if (! ui->lineEdit_weight_ZZP->text().isEmpty())
        params_of_task[3] = ui->lineEdit_weight_ZZP->text().toDouble();
    if (! ui->lineEdit_weight_angle_broke->text().isEmpty())
        params_of_task[4] = ui->lineEdit_weight_angle_broke->text().toDouble();

    emit transmit_param_of_task(params_of_task);

    this->close();
}


void form_of_task_parameters::on_pushButton_to_default_clicked()
{
    QVector<double> standart_params_of_task = {3, 15.0, 10.0, 1.0, 2.0};
    update_params(standart_params_of_task);
}

