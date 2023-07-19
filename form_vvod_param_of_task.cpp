#include "form_vvod_param_of_task.h"
#include "ui_form_vvod_param_of_task.h"

Form_vvod_param_of_task::Form_vvod_param_of_task(QVector<double> Params, QWidget *parent) : Params_GA(Params),
    QWidget(parent),
    ui(new Ui::Form_vvod_param_of_task)
{
    ui->setupUi(this);

//    ui->label_kol_osobey->setText(QString::number(Params_GA[0]));
//    ui->label_max_pokoleniy->setText(QString::number(Params_GA[1]));
//    ui->label_procent_elit->setText(QString::number(Params_GA[2]));
//    ui->comboBox_tip_otbora->setCurrentIndex((int)Params_GA[3]);
//    ui->label_veroyat_skreshch->setText(QString::number(Params_GA[4]));
//    ui->comboBox_tip_mutacii->setCurrentIndex((int)Params_GA[5]);
//    ui->label_ver_mutacii->setText(QString::number(Params_GA[6]));
//    ui->label_sila_mutacii->setText(QString::number(Params_GA[7]));
}

Form_vvod_param_of_task::~Form_vvod_param_of_task()
{
    delete ui;
}

void Form_vvod_param_of_task::obnovit_params(QVector<double> params)
{
    Params_GA = params;
    ui->label_kol_osobey->setText(QString::number(Params_GA[0]));
    ui->label_max_pokoleniy->setText(QString::number(Params_GA[1]));
    ui->label_procent_elit->setText(QString::number(Params_GA[2]));
    ui->comboBox_tip_otbora->setCurrentIndex((int)Params_GA[3]);
    ui->label_veroyat_skreshch->setText(QString::number(Params_GA[4]));
    ui->comboBox_tip_mutacii->setCurrentIndex((int)Params_GA[5]);
    ui->label_ver_mutacii->setText(QString::number(Params_GA[6]));
    ui->label_sila_mutacii->setText(QString::number(Params_GA[7]));
    ui->comboBox_tip_skreshchivaniya->setCurrentIndex((int)Params_GA[8]);

    ui->lineEdit_kol_osobey->setText("");
    ui->lineEdit_max_pokoleniy->setText("");
    ui->lineEdit_procent_elit->setText("");
    ui->lineEdit_sila_mutacii->setText("");
    ui->lineEdit_ver_mutacii->setText("");
    ui->lineEdit_veroyat_skreshch->setText("");
}


void Form_vvod_param_of_task::on_save_n_quit_clicked()
{
    if (! ui->lineEdit_kol_osobey->text().isEmpty()) {
        Params_GA[0] = ui->lineEdit_kol_osobey->text().toInt();
    }
    if (! ui->lineEdit_max_pokoleniy->text().isEmpty()) {
        Params_GA[1] = ui->lineEdit_max_pokoleniy->text().toInt();
    }
    if (! ui->lineEdit_procent_elit->text().isEmpty()) {
        Params_GA[2] = ui->lineEdit_procent_elit->text().toDouble();
    }
    Params_GA[3] = ui->comboBox_tip_otbora->currentIndex();
    if (! ui->lineEdit_veroyat_skreshch->text().isEmpty()) {
        Params_GA[4] = ui->lineEdit_veroyat_skreshch->text().toDouble();
    }
    Params_GA[5] = ui->comboBox_tip_mutacii->currentIndex();
    if (! ui->lineEdit_ver_mutacii->text().isEmpty()) {
        Params_GA[6] = ui->lineEdit_ver_mutacii->text().toDouble();
    }
    if (! ui->lineEdit_sila_mutacii->text().isEmpty()) {
        Params_GA[7] = ui->lineEdit_sila_mutacii->text().toDouble();
    }
    Params_GA[8] = ui->comboBox_tip_skreshchivaniya->currentIndex();

    emit peredat_parametry_GA(Params_GA);

    this->close();
}


void Form_vvod_param_of_task::on_sbrosit_parametry_clicked()
{
    QVector<double> standart_params_GA = {500, 80, 20.0, 3, 0.95, 0, 0.1, 20.0, 0};
    obnovit_params(standart_params_GA);
}


