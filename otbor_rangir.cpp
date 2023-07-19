#include "functions.h"


QVector<QVector<double>> otbor_rangir(QVector<QVector<double>> nach_populyaciya, QVector<double> ocenki_nach) {

    QVector<QVector<double>> populyaciya_roditeley(nach_populyaciya.size());

    // Объявим переменную, содержащую ранги всех особей (младшая - 1, затем - 2, и т.д.)
    QVector<int> rang(nach_populyaciya.size());

    // Создаём копию популяции для последующего последовательного поиска наименьших элементов с исключением их их состава (а-ля сортировка, но без неё)
    QVector<double> ocenki_nach_kop = ocenki_nach;

    for (int i = 0; i < nach_populyaciya.size(); i++) {
        QVector<double>::iterator min_elem = std::min_element(ocenki_nach_kop.begin(), ocenki_nach_kop.end());
        int nom_min_elem = std::distance(ocenki_nach_kop.begin(), min_elem);
        rang[nom_min_elem] = i+1;
        ocenki_nach_kop[nom_min_elem] = 1e20;
    }

    // А теперь определим долю ранга
    double summar_ocenka = 0;
    for (int i = 0; i < rang.size(); i++) {
        summar_ocenka += rang[i];
    }

    QVector<double> dolya_ranga(rang.size());
    for (int i = 0; i < rang.size(); i++) {
        dolya_ranga[i] = rang[i]/summar_ocenka;
    }

    // И снова рулетка
    QVector<QVector<double>> granitsy(ocenki_nach.size());
    double tek_lev_gr = 0.0;

    for (int i = 0; i < granitsy.size(); i++) {
        granitsy[i].push_back(tek_lev_gr);
        granitsy[i].push_back(tek_lev_gr + dolya_ranga[i]);
        tek_lev_gr += dolya_ranga[i];
    }

    for (int i = 0; i < populyaciya_roditeley.size(); i++) {
        double chislo = QRandomGenerator::global()->generateDouble(); // дробное число в диапазоне [0, 1)

        for (int j = 0; j < granitsy.size(); j++) {
            if (chislo >= granitsy[j][0] && chislo < granitsy[j][1]) {
                populyaciya_roditeley[i] = nach_populyaciya[j];
                break;
            }
        }
    }

    return populyaciya_roditeley;
}
