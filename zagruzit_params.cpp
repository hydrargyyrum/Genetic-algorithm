#include <QVector>
#include <QApplication>
#include <QFile>
#include <QDataStream>

#include "functions.h"

QVector<double> zagruzit_params(QVector<double> Params_GA) {
    QString put_k_failu = QCoreApplication::applicationDirPath();
    put_k_failu.push_back("/paramsGA.PCRG");
    QFile File(put_k_failu); // объявляем объект File класса QFile, являющийся "дескриптором" открываемого файла
    if (File.exists()) {
        File.open(QIODevice::ReadOnly); // применяем к объекту File метод open для его открытия в режиме только чтения (readonly)
        QDataStream in(&File);    // открываем возможность последовательного чтения данных из файла, объявляя объект in класса QDataStream, давая ссылку на объект File
        in.QDataStream::setFloatingPointPrecision(QDataStream::FloatingPointPrecision(QDataStream::DoublePrecision)); // сообщаем компилятору, как именно читать данные с плавающей точкой (float) - как single (4 байта) или как double (8 байт)
        in.QDataStream::setByteOrder(QDataStream::ByteOrder(QDataStream::BigEndian));

        for (int i = 0; i < 9; i++) {
            in >> Params_GA[i];
        }
        File.close();
    }
    return Params_GA;
}
