#ifndef PAINT_ZZP_H
#define PAINT_ZZP_H

#include <QGraphicsObject>
#include <QPainter>
//#include <QGraphicsSceneMouseEvent>
//#include <QtMath>
//#include "functions.h"

class paint_ZZP : public QGraphicsObject
{
    Q_OBJECT

public:
    explicit paint_ZZP(QVector<QPointF> points, QObject *parent = nullptr);
    ~paint_ZZP();

private:
    QRectF boundingRect() const; // ОБЯЗАТЕЛЬНАЯ функция, определяющая прямокгольник, в котором лежит вся фигура (не обязательно минимальный прямоугольник)
    QPainterPath shape() const; // НЕобязательная функция, определяющая область для взаимодействия с мышью (физический контур рисуемого объекта)
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // функция рисования
    void calculate_polygon();

public:
    void set_end_point(QPointF end_point);
    void add_point(QPointF new_point);

    QVector<QPointF> tochki;

private:


};

#endif // PAINT_ZZP_H
