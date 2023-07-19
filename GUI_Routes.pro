#-------------------------------------------------
#
# Project created by QtCreator 2022-07-19T15:06:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUI_Ellips
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += \Eigen\

CONFIG += c++11

SOURCES += \
        GenAlg.cpp \
        OTBOR.cpp \
        approximate_ellips.cpp \
        blend_crossover_BLX.cpp \
        crossover.cpp \
        custom_paintscene.cpp \
        elitizm.cpp \
        form_of_task_parameters.cpp \
        form_vvod_param_ga.cpp \
        generate_random_double_from_interval_of_double.cpp \
        intersection_functions.cpp \
        k_point_crossover.cpp \
        load_params_of_task.cpp \
        main.cpp \
        mainwindow.cpp \
        mutaciya.cpp \
        otbor_SUS.cpp \
        otbor_rangir.cpp \
        otbor_ruletka.cpp \
        otbor_turnir.cpp \
        paint_polygon_p.cpp \
        paint_solution.cpp \
        paint_zona_puska.cpp \
        paint_zzp.cpp \
        procedure_ocenka.cpp \
        procedure_sred_ocenka.cpp \
        save_params_of_task.cpp \
        simulated_binary_crossover_SBX.cpp \
        sokhranit_dannye.cpp \
        sokhranit_params.cpp \
        sost_nach_populyacii.cpp \
        uniform_crossover.cpp \
        zagr_dannye.cpp \
        zagruzit_params.cpp

HEADERS += \
        custom_paintscene.h \
        form_of_task_parameters.h \
        form_vvod_param_ga.h \
        functions.h \
        intersection_functions.h \
        mainwindow.h \
        paint_polygon_p.h \
        paint_solution.h \
        paint_zona_puska.h \
        paint_zzp.h

FORMS += \
        form_of_task_parameters.ui \
        form_vvod_param_ga.ui \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
