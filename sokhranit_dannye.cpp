#include <functions.h>

#include <QDebug>

bool sokhranit_dannye(QString put_k_failu_istinniy, QVector<paint_ZZP*> nabor_ZZP, paint_zona_puska *zona_puska, paint_polygon_p *sektor_zapuska) {

    QFile File(put_k_failu_istinniy); // объявляем объект File класса QFile, являющийся "дескриптором" открываемого файла
    if (!File.open(QIODevice::WriteOnly)) // применяем к объекту File метод open для его открытия в режиме только чтения (readonly)
    { return false; }
    QDataStream out(&File);
    out.QDataStream::setFloatingPointPrecision(QDataStream::FloatingPointPrecision(QDataStream::SinglePrecision));
    out.QDataStream::setByteOrder(QDataStream::ByteOrder(QDataStream::BigEndian));
//static_cast<float>(

    out << static_cast<int>(nabor_ZZP.length());
    for (int i = 0; i < nabor_ZZP.length(); i++) {
        out << static_cast<int>(nabor_ZZP[i]->tochki.length());
        for (int j = 0; j < nabor_ZZP[i]->tochki.length(); j++) {
            out << static_cast<double>(nabor_ZZP[i]->tochki[j].x());
            out << static_cast<double>(nabor_ZZP[i]->tochki[j].y());
        }
    }

    out << static_cast<int>(zona_puska->tochki.length());
    for (int i = 0; i < zona_puska->tochki.length(); i++) {
        out << static_cast<double>(zona_puska->tochki[i].x());
        out << static_cast<double>(zona_puska->tochki[i].y());
    }

    out << static_cast<double>(sektor_zapuska->first_point.x());
    out << static_cast<double>(sektor_zapuska->first_point.y());
    out << static_cast<double>(sektor_zapuska->glavniy_ugol);
    out << static_cast<float>(sektor_zapuska->ugol_sektora);

    File.close();

    return true;
}
