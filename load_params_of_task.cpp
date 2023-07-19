#include <QVector>
#include <QApplication>
#include <QFile>
#include <QDataStream>

#include "functions.h"

QVector<double> load_params_of_task(QVector<double> Params_of_task) {
    QString put_k_failu = QCoreApplication::applicationDirPath();
    put_k_failu.push_back("/paramsGA.TaPa");
    QFile File(put_k_failu); // объявляем объект File класса QFile, являющийся "дескриптором" открываемого файла
    if (File.exists()) {
        File.open(QIODevice::ReadOnly); // применяем к объекту File метод open для его открытия в режиме только чтения (readonly)
        QDataStream in(&File);    // открываем возможность последовательного чтения данных из файла, объявляя объект in класса QDataStream, давая ссылку на объект File
        in.QDataStream::setFloatingPointPrecision(QDataStream::FloatingPointPrecision(QDataStream::DoublePrecision)); // сообщаем компилятору, как именно читать данные с плавающей точкой (float) - как single (4 байта) или как double (8 байт)
        in.QDataStream::setByteOrder(QDataStream::ByteOrder(QDataStream::BigEndian));

        for (int i = 0; i < 5; i++) {
            in >> Params_of_task[i];
        }
        File.close();
    }
    return Params_of_task;
}
