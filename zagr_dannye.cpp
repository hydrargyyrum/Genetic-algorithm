#include "functions.h"

#include <QDebug>

struct_dannykh zagr_dannye(QString put_k_failu_istinniy) {

    struct_dannykh dannye;

    QFile File(put_k_failu_istinniy); // объявляем объект File класса QFile, являющийся "дескриптором" открываемого файла
    if (!File.open(QIODevice::ReadOnly)) // применяем к объекту File метод open для его открытия в режиме только чтения (readonly)
    { dannye.flag_korrektnosti = false; return dannye; }
    QFileInfo info(File); // проветриваем расширение файла - если открыт не PoDa, то сообщаем о неудаче
    if (info.suffix() != "PoDa") { dannye.flag_korrektnosti = false; return dannye; }

    QDataStream in(&File);    // открываем возможность последовательного чтения данных из файла, объявляя объект in класса QDataStream, давая ссылку на объект File
    in.QDataStream::setFloatingPointPrecision(QDataStream::FloatingPointPrecision(QDataStream::SinglePrecision)); // сообщаем компилятору, как именно читать данные с плавающей точкой (float) - как single (4 байта) или как double (8 байт)
    in.QDataStream::setByteOrder(QDataStream::ByteOrder(QDataStream::BigEndian));

    int kol_ZZP;
    in >> kol_ZZP;
    dannye.ZZP.resize(kol_ZZP);
    for (int i = 0; i < kol_ZZP; i++) {
        int kol_tochek_tek_ZZP;
        in >> kol_tochek_tek_ZZP;
        dannye.ZZP[i].resize(kol_tochek_tek_ZZP);
        for (int j = 0; j < kol_tochek_tek_ZZP; j++) {
            double x, y;
            in >> x >> y;
            dannye.ZZP[i][j] = {x, y};
        }
    }

    int kol_tochek_ZP;
    in >> kol_tochek_ZP;
    dannye.zona_puska.resize(kol_tochek_ZP);
    for (int i = 0; i < kol_tochek_ZP; i++) {
        double x, y;
        in >> x >> y;
        dannye.zona_puska[i] = {x,y};
    }

    double fpsp_x;
    double fpsp_y;
    double gusp;
    float ursp;
    in >> fpsp_x >> fpsp_y >> gusp >> ursp;
    dannye.first_point_sektora_puska = {fpsp_x, fpsp_y};
    dannye.glavniy_ugol_sektora_puska = gusp;
    dannye.ugol_rastvora_sektora_puska = ursp;

    dannye.flag_korrektnosti = true;

    File.close();

    return dannye;
}
