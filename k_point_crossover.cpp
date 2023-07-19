#include "functions.h"

QVector<QVector<double>> k_point_crossover(QVector<QVector<double>> populyaciya_potomkov, QVector<QVector<double>> populyaciya_roditeley, int k_tochek, double veroyat_skreshch) {

    // k-точечное скрещивание

    int k = k_tochek; // кол-во разделителей в массиве
    int max_kol_razdeliteley = populyaciya_roditeley[0].size();
    if (k > max_kol_razdeliteley) k = max_kol_razdeliteley;
    if (k < 1) k = 1;
    int treb_razmer_spiska = populyaciya_roditeley.size();

    while (populyaciya_potomkov.size() < treb_razmer_spiska) {
        // Выберем случайным образом двух НЕОДИНАКОВЫХ родителей для скрещивания
        int rod1 = QRandomGenerator::global()->bounded(0, populyaciya_roditeley.size()-1); // !!! правая граница не включается в выборку
        int rod2 = QRandomGenerator::global()->bounded(0, populyaciya_roditeley.size()-1);
        while (rod2 == rod1) {
            rod2 = QRandomGenerator::global()->bounded(0, populyaciya_roditeley.size()-1);
        }
        // Проверяем вероятность скрещивания
        double ver_skreshch_tek = QRandomGenerator::global()->generateDouble(); // дробное число в диапазоне [0, 1)

        if (ver_skreshch_tek > (1 - veroyat_skreshch)) { // Если текущая вероятность больше порогового минимума, то начинаем скрещивание:
            // объявим массив, где будут указаны координаты точек разделения
            // формат: указаны упорядоченные по возрастанию номера элементов, с которых части хромосом должны быть обменяны
            // то есть, даны интервальные границы: с элемента [0] включительно начинаем и меняем всё вплоть ДО элемента [1], не включая его
            QVector<int> ukazateli(k);
            for (int i = 0; i < k; i++) { // создаём k случайных неповторяющихся разделителей (с позиции "0" - "обменять с первых")
                if (i == 0) {
                    int poz_ukaz = QRandomGenerator::global()->bounded(0, (populyaciya_roditeley[0].size()-1) - ((k-1)-i)); // -1, чтобы указатель не мог стоять на последнем элементе
                    ukazateli[i] = poz_ukaz;
                }
                else {
                    int poz_ukaz = QRandomGenerator::global()->bounded(ukazateli[i-1]+1, (populyaciya_roditeley[0].size()-1) - ((k-1)-i)); // -1, чтобы указатель не мог стоять на последнем элементе
                    ukazateli[i] = poz_ukaz;
                }
            }
            QVector<double> potomok1 = populyaciya_roditeley[rod1];
            QVector<double> potomok2 = populyaciya_roditeley[rod2];
            // создаём флаговую переменную для переключения "заменять/не заменять"
            bool flag_obmena = false; // умолчание - "не заменять"
            for (int i = 0; i < populyaciya_roditeley[0].size() - 1; i++) {
                if (ukazateli.size() > 0) {
                    if (i == ukazateli[0]) { // если текущая позиция есть в указателях
                        ukazateli.remove(0); // убираем из указателей упоминание о текущей позиции
                        flag_obmena = !flag_obmena; // смена "не заменять -> заменяить" и обратно
                    }
                }
                if (flag_obmena) { // если "заменяем", то, соответственно, заменяем xD:
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
