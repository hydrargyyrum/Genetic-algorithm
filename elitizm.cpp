#include "functions.h"

QVector<QVector<double>> elitizm(QVector<QVector<double>> nach_populyaciya, QVector<double> ocenki_star, double percent_elit) {

    QVector<QVector<double>> populyaciya_potomkov; //(nach_populyaciya.size()); // Создаём список потомков

    int kol_elit_roditeley = round((percent_elit/100.0)*nach_populyaciya.size()); // Сколько-то % (с округлением до целого) от популяции будут элитными особями
    int ostatok = kol_elit_roditeley % 2;
    kol_elit_roditeley -= ostatok;

    // Делаем элитизм
    for (int j = 0; j < kol_elit_roditeley; j++) {
        double max_elem_ocenki = * std::max_element(ocenki_star.begin(), ocenki_star.end());
        int nom_max_elem;
        for (int l = 0; l < ocenki_star.size(); l++) {
            if (fabs(max_elem_ocenki-ocenki_star[l]) < 0.0000001) {
                nom_max_elem = l;
                break;
            }
        }
        //populyaciya_potomkov[j] = nach_populyaciya[nom_max_elem];
        populyaciya_potomkov.push_back(nach_populyaciya[nom_max_elem]);
        nach_populyaciya.remove(nom_max_elem);
        ocenki_star.remove(nom_max_elem);
    }

    return populyaciya_potomkov;
}
