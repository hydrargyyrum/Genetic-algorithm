#ifndef FORM_VVOD_PARAM_GA_H
#define FORM_VVOD_PARAM_GA_H

#include <QWidget>

namespace Ui {
class Form_vvod_param_GA;
}

class Form_vvod_param_GA : public QWidget
{
    Q_OBJECT

public:
    explicit Form_vvod_param_GA(QVector<double> Params, QWidget *parent = nullptr);
    ~Form_vvod_param_GA();

private:
    Ui::Form_vvod_param_GA *ui;
    QVector<double> Params_GA;

public:
    void obnovit_params(QVector<double> params);

signals:
     void peredat_parametry_GA(QVector<double> params_GA); // к этой вещи функция не пишется; объявление производится в "emit .."

private slots:
    void on_save_n_quit_clicked();
    void on_sbrosit_parametry_clicked();
};

#endif // FORM_VVOD_PARAM_GA_H
