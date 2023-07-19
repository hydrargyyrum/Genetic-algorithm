#ifndef INTERSECTION_FUNCTIONS_H
#define INTERSECTION_FUNCTIONS_H


#include <QVector>
#include <math.h>
#include <QPointF>
#include <QLineF>
#include <QPolygon>


double twisted_product(double &v1x, double &v1y, double &v2x, double &v2y);
double dot_product(double &v1x, double &v1y, double &v2x, double &v2y);

bool isPointInSeg(QLineF &line_segment, QPointF &tested_point);

QPointF LiinesegCrossLineseg(QLineF &line_segment1, QLineF &line_segment2);
QVector<QPointF> linesegment_cross_polygon(QVector<QPointF> &polygon_points, QLineF &linesegment);

#endif // INTERSECTION_FUNCTIONS_H
