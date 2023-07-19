#include "functions.h"


QVector<QVector<double>> otbor_SUS(QVector<QVector<double>> nach_populyaciya, QVector<double> ocenki_nach) {

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

    // Найдём шаг (по шкале 0%...100% (0...1)), обозначающий расстояние между стрелками у "барабана" (равномерное размещение стрелок)
    double shag_strelki = 1.0 / nach_populyaciya.size(); // ( а-ля ((100/кол.особей)/100) )
    // Найдём базовую вероятность, обозначающую первую стрелку, от которой будут отсчитываться все остальные с найденным ранее шагом
    // Используется инверсия - крутится не барабан около неподвижных стрелок, а стрелки у неподвижного барабана
    double strelka1 = QRandomGenerator::global()->generateDouble(); // дробное число в диапазоне [0, 1)
    double strelka_tek = strelka1;

    for (int i = 0; i < nach_populyaciya.size(); i++) {
        for (int j = 0; j < granitsy.size(); j++) {
            if (strelka_tek >= granitsy[j][0] && strelka_tek < granitsy[j][1]) {
                populyaciya_roditeley[i] = nach_populyaciya[j];
                break;
            }
        }
        strelka_tek += shag_strelki;
        if (strelka_tek > 1) {
            strelka_tek -= 1;
        }
    }

    return populyaciya_roditeley;
}
