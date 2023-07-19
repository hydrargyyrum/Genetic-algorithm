#ifndef CUSTOM_PAINTSCENE_H
#define CUSTOM_PAINTSCENE_H

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>

#include <paint_zzp.h>

//#include "functions.h"

#include <paint_solution.h>

#include <QInputDialog>

#include <paint_zona_puska.h>

#include <paint_polygon_p.h>

class custom_paintscene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit custom_paintscene(int *tip_postr, double *angle_of_sector, QObject *parent = 0);
    ~custom_paintscene();

    void draw_solution(QVector<double> ellips_params, QVector<uint8_t> color_RGB);
    void delete_solution();
    void add_data_from_file(struct_dannykh dannye);

private:
    // Для рисования используем события мыши
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
//    void drawBackground(QPainter *painter, const QRectF &rect);
    void wheelEvent(QGraphicsSceneWheelEvent *event);

public:
    QVector<paint_ZZP*> nabor_ZZP;
    paint_solution *sol = nullptr;
    paint_zona_puska *zona_puska = nullptr;
    paint_polygon_p *sektor_zapuska = nullptr;

private:
    // Добавляем переменную (и не только её), следящую за комбинациями нажатий на ЛКМ
    int kol_naj_LKM;
    QPointF first_point, last_point;

    paint_ZZP *vrem_zzp;

    QGraphicsObject *pressed_uni_item = nullptr;

    int *tip_postroyeniya;
    double *sector_angle;

};

#endif // CUSTOM_PAINTSCENE_H
