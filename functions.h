#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <QVector>
#include <QProgressBar>
#include <QProgressDialog>
#include <QRandomGenerator>
#include <QFile>
#include <QFileInfo>
#include <paint_zzp.h>
#include <paint_polygon_p.h>
#include <paint_zona_puska.h>


#include "intersection_functions.h"


const float window_w = 951.0f, // базовые длины сторон для ..
            window_h = 621.0f, // .. ф-ии fininview
// и добавим привязку геокоординат к углам фото:
            left_B = 71.787975f, // широта левого верхнего угла
            left_L = -14.39963f, // долгота левого верхнего угла
            right_B = 37.106893f, // то же
            right_L = 90.937283f, // в правом нижнем углу
            lambda0 = 0.0f, // нулевой меридиан (рад.)
            earth_radius = 6371000.0f; // радиус земли-сферы (м)

struct struct_dannykh {
    bool flag_korrektnosti;
    QVector<QVector<QPointF>> ZZP;
    QVector<QPointF> zona_puska;
    QPointF first_point_sektora_puska;
    double glavniy_ugol_sektora_puska;
    double ugol_rastvora_sektora_puska;
};


QVector<double> GenAlg(QVector<double> Params_GA, QVector<paint_ZZP*> nabor_ZZP, paint_zona_puska *zona_puska, paint_polygon_p *sektor_zapuska, QVector<double> params_of_task);

QVector<double> procedure_ocenka(QVector<QVector<double>> populyaciya, QVector<paint_ZZP*> nabor_ZZP, paint_zona_puska *zona_puska, paint_polygon_p *sektor_zapuska, QVector<double> params_of_task);
double procedure_sred_ocenka(QVector<double> ocenki);

QVector<QVector<double>> sost_nach_populyacii(int kol_osobey_v_populyacii, int kol_PPPM, QVector<paint_ZZP*> nabor_ZZP, paint_zona_puska *zona_puska, paint_polygon_p *sektor_zapuska);

QVector<QVector<double>> elitizm(QVector<QVector<double>> nach_populyaciya, QVector<double> nach_ocenki, double percent_elit);

QVector<QVector<double>> OTBOR(int, QVector<QVector<double>>, QVector<double>);
QVector<QVector<double>> otbor_ruletka(QVector<QVector<double>>, QVector<double>);
QVector<QVector<double>> otbor_SUS(QVector<QVector<double>>, QVector<double>);
QVector<QVector<double>> otbor_rangir(QVector<QVector<double>>, QVector<double>);
QVector<QVector<double>> otbor_turnir(QVector<QVector<double>>, QVector<double>);

QVector<QVector<double>> crossover(QVector<QVector<double>> populyaciya_potomkov, QVector<QVector<double>> populyaciya_roditeley, int tip_skreshch, double veroyat_skreshch);
QVector<QVector<double>> k_point_crossover(QVector<QVector<double>> populyaciya_potomkov, QVector<QVector<double>> populyaciya_roditeley, int k_tochek, double veroyat_skreshch);
QVector<QVector<double>> uniform_crossover(QVector<QVector<double>> populyaciya_potomkov, QVector<QVector<double>> populyaciya_roditeley, double veroyat_skreshch);
QVector<QVector<double>> blend_crossover_BLX(QVector<QVector<double>> populyaciya_potomkov, QVector<QVector<double>> populyaciya_roditeley, double veroyat_skreshch);
QVector<QVector<double>> simulated_binary_crossover_SBX(QVector<QVector<double>> populyaciya_potomkov, QVector<QVector<double>> populyaciya_roditeley, double veroyat_skreshch);

QVector<QVector<double>> mutaciya(QVector<QVector<double>>, double, int, int);

QVector<double> zagruzit_params(QVector<double> Params_GA);
void sokhranit_params(QVector<double> Params_GA);
bool sokhranit_dannye(QString put_k_failu_istinniy, QVector<paint_ZZP*> nabor_ZZP, paint_zona_puska *zona_puska, paint_polygon_p *sektor_zapuska);
struct_dannykh zagr_dannye(QString put_k_failu_istinniy);

double generate_random_double_from_interval_of_double(double lowest_num, double highest_num);

QVector<double> approximate_ellips(QVector<QPointF> tochki_poligona);

QVector<double> load_params_of_task(QVector<double> Params_of_task);
void save_params_of_task(QVector<double> Params_of_task);

#endif // FUNCTIONS_H
