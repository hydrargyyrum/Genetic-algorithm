#include "functions.h"


QVector<QVector<double>> otbor_turnir(QVector<QVector<double>> nach_populyaciya, QVector<double> ocenki_nach) {//, double percent_elit){

    QVector<QVector<double>> populyaciya_roditeley(nach_populyaciya.size());
//    int kol_elit_roditeley = round((percent_elit/100.0)*nach_populyaciya.size()); // Сколько-то % (с округлением до целого) от популяции будут элитными особями

//    QVector<QVector<int>> nach_populyaciya_kop = nach_populyaciya;
//    QVector<double> ocenki_nach_kop = ocenki_nach;

//    // Делаем элитизм
//    for (int j = 0; j < kol_elit_roditeley; j++) {
//        double max_elem_ocenki = * std::max_element(ocenki_nach_kop.begin(), ocenki_nach_kop.end());
//        int nom_max_elem;
//        for (int l = 0; l < ocenki_nach_kop.size(); l++) {
//            if (fabs(max_elem_ocenki-ocenki_nach_kop[l]) < 0.0000001) {
//                nom_max_elem = l;
//                break;
//            }
//        }
//        populyaciya_roditeley[j] = nach_populyaciya[nom_max_elem];
//        nach_populyaciya_kop.remove(nom_max_elem);
//        ocenki_nach_kop.remove(nom_max_elem);
//    }

    // Турнирный отбор из трёх:
    for (int i = 0; i < nach_populyaciya.size(); i++) {
        /*quint32*/ int kand1 = QRandomGenerator::global()->bounded(0, nach_populyaciya.size());
        int kand2 = QRandomGenerator::global()->bounded(0, nach_populyaciya.size());
        int kand3 = QRandomGenerator::global()->bounded(0, nach_populyaciya.size());

        if (ocenki_nach[kand1] >= ocenki_nach[kand2]) {
            if (ocenki_nach[kand1] >= ocenki_nach[kand3]) {
                populyaciya_roditeley[i] = nach_populyaciya[kand1];
            }
            else {
                populyaciya_roditeley[i] = nach_populyaciya[kand3];
            }
        }
        else {
            if (ocenki_nach[kand2] >= ocenki_nach[kand3]) {
            populyaciya_roditeley[i] = nach_populyaciya[kand2];
            }
            else {
                populyaciya_roditeley[i] = nach_populyaciya[kand3];
            }
        }
    }

    return populyaciya_roditeley;
}
