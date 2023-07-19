#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <custom_paintscene.h>
#include "form_vvod_param_ga.h"
#include "form_of_task_parameters.h"

// функция расчёта:
#include "functions.h"
// // //

#include <QFileDialog>
#include <QMessageBox>
#include <QDebug>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    custom_paintscene *scene1;

    Form_vvod_param_GA *okno_parametrov_GA;
    form_of_task_parameters *okno_parametrov_zadachi;


    const float window_width = window_w, // базовые длины сторон граф. поля ..
                window_height = window_h; // .. для ф-ии fininview

    // Для отслеживания полноэкранного режима
    bool polnoekran = 0;

    // // блок ввода параметров генетического алгоритма
    QVector<double> Params_GA = {500, 80, 20.0, 3, 0.95, 0, 0.1, 20.0, 0}; // параметры ГА по умолчанию
    // кодировка: QVector<> Params_GA: 1. количество особей в популяции, 2. макс. кол-во поколений, 3. процент элитных особей,
    // 4. тип отбора, 5. вероятность скрещивания, 6. тип мутации, 7. вер. мутации, 8. сила мутации, 9. тип скрещивания
    // //
    // 4. 0 - рулетка, 1 - стохастическая универслаьная выборка (SUS), 2 - ранжированный отбор, 3 - турнирный отбор
    // 6. 0 - мутация обменом, 1 - мутация обращением, 2 - мутация перетасовкой, 3 - нормальная, 4 - инвертированием
    // 9. 0 - одноточечное скрещивание, 1 - двуточечное, 2 - трёхточечное, 3 - равномерное, 4 - смешением (BLX), 5 - ИДС (имитация двоичного скрещивания, SBX)

    QVector<double> Params_of_task = {3, 15.0, 10.0, 1.0, 2.0}; // параметры задачи по умолчанию
    // кодировка: 1. количество ПППМ, 2. максимальный угол поворота, 3. угол раствора сектора конечной точки,
    // 4. весовая жёсткость запрета прохода через ЗЗП, 5. весовая жёсткость запрета превышения допустимого угла поворота

    // Тип построения (изменяется во время ручного построения в графическом окне)
    int tip_postroyeniya = 0; // 1 - ЗЗП, 2 - РЗП, 3 - СП

public:


private:
    bool eventFilter(QObject *, QEvent *event);


public slots:
    void slot_priyoma_Param_GA(QVector<double> new_param_GA);
    void slot_priyoma_Param_of_task(QVector<double> new_param_of_task);


private slots:
    void on_action_start_GA_triggered();
    void on_action_exit_triggered();
    void on_action_full_small_screen_triggered();
    void on_action_change_params_GA_triggered();
    void on_action_screenshot_triggered();
    void on_action_save_data_triggered();
    void on_action_load_data_triggered();
    void on_action_B_zzp_triggered();
    void on_action_B_rzp_triggered();
    void on_action_B_sp_triggered();
    void on_action_change_task_parameters_triggered();
};

#endif // MAINWINDOW_H
