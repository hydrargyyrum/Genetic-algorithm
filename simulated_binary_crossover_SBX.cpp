#include "functions.h"

QVector<QVector<double>> simulated_binary_crossover_SBX(QVector<QVector<double>> populyaciya_potomkov, QVector<QVector<double>> populyaciya_roditeley, double veroyat_skreshch) {

    // имитация двоичного скрещивания
    // ключевая особенность - равенство среднего значения хромосомы у родителей и потомков //

    // вводим некоторые параметры:
    double eta = 10.0; // или "20.0" - ИССЛЕДОВАТЬ ВОПРОС // "индекс распределения" - параметр, отвечающий за близость потомков к родителям
    /*
     double u = QRandomGenerator::global()->generateDouble(); // - некоторая величина ([0, 1]), использующаяся в формуле для параметра beta

     double beta; // коэффициент распределения: при beta = 1 потомки будут полностью идентичны родителям,
                  // при <1 - средние значения потомков будут ближе друг к другу, чем у родителей,
                  // при >1 - .. дальше друг ото друга. Значение зависит от u.
     if (u <= 0.5) beta = pow(2*u, 1.0/(eta + 1.0));
     else beta = pow(0.5*(1-u), 1.0/(eta + 1.0));

     u и beta формируются заново для каждой пары родителей при скрещивании (для каждой пары - новые значения)
     */

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
                double u = QRandomGenerator::global()->generateDouble();
                double beta;
                if (u <= 0.5) beta = pow(2*u, 1.0/(eta + 1.0));
                else beta = pow(0.5*(1-u), 1.0/(eta + 1.0));

                double a = 0.5*((1.0+beta)*potomok1[i] + (1.0-beta)*potomok2[i]),
                       b = 0.5*((1.0-beta)*potomok1[i] + (1.0+beta)*potomok2[i]);

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
            // УДАЛЕНИЕ РОДИТЕЛЕЙ ИЗ СПИСКА -НЕ- ПРОИЗВОДИТСЯ
                            if (rod1 > rod2) {
                                populyaciya_roditeley.remove(rod1);
                                populyaciya_roditeley.remove(rod2);
                            }
                            else {
                                populyaciya_roditeley.remove(rod2);
                                populyaciya_roditeley.remove(rod1);
                            }
        }
    }

    return populyaciya_potomkov;
}
