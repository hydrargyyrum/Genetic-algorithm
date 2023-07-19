#include "paint_solution.h"


paint_solution::paint_solution(QVector<double> marshrut_PPPM, QVector<uint8_t> color_RGB, double central_ugol_sektora, QObject *parent) : marshrut(marshrut_PPPM), color(color_RGB), glav_ug_sektora(central_ugol_sektora), QGraphicsObject()
{
    calculate();
}


paint_solution::~paint_solution() {

}


QRectF paint_solution::boundingRect() const {

    QVector<float> massiv_X, massiv_Y;
    for (int i = 0; i < marshrut.length(); i = i+2) {
        // точки идут парами, поэтому можно просто производить одинаковые процедуры с обоими массивами сразу
        massiv_X.push_back(marshrut[i]);
        massiv_Y.push_back(marshrut[i+1]);
    }
    float min_x = *std::min_element(massiv_X.begin(), massiv_X.end()) - 5;
    float max_x = *std::max_element(massiv_X.begin(), massiv_X.end()) + 5;
    float min_y = *std::min_element(massiv_Y.begin(), massiv_Y.end()) - 5;
    float max_y = *std::max_element(massiv_Y.begin(), massiv_Y.end()) + 5;

    return QRectF (min_x,min_y,max_x-min_x,max_y-min_y);
//    return QRectF (0, 0, window_width, window_height);
}


QPainterPath paint_solution::shape() const {
    QPainterPath Path;

//    QVector<QPointF> massiv_tochek;

//    for (int j = 0; j < points_x_polygon.size(); j++) {
//        massiv_tochek.push_back({points_x_polygon[j], points_y_polygon[j]});
//    }

    //Path.addPolygon(QPolygonF(tochki_res_ellipsa));
    return Path;
}


void paint_solution::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {

    QPen pen;
    //uint8_t red = 227, green = 66, blue = 52, transparency = 255; // всё от 0 до 255
    uint8_t red = color[0], green = color[1], blue = color[2], transparency = 255; // всё от 0 до 255
    QColor color_liniy = QColor(red, green, blue, transparency);
    pen.setBrush(color_liniy);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setWidth(2);

    //painter->setBrush(color_liniy);
    //painter->setPen(color_liniy);

    painter->setRenderHint(QPainter::Antialiasing); // добавляем сглаживание линиям

    //painter->setPen(Qt::PenJoinStyle(Qt::RoundJoin));

    painter->setPen(pen);

    for (int i = 0; i < marshrut.length()-1-2; i = i+2) {
        painter->drawLine(marshrut[i], marshrut[i+1], marshrut[i+2], marshrut[i+3]);
    }

    QFont serifFont("Times", 10, QFont::Bold);
    painter->setFont(serifFont);

    for (int i = 0; i < ugly_PPPM.length(); i++) {
        QPointF point_of_text = {0,0};
        point_of_text.setX(marshrut[i*2 + 2]);
        point_of_text.setY(marshrut[i*2 + 3] - 5);
        painter->drawText(point_of_text, QString::number(qRadiansToDegrees(ugly_PPPM[i]), 'g', 4));
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}


void paint_solution::calculate() {

    for (int i = 0; i < marshrut.length()-1-4; i = i+2) {
        double ugol_povorota_l_lp1 = fabs(atan2((marshrut[i+3]-marshrut[i+1]), (marshrut[i+2]-marshrut[i+0])) - atan2((marshrut[i+5]-marshrut[i+3]), (marshrut[i+4]-marshrut[i+2])));
        ugly_PPPM.push_back(ugol_povorota_l_lp1);
    }
    double last_ugol = glav_ug_sektora - atan2((marshrut[marshrut.length()-1-0]-marshrut[marshrut.length()-1-2]), (marshrut[marshrut.length()-1-1]-marshrut[marshrut.length()-1-3]));
    ugly_PPPM.push_back(last_ugol);
}
