#include "functions.h"

double procedure_sred_ocenka(QVector<double> ocenki) {

    double sred_ocenka = 0;
    for (int i = 0; i < ocenki.size(); i++) {
        sred_ocenka += ocenki[i];
    }
    sred_ocenka /= ocenki.size();

    return sred_ocenka;
}
