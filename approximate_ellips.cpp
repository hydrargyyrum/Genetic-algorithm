#include "functions.h"
#include <Eigen/Dense>

#include <QDebug>

using Eigen::MatrixXd;
using Eigen::VectorXd;

QVector<double> approximate_ellips(QVector<QPointF> tochki_poligona) {

    // Аппроксимация методом наименьших квадратов (МНК) эллипса по заданным точкам (xi,yi)

    int N = tochki_poligona.length();

    QVector<double> X(N);
    QVector<double> Y(N);
    for (int i = 0; i < N; i++) {
        X[i] = tochki_poligona[i].x();
        Y[i] = tochki_poligona[i].y();
    }

    // переменые производо-суммирования векторов //

    double sX = 0;
    for (int i = 0; i < N; i++) {
        sX += X[i];
    }
    double sX2 = 0;
    for (int i = 0; i < N; i++) {
        sX2 += X[i]*X[i];
    }
    double sX3 = 0;
    for (int i = 0; i < N; i++) {
        sX3 += X[i]*X[i]*X[i];
    }
    double sX4 = 0;
    for (int i = 0; i < N; i++) {
        sX4 += X[i]*X[i]*X[i]*X[i];
    }
    // // //
    double sY = 0;
    for (int i = 0; i < N; i++) {
        sY += Y[i];
    }
    double sY2 = 0;
    for (int i = 0; i < N; i++) {
        sY2 += Y[i]*Y[i];
    }
    double sY3 = 0;
    for (int i = 0; i < N; i++) {
        sY3 += Y[i]*Y[i]*Y[i];
    }
    double sY4 = 0;
    for (int i = 0; i < N; i++) {
        sY4 += Y[i]*Y[i]*Y[i]*Y[i];
    }
    // // //
    double sXY = 0;
    for (int i = 0; i < N; i++) {
        sXY += X[i]*Y[i];
    }
    double sX2Y = 0;
    for (int i = 0; i < N; i++) {
        sX2Y += X[i]*X[i]*Y[i];
    }
    double sX3Y = 0;
    for (int i = 0; i < N; i++) {
        sX3Y += X[i]*X[i]*X[i]*Y[i];
    }
    double sXY2 = 0;
    for (int i = 0; i < N; i++) {
        sXY2 += X[i]*Y[i]*Y[i];
    }
    double sXY3 = 0;
    for (int i = 0; i < N; i++) {
        sXY3 += X[i]*Y[i]*Y[i]*Y[i];
    }
    double sX2Y2 = 0;
    for (int i = 0; i < N; i++) {
        sX2Y2 += X[i]*X[i]*Y[i]*Y[i];
    }
    // // //

    MatrixXd A(6,6);
    A(0,0) = N;   A(0,1) = sX;   A(0,2) = sY;   A(0,3) = sXY;   A(0,4) = sX2;   A(0,5) = sY2;
    A(1,0) = sX;  A(1,1) = sX2;  A(1,2) = sXY;  A(1,3) = sX2Y;  A(1,4) = sX3;   A(1,5) = sXY2;
    A(2,0) = sY;  A(2,1) = sXY;  A(2,2) = sY2;  A(2,3) = sXY2;  A(2,4) = sX2Y;  A(2,5) = sY3;
    A(3,0) = sXY; A(3,1) = sX2Y; A(3,2) = sXY2; A(3,3) = sX2Y2; A(3,4) = sX3Y;  A(3,5) = sXY3;
    A(4,0) = sX2; A(4,1) = sX3;  A(4,2) = sX2Y; A(4,3) = sX3Y;  A(4,4) = sX4;   A(4,5) = sX2Y2;
    A(5,0) = sY2; A(5,1) = sXY2; A(5,2) = sY3;  A(5,3) = sXY3;  A(5,4) = sX2Y2; A(5,5) = sY4;

    VectorXd B(6); B << 1, 1, 1, 1, 1, 1; B.transpose();

    MatrixXd A_1 = A.inverse(); // обратная матрица

    VectorXd res = A_1 * B;

//    VectorXd xx(5); xx << 1,2,3,4,5;
//    VectorXd yy(5); yy << 6,7,8,9,10;
//    double product = xx.dot(yy); // это скалярка
//    qDebug() << "произведение: " << product;

    // параметры {A B C D E F}
    QVector<double> ellips_params = {res(4), res(3)/2.0, res(5), res(1)/2.0, res(2)/2.0, res(0)};

    return ellips_params;
}
