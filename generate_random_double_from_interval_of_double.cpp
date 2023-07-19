#include "functions.h"

double generate_random_double_from_interval_of_double(double lowest_num, double highest_num) {
    // функция генерации случайного вещественного числа из диапазона, заданного двумя вещественными числами
    // функция планировалась быть большой, но не склалось xD

    return (QRandomGenerator::global()->generateDouble() * fabs(highest_num - lowest_num) + lowest_num);
}
