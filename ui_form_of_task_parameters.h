/********************************************************************************
** Form generated from reading UI file 'form_of_task_parameters.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_OF_TASK_PARAMETERS_H
#define UI_FORM_OF_TASK_PARAMETERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_form_of_task_parameters
{
public:
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_weight_ZZP;
    QLabel *label_2;
    QLabel *label_5;
    QLineEdit *lineEdit_max_angle;
    QPushButton *pushButton_to_default;
    QLabel *label;
    QPushButton *pushButton_save_n_quit;
    QLineEdit *lineEdit_sector_angle;
    QLineEdit *lineEdit_PPPM;
    QLineEdit *lineEdit_weight_angle_broke;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_cancel;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *form_of_task_parameters)
    {
        if (form_of_task_parameters->objectName().isEmpty())
            form_of_task_parameters->setObjectName(QString::fromUtf8("form_of_task_parameters"));
        form_of_task_parameters->resize(646, 234);
        gridLayout = new QGridLayout(form_of_task_parameters);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_weight_ZZP = new QLineEdit(form_of_task_parameters);
        lineEdit_weight_ZZP->setObjectName(QString::fromUtf8("lineEdit_weight_ZZP"));
        QFont font;
        font.setFamily(QString::fromUtf8("Nunito SemiBold"));
        font.setPointSize(12);
        lineEdit_weight_ZZP->setFont(font);
        lineEdit_weight_ZZP->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_weight_ZZP, 3, 2, 1, 1);

        label_2 = new QLabel(form_of_task_parameters);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nunito"));
        font1.setPointSize(12);
        label_2->setFont(font1);

        gridLayout->addWidget(label_2, 1, 0, 1, 2);

        label_5 = new QLabel(form_of_task_parameters);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font1);

        gridLayout->addWidget(label_5, 4, 0, 1, 2);

        lineEdit_max_angle = new QLineEdit(form_of_task_parameters);
        lineEdit_max_angle->setObjectName(QString::fromUtf8("lineEdit_max_angle"));
        lineEdit_max_angle->setFont(font);
        lineEdit_max_angle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_max_angle, 1, 2, 1, 1);

        pushButton_to_default = new QPushButton(form_of_task_parameters);
        pushButton_to_default->setObjectName(QString::fromUtf8("pushButton_to_default"));
        pushButton_to_default->setFont(font1);

        gridLayout->addWidget(pushButton_to_default, 6, 1, 1, 1);

        label = new QLabel(form_of_task_parameters);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font1);

        gridLayout->addWidget(label, 0, 0, 1, 2);

        pushButton_save_n_quit = new QPushButton(form_of_task_parameters);
        pushButton_save_n_quit->setObjectName(QString::fromUtf8("pushButton_save_n_quit"));
        pushButton_save_n_quit->setFont(font1);

        gridLayout->addWidget(pushButton_save_n_quit, 6, 2, 1, 1);

        lineEdit_sector_angle = new QLineEdit(form_of_task_parameters);
        lineEdit_sector_angle->setObjectName(QString::fromUtf8("lineEdit_sector_angle"));
        lineEdit_sector_angle->setFont(font);
        lineEdit_sector_angle->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_sector_angle, 2, 2, 1, 1);

        lineEdit_PPPM = new QLineEdit(form_of_task_parameters);
        lineEdit_PPPM->setObjectName(QString::fromUtf8("lineEdit_PPPM"));
        lineEdit_PPPM->setFont(font);
        lineEdit_PPPM->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_PPPM, 0, 2, 1, 1);

        lineEdit_weight_angle_broke = new QLineEdit(form_of_task_parameters);
        lineEdit_weight_angle_broke->setObjectName(QString::fromUtf8("lineEdit_weight_angle_broke"));
        lineEdit_weight_angle_broke->setFont(font);
        lineEdit_weight_angle_broke->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_weight_angle_broke, 4, 2, 1, 1);

        label_3 = new QLabel(form_of_task_parameters);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);

        gridLayout->addWidget(label_3, 2, 0, 1, 2);

        label_4 = new QLabel(form_of_task_parameters);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font1);

        gridLayout->addWidget(label_4, 3, 0, 1, 2);

        pushButton_cancel = new QPushButton(form_of_task_parameters);
        pushButton_cancel->setObjectName(QString::fromUtf8("pushButton_cancel"));
        pushButton_cancel->setFont(font1);

        gridLayout->addWidget(pushButton_cancel, 6, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Minimum);

        gridLayout->addItem(verticalSpacer, 5, 1, 1, 1);


        retranslateUi(form_of_task_parameters);

        QMetaObject::connectSlotsByName(form_of_task_parameters);
    } // setupUi

    void retranslateUi(QWidget *form_of_task_parameters)
    {
        form_of_task_parameters->setWindowTitle(QApplication::translate("form_of_task_parameters", "Form", nullptr));
        lineEdit_weight_ZZP->setText(QApplication::translate("form_of_task_parameters", "1", nullptr));
        label_2->setText(QApplication::translate("form_of_task_parameters", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\321\213\320\271 \321\203\320\263\320\276\320\273 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260, \320\263\321\200\320\260\320\264.", nullptr));
        label_5->setText(QApplication::translate("form_of_task_parameters", "\320\222\320\265\321\201 \320\267\320\260\320\277\321\200\320\265\321\202\320\260 \320\277\321\200\320\265\320\262\321\213\321\210\320\265\320\275\320\270\321\217 \320\264\320\276\320\277\321\203\321\201\321\202\320\270\320\274\320\276\320\263\320\276 \321\203\320\263\320\273\320\260 \320\277\320\276\320\262\320\276\321\200\320\276\321\202\320\260 (-5 ... 5)", nullptr));
        lineEdit_max_angle->setText(QApplication::translate("form_of_task_parameters", "15", nullptr));
        pushButton_to_default->setText(QApplication::translate("form_of_task_parameters", "\320\237\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", nullptr));
        label->setText(QApplication::translate("form_of_task_parameters", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\237\320\237\320\237\320\234", nullptr));
        pushButton_save_n_quit->setText(QApplication::translate("form_of_task_parameters", "\320\237\321\200\320\270\320\275\321\217\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        lineEdit_sector_angle->setText(QApplication::translate("form_of_task_parameters", "20", nullptr));
        lineEdit_PPPM->setText(QApplication::translate("form_of_task_parameters", "3", nullptr));
        lineEdit_weight_angle_broke->setText(QApplication::translate("form_of_task_parameters", "2", nullptr));
        label_3->setText(QApplication::translate("form_of_task_parameters", "\320\243\320\263\320\276\320\273 \321\200\320\260\321\201\321\202\320\262\320\276\321\200\320\260 \321\201\320\265\320\272\321\202\320\276\321\200\320\260 \320\277\320\276\320\264\321\205\320\276\320\264\320\260, \320\263\321\200\320\260\320\264.", nullptr));
        label_4->setText(QApplication::translate("form_of_task_parameters", "\320\222\320\265\321\201 \320\267\320\260\320\277\321\200\320\265\321\202\320\260 \320\277\321\200\320\276\321\205\320\276\320\264\320\260 \321\207\320\265\321\200\320\265\320\267 \320\227\320\227\320\237 (-5 ... 5)", nullptr));
        pushButton_cancel->setText(QApplication::translate("form_of_task_parameters", "\320\236\321\202\320\274\320\265\320\275\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class form_of_task_parameters: public Ui_form_of_task_parameters {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_OF_TASK_PARAMETERS_H
