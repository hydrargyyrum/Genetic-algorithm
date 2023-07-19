#include "functions.h"

// Функция для составления исходной (начальной) популяции
QVector<QVector<double>> sost_nach_populyacii(int kol_osobey_v_populyacii, int kol_PPPM, QVector<paint_ZZP*> nabor_ZZP, paint_zona_puska *zona_puska, paint_polygon_p *sektor_zapuska) {

    QVector<QVector<double>> nach_populyaciya(kol_osobey_v_populyacii);

    // длина вектора-решения = 2*(кол-во ПППМ) + 2;
    // "+2", поскольку точка пуска не определена (и также выбирается в процессе решения), но не является ПППМ;
    // "*2", поскольку каждый ПППМ описывается парой координат {x,y}
    int kol_genov = 2*kol_PPPM + 2;

    int i;
    for (i = 0; i < 0.5*kol_osobey_v_populyacii; i++) {
        QVector<double> osob(kol_genov);

        double rand_first_x = generate_random_double_from_interval_of_double(zona_puska->min_x, zona_puska->max_x);
        double rand_first_y = generate_random_double_from_interval_of_double(zona_puska->min_y, zona_puska->max_y);
        osob[0] = rand_first_x; osob[1] = rand_first_y;

        for (int j = 2; j < kol_genov; j = j+2) {
            double non_rand_x = generate_random_double_from_interval_of_double(osob[j-2], osob[j-2] + fabs(sektor_zapuska->first_point.x() - osob[j-2])/kol_PPPM);
            double non_rand_y = generate_random_double_from_interval_of_double(osob[j-1], osob[j-1] + fabs(sektor_zapuska->first_point.y() - osob[j-1])/kol_PPPM);
            osob[j] = non_rand_x; osob[j+1] = non_rand_y;
        }
        nach_populyaciya[i] = osob;
    }

    for ( ; i < kol_osobey_v_populyacii; i++) {
        QVector<double> osob(kol_genov);

        double rand_first_x = generate_random_double_from_interval_of_double(zona_puska->min_x - fabs(zona_puska->max_x-zona_puska->min_x), zona_puska->max_x + fabs(zona_puska->max_x-zona_puska->min_x));
        double rand_first_y = generate_random_double_from_interval_of_double(zona_puska->min_y - fabs(zona_puska->max_y-zona_puska->min_y), zona_puska->max_y + fabs(zona_puska->max_y-zona_puska->min_y));
        osob[0] = rand_first_x; osob[1] = rand_first_y;

        for (int j = 2; j < kol_genov; j = j+2) {
            double non_rand_x = generate_random_double_from_interval_of_double(zona_puska->central_point.x() - 0.5*fabs(sektor_zapuska->first_point.x()-zona_puska->central_point.x()), sektor_zapuska->first_point.x() + 0.5*fabs(sektor_zapuska->first_point.x()-zona_puska->central_point.x()));
            double non_rand_y = generate_random_double_from_interval_of_double(zona_puska->central_point.y() - 0.5*fabs(sektor_zapuska->first_point.y()-zona_puska->central_point.y()), sektor_zapuska->first_point.y() + 0.5*fabs(sektor_zapuska->first_point.y()-zona_puska->central_point.y()));
            osob[j] = non_rand_x; osob[j+1] = non_rand_y;
        }
        nach_populyaciya[i] = osob;
    }

    return nach_populyaciya;
}

