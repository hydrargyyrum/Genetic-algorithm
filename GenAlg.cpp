#include "functions.h"

#include <QProgressBar>
#include <QtMath>
#include <QDebug>

// главная функция генетического алгоритма.
QVector<double> GenAlg(QVector<double> Params_GA, QVector<paint_ZZP*> nabor_ZZP, paint_zona_puska *zona_puska, paint_polygon_p *sektor_zapuska, QVector<double> params_of_task) {

    // // блок ввода параметров генетического алгоритма
//*    QVector<double> Params_GA = {500, 80, 20.0, 3, 0.95, 0, 0.1, 20.0, 0}; // параметры по умолчанию
    // кодировка: QVector<> Params_GA: 1. количество особей в популяции, 2. макс. кол-во поколений, 3. процент элитных особей,
    // 4. тип отбора, 5. вероятность скрещивания, 6. тип мутации, 7. вер. мутации, 8. сила мутации, 9. тип скрещивания
    // //
    // 4. 0 - рулетка, 1 - стохастическая универслаьная выборка (SUS), 2 - ранжированный отбор, 3 - турнирный отбор
    // 6. 0 - мутация обменом, 1 - мутация обращением, 2 - мутация перетасовкой, 3 - нормальная, 4 - инвертированием
    // 9. 0 - одноточечное скрещивание, 1 - двуточечное, 2 - трёхточечное, 3 - равномерное, 4 - смешением (BLX), 5 - ИДС (имитация двоичного скрещивания, SBX)


    // Функция "полуинтерфейса" в виде консольного меню

    //Params_GA = menu_params_GA(Params_GA);

    // // //
    QProgressDialog progress("Расчёт приближённым методом...", "Прервать", 0, 100);//, numFiles, this);
    progress.setWindowModality(Qt::WindowModal);
    // // //

    unsigned long TIC = clock();

    // Составим начальную популяцию
    // int kol_osobey_v_populyacii = 50;
    QVector<QVector<double>> nach_populyaciya = sost_nach_populyacii(Params_GA[0], params_of_task[0], nabor_ZZP, zona_puska, sektor_zapuska);//(kol_osobey_v_populyacii);

    // Оценим начальную популяцию
    QVector<double> ocenki_nach = procedure_ocenka(nach_populyaciya, nabor_ZZP, zona_puska, sektor_zapuska, params_of_task);
    double sred_ocen_nach = procedure_sred_ocenka(ocenki_nach);


	qDebug() << "оценки последней популяции: ";
	for (int i = 0; i < ocenki_nach.size(); i++) {
		qDebug() << i << ": " << ocenki_nach[i];
	}


    int tek_pokoleniye = 0;

    while (tek_pokoleniye < Params_GA[1]) {

        unsigned long TIC_vnutr = clock();

        QVector<QVector<double>> populyaciya_roditeley = OTBOR(Params_GA[3], nach_populyaciya, ocenki_nach);

        QVector<QVector<double>> populyaciya_potomkov = elitizm(nach_populyaciya, ocenki_nach, Params_GA[2]);

        populyaciya_potomkov = crossover(populyaciya_potomkov, populyaciya_roditeley, Params_GA[8], Params_GA[4]);

        populyaciya_potomkov = mutaciya(populyaciya_potomkov, Params_GA[6], Params_GA[5], Params_GA[7]);

        QVector<double> ocenki_potomkov = procedure_ocenka(populyaciya_potomkov, nabor_ZZP, zona_puska, sektor_zapuska, params_of_task);

		double sred_ocen_potomkov = procedure_sred_ocenka(ocenki_potomkov);
		qDebug() << "Средняя оценка поколения " << tek_pokoleniye << " составляет " << sred_ocen_potomkov;

        double max_elem_ocenki = * std::max_element(ocenki_nach.begin(), ocenki_nach.end());
        int nom_max_elem;
        for (int l = 0; l < ocenki_nach.size(); l++) {
            if (fabs(max_elem_ocenki-ocenki_nach[l]) < 0.0000001) {
                nom_max_elem = l;
                break;
            }
        }
        // double luchshaya_ocenka = ocenki_nach[nom_max_elem];

        float tek_pr = (tek_pokoleniye+1)/Params_GA[1]*100.0;

//        PrBar->setValue((int)tek_pr);
        progress.setValue((int)tek_pr);
        if (progress.wasCanceled()) return {1,2,3,4,5,6};


        double TOC_vnutr = (clock() - TIC_vnutr)/1000.0;
        float ostalos_vremeni = TOC_vnutr*(Params_GA[1] - tek_pokoleniye+1);
//        std::cout <<"\u001b[1;37;42m" << ostalos_vremeni << " сек.\r";

        nach_populyaciya = populyaciya_potomkov;
        ocenki_nach = ocenki_potomkov;
        tek_pokoleniye += 1;
    }

    // Ищем лучшую особь конечной популяции
    double max_elem_ocenki = * std::max_element(ocenki_nach.begin(), ocenki_nach.end());
    int nom_max_elem;
    for (int l = 0; l < ocenki_nach.size(); l++) {
        if (fabs(max_elem_ocenki-ocenki_nach[l]) < 0.0000001) {
            nom_max_elem = l;
            break;
        }
    }
    double luchshaya_ocenka = ocenki_nach[nom_max_elem];
    qDebug() << "лучшая оценка: " << luchshaya_ocenka;

//	qDebug() << "оценки последней популяции: ";
//	for (int i = 0; i < ocenki_nach.size(); i++) {
//		qDebug() << i << ": " << ocenki_nach[i];
//	}

    QVector<double> luchshaya_osob = nach_populyaciya[nom_max_elem];

    double TOC = (clock() - TIC)/1000.0;

    //     filing(i_ataka, variant, TOC, Veroyat_celey_1, Veroyat_celey_2);

    // добавляем в особь последнюю точку - точку запуска
    luchshaya_osob.push_back(sektor_zapuska->first_point.x());
    luchshaya_osob.push_back(sektor_zapuska->first_point.y());

    progress.setValue(100);

    return luchshaya_osob;
}
