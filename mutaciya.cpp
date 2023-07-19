#include "functions.h"
#include <random>

QVector<QVector<double>> mutaciya(QVector<QVector<double>> populyaciya_potomkov, double shance_mutacii, int tip_mutacii, int glub_mutacii) {

    std::mt19937 generator(std::time(nullptr));

    switch (tip_mutacii) {
        case 0: { // мутация обменом
            for (int i = 0; i < populyaciya_potomkov.size(); i++) {
                double ver = QRandomGenerator::global()->generateDouble(); // дробное число в диапазоне [0, 1)
                // int ver = QRandomGenerator::global()->bounded(0, 100); // вычислим вероятность того, что этот потомок мутирует
                if (ver <= shance_mutacii) { // Если вероятность входит в заданный интервал, то мутируем
                    int nom_gen1 = QRandomGenerator::global()->bounded(0, populyaciya_potomkov[i].size()); // ищем первый ген для обмена
                    int nom_gen2 = QRandomGenerator::global()->bounded(0, populyaciya_potomkov[i].size()); // ищем второй ген для обмена
                    // и меняем его в случае совпадения с первым:
                    while (nom_gen2 == nom_gen1)
                        nom_gen2 = QRandomGenerator::global()->bounded(0, populyaciya_potomkov[i].size());
                    // Совершаем обмен:
                    double gen1 = populyaciya_potomkov[i][nom_gen1];
                    populyaciya_potomkov[i][nom_gen1] = populyaciya_potomkov[i][nom_gen2];
                    populyaciya_potomkov[i][nom_gen2] = gen1;
                }
            }
            break;
        }
        case 1: { // мутация обращением
            for (int i = 0; i < populyaciya_potomkov.size(); i++) {
                double ver = QRandomGenerator::global()->generateDouble(); // дробное число в диапазоне [0, 1)
                // int ver = QRandomGenerator::global()->bounded(0, 100); // вычислим вероятность того, что этот потомок мутирует
                if (ver <= shance_mutacii) { // Если вероятность входит в заданный интервал, то мутируем
                    int prav_gr = round(populyaciya_potomkov[i].size()*glub_mutacii/100.0);
                    int dlina_intervala;
                    if (prav_gr < 2)
                        dlina_intervala = 2;
                    else
                        dlina_intervala = QRandomGenerator::global()->bounded(2, prav_gr); // ищем длину интервала

                    int nom_gen_nach = QRandomGenerator::global()->bounded(0, populyaciya_potomkov[i].size() - dlina_intervala); // левая граница интервала

                    // Создаём новую последовательность генов по найденному ранее интервалу
                    QVector<double> new_khromosoma;
                    for (int j = nom_gen_nach; j < nom_gen_nach + dlina_intervala; j++) {
                        new_khromosoma.push_back(populyaciya_potomkov[i][j]);
                    }
                    std::reverse(new_khromosoma.begin(), new_khromosoma.end()); // инвертируем её
                    // и вставляем обратно
                    for (int j = nom_gen_nach; j < nom_gen_nach + dlina_intervala; j++) {
                        populyaciya_potomkov[i][j] = new_khromosoma[j - nom_gen_nach];
                    }
                }
            }
            break;
        }
        case 2: { // мутация перетасовкой
            for (int i = 0; i < populyaciya_potomkov.size(); i++) {
                double ver = QRandomGenerator::global()->generateDouble(); // дробное число в диапазоне [0, 1)
                // int ver = QRandomGenerator::global()->bounded(0, 100); // вычислим вероятность того, что этот потомок мутирует
                if (ver <= shance_mutacii) { // Если вероятность входит в заданный интервал, то мутируем
                    int prav_gr = round(populyaciya_potomkov[i].size()*glub_mutacii/100.0);
                    int dlina_intervala;
                    if (prav_gr < 2)
                        dlina_intervala = 2;
                    else
                        dlina_intervala = QRandomGenerator::global()->bounded(2, prav_gr); // ищем длину интервала

                    int nom_gen_nach = QRandomGenerator::global()->bounded(0, populyaciya_potomkov[i].size() - dlina_intervala); // левая граница интервала

                    // Создаём новую последовательность генов по найденному ранее интервалу
                    QVector<double> new_khromosoma;
                    for (int j = nom_gen_nach; j < nom_gen_nach + dlina_intervala; j++) {
                        new_khromosoma.push_back(populyaciya_potomkov[i][j]);
                    }
                    // ПЕРЕТАСОСЫВАЕМ ЕЁ случайным образом:
                    QVector<double> new_khromosoma_tasovan;
                    while (new_khromosoma.size() > 0) {
                        int poz = QRandomGenerator::global()->bounded(0, new_khromosoma.size());
                        new_khromosoma_tasovan.push_back(new_khromosoma[poz]);
                        new_khromosoma.remove(poz);
                    }
                    // и вставляем обратно
                    for (int j = nom_gen_nach; j < nom_gen_nach + dlina_intervala; j++) {
                        populyaciya_potomkov[i][j] = new_khromosoma_tasovan[j - nom_gen_nach];
                    }
                }
            }
            break;
        }
    case 3: { // Нормальная мутация (мутация вещ. чисел)
        for (int i = 0; i < populyaciya_potomkov.size(); i++) {
            double ver = QRandomGenerator::global()->generateDouble(); // дробное число в диапазоне [0, 1)
            if (ver <= shance_mutacii) { // Если вероятность входит в заданный интервал, то мутируем
                int nom_gen = QRandomGenerator::global()->bounded(0, populyaciya_potomkov[i].size()); // ищем первый ген для обмена
                // Совершаем изменение значения гена по принципу генерации числа с нормальным распределением с мат.
                // ожиданием, равным текущему значению гена (а СКО задаётся как десятая доля от модуля МО):
                std::normal_distribution<double> distribution(populyaciya_potomkov[i][nom_gen],fabs(0.1*populyaciya_potomkov[i][nom_gen]));
                //                                                              ^                        ^
                //                                             среднее значение |                        | СКО (сигма; отклонение влево и вправо: 1s - 68% данных, 2s - 95% данных, 3s - 99,7% данных)
                double new_gen_value = distribution(generator);
                populyaciya_potomkov[i][nom_gen] = new_gen_value;
            }
        }
        break;
    }
    case 4: { // Мутация инвертированием гена
        for (int i = 0; i < populyaciya_potomkov.size(); i++) {
            double ver = QRandomGenerator::global()->generateDouble(); // дробное число в диапазоне [0, 1)
            if (ver <= shance_mutacii) { // Если вероятность входит в заданный интервал, то мутируем
                int nom_gen = QRandomGenerator::global()->bounded(0, populyaciya_potomkov[i].size()); // ищем первый ген для обмена
                // Совершаем инвертирование:
                double inversion = -1;
                populyaciya_potomkov[i][nom_gen] = inversion*populyaciya_potomkov[i][nom_gen];
            }
        }
        break;
    }
        break;
    }
    return populyaciya_potomkov;
}
