#ifndef PAINT_ZONA_PUSKA_H
#define PAINT_ZONA_PUSKA_H

#include <QGraphicsObject>
#include <QPainter>

class paint_zona_puska : public QGraphicsObject
{
    Q_OBJECT

public:
    explicit paint_zona_puska(QVector<QPointF> points, QObject *parent = nullptr);
    ~paint_zona_puska();

private:
    QRectF boundingRect() const; // ОБЯЗАТЕЛЬНАЯ функция, определяющая прямокгольник, в котором лежит вся фигура (не обязательно минимальный прямоугольник)
    QPainterPath shape() const; // НЕобязательная функция, определяющая область для взаимодействия с мышью (физический контур рисуемого объекта)
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // функция рисования
    void calculate_polygon();

public:
    void set_end_point(QPointF end_point);
    void add_point(QPointF new_point);

    QVector<QPointF> tochki;
    double min_x, max_x, min_y, max_y;
    QPointF central_point;

private:
};

#endif // PAINT_ZONA_PUSKA_H
