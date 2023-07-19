#include "paint_polygon_p.h"


paint_polygon_p::paint_polygon_p(QPointF f_point, QPointF l_point, double sector_angle, QObject *parent) : first_point(f_point), last_point(l_point), ugol_sektora(sector_angle), QGraphicsObject()
{
    calculate_polygon(first_point, last_point);
}


paint_polygon_p::paint_polygon_p(QPointF f_point, double glavniy_ugol, double ugol_sekt, QObject *parent) : first_point(f_point), ugol_sektora(ugol_sekt), QGraphicsObject() {

    double x_kon, y_kon, radius = 75.0;
    x_kon = first_point.x() + radius*cos(glavniy_ugol);
    y_kon = first_point.y() + radius*sin(glavniy_ugol); // Y инвертирована, но углы также инвертированы, поэтому следить за левой СК не обязательно

    last_point = {x_kon, y_kon};

    calculate_polygon(first_point, last_point);
}


paint_polygon_p::~paint_polygon_p() {

}


QRectF paint_polygon_p::boundingRect() const {

    float min_x, min_y, max_x, max_y;
    min_x = *std::min_element(points_x_polygon.begin(), points_x_polygon.end()) - 5;
    max_x = *std::max_element(points_x_polygon.begin(), points_x_polygon.end()) + 5;
    min_y = *std::min_element(points_y_polygon.begin(), points_y_polygon.end()) - 5;
    max_y = *std::max_element(points_y_polygon.begin(), points_y_polygon.end()) + 5;

    return QRectF (min_x,min_y,max_x-min_x,max_y-min_y);
}


QPainterPath paint_polygon_p::shape() const {
    QPainterPath Path;

    QVector<QPointF> massiv_tochek;

    for (int j = 0; j < points_x_polygon.size(); j++) {
        massiv_tochek.push_back({points_x_polygon[j], points_y_polygon[j]});
    }

    Path.addPolygon(QPolygonF(massiv_tochek));
    Path.addEllipse(first_point.x()-5, first_point.y()-5, 10, 10);
    return Path;
}


void paint_polygon_p::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    uint8_t red = 118, green = 255, blue = 122, transparency = 50; // всё от 0 до 255
    QColor color_rastrub = QColor(red, green, blue, transparency);
    painter->setBrush(color_rastrub);

    QFont serifFont("Times", 11, QFont::Bold);
    painter->setFont(serifFont);

    painter->setRenderHint(QPainter::Antialiasing); // добавляем сглаживание линиям
    painter->setRenderHint(QPainter::TextAntialiasing); // добавляем сглаживание тексту
    painter->setRenderHint(QPainter::SmoothPixmapTransform); // сглаживание картиночек

    QVector<QPointF> massiv_tochek;

    for (int j = 0; j < points_x_polygon.size(); j++) {
        massiv_tochek.push_back({points_x_polygon[j], points_y_polygon[j]});
    }

    painter->drawPolygon(massiv_tochek);

    uint8_t red_a = 201, green_a = 53, blue_a = 34, transparency_a = 180; // всё от 0 до 255
    QColor color_center_ataka = QColor(red_a, green_a, blue_a, transparency_a);
    painter->setBrush(color_center_ataka);
    painter->drawEllipse(first_point.x()-5, first_point.y()-5, 10, 10);

    // выведем главный угол сектора
    QPointF point_of_text = {0,0};
    if (last_point.x()-first_point.x() > 0) { point_of_text.setX(last_point.x() + 5); }
    else { point_of_text.setX(last_point.x() - 60); }
    if (last_point.y()-first_point.y() > 0) { point_of_text.setY(last_point.y() + 15); }
    else { point_of_text.setY(last_point.y() - 5); }

        painter->drawText(point_of_text, QString::number(qRadiansToDegrees(glavniy_ugol), 'g', 5));
    //

    Q_UNUSED(option);
    Q_UNUSED(widget);
}


