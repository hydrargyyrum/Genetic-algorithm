/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *action_exit;
    QAction *action_full_small_screen;
    QAction *action_start_GA;
    QAction *action_change_params_GA;
    QAction *action_screenshot;
    QAction *action_save_data;
    QAction *action_load_data;
    QAction *action_B_zzp;
    QAction *action_B_rzp;
    QAction *action_B_sp;
    QAction *action_change_task_parameters;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;
    QMenu *menu_4;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(969, 678);
        QFont font;
        font.setPointSize(12);
        MainWindow->setFont(font);
        action_exit = new QAction(MainWindow);
        action_exit->setObjectName(QString::fromUtf8("action_exit"));
        action_exit->setFont(font);
        action_full_small_screen = new QAction(MainWindow);
        action_full_small_screen->setObjectName(QString::fromUtf8("action_full_small_screen"));
        action_full_small_screen->setFont(font);
        action_start_GA = new QAction(MainWindow);
        action_start_GA->setObjectName(QString::fromUtf8("action_start_GA"));
        action_start_GA->setFont(font);
        action_change_params_GA = new QAction(MainWindow);
        action_change_params_GA->setObjectName(QString::fromUtf8("action_change_params_GA"));
        action_change_params_GA->setFont(font);
        action_screenshot = new QAction(MainWindow);
        action_screenshot->setObjectName(QString::fromUtf8("action_screenshot"));
        action_screenshot->setFont(font);
        action_save_data = new QAction(MainWindow);
        action_save_data->setObjectName(QString::fromUtf8("action_save_data"));
        action_save_data->setFont(font);
        action_load_data = new QAction(MainWindow);
        action_load_data->setObjectName(QString::fromUtf8("action_load_data"));
        action_load_data->setFont(font);
        action_B_zzp = new QAction(MainWindow);
        action_B_zzp->setObjectName(QString::fromUtf8("action_B_zzp"));
        action_B_zzp->setFont(font);
        action_B_rzp = new QAction(MainWindow);
        action_B_rzp->setObjectName(QString::fromUtf8("action_B_rzp"));
        action_B_rzp->setFont(font);
        action_B_sp = new QAction(MainWindow);
        action_B_sp->setObjectName(QString::fromUtf8("action_B_sp"));
        action_B_sp->setFont(font);
        action_change_task_parameters = new QAction(MainWindow);
        action_change_task_parameters->setObjectName(QString::fromUtf8("action_change_task_parameters"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        gridLayout->addWidget(graphicsView, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 969, 27));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menu->setFont(font);
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QString::fromUtf8("menu_2"));
        menu_2->setFont(font);
        menu_3 = new QMenu(menu_2);
        menu_3->setObjectName(QString::fromUtf8("menu_3"));
        menu_3->setFont(font);
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QString::fromUtf8("menu_4"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setFont(font);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menu->addAction(action_load_data);
        menu->addAction(action_save_data);
        menu->addSeparator();
        menu->addAction(action_full_small_screen);
        menu->addAction(action_screenshot);
        menu->addSeparator();
        menu->addAction(action_exit);
        menu_2->addAction(menu_3->menuAction());
        menu_2->addAction(action_change_task_parameters);
        menu_3->addAction(action_start_GA);
        menu_3->addAction(action_change_params_GA);
        menu_4->addAction(action_B_zzp);
        menu_4->addAction(action_B_rzp);
        menu_4->addAction(action_B_sp);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274 \320\264\320\273\321\217 \321\200\320\265\321\210\320\265\320\275\320\270\321\217 \320\267\320\260\320\264\320\260\321\207\320\270 \320\275\320\265\320\273\320\270\320\275\320\265\320\271\320\275\320\276\320\263\320\276 \320\277\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217", nullptr));
        action_exit->setText(QApplication::translate("MainWindow", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        action_full_small_screen->setText(QApplication::translate("MainWindow", "\320\240\320\260\320\267\320\262\320\265\321\200\320\275\321\203\321\202\321\214 \320\262\320\276 \320\262\320\265\321\201\321\214 \321\215\320\272\321\200\320\260\320\275 / \321\201\320\262\320\265\321\200\320\275\321\203\321\202\321\214 \320\262 \320\276\320\272\320\275\320\276", nullptr));
        action_start_GA->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\207\320\260\321\202\321\214", nullptr));
        action_change_params_GA->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \321\200\320\260\321\201\321\207\321\221\321\202\320\260", nullptr));
        action_screenshot->setText(QApplication::translate("MainWindow", "\320\241\320\264\320\265\320\273\320\260\321\202\321\214 \321\201\320\272\321\200\320\270\320\275\321\210\320\276\321\202", nullptr));
        action_save_data->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        action_load_data->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        action_B_zzp->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\227\320\227\320\237", nullptr));
        action_B_rzp->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \320\240\320\227\320\237", nullptr));
        action_B_sp->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\270\321\202\321\214 \321\201\320\265\320\272\321\202\320\276\321\200 \320\277\320\276\320\264\320\273\321\221\321\202\320\260", nullptr));
        action_change_task_parameters->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\267\320\260\320\264\320\260\321\207\320\270", nullptr));
        menu->setTitle(QApplication::translate("MainWindow", "\320\234\320\265\320\275\321\216", nullptr));
        menu_2->setTitle(QApplication::translate("MainWindow", "\320\240\320\260\321\201\321\207\321\221\321\202", nullptr));
        menu_3->setTitle(QApplication::translate("MainWindow", "\320\223\320\265\320\275\320\265\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \320\260\320\273\320\263\320\276\321\200\320\270\321\202\320\274", nullptr));
        menu_4->setTitle(QApplication::translate("MainWindow", "\320\237\320\276\321\201\321\202\321\200\320\276\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
