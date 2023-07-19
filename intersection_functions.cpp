#include "intersection_functions.h"

double twisted_product(double &v1x, double &v1y, double &v2x, double &v2y)
{
    return (v1x * v2y - v2x * v1y);
}


double dot_product(double &v1x, double &v1y, double &v2x, double &v2y)
{
    return (v1x * v2x + v1y * v2y);
}


bool isPointInSeg(QLineF &line_segment, QPointF &tested_point)
{
    double vecXls = line_segment.x2() - line_segment.x1();
    double vecYls = line_segment.y2() - line_segment.y1();
    double vecX_tp_ls1 = tested_point.x() - line_segment.x1();
    double vecY_tp_ls1 = tested_point.y() - line_segment.y1();
    double twp = twisted_product(vecXls, vecYls, vecX_tp_ls1, vecY_tp_ls1);

    double vecX_ls1_tp = line_segment.x1() - tested_point.x();
    double vecY_ls1_tp = line_segment.y1() - tested_point.y();
    double vecX_ls2_tp = line_segment.x2() - tested_point.x();
    double vecY_ls2_tp = line_segment.y2() - tested_point.y();
    double dp  = dot_product(vecX_ls1_tp, vecY_ls1_tp, vecX_ls2_tp, vecY_ls2_tp);

    //std::cout << dp << " " << twp << std::endl;
    if (fabs(twp) <= 1e-8 && dp <= 0)
    {
        double minx, miny, maxx, maxy;
        if (line_segment.x1() <= line_segment.x2()) { minx = line_segment.x1(); maxx = line_segment.x2(); }
        else { minx = line_segment.x2(); maxx = line_segment.x1(); }
        if (line_segment.y1() <= line_segment.y2()) { miny = line_segment.y1(); maxy = line_segment.y2(); }
        else { miny = line_segment.y2(); maxy = line_segment.y1(); }

        if ((minx <= tested_point.x() && maxx >= tested_point.x()) && (miny <= tested_point.y() && maxy >= tested_point.y()))
            return true;
    }
    return false;
}


QPointF LiinesegCrossLineseg(QLineF &line_segment1, QLineF &line_segment2)
        //double p1x, double p1y, double p2x, double p2y, double m1x, double m1y, double m2x, double m2y)
    {
        //Point2f dir1 = end1 - start1;
        //Point2f dir2 = end2 - start2;

        double vecXls1 = line_segment1.x2() - line_segment1.x1();
        double vecYls1 = line_segment1.y2() - line_segment1.y1();

        double vecXls2 = line_segment2.x2() - line_segment2.x1();
        double vecYls2 = line_segment2.y2() - line_segment2.y1();

        //считаем уравнения прямых проходящих через отрезки
        double a1 = -vecYls1;
        double b1 = +vecXls1;
        double d1 = -(a1 * line_segment1.x1() + b1 * line_segment1.y1());

        double a2 = -vecYls2;
        double b2 = +vecXls2;
        double d2 = -(a2 * line_segment2.x1() + b2 * line_segment2.y1());

        //подставляем концы отрезков, для выяснения в каких полуплоскотях они
        double seg1_line2_start = a2 * line_segment1.x1() + b2 * line_segment1.y1() + d2;
        double seg1_line2_end = a2 * line_segment1.x2() + b2 * line_segment1.y2() + d2;

        double seg2_line1_start = a1 * line_segment2.x1() + b1 * line_segment2.y1() + d1;
        double seg2_line1_end = a1 * line_segment2.x2() + b1 * line_segment2.y2() + d1;

        //если концы одного отрезка имеют один знак, значит он в одной полуплоскости и пересечения нет.
        if (seg1_line2_start * seg1_line2_end > 0 || seg2_line1_start * seg2_line1_end > 0)
        {
            //std::cout << seg1_line2_start << " " << seg1_line2_end << " " << seg2_line1_start << " " << seg2_line1_end << std::endl;
            //std::cout << "1" << std::endl;
            return {};
        }
        if (fabs(seg1_line2_start - seg1_line2_end) <= 1e-8)
        {
            //std::cout << "2" << std::endl;
            return {};
        }
        double u = seg1_line2_start / (seg1_line2_start - seg1_line2_end);

        if (u == 0)
            return {};

        double ansx = line_segment1.x1() + u * vecXls1;
        double ansy = line_segment1.y1() + u * vecYls1;

        QPointF searchable_solution = {ansx, ansy};

        if (!isPointInSeg(line_segment1, searchable_solution))
        {
            //std::cout << "3" << std::endl;
            return {};
        }

        if (!isPointInSeg(line_segment2, searchable_solution))
        {
            //std::cout << "3" << std::endl;
            return {};
        }

        QPointF intersection_point = {ansx, ansy};

        return intersection_point;
    }


QVector<QPointF> linesegment_cross_polygon(QVector<QPointF> &polygon_points, QLineF &linesegment) {
    QVector<QPointF> solution = {};

    QPolygonF real_polygon(polygon_points);

    QPointF ans;
    // проверяем все отрезки незамкнутого полигона
    for (int i = 0; i < polygon_points.length() - 1; i++) {
        QLineF part_of_polygon = {polygon_points[i], polygon_points[i+1]};
        ans = LiinesegCrossLineseg(part_of_polygon, linesegment);
        if (!ans.isNull()) { solution.push_back(ans); }
    }
    // проверяем замыкающий отрезок
    QLineF last_part_of_polygon = {polygon_points[0], polygon_points[polygon_points.length()-1]};
    ans = LiinesegCrossLineseg(last_part_of_polygon, linesegment);
    if (!ans.isNull()) { solution.push_back(ans); }

    // Проверяем наличие дубликатов (если отрезок попал в угол полигона, например)
    QVector<int> numbers_of_duplicates;
    for (int i = 0; i < solution.length() - 1; i++) {
        if ( fabs(solution[i].x() - solution[i+1].x()) < 1e-8 && fabs(solution[i].y() - solution[i+1].y()) < 1e-8 ) {
            numbers_of_duplicates.push_back(i);
        }
    }
    // и убираем их
    for (int i = numbers_of_duplicates.length()-1; i >= 0; i--) {
        solution.remove(i);
    }

    if (solution.length() <= 1) {
        bool p1_contains = real_polygon.containsPoint(linesegment.p1(), Qt::OddEvenFill),
             p2_contains = real_polygon.containsPoint(linesegment.p2(), Qt::OddEvenFill);
        if (p1_contains && p2_contains) {
            solution = {linesegment.p1(), linesegment.p2()};
        }
        else if (p1_contains && !p2_contains) {
            solution.push_back(linesegment.p1());
        }
        else if (!p1_contains && p2_contains) {
            solution.push_back(linesegment.p2());
        }
        else if (!p1_contains && !p2_contains) {
            solution = {};
        }
    }

    return solution;
}
