#include "functions.h"

QVector<QVector<double>> uniform_crossover(QVector<QVector<double>> populyaciya_potomkov, QVector<QVector<double>> populyaciya_roditeley, double veroyat_skreshch) {

    // равномерное скрещивание

    int treb_razmer_spiska = populyaciya_roditeley.size();
    while (populyaciya_potomkov.size() < treb_razmer_spiska) {
        // Выберем случайным образом двух НЕОДИНАКОВЫХ родителей для скрещивания
        int rod1 = QRandomGenerator::global()->bounded(0, populyaciya_roditeley.size() - 1); // !!! правая граница не включается в выборку
        int rod2 = QRandomGenerator::global()->bounded(0, populyaciya_roditeley.size() - 1);
        while (rod2 == rod1) {
            rod2 = QRandomGenerator::global()->bounded(0, populyaciya_roditeley.size() - 1);
        }
        // Проверяем вероятность скрещивания
        double ver_skreshch_tek = QRandomGenerator::global()->generateDouble(); // дробное число в диапазоне [0, 1)

        if (ver_skreshch_tek > (1 - veroyat_skreshch)) { // Если текущая вероятность больше порогового минимума, то начинаем скрещивание:
            QVector<double> potomok1 = populyaciya_roditeley[rod1];
            QVector<double> potomok2 = populyaciya_roditeley[rod2];

            for (int i = 0; i < potomok1.size()-1; i++) {
                double ver_obmena = QRandomGenerator::global()->generateDouble(); // дробное число в диапазоне [0, 1)
                if (ver_obmena >= 0.5) {
                    double a = potomok1[i];
                    double b = potomok2[i];
                    potomok1[i] = b;
                    potomok2[i] = a;
                }
            }

            populyaciya_potomkov.push_back(potomok1);
            if (populyaciya_potomkov.size() < treb_razmer_spiska)
                populyaciya_potomkov.push_back(potomok2);
        }
        else { // иначе (если вероятность вошла в диапазон "неудачи"), просто копируем обоих родителей в новое поколение
            populyaciya_potomkov.push_back(populyaciya_roditeley[rod1]);
            if (populyaciya_potomkov.size() < treb_razmer_spiska)
                populyaciya_potomkov.push_back(populyaciya_roditeley[rod2]);
            // УДАЛЕНИЕ РОДИТЕЛЕЙ ИЗ СПИСКА НЕ ПРОИЗВОДИТСЯ
            //                if (rod1 > rod2) {
            //                    populyaciya_roditeley.remove(rod1);
            //                    populyaciya_roditeley.remove(rod2);
            //                }
            //                else {
            //                    populyaciya_roditeley.remove(rod2);
            //                    populyaciya_roditeley.remove(rod1);
            //                }
        }
    }
    return populyaciya_potomkov;
}
