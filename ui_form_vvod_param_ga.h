/********************************************************************************
** Form generated from reading UI file 'form_vvod_param_ga.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_VVOD_PARAM_GA_H
#define UI_FORM_VVOD_PARAM_GA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form_vvod_param_GA
{
public:
    QGridLayout *gridLayout_2;
    QPushButton *discard_n_quit;
    QPushButton *sbrosit_parametry;
    QPushButton *save_n_quit;
    QGridLayout *gridLayout;
    QLabel *label_text_1;
    QLabel *label_text_5;
    QLabel *label_text_2;
    QLabel *label_veroyat_skreshch;
    QLabel *label_text_7;
    QLabel *label_text_3;
    QLineEdit *lineEdit_veroyat_skreshch;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QLabel *label_max_pokoleniy;
    QLineEdit *lineEdit_kol_osobey;
    QSpacerItem *verticalSpacer;
    QLineEdit *lineEdit_sila_mutacii;
    QLabel *label_text_6;
    QLabel *label_2;
    QLineEdit *lineEdit_max_pokoleniy;
    QLabel *label_text_8;
    QLineEdit *lineEdit_ver_mutacii;
    QLabel *label_procent_elit;
    QComboBox *comboBox_tip_otbora;
    QLabel *label_sila_mutacii;
    QComboBox *comboBox_tip_mutacii;
    QLabel *label_text_4;
    QLabel *label_3;
    QLabel *label_ver_mutacii;
    QLabel *label_kol_osobey;
    QLineEdit *lineEdit_procent_elit;
    QLabel *label_4;
    QComboBox *comboBox_tip_skreshchivaniya;

    void setupUi(QWidget *Form_vvod_param_GA)
    {
        if (Form_vvod_param_GA->objectName().isEmpty())
            Form_vvod_param_GA->setObjectName(QString::fromUtf8("Form_vvod_param_GA"));
        Form_vvod_param_GA->setWindowModality(Qt::WindowModal);
        Form_vvod_param_GA->resize(706, 422);
        QFont font;
        font.setStyleStrategy(QFont::PreferAntialias);
        Form_vvod_param_GA->setFont(font);
        gridLayout_2 = new QGridLayout(Form_vvod_param_GA);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setSizeConstraint(QLayout::SetFixedSize);
        discard_n_quit = new QPushButton(Form_vvod_param_GA);
        discard_n_quit->setObjectName(QString::fromUtf8("discard_n_quit"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Nunito SemiBold"));
        font1.setPointSize(13);
        font1.setStyleStrategy(QFont::PreferAntialias);
        discard_n_quit->setFont(font1);

        gridLayout_2->addWidget(discard_n_quit, 2, 2, 1, 1);

        sbrosit_parametry = new QPushButton(Form_vvod_param_GA);
        sbrosit_parametry->setObjectName(QString::fromUtf8("sbrosit_parametry"));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Nunito SemiBold"));
        font2.setPointSize(10);
        font2.setStyleStrategy(QFont::PreferAntialias);
        sbrosit_parametry->setFont(font2);

        gridLayout_2->addWidget(sbrosit_parametry, 2, 1, 1, 1);

        save_n_quit = new QPushButton(Form_vvod_param_GA);
        save_n_quit->setObjectName(QString::fromUtf8("save_n_quit"));
        save_n_quit->setFont(font1);

        gridLayout_2->addWidget(save_n_quit, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_text_1 = new QLabel(Form_vvod_param_GA);
        label_text_1->setObjectName(QString::fromUtf8("label_text_1"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_text_1->sizePolicy().hasHeightForWidth());
        label_text_1->setSizePolicy(sizePolicy);
        QFont font3;
        font3.setFamily(QString::fromUtf8("Nunito SemiBold"));
        font3.setPointSize(12);
        font3.setStyleStrategy(QFont::PreferAntialias);
        label_text_1->setFont(font3);
        label_text_1->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_text_1, 2, 0, 1, 1);

        label_text_5 = new QLabel(Form_vvod_param_GA);
        label_text_5->setObjectName(QString::fromUtf8("label_text_5"));
        sizePolicy.setHeightForWidth(label_text_5->sizePolicy().hasHeightForWidth());
        label_text_5->setSizePolicy(sizePolicy);
        label_text_5->setFont(font3);
        label_text_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_text_5, 7, 0, 1, 1);

        label_text_2 = new QLabel(Form_vvod_param_GA);
        label_text_2->setObjectName(QString::fromUtf8("label_text_2"));
        sizePolicy.setHeightForWidth(label_text_2->sizePolicy().hasHeightForWidth());
        label_text_2->setSizePolicy(sizePolicy);
        label_text_2->setFont(font3);
        label_text_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_text_2, 3, 0, 1, 1);

        label_veroyat_skreshch = new QLabel(Form_vvod_param_GA);
        label_veroyat_skreshch->setObjectName(QString::fromUtf8("label_veroyat_skreshch"));
        sizePolicy.setHeightForWidth(label_veroyat_skreshch->sizePolicy().hasHeightForWidth());
        label_veroyat_skreshch->setSizePolicy(sizePolicy);
        label_veroyat_skreshch->setFont(font3);
        label_veroyat_skreshch->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_veroyat_skreshch, 7, 1, 1, 1);

        label_text_7 = new QLabel(Form_vvod_param_GA);
        label_text_7->setObjectName(QString::fromUtf8("label_text_7"));
        sizePolicy.setHeightForWidth(label_text_7->sizePolicy().hasHeightForWidth());
        label_text_7->setSizePolicy(sizePolicy);
        label_text_7->setFont(font3);
        label_text_7->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_text_7, 9, 0, 1, 1);

        label_text_3 = new QLabel(Form_vvod_param_GA);
        label_text_3->setObjectName(QString::fromUtf8("label_text_3"));
        sizePolicy.setHeightForWidth(label_text_3->sizePolicy().hasHeightForWidth());
        label_text_3->setSizePolicy(sizePolicy);
        label_text_3->setFont(font3);
        label_text_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_text_3, 4, 0, 1, 1);

        lineEdit_veroyat_skreshch = new QLineEdit(Form_vvod_param_GA);
        lineEdit_veroyat_skreshch->setObjectName(QString::fromUtf8("lineEdit_veroyat_skreshch"));
        sizePolicy.setHeightForWidth(lineEdit_veroyat_skreshch->sizePolicy().hasHeightForWidth());
        lineEdit_veroyat_skreshch->setSizePolicy(sizePolicy);
        lineEdit_veroyat_skreshch->setFont(font3);
        lineEdit_veroyat_skreshch->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_veroyat_skreshch, 7, 2, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 15, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer_2, 11, 1, 1, 1);

        label = new QLabel(Form_vvod_param_GA);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_max_pokoleniy = new QLabel(Form_vvod_param_GA);
        label_max_pokoleniy->setObjectName(QString::fromUtf8("label_max_pokoleniy"));
        sizePolicy.setHeightForWidth(label_max_pokoleniy->sizePolicy().hasHeightForWidth());
        label_max_pokoleniy->setSizePolicy(sizePolicy);
        label_max_pokoleniy->setFont(font3);
        label_max_pokoleniy->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_max_pokoleniy, 3, 1, 1, 1);

        lineEdit_kol_osobey = new QLineEdit(Form_vvod_param_GA);
        lineEdit_kol_osobey->setObjectName(QString::fromUtf8("lineEdit_kol_osobey"));
        sizePolicy.setHeightForWidth(lineEdit_kol_osobey->sizePolicy().hasHeightForWidth());
        lineEdit_kol_osobey->setSizePolicy(sizePolicy);
        lineEdit_kol_osobey->setFont(font3);
        lineEdit_kol_osobey->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_kol_osobey, 2, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        gridLayout->addItem(verticalSpacer, 1, 1, 1, 1);

        lineEdit_sila_mutacii = new QLineEdit(Form_vvod_param_GA);
        lineEdit_sila_mutacii->setObjectName(QString::fromUtf8("lineEdit_sila_mutacii"));
        sizePolicy.setHeightForWidth(lineEdit_sila_mutacii->sizePolicy().hasHeightForWidth());
        lineEdit_sila_mutacii->setSizePolicy(sizePolicy);
        lineEdit_sila_mutacii->setFont(font3);
        lineEdit_sila_mutacii->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_sila_mutacii, 10, 2, 1, 1);

        label_text_6 = new QLabel(Form_vvod_param_GA);
        label_text_6->setObjectName(QString::fromUtf8("label_text_6"));
        sizePolicy.setHeightForWidth(label_text_6->sizePolicy().hasHeightForWidth());
        label_text_6->setSizePolicy(sizePolicy);
        label_text_6->setFont(font3);
        label_text_6->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_text_6, 8, 0, 1, 1);

        label_2 = new QLabel(Form_vvod_param_GA);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_2, 0, 1, 1, 1);

        lineEdit_max_pokoleniy = new QLineEdit(Form_vvod_param_GA);
        lineEdit_max_pokoleniy->setObjectName(QString::fromUtf8("lineEdit_max_pokoleniy"));
        sizePolicy.setHeightForWidth(lineEdit_max_pokoleniy->sizePolicy().hasHeightForWidth());
        lineEdit_max_pokoleniy->setSizePolicy(sizePolicy);
        lineEdit_max_pokoleniy->setFont(font3);
        lineEdit_max_pokoleniy->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_max_pokoleniy, 3, 2, 1, 1);

        label_text_8 = new QLabel(Form_vvod_param_GA);
        label_text_8->setObjectName(QString::fromUtf8("label_text_8"));
        sizePolicy.setHeightForWidth(label_text_8->sizePolicy().hasHeightForWidth());
        label_text_8->setSizePolicy(sizePolicy);
        label_text_8->setFont(font3);
        label_text_8->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_text_8, 10, 0, 1, 1);

        lineEdit_ver_mutacii = new QLineEdit(Form_vvod_param_GA);
        lineEdit_ver_mutacii->setObjectName(QString::fromUtf8("lineEdit_ver_mutacii"));
        sizePolicy.setHeightForWidth(lineEdit_ver_mutacii->sizePolicy().hasHeightForWidth());
        lineEdit_ver_mutacii->setSizePolicy(sizePolicy);
        lineEdit_ver_mutacii->setFont(font3);
        lineEdit_ver_mutacii->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_ver_mutacii, 9, 2, 1, 1);

        label_procent_elit = new QLabel(Form_vvod_param_GA);
        label_procent_elit->setObjectName(QString::fromUtf8("label_procent_elit"));
        sizePolicy.setHeightForWidth(label_procent_elit->sizePolicy().hasHeightForWidth());
        label_procent_elit->setSizePolicy(sizePolicy);
        label_procent_elit->setFont(font3);
        label_procent_elit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_procent_elit, 4, 1, 1, 1);

        comboBox_tip_otbora = new QComboBox(Form_vvod_param_GA);
        comboBox_tip_otbora->addItem(QString());
        comboBox_tip_otbora->addItem(QString());
        comboBox_tip_otbora->addItem(QString());
        comboBox_tip_otbora->addItem(QString());
        comboBox_tip_otbora->setObjectName(QString::fromUtf8("comboBox_tip_otbora"));
        sizePolicy.setHeightForWidth(comboBox_tip_otbora->sizePolicy().hasHeightForWidth());
        comboBox_tip_otbora->setSizePolicy(sizePolicy);
        comboBox_tip_otbora->setFont(font3);
        comboBox_tip_otbora->setMaxVisibleItems(10);

        gridLayout->addWidget(comboBox_tip_otbora, 5, 1, 1, 2);

        label_sila_mutacii = new QLabel(Form_vvod_param_GA);
        label_sila_mutacii->setObjectName(QString::fromUtf8("label_sila_mutacii"));
        sizePolicy.setHeightForWidth(label_sila_mutacii->sizePolicy().hasHeightForWidth());
        label_sila_mutacii->setSizePolicy(sizePolicy);
        label_sila_mutacii->setFont(font3);
        label_sila_mutacii->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_sila_mutacii, 10, 1, 1, 1);

        comboBox_tip_mutacii = new QComboBox(Form_vvod_param_GA);
        comboBox_tip_mutacii->addItem(QString());
        comboBox_tip_mutacii->addItem(QString());
        comboBox_tip_mutacii->addItem(QString());
        comboBox_tip_mutacii->addItem(QString());
        comboBox_tip_mutacii->addItem(QString());
        comboBox_tip_mutacii->setObjectName(QString::fromUtf8("comboBox_tip_mutacii"));
        sizePolicy.setHeightForWidth(comboBox_tip_mutacii->sizePolicy().hasHeightForWidth());
        comboBox_tip_mutacii->setSizePolicy(sizePolicy);
        comboBox_tip_mutacii->setMinimumSize(QSize(388, 0));
        comboBox_tip_mutacii->setFont(font3);

        gridLayout->addWidget(comboBox_tip_mutacii, 8, 1, 1, 2);

        label_text_4 = new QLabel(Form_vvod_param_GA);
        label_text_4->setObjectName(QString::fromUtf8("label_text_4"));
        sizePolicy.setHeightForWidth(label_text_4->sizePolicy().hasHeightForWidth());
        label_text_4->setSizePolicy(sizePolicy);
        label_text_4->setFont(font3);
        label_text_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_text_4, 5, 0, 1, 1);

        label_3 = new QLabel(Form_vvod_param_GA);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);
        label_3->setFont(font1);
        label_3->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_3, 0, 2, 1, 1);

        label_ver_mutacii = new QLabel(Form_vvod_param_GA);
        label_ver_mutacii->setObjectName(QString::fromUtf8("label_ver_mutacii"));
        sizePolicy.setHeightForWidth(label_ver_mutacii->sizePolicy().hasHeightForWidth());
        label_ver_mutacii->setSizePolicy(sizePolicy);
        label_ver_mutacii->setFont(font3);
        label_ver_mutacii->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_ver_mutacii, 9, 1, 1, 1);

        label_kol_osobey = new QLabel(Form_vvod_param_GA);
        label_kol_osobey->setObjectName(QString::fromUtf8("label_kol_osobey"));
        sizePolicy.setHeightForWidth(label_kol_osobey->sizePolicy().hasHeightForWidth());
        label_kol_osobey->setSizePolicy(sizePolicy);
        label_kol_osobey->setFont(font3);
        label_kol_osobey->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_kol_osobey, 2, 1, 1, 1);

        lineEdit_procent_elit = new QLineEdit(Form_vvod_param_GA);
        lineEdit_procent_elit->setObjectName(QString::fromUtf8("lineEdit_procent_elit"));
        sizePolicy.setHeightForWidth(lineEdit_procent_elit->sizePolicy().hasHeightForWidth());
        lineEdit_procent_elit->setSizePolicy(sizePolicy);
        lineEdit_procent_elit->setFont(font3);
        lineEdit_procent_elit->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(lineEdit_procent_elit, 4, 2, 1, 1);

        label_4 = new QLabel(Form_vvod_param_GA);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setFont(font3);
        label_4->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        comboBox_tip_skreshchivaniya = new QComboBox(Form_vvod_param_GA);
        comboBox_tip_skreshchivaniya->addItem(QString());
        comboBox_tip_skreshchivaniya->addItem(QString());
        comboBox_tip_skreshchivaniya->addItem(QString());
        comboBox_tip_skreshchivaniya->addItem(QString());
        comboBox_tip_skreshchivaniya->addItem(QString());
        comboBox_tip_skreshchivaniya->addItem(QString());
        comboBox_tip_skreshchivaniya->setObjectName(QString::fromUtf8("comboBox_tip_skreshchivaniya"));
        sizePolicy.setHeightForWidth(comboBox_tip_skreshchivaniya->sizePolicy().hasHeightForWidth());
        comboBox_tip_skreshchivaniya->setSizePolicy(sizePolicy);
        comboBox_tip_skreshchivaniya->setFont(font3);

        gridLayout->addWidget(comboBox_tip_skreshchivaniya, 6, 1, 1, 2);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 3);


        retranslateUi(Form_vvod_param_GA);

        comboBox_tip_otbora->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Form_vvod_param_GA);
    } // setupUi

    void retranslateUi(QWidget *Form_vvod_param_GA)
    {
        Form_vvod_param_GA->setWindowTitle(QApplication::translate("Form_vvod_param_GA", "\320\236\320\261\320\275\320\276\320\262\320\273\320\265\320\275\320\270\320\265 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\320\276\320\262 \320\223\320\220", nullptr));
        discard_n_quit->setText(QApplication::translate("Form_vvod_param_GA", "\320\236\321\202\320\274\320\265\320\275\320\270\321\202\321\214 \320\262\321\201\320\265 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        sbrosit_parametry->setText(QApplication::translate("Form_vvod_param_GA", "\320\222\320\276\321\201\321\201\321\202\320\260\320\275\320\276\320\262\320\270\321\202\321\214 \320\277\320\260\321\200\320\260\320\274\320\265\321\202\321\200\321\213 \320\277\320\276 \321\203\320\274\320\276\320\273\321\207\320\260\320\275\320\270\321\216", nullptr));
        save_n_quit->setText(QApplication::translate("Form_vvod_param_GA", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\321\217", nullptr));
        label_text_1->setText(QApplication::translate("Form_vvod_param_GA", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\276\321\201\320\276\320\261\320\265\320\271 \320\262 \320\277\320\276\320\277\321\203\320\273\321\217\321\206\320\270\320\270", nullptr));
        label_text_5->setText(QApplication::translate("Form_vvod_param_GA", "\320\222\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\321\214 \321\201\320\272\321\200\320\265\321\211\320\270\320\262\320\260\320\275\320\270\321\217 (0...1)", nullptr));
        label_text_2->setText(QApplication::translate("Form_vvod_param_GA", "\320\234\320\260\320\272\321\201\320\270\320\274\320\260\320\273\321\214\320\275\320\276\320\265 \320\272\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\277\320\276\320\272\320\276\320\273\320\265\320\275\320\270\320\271", nullptr));
        label_veroyat_skreshch->setText(QApplication::translate("Form_vvod_param_GA", "---", nullptr));
        label_text_7->setText(QApplication::translate("Form_vvod_param_GA", "\320\222\320\265\321\200\320\276\321\217\321\202\320\275\320\276\321\201\321\202\321\214 \320\274\321\203\321\202\320\260\321\206\320\270\320\270 (0...1)", nullptr));
        label_text_3->setText(QApplication::translate("Form_vvod_param_GA", "\320\255\320\273\320\270\321\202\320\275\321\213\321\205 \320\276\321\201\320\276\320\261\320\265\320\271, %", nullptr));
        label->setText(QApplication::translate("Form_vvod_param_GA", "\320\237\320\260\321\200\320\260\320\274\320\265\321\202\321\200", nullptr));
        label_max_pokoleniy->setText(QApplication::translate("Form_vvod_param_GA", "---", nullptr));
        label_text_6->setText(QApplication::translate("Form_vvod_param_GA", "\320\242\320\270\320\277 \320\274\321\203\321\202\320\260\321\206\320\270\320\270", nullptr));
        label_2->setText(QApplication::translate("Form_vvod_param_GA", "\320\242\320\265\320\272\321\203\321\211\320\265\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        label_text_8->setText(QApplication::translate("Form_vvod_param_GA", "\320\241\320\270\320\273\320\260 \320\274\321\203\321\202\320\260\321\206\320\270\320\270, %", nullptr));
        label_procent_elit->setText(QApplication::translate("Form_vvod_param_GA", "---", nullptr));
        comboBox_tip_otbora->setItemText(0, QApplication::translate("Form_vvod_param_GA", "\"\320\240\321\203\320\273\320\265\321\202\320\272\320\260\"", nullptr));
        comboBox_tip_otbora->setItemText(1, QApplication::translate("Form_vvod_param_GA", "\320\241\321\202\320\276\321\205\320\260\321\201\321\202\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \321\203\320\275\320\270\320\262\320\265\321\200\321\201\320\260\320\273\321\214\320\275\320\260\321\217 \320\262\321\213\320\261\320\276\321\200\320\272\320\260 (SUS)", nullptr));
        comboBox_tip_otbora->setItemText(2, QApplication::translate("Form_vvod_param_GA", "\320\240\320\260\320\275\320\266\320\270\321\200\320\276\320\262\320\260\320\275\320\275\321\213\320\271 \320\276\321\202\320\261\320\276\321\200 (\320\240\320\236)", nullptr));
        comboBox_tip_otbora->setItemText(3, QApplication::translate("Form_vvod_param_GA", "\320\242\321\203\321\200\320\275\320\270\321\200\320\275\321\213\320\271 \320\276\321\202\320\261\320\276\321\200 (\320\242\320\236)", nullptr));

        label_sila_mutacii->setText(QApplication::translate("Form_vvod_param_GA", "---", nullptr));
        comboBox_tip_mutacii->setItemText(0, QApplication::translate("Form_vvod_param_GA", "\320\236\320\261\320\274\320\265\320\275\320\276\320\274", nullptr));
        comboBox_tip_mutacii->setItemText(1, QApplication::translate("Form_vvod_param_GA", "\320\236\320\261\321\200\320\260\321\211\320\265\320\275\320\270\320\265\320\274", nullptr));
        comboBox_tip_mutacii->setItemText(2, QApplication::translate("Form_vvod_param_GA", "\320\237\320\265\321\200\320\265\321\202\320\260\321\201\320\276\320\262\320\272\320\276\320\271", nullptr));
        comboBox_tip_mutacii->setItemText(3, QApplication::translate("Form_vvod_param_GA", "\320\235\320\276\321\200\320\274\320\260\320\273\321\214\320\275\320\260\321\217", nullptr));
        comboBox_tip_mutacii->setItemText(4, QApplication::translate("Form_vvod_param_GA", "\320\230\320\275\320\262\320\265\321\200\321\202\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265\320\274", nullptr));

        label_text_4->setText(QApplication::translate("Form_vvod_param_GA", "\320\242\320\270\320\277 \320\276\321\202\320\261\320\276\321\200\320\260", nullptr));
        label_3->setText(QApplication::translate("Form_vvod_param_GA", "\320\235\320\276\320\262\320\276\320\265 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", nullptr));
        label_ver_mutacii->setText(QApplication::translate("Form_vvod_param_GA", "---", nullptr));
        label_kol_osobey->setText(QApplication::translate("Form_vvod_param_GA", "---", nullptr));
        label_4->setText(QApplication::translate("Form_vvod_param_GA", "\320\242\320\270\320\277 \321\201\320\272\321\200\320\265\321\211\320\270\320\262\320\260\320\275\320\270\321\217", nullptr));
        comboBox_tip_skreshchivaniya->setItemText(0, QApplication::translate("Form_vvod_param_GA", "\320\236\320\264\320\275\320\276\321\202\320\276\321\207\320\265\321\207\320\275\320\276\320\265", nullptr));
        comboBox_tip_skreshchivaniya->setItemText(1, QApplication::translate("Form_vvod_param_GA", "\320\224\320\262\321\203\321\205\321\202\320\276\321\207\320\265\321\207\320\275\320\276\320\265", nullptr));
        comboBox_tip_skreshchivaniya->setItemText(2, QApplication::translate("Form_vvod_param_GA", "\320\242\321\200\321\221\321\205\321\202\320\276\321\207\320\265\321\207\320\275\320\276\320\265", nullptr));
        comboBox_tip_skreshchivaniya->setItemText(3, QApplication::translate("Form_vvod_param_GA", "\320\240\320\260\320\262\320\275\320\276\320\274\320\265\321\200\320\275\320\276\320\265", nullptr));
        comboBox_tip_skreshchivaniya->setItemText(4, QApplication::translate("Form_vvod_param_GA", "\320\241\320\274\320\265\321\210\320\265\320\275\320\270\320\265\320\274 (BLX)", nullptr));
        comboBox_tip_skreshchivaniya->setItemText(5, QApplication::translate("Form_vvod_param_GA", "\320\230\320\224\320\241 (SBX)", nullptr));

    } // retranslateUi

};

namespace Ui {
    class Form_vvod_param_GA: public Ui_Form_vvod_param_GA {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_VVOD_PARAM_GA_H
