#include "functions.h"

QVector<QVector<double>> blend_crossover_BLX(QVector<QVector<double>> populyaciya_potomkov, QVector<QVector<double>> populyaciya_roditeley, double veroyat_skreshch) {

    // Скрещивание смешением

    double param_alpha = 0.5; // некоторый параметр, определяющий интервал смешения:
    // a = 1     x---------p1******p2---------x  вчетверо более широкий интервал
    // a = 0.5        x----p1******p2----x       вдвое более широкий интервал
    // a = 0              xp1******p2x           базовый интервал
    // где p1 и p2 - гены первого и второго родителя соответственно

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
                double lev_granica = potomok1[i] - param_alpha*(potomok2[i]-potomok1[i]),
                       prav_granica = potomok2[i] + param_alpha*(potomok2[i]-potomok1[i]);

                double a = generate_random_double_from_interval_of_double(lev_granica, prav_granica),
                       b = generate_random_double_from_interval_of_double(lev_granica, prav_granica);

                potomok1[i] = a;
                potomok2[i] = b;
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