void paint_polygon_p::calculate_polygon(QPointF first_p, QPointF last_p) {
    float X0 = first_p.x(), Y0 = first_p.y(), X1 = last_p.x(), Y1 = last_p.y();

  glavniy_ugol = atan2(Y1-Y0, X1-X0);

    float Ugol_rastruba = ugol_sektora;
    int kol_tochek = (int)ugol_sektora;//*2; //100;
    float shag = Ugol_rastruba/kol_tochek;

    QVector<float> X;
    QVector<float> Y;



    float X_nach = (X1-X0)*qCos(qDegreesToRadians(+Ugol_rastruba/2)) - (Y1-Y0)*qSin(qDegreesToRadians(+Ugol_rastruba/2)) + X0;
    float Y_nach = (X1-X0)*qSin(qDegreesToRadians(+Ugol_rastruba/2)) + (Y1-Y0)*qCos(qDegreesToRadians(+Ugol_rastruba/2)) + Y0;

//    // если окружность не замкнута, то две прямые сектора должны превратиться в ортодромии
//    // начнём с первой прямой:
//    if (ugol_sektora < 360.0) {
//        QVector<float> LB1 = xy2LB({(float)X0, (float)Y0});//, left_B, left_L, right_B, right_L, window_width, window_height);
//        QVector<float> LB2 = xy2LB({(float)X_nach, (float)Y_nach});//, left_B, left_L, right_B, right_L, window_width, window_height);
//        QVector<QPointF> orthodromy = interpolate_orthodromy(LB1[1], LB1[0], LB2[1], LB2[0], 20);
//        for (int i = 0; i < orthodromy.length(); i++) {
//            QVector<float> koords = LB2xy({(float)orthodromy[i].x(), (float)orthodromy[i].y()});//, left_B, left_L, right_B, right_L, window_width, window_height);
//            QPointF new_xy = {koords[0], koords[1]};
//            orthodromy[i] = new_xy;
//        }
//        for (int i = 0; i < orthodromy.length(); i++) {
//            X.push_back(orthodromy[i].x());
//            Y.push_back(orthodromy[i].y());
//        }
//    }

    X.push_back(X_nach); Y.push_back(Y_nach);
    for (float tek_ugol = 0; tek_ugol > -Ugol_rastruba; tek_ugol -= shag) {
        X.push_back((X_nach-X0)*qCos(qDegreesToRadians(tek_ugol)) - (Y_nach-Y0)*qSin(qDegreesToRadians(tek_ugol)) + X0);
        Y.push_back((X_nach-X0)*qSin(qDegreesToRadians(tek_ugol)) + (Y_nach-Y0)*qCos(qDegreesToRadians(tek_ugol)) + Y0);
    }
    X.push_back(X0); Y.push_back(Y0);

//    if (ugol_sektora < 360.0) {
// //        X.push_back(X0);
// //        Y.push_back(Y0);
//        float X_kon = (X1-X0)*qCos(qDegreesToRadians(-Ugol_rastruba/2)) - (Y1-Y0)*qSin(qDegreesToRadians(-Ugol_rastruba/2)) + X0;
//        float Y_kon = (X1-X0)*qSin(qDegreesToRadians(-Ugol_rastruba/2)) + (Y1-Y0)*qCos(qDegreesToRadians(-Ugol_rastruba/2)) + Y0;
//        QVector<float> LB1 = xy2LB({(float)X_kon, (float)Y_kon});//, left_B, left_L, right_B, right_L, window_width, window_height);
//        QVector<float> LB2 = xy2LB({(float)X0, (float)Y0});//, left_B, left_L, right_B, right_L, window_width, window_height);
//        QVector<QPointF> orthodromy = interpolate_orthodromy(LB1[1], LB1[0], LB2[1], LB2[0], 20);
//        for (int i = 0; i < orthodromy.length(); i++) {
//            QVector<float> koords = LB2xy({(float)orthodromy[i].x(), (float)orthodromy[i].y()});//, left_B, left_L, right_B, right_L, window_width, window_height);
//            QPointF new_xy = {koords[0], koords[1]};
//            orthodromy[i] = new_xy;
//        }
//        for (int i = 0; i < orthodromy.length(); i++) {
//            X.push_back(orthodromy[i].x());
//            Y.push_back(orthodromy[i].y());
//        }
//    }


//    // новый принцип - ищем равноудалённые точки сектора (если уж сектор радиальный)

//    double severnyi_ugol_glav_napravlen = qRadiansToDegrees(atan2(Y1 - Y0, X1 - X0)); // угол между севером и линией, соединяющей центр АО и указатель мыши
//    QVector<double> LBnach_centr = xy2LB({X0, Y0});
//    QVector<double> LBkon_centr = xy2LB({X1, Y1});
//    if (fabs(LBkon_centr[0] - LBnach_centr[0]) < 0.001) LBkon_centr[0] += 0.001;
//    // ортодромическое расстояние В МЕТРАХ
//    double tek_ortho_dist = 1000.0*111.1*qRadiansToDegrees((acos(sin(qDegreesToRadians(LBnach_centr[1]))*sin(qDegreesToRadians(LBkon_centr[1])) +
//            cos(qDegreesToRadians(LBnach_centr[1]))*cos(qDegreesToRadians(LBkon_centr[1]))*cos(qDegreesToRadians(LBkon_centr[0]-LBnach_centr[0])))));


//    double ugol_nach = severnyi_ugol_glav_napravlen - Ugol_rastruba/2.0;
//    double ugol_kon = severnyi_ugol_glav_napravlen + Ugol_rastruba/2.0;

//    int kol_shagov = ceil(tek_ortho_dist/(1.0*10000.0)); // аналог той же функции в MatLab
//    QVector<double> BL_nach = trace_by_direction(qDegreesToRadians(LBnach_centr[1]), qDegreesToRadians(LBnach_centr[0]), ugol_nach, tek_ortho_dist, kol_shagov);
//    if (BL_nach[1] > M_PI) BL_nach[1] = BL_nach[1] - 2.0*M_PI;  // поскольку ЗДЕСЬ мы РАБОТАЕМ с отрицательными долготами, а ГОСТ - нет, обращаем в отрицательные значения все долготы, превышающие значение ПИ
//    QVector<double> BL_kon = trace_by_direction(qDegreesToRadians(LBnach_centr[1]), qDegreesToRadians(LBnach_centr[0]), ugol_kon, tek_ortho_dist, kol_shagov);
//    if (BL_kon[1] > M_PI) BL_kon[1] = BL_kon[1] - 2.0*M_PI;  // поскольку ЗДЕСЬ мы РАБОТАЕМ с отрицательными долготами, а ГОСТ - нет, обращаем в отрицательные значения все долготы, превышающие значение ПИ

//    QVector<double> xy_nach = LB2xy({qRadiansToDegrees(BL_nach[1]), qRadiansToDegrees(BL_nach[0])});
//    QVector<double> xy_kon = LB2xy({qRadiansToDegrees(BL_kon[1]), qRadiansToDegrees(BL_kon[0])});

//    // если окружность не замкнута, то две прямые сектора должны превратиться в ортодромии
//    // начнём с первой прямой:
//    if (ugol_sektora < 360.0) {
//        QVector<double> LB1 = xy2LB({X0, Y0});//, left_B, left_L, right_B, right_L, window_width, window_height);
//        QVector<double> LB2 = xy2LB({xy_nach[0], xy_nach[1]});//, left_B, left_L, right_B, right_L, window_width, window_height);
//        QVector<QPointF> orthodromy = interpolate_orthodromy(LB1[1], LB1[0], LB2[1], LB2[0], 20);
//        for (int i = 0; i < orthodromy.length(); i++) {
//            QVector<double> koords = LB2xy({orthodromy[i].x(), orthodromy[i].y()});//, left_B, left_L, right_B, right_L, window_width, window_height);
//            QPointF new_xy = {koords[0], koords[1]};
//            orthodromy[i] = new_xy;
//        }
//        for (int i = 0; i < orthodromy.length(); i++) {
//            X.push_back(orthodromy[i].x());
//            Y.push_back(orthodromy[i].y());
//        }
//    }

//    double delta_ugol = (ugol_kon - ugol_nach)/kol_tochek;
//    for (double tek_ugol = ugol_nach+delta_ugol; tek_ugol <= ugol_kon; tek_ugol += delta_ugol) {
//        QVector<double> BL_tek = trace_by_direction(qDegreesToRadians(LBnach_centr[1]), qDegreesToRadians(LBnach_centr[0]), tek_ugol, tek_ortho_dist, kol_shagov);
//        if (BL_tek[1] > M_PI) BL_tek[1] = BL_tek[1] - 2.0*M_PI; // поскольку ЗДЕСЬ мы РАБОТАЕМ с отрицательными долготами, а ГОСТ - нет, обращаем в отрицательные значения все долготы, превышающие значение ПИ
//        QVector<double> koords = LB2xy({qRadiansToDegrees(BL_tek[1]), qRadiansToDegrees(BL_tek[0])});//, left_B, left_L, right_B, right_L, window_width, window_height);
//        X.push_back(koords[0]);
//        Y.push_back(koords[1]);
//    }

//    // и закончим второй прямой:
//    if (ugol_sektora < 360.0) {
//        QVector<double> LB1 = xy2LB({xy_kon[0], xy_kon[1]});//, left_B, left_L, right_B, right_L, window_width, window_height);
//        QVector<double> LB2 = xy2LB({X0, Y0});//, left_B, left_L, right_B, right_L, window_width, window_height);
//        QVector<QPointF> orthodromy = interpolate_orthodromy(LB1[1], LB1[0], LB2[1], LB2[0], 20);
//        for (int i = 0; i < orthodromy.length(); i++) {
//            QVector<double> koords = LB2xy({orthodromy[i].x(), orthodromy[i].y()});//, left_B, left_L, right_B, right_L, window_width, window_height);
//            QPointF new_xy = {koords[0], koords[1]};
//            orthodromy[i] = new_xy;
//        }
//        for (int i = 0; i < orthodromy.length(); i++) {
//            X.push_back(orthodromy[i].x());
//            Y.push_back(orthodromy[i].y());
//        }
//    }
// //    float X_nach = (X1-X0)*qCos(qDegreesToRadians(+Ugol_rastruba/2)) - (Y1-Y0)*qSin(qDegreesToRadians(+Ugol_rastruba/2)) + X0;
// //    float Y_nach = (X1-X0)*qSin(qDegreesToRadians(+Ugol_rastruba/2)) + (Y1-Y0)*qCos(qDegreesToRadians(+Ugol_rastruba/2)) + Y0;


    // // //

    points_x_polygon = X;
    points_y_polygon = Y;

    QVector<QPointF> massiv;
    for (int j = 0; j < X.size(); j++) {
        massiv.push_back({X[j], Y[j]});
    }
    tochki_poligona = massiv;
}

