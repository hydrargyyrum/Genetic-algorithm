#include "functions.h"


QVector<QVector<double>> OTBOR(int tip_otbora, QVector<QVector<double>> nach_populyaciya, QVector<double> ocenki_nach) {

    QVector<QVector<double>> populyaciya_roditeley;

    switch (tip_otbora) {
        case 0: {
            populyaciya_roditeley = otbor_ruletka(nach_populyaciya, ocenki_nach);
            break;
        }
        case 1: {
            populyaciya_roditeley = otbor_SUS(nach_populyaciya, ocenki_nach);
            break;
        }
        case 2: {
            populyaciya_roditeley = otbor_rangir(nach_populyaciya, ocenki_nach);
            break;
        }
        case 3: {
            populyaciya_roditeley = otbor_turnir(nach_populyaciya, ocenki_nach);
            break;
        }
    }
    return populyaciya_roditeley;
}
