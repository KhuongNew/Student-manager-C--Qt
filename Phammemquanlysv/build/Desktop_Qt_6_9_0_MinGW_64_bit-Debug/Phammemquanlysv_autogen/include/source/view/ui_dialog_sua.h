/********************************************************************************
** Form generated from reading UI file 'dialog_sua.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_SUA_H
#define UI_DIALOG_SUA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dialog_sua
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_sua_dia;
    QPushButton *pushButton_huy_dia_fix;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLineEdit *lineEdit_suadiem;
    QLineEdit *lineEdit_sualop;
    QLineEdit *lineEdit_suaten;
    QLineEdit *lineEdit_suaho;
    QLabel *label__ho_dia_fix;
    QLabel *label_ten_dia_fix;
    QLabel *label_lop_dia_fix;
    QLabel *label_diem_dia_fix;
    QLineEdit *lineEdit_suama;
    QLabel *label_ma_dia_fix;

    void setupUi(QDialog *Dialog_sua)
    {
        if (Dialog_sua->objectName().isEmpty())
            Dialog_sua->setObjectName("Dialog_sua");
        Dialog_sua->resize(550, 425);
        horizontalLayoutWidget = new QWidget(Dialog_sua);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(120, 280, 291, 131));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_sua_dia = new QPushButton(horizontalLayoutWidget);
        pushButton_sua_dia->setObjectName("pushButton_sua_dia");
        pushButton_sua_dia->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #4FBDBA\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 6px 20px;\n"
"    font: bold 15px \"Segoe UI\";\n"
"}\n"
"QPushButton:hover {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #368DB2, stop: 1 #6FDCD1\n"
"    );\n"
"}\n"
"QPushButton:pressed {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #F06E6E, stop: 1 #FFC857\n"
"    );\n"
"    color: white;\n"
"}"));

        horizontalLayout->addWidget(pushButton_sua_dia);

        pushButton_huy_dia_fix = new QPushButton(horizontalLayoutWidget);
        pushButton_huy_dia_fix->setObjectName("pushButton_huy_dia_fix");
        pushButton_huy_dia_fix->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_huy_dia_fix {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #E53935, stop: 1 #EF5350\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 6px;\n"
"    padding: 6px 22px;\n"
"    font: bold 15px \"Segoe UI\";\n"
"}\n"
"\n"
"QPushButton#pushButton_huy_dia_fix:hover {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #FF6F61, stop: 1 #FFA07A\n"
"    );\n"
"}\n"
"\n"
"QPushButton#pushButton_huy_dia_fix:pressed {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #B71C1C, stop: 1 #D84315\n"
"    );\n"
"    color: #FFF;\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_huy_dia_fix);

        formLayoutWidget = new QWidget(Dialog_sua);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 29, 511, 251));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_suadiem = new QLineEdit(formLayoutWidget);
        lineEdit_suadiem->setObjectName("lineEdit_suadiem");
        lineEdit_suadiem->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF;\n"
"    border: 1.5px solid #B0BEC5;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"    selection-background-color: #A7E3F2;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2C7DA0;\n"
"    background-color: #FAFEFF;\n"
"    outline: none;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #90A4AE;\n"
"    font-style: italic;\n"
"}\n"
""));

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, lineEdit_suadiem);

        lineEdit_sualop = new QLineEdit(formLayoutWidget);
        lineEdit_sualop->setObjectName("lineEdit_sualop");
        lineEdit_sualop->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF;\n"
"    border: 1.5px solid #B0BEC5;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"    selection-background-color: #A7E3F2; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2C7DA0;\n"
"    background-color: #FAFEFF;\n"
"    outline: none;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #90A4AE;\n"
"    font-style: italic;\n"
"}\n"
""));

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEdit_sualop);

        lineEdit_suaten = new QLineEdit(formLayoutWidget);
        lineEdit_suaten->setObjectName("lineEdit_suaten");
        lineEdit_suaten->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF;\n"
"    border: 1.5px solid #B0BEC5;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"    selection-background-color: #A7E3F2; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2C7DA0;\n"
"    background-color: #FAFEFF;\n"
"    outline: none;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #90A4AE;\n"
"    font-style: italic;\n"
"}\n"
""));

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEdit_suaten);

        lineEdit_suaho = new QLineEdit(formLayoutWidget);
        lineEdit_suaho->setObjectName("lineEdit_suaho");
        lineEdit_suaho->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF;\n"
"    border: 1.5px solid #B0BEC5;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"    selection-background-color: #A7E3F2; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2C7DA0;\n"
"    background-color: #FAFEFF;\n"
"    outline: none;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #90A4AE;\n"
"    font-style: italic;\n"
"}\n"
""));

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_suaho);

        label__ho_dia_fix = new QLabel(formLayoutWidget);
        label__ho_dia_fix->setObjectName("label__ho_dia_fix");
        label__ho_dia_fix->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label__ho_dia_fix);

        label_ten_dia_fix = new QLabel(formLayoutWidget);
        label_ten_dia_fix->setObjectName("label_ten_dia_fix");
        label_ten_dia_fix->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"}"));

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_ten_dia_fix);

        label_lop_dia_fix = new QLabel(formLayoutWidget);
        label_lop_dia_fix->setObjectName("label_lop_dia_fix");
        label_lop_dia_fix->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"}\n"
""));

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_lop_dia_fix);

        label_diem_dia_fix = new QLabel(formLayoutWidget);
        label_diem_dia_fix->setObjectName("label_diem_dia_fix");
        label_diem_dia_fix->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"}"));

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_diem_dia_fix);

        lineEdit_suama = new QLineEdit(formLayoutWidget);
        lineEdit_suama->setObjectName("lineEdit_suama");
        lineEdit_suama->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background-color: #FFFFFF;\n"
"    border: 1.5px solid #B0BEC5;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"    selection-background-color: #A7E3F2; \n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 2px solid #2C7DA0;\n"
"    background-color: #FAFEFF;\n"
"    outline: none;\n"
"}\n"
"\n"
"QLineEdit::placeholder {\n"
"    color: #90A4AE;\n"
"    font-style: italic;\n"
"}\n"
""));

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit_suama);

        label_ma_dia_fix = new QLabel(formLayoutWidget);
        label_ma_dia_fix->setObjectName("label_ma_dia_fix");
        label_ma_dia_fix->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_ma_dia_fix);


        retranslateUi(Dialog_sua);

        QMetaObject::connectSlotsByName(Dialog_sua);
    } // setupUi

    void retranslateUi(QDialog *Dialog_sua)
    {
        Dialog_sua->setWindowTitle(QCoreApplication::translate("Dialog_sua", "Dialog", nullptr));
        pushButton_sua_dia->setText(QCoreApplication::translate("Dialog_sua", "S\341\273\255a", nullptr));
        pushButton_huy_dia_fix->setText(QCoreApplication::translate("Dialog_sua", "H\341\273\247y", nullptr));
        label__ho_dia_fix->setText(QCoreApplication::translate("Dialog_sua", "H\341\273\215:", nullptr));
        label_ten_dia_fix->setText(QCoreApplication::translate("Dialog_sua", "T\303\252n:", nullptr));
        label_lop_dia_fix->setText(QCoreApplication::translate("Dialog_sua", "L\341\273\233p:", nullptr));
        label_diem_dia_fix->setText(QCoreApplication::translate("Dialog_sua", "\304\220i\341\273\203m:", nullptr));
        label_ma_dia_fix->setText(QCoreApplication::translate("Dialog_sua", "M\303\243 Sinh Vi\303\252n:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_sua: public Ui_Dialog_sua {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_SUA_H