void paint_polygon_p::set_last_point(QPointF l_point) {
    last_point = l_point;
    paint_polygon_p::calculate_polygon(first_point, last_point);
}


void paint_polygon_p::set_ugol_rastvora(QPointF third_point) {
    // Функция, позволяющая мышью (движением курсора) определить ширину раструба -
    // чем дальше мышь от главной оси раструба, тем он шире.
    // Признано неоптимальным ввиду невозможности (сложности) создания замкнутого раструба и сложности вычислений в целом.

//    float dlina_sektora = sqrt(pow(last_point.x()-first_point.x() , 2) + pow(last_point.y()-first_point.y() , 2));
//    float x0, y0, x1, y1, x2, y2;
//    x0 = third_point.x(); y0 = third_point.y();
//    x1 = first_point.x(); y1 = first_point.y();
//    x2 = last_point.x(); y2 = last_point.y();
//    float dlina_perdendikulara = (fabs((y2-y1)*x0 - (x2-x1)*y0 + x2*y1 - y2*x1))/(sqrt(pow(y2-y1, 2) + pow(x2-x1, 2)));

}


void paint_polygon_p::set_ugol_rastvora(float ugol) {
    if (ugol < 5.0) ugol_sektora = 5.0;
    else if (ugol >= 360.0) ugol_sektora = 360.0;
    else ugol_sektora = ugol;
    paint_polygon_p::calculate_polygon(first_point, last_point);
}


float paint_polygon_p::get_ugol_rastvora() {
    return ugol_sektora;
}
