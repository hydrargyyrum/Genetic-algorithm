#include <QVector>
#include <QApplication>
#include <QFile>
#include <QDataStream>

#include "functions.h"

void save_params_of_task(QVector<double> Params_of_task) {
    QString put_k_failu = QCoreApplication::applicationDirPath();
    put_k_failu.push_back("/paramsGA.TaPa");
    QFile File(put_k_failu);
    File.remove(); // на всякий случай
    File.open(QIODevice::WriteOnly);
    QDataStream out(&File);
    out.QDataStream::setFloatingPointPrecision(QDataStream::FloatingPointPrecision(QDataStream::DoublePrecision));
    out.QDataStream::setByteOrder(QDataStream::ByteOrder(QDataStream::BigEndian));

    for (int i = 0; i < 5; i++) {
        out << Params_of_task[i];
    }

    File.close();
}
