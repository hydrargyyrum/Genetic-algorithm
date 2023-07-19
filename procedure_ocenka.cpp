#include "functions.h"

QVector<double> procedure_ocenka(QVector<QVector<double>> populyaciya, QVector<paint_ZZP*> nabor_ZZP, paint_zona_puska *zona_puska, paint_polygon_p *sektor_zapuska, QVector<double> params_of_task) {


    double dopustimiy_ugol = qDegreesToRadians(params_of_task[1]); // ограничительный угол в радианах


    QVector<double> ocenki(populyaciya.size());

    // используется простая трассировка маршрута - задаём шаг, после чего разбиваем каждый интервал (от ПППМ(i) до ПППМ(i+1)) на N точек (округляем по шагам до целого числа в большую сторону) и считаем по ним длину части маршрута, проходящую через ЗЗП
//    double shag_trass = 5.0;

    // Пробежимся по всем генам всех хромосом для подсчёта
    for (int i = 0; i < populyaciya.size(); i++) { // для каждой особи в популяции производим проверку
        double sum = 0.0; // базовое ненулевое значение (временно)

        QPointF first_point = {populyaciya[i][0], populyaciya[i][1]};
        if (zona_puska->contains(first_point)) sum += 10000;
        else sum -= 50*sqrt(pow(first_point.x() - zona_puska->central_point.x(), 2) + pow(first_point.y() - zona_puska->central_point.y(), 2));

        double full_dist = 1.0;

//        QVector<int> kol_tochek_trassirovki;
        // единый блок подсчёта количества точек на интервалах между ПППМ //
        for (int j = 0; j < populyaciya[i].length()-2; j = j+2) {
            double xj = populyaciya[i][j],
                   yj = populyaciya[i][j+1],
                   xjp1 = populyaciya[i][j+2],
                   yjp1 = populyaciya[i][j+3];
            double dist_j_jp1 = sqrt((xjp1-xj)*(xjp1-xj) + (yjp1-yj)*(yjp1-yj));
            full_dist += dist_j_jp1;
//            kol_tochek_trassirovki.push_back(ceil(dist_j_jp1/shag_trass));
        }
        //последняя точка стоит особняком, поскольку не находится в массиве
        if (true) {
            double xj = populyaciya[i][populyaciya[i].length()-2],
                   yj = populyaciya[i][populyaciya[i].length()-1],
                   xjp1 = sektor_zapuska->first_point.x(),
                   yjp1 = sektor_zapuska->first_point.y();
                double dist_jend_tz = sqrt((xjp1-xj)*(xjp1-xj) + (yjp1-yj)*(yjp1-yj));
                full_dist += dist_jend_tz;
//                kol_tochek_trassirovki.push_back(ceil(dist_jend_tz/shag_trass));
        }
        // конец блока //

        double cross_dist = 0.0; // дистанция пересечений

        for (int p = 0; p < populyaciya[i].length()-2; p = p+2) {
            QLineF linesegment(populyaciya[i][p], populyaciya[i][p+1], populyaciya[i][p+2], populyaciya[i][p+3]);
            for (int z = 0; z < nabor_ZZP.length(); z++) {
                QVector<QPointF> solution =  linesegment_cross_polygon(nabor_ZZP[z]->tochki, linesegment);
                if (!solution.isEmpty()) {
                    cross_dist += sqrt(pow(solution[0].x() - solution[1].x(), 2) + pow(solution[0].y() - solution[1].y(), 2));
                    break;
                }
            }
        }
        // последняя точка стоит особняком, поскольку не находится в массиве
        double xj = populyaciya[i][populyaciya[i].length()-2],
                yj = populyaciya[i][populyaciya[i].length()-1],
                xjp1 = sektor_zapuska->first_point.x(),
                yjp1 = sektor_zapuska->first_point.y();
        QLineF linesegment(xj, yj, xjp1, yjp1);
        for (int z = 0; z < nabor_ZZP.length(); z++) {
            QVector<QPointF> solution =  linesegment_cross_polygon(nabor_ZZP[z]->tochki, linesegment);
            if (!solution.isEmpty()) {
                cross_dist += sqrt(pow(solution[0].x() - solution[1].x(), 2) + pow(solution[0].y() - solution[1].y(), 2));
                break;
            }
        }
        // // //

        // Проверим соответствие углу поворота у всех ПППМ
        double sum_angles_errors = 0.01;

        QVector<double> mar2 = populyaciya[i];
        mar2.push_back(sektor_zapuska->first_point.x());
        mar2.push_back(sektor_zapuska->first_point.y());
        for (int l = 0; l < mar2.length()-1-4; l = l+2) {
            double ugol_povorota_l_lp1 = fabs(atan2((mar2[l+3]-mar2[l+1]), (mar2[l+2]-mar2[l+0])) - atan2((mar2[l+5]-mar2[l+3]), (mar2[l+4]-mar2[l+2])));
            if (ugol_povorota_l_lp1 > dopustimiy_ugol) {
                sum_angles_errors += fabs(ugol_povorota_l_lp1-dopustimiy_ugol);
                //sum = sum/(qRadiansToDegrees(fabs(ugol_povorota_l_lp1 - dopustimiy_ugol)));
            }
            //else sum += 20000;
        }
        // проверка для конечного вектора направления:
        double last_ugol = atan2((mar2[mar2.length()-1-0]-mar2[mar2.length()-1-2]), (mar2[mar2.length()-1-1]-mar2[mar2.length()-1-3]));
        // qDebug() << qRadiansToDegrees(fabs(last_ugol-sektor_zapuska->glavniy_ugol));
        if (fabs(last_ugol-sektor_zapuska->glavniy_ugol) > qDegreesToRadians(params_of_task[2]/2.0)) {
            sum_angles_errors += fabs(last_ugol-sektor_zapuska->glavniy_ugol);
            //sum = sum/(qRadiansToDegrees(fabs(last_ugol-sektor_zapuska->glavniy_ugol)));
        }
        //else sum += 20000;


        sum = sum/(pow(cross_dist, params_of_task[3]) + full_dist*(pow(sum_angles_errors, params_of_task[4])));

//        qDebug() << "дП: " << full_dist;
//        qDebug() << "дЗ: " << cross_dist;

        ocenki[i] = sum;

//        qDebug() << "номер особи - " << i << ". кол-во точек трассировки: " << kol_tochek_trassirovki_sum;
//        qDebug() << "длина маршрута: " << marshrut.length() << ". текущая позиция указателя заполнения: " << tek_nezapoln_poz;
    }

    // многие методы несовместимы с отрицательными значениями фитнесс-функции,
    // но просто удалять такие особи не только сложно, но и нецелесообразно,
    // поэтому имеет смысл, возможно, просто инвертировать значения функции для отрицательных функций и уменьшать их в десять раз
    // (присваивание одинакового очень маленького числа неразумно по двум причинам: 1. особи становятся одинаковыми и хуже используются
    // 2. нельзя знать заранее, какие именно оценки будут у популяции. Возможно, оценки будут меньше той, что мы захотим присвоить
    // отрицательным особям, что просто сломает логику выполнения алгоритма).

//  -------------------
// |ВРЕМЕННО ОТКЛЮЧЕНО.| ИСПОЛЬЗОВАТЬ ТОЛЬКО ТУРНИРНЫЙ ОТБОР
//  -------------------

//    for (int i = 0; i < ocenki.size(); i++) {
//        if (ocenki[i] < 0) {
//            ocenki[i] = fabs(ocenki[i])/100.0;
//        }
//    }

    return ocenki;
}
