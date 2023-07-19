#ifndef PAINT_SOLUTION_H
#define PAINT_SOLUTION_H

#include <QGraphicsObject>
#include <QPainter>
#include <functions.h>

class paint_solution : public QGraphicsObject
{
    Q_OBJECT

public:
    explicit paint_solution(QVector<double> marshrut_PPPM, QVector<uint8_t> color_RGB, double central_ugol_sektora, QObject *parent = nullptr);
    ~paint_solution();

private:
    QRectF boundingRect() const; // ОБЯЗАТЕЛЬНАЯ функция, определяющая прямоугольник, в котором лежит вся фигура (не обязательно минимальный прямоугольник)
    QPainterPath shape() const; // НЕобязательная функция, определяющая область для взаимодействия с мышью (физический контур рисуемого объекта) и другими объектами (поиск пересечений)
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // ОБЯЗАТЕЛЬНАЯ функция рисования

    void calculate();

public:

private:
    QVector<double> marshrut;
    QVector<uint8_t> color;

    QVector<double> ugly_PPPM;
    double glav_ug_sektora;
};

#endif // PAINT_SOLUTION_H
