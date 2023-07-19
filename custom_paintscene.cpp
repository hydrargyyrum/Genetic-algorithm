#include "custom_paintscene.h"
#include <QDebug>

//using namespace global;

custom_paintscene::custom_paintscene(int *tip_postr, double *angle_of_sector, QObject *parent) : QGraphicsScene(parent), tip_postroyeniya(tip_postr), sector_angle(angle_of_sector)
{
    kol_naj_LKM = 0;
}

custom_paintscene::~custom_paintscene()
{

}

void custom_paintscene::mousePressEvent(QGraphicsSceneMouseEvent * event) {

    if (event->button() == 1) {
        if (*tip_postroyeniya == 1) {
            if (kol_naj_LKM == 0) {
                QVector<QPointF> tek_tochki = {event->scenePos(), QPointF(event->scenePos().x()+1, event->scenePos().y()+1)};
                vrem_zzp = new paint_ZZP(tek_tochki);
                this->addItem(vrem_zzp);
                kol_naj_LKM = 1;
            }
            else if (kol_naj_LKM == 1) {
                vrem_zzp->add_point(event->scenePos());
            }
        }
        else if (*tip_postroyeniya == 2) {
            if (kol_naj_LKM == 0) {
                if (zona_puska != nullptr) {zona_puska->deleteLater(); zona_puska = nullptr;}
                QVector<QPointF> tek_tochki = {event->scenePos(), QPointF(event->scenePos().x()+1, event->scenePos().y()+1)};
                zona_puska = new paint_zona_puska(tek_tochki);
                this->addItem(zona_puska);
                kol_naj_LKM = 1;
            }
            else if (kol_naj_LKM == 1) {
                zona_puska->add_point(event->scenePos());
            }
        }
        else if (*tip_postroyeniya == 3) {
            if (kol_naj_LKM == 0) {
                if (sektor_zapuska != nullptr) {sektor_zapuska->deleteLater(); sektor_zapuska = nullptr;}
                first_point = event->scenePos();
                last_point = {event->scenePos().x()+1, event->scenePos().y()+1};

                sektor_zapuska = new paint_polygon_p(first_point, last_point, *sector_angle);
                this->addItem(sektor_zapuska);
                kol_naj_LKM = 1;
            }
            else if (kol_naj_LKM == 1) {
                kol_naj_LKM = 0;
            }
        }
    }
    else if (event->button() == 2) {
        // qDebug() << "X: " << event->scenePos().x() << "; Y: " << event->scenePos().y() << endl;
        if (kol_naj_LKM == 0) {
            pressed_uni_item = static_cast<QGraphicsObject*>(itemAt(event->scenePos(),QTransform()));
            if (pressed_uni_item != nullptr) {
                //qDebug() << pressed_uni_item->metaObject()->className();
                QString class_of_clicked_object_name = pressed_uni_item->metaObject()->className();
                if(class_of_clicked_object_name == "paint_ZZP") {
                    for (int i = 0; i < nabor_ZZP.size(); i++) {
                        if (nabor_ZZP[i] == pressed_uni_item) {
                            nabor_ZZP[i]->deleteLater();
                            nabor_ZZP.remove(i);
                        }
                    }
                }
                if(class_of_clicked_object_name == "paint_zona_puska") {
                            zona_puska->deleteLater();
                            zona_puska = nullptr;
                }
            }
        }
        else if (kol_naj_LKM == 1) {
            if (*tip_postroyeniya == 1) {
                nabor_ZZP.push_back(vrem_zzp);
                //this->removeItem(vrem_zzp);
                kol_naj_LKM = 0;
            }
            else if (*tip_postroyeniya == 2) {
                kol_naj_LKM = 0;
            }
        }
    }
}

void custom_paintscene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
    //qDebug() << "X: " << event->scenePos().x() << "; Y: " << event->scenePos().y() << endl;
    if (*tip_postroyeniya == 1) {
        if (kol_naj_LKM == 1) {
            vrem_zzp->set_end_point(event->scenePos());
            update();
        }
    }
    else if (*tip_postroyeniya == 2) {
        if (kol_naj_LKM == 1) {
            zona_puska->set_end_point(event->scenePos());
            update();
        }
    }
    else if (*tip_postroyeniya == 3) {
        if (kol_naj_LKM == 1) {
            last_point = event->scenePos();
            sektor_zapuska->set_last_point(last_point);
            update();
        }
    }
}


void custom_paintscene::wheelEvent(QGraphicsSceneWheelEvent *event) {

}


void custom_paintscene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {

}


//void custom_paintscene::drawBackground(QPainter *painter, const QRectF &rect) {
//    QImage kartinka = kartinka_fona;
//    QRectF target(0,0,this->width(), this->height());
//    QRectF source(0,0,kartinka.width(), kartinka.height());
//    painter->setRenderHints(QPainter::SmoothPixmapTransform);
//    painter->drawImage(target, kartinka, source);

//    Q_UNUSED(rect);
//}



void custom_paintscene::draw_solution(QVector<double> ellips_params, QVector<uint8_t> color_RGB) {
    sol = new paint_solution(ellips_params, color_RGB, sektor_zapuska->glavniy_ugol);
    this->addItem(sol);
}


void custom_paintscene::delete_solution() {
    if (sol != nullptr) {
    sol->deleteLater();
    sol = nullptr;
    }
}


void custom_paintscene::add_data_from_file(struct_dannykh dannye)
{
    if (zona_puska != nullptr) {zona_puska->deleteLater(); zona_puska = nullptr;}
    if (sektor_zapuska != nullptr) {sektor_zapuska->deleteLater(); sektor_zapuska = nullptr;}
    if (nabor_ZZP.length() > 0) {
        int leng = nabor_ZZP.length();
        for (int i = 0; i < leng; i++) {
            nabor_ZZP[0]->deleteLater();
            nabor_ZZP.remove(0);
        }
    }

    sektor_zapuska = new paint_polygon_p(dannye.first_point_sektora_puska, dannye.glavniy_ugol_sektora_puska, dannye.ugol_rastvora_sektora_puska);
    this->addItem(sektor_zapuska);

    for (int i = 0; i < dannye.ZZP.length(); i++) {
        paint_ZZP* new_polygon = new paint_ZZP(dannye.ZZP[i]);
        this->addItem(new_polygon);
        nabor_ZZP.push_back(new_polygon);
    }

    zona_puska = new paint_zona_puska(dannye.zona_puska);
    this->addItem(zona_puska);

    //update();
}

