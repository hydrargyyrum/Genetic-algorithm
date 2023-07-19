#ifndef PAINT_POLYGON_P_H
#define PAINT_POLYGON_P_H

#include <QGraphicsObject>
#include <QPainter>
//#include <QGraphicsSceneMouseEvent>
#include <QtMath>
//#include "functions.h"
#include <QDebug>

class paint_polygon_p : public QGraphicsObject
{
    Q_OBJECT

public:
    explicit paint_polygon_p(QPointF f_point, QPointF l_point, double sector_angle, QObject *parent = nullptr); // для рисования мышью
    explicit paint_polygon_p(QPointF f_point, double glavniy_ugol, double ugol_sektora, QObject *parent = nullptr); // перегруженный - для загрузки из файла (полигон известен)
    ~paint_polygon_p();

private:
    QRectF boundingRect() const; // ОБЯЗАТЕЛЬНАЯ функция, определяющая прямокгольник, в котором лежит вся фигура (не обязательно минимальный прямоугольник)
    QPainterPath shape() const; // НЕобязательная функция, определяющая область для взаимодействия с мышью (физический контур рисуемого объекта)
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget); // функция рисования
    void calculate_polygon(QPointF, QPointF); // функция, рассчитывающая геометрию полигона при создании/изменении объекта

public:
    void set_last_point(QPointF);
    void set_ugol_rastvora(QPointF);
    void set_ugol_rastvora(float); // перегруженный метод для ввода угла с колёсика из scene
    float get_ugol_rastvora();

private:
    QPointF last_point; // а первая точка - центр сектора - публичная
    QVector<float> points_x_polygon;
    QVector<float> points_y_polygon;

public:
    QVector<QPointF> tochki_poligona; // для передачи в другие классы
    QPointF first_point;              // по сути, главная точка полигона (угол сектора)
    double ugol_sektora;
    double glavniy_ugol;
};

#endif // PAINT_POLYGON_P_H
