#include "functions.h"
#include <QDebug>

QVector<QVector<double>> crossover(QVector<QVector<double>> populyaciya_potomkov, QVector<QVector<double>> populyaciya_roditeley, int tip_skreshch, double veroyat_skreshch) {

    switch(tip_skreshch) {
    case 0: { // одноточечное скрещивание
        int k = 1; // кол-во разделителей в массиве
        populyaciya_potomkov = k_point_crossover(populyaciya_potomkov, populyaciya_roditeley, k, veroyat_skreshch);
        break;
    }
    case 1: { // двуточечное скрещивание
        int k = 2; // кол-во разделителей в массиве
        populyaciya_potomkov = k_point_crossover(populyaciya_potomkov, populyaciya_roditeley, k, veroyat_skreshch);
        break;
    }
    case 2: { // трёхточечное скрещивание
        int k = 3; // кол-во разделителей в массиве
        populyaciya_potomkov = k_point_crossover(populyaciya_potomkov, populyaciya_roditeley, k, veroyat_skreshch);
        break;
    }
    case 3: { // равномерное скрещивание
        populyaciya_potomkov = uniform_crossover(populyaciya_potomkov, populyaciya_roditeley, veroyat_skreshch);
        break;
    }
    case 4: { // скрещивание смешением (BLX)
        populyaciya_potomkov = blend_crossover_BLX(populyaciya_potomkov, populyaciya_roditeley, veroyat_skreshch);
        break;
    }
    case 5: { // имитация двоичного скрещивания (ИДС/SBX)
        populyaciya_potomkov = simulated_binary_crossover_SBX(populyaciya_potomkov, populyaciya_roditeley, veroyat_skreshch);
        break;
    }
        break;
    }

    return populyaciya_potomkov;
}

