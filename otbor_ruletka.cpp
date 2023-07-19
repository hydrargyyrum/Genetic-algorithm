#include "functions.h"

QVector<QVector<double>> otbor_ruletka(QVector<QVector<double>> nach_populyaciya, QVector<double> ocenki_nach) {//, double percent_elit){

    QVector<QVector<double>> populyaciya_roditeley(nach_populyaciya.size());

    double summar_ocenka = 0;
    for (int i = 0; i < ocenki_nach.size(); i++) {
        summar_ocenka += ocenki_nach[i];
    }

    QVector<double> dolya(ocenki_nach.size());
    for (int i = 0; i < ocenki_nach.size(); i++) {
        dolya[i] = ocenki_nach[i]/summar_ocenka;
    }

    // Назначим переменную, описывающую границы сектора на барабане (по шкале от [0 до 100) ) для каждой особи
    // Первый вектор - особь, внутренний вектор - две части: левая граница (.[0]) и правая граница (.[1])
    QVector<QVector<double>> granitsy(ocenki_nach.size());
    double tek_lev_gr = 0.0;

    for (int i = 0; i < granitsy.size(); i++) {
        granitsy[i].push_back(tek_lev_gr);
        granitsy[i].push_back(tek_lev_gr + dolya[i]);
        tek_lev_gr += dolya[i];
    }

    for (int i = 0; i < populyaciya_roditeley.size(); i++) {
        double chislo = QRandomGenerator::global()->generateDouble(); // дробное число в диапазоне [0, 1)

        for (int j = 0; j < granitsy.size(); j++) {
            if (chislo >= granitsy[j][0] && chislo < granitsy[j][1]) {
                populyaciya_roditeley[i] = nach_populyaciya[j];
                //nach_populyaciya.remove(j);
                break;
            }
//            if (j == granitsy.size()-1) {
//                double j_rezervn = QRandomGenerator::global()->bounded(0, granitsy.size());
//                populyaciya_roditeley[i]
//            }
        }
    }

    return populyaciya_roditeley;
}
