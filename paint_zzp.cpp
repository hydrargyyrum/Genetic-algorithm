#include "paint_zzp.h"

paint_ZZP::paint_ZZP(QVector<QPointF> points, QObject *parent) : tochki(points), QGraphicsObject()
{
    calculate_polygon();
}


paint_ZZP::~paint_ZZP() {

}


QRectF paint_ZZP::boundingRect() const {

    float min_x, min_y, max_x, max_y;
    QVector<float> mass_X;
    QVector<float> mass_Y;
    for (int i = 0; i < tochki.size(); i++) {
        mass_X.push_back(tochki[i].x());
        mass_Y.push_back(tochki[i].y());
    }
    min_x = *std::min_element(mass_X.begin(), mass_X.end())-2;
    max_x = *std::max_element(mass_X.begin(), mass_X.end())+2;
    min_y = *std::min_element(mass_Y.begin(), mass_Y.end())-2;
    max_y = *std::max_element(mass_Y.begin(), mass_Y.end())+2;

    return QRectF (min_x,min_y,max_x-min_x,max_y-min_y);
}


QPainterPath paint_ZZP::shape() const {

    QPainterPath Path;
    if (tochki.size() >= 3) {
        Path.addPolygon(QPolygonF(tochki));
    }
    return Path;
}


void paint_ZZP::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::red);
    uint8_t red = 240, green = 220, blue = 220, transparency = 70; // всё от 0 до 255
    QColor color_zzp = QColor(red, green, blue, transparency);
    painter->setBrush(color_zzp);

    painter->setRenderHint(QPainter::Antialiasing); // добавляем сглаживание линиям
    painter->setRenderHint(QPainter::TextAntialiasing); // добавляем сглаживание тексту
    //painter->setRenderHint(QPainter::SmoothPixmapTransform); // сглаживание картиночек

//    for (int i = 0; i < tochki.size() - 1; i++) {
//        painter->drawLine(tochki[i].x(), tochki[i].y(), tochki[i+1].x(), tochki[i+1].y());
//    }
    if (tochki.size() >= 3) {
        //painter->drawPolygon(tochki);
        painter->drawPolygon(tochki);
    }
    else {
        painter->drawLine({tochki[0], tochki[1]});
    }


    Q_UNUSED(option);
    Q_UNUSED(widget);
}


void paint_ZZP::calculate_polygon()
{

}


void paint_ZZP::set_end_point(QPointF end_point) {
    tochki.last() = end_point;
    calculate_polygon();
}


void paint_ZZP::add_point(QPointF new_point) {
    tochki.push_back(new_point);
    calculate_polygon();
}
