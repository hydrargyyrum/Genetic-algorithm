#include <QVector>
#include <QApplication>
#include <QFile>
#include <QDataStream>

#include "functions.h"

void sokhranit_params(QVector<double> Params_GA) {
    QString put_k_failu = QCoreApplication::applicationDirPath();
    put_k_failu.push_back("/paramsGA.PCRG");
    QFile File(put_k_failu);
    File.remove(); // на всякий случай
    File.open(QIODevice::WriteOnly);
    QDataStream out(&File);
    out.QDataStream::setFloatingPointPrecision(QDataStream::FloatingPointPrecision(QDataStream::DoublePrecision));
    out.QDataStream::setByteOrder(QDataStream::ByteOrder(QDataStream::BigEndian));

    for (int i = 0; i < 9; i++) {
        out << Params_GA[i];
    }

    File.close();
}
