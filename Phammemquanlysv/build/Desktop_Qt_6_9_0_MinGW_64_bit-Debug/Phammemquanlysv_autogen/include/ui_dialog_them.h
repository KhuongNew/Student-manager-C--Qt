/********************************************************************************
** Form generated from reading UI file 'dialog_them.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_THEM_H
#define UI_DIALOG_THEM_H

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

class Ui_Dialog_them
{
public:
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label_ma_dia;
    QLabel *label__ho_dia;
    QLineEdit *lineEdit_themho;
    QLabel *label_ten_dia;
    QLabel *label_lop_dia;
    QLabel *label_diem_dia;
    QLineEdit *lineEdit_themdiem;
    QLineEdit *lineEdit_themlop;
    QLineEdit *lineEdit_themma;
    QLineEdit *lineEdit_themten;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_them_dia;
    QPushButton *pushButton_huy_dia;

    void setupUi(QDialog *Dialog_them)
    {
        if (Dialog_them->objectName().isEmpty())
            Dialog_them->setObjectName("Dialog_them");
        Dialog_them->resize(550, 424);
        Dialog_them->setStyleSheet(QString::fromUtf8("QDialog {\n"
"    background-color: #F5F9FA; \n"
"    font: 13px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"    border: 1px solid #D0DCE5;\n"
"    border-radius: 10px;\n"
"}\n"
""));
        formLayoutWidget = new QWidget(Dialog_them);
        formLayoutWidget->setObjectName("formLayoutWidget");
        formLayoutWidget->setGeometry(QRect(20, 39, 511, 251));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName("formLayout");
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_ma_dia = new QLabel(formLayoutWidget);
        label_ma_dia->setObjectName("label_ma_dia");
        label_ma_dia->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"}"));

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, label_ma_dia);

        label__ho_dia = new QLabel(formLayoutWidget);
        label__ho_dia->setObjectName("label__ho_dia");
        label__ho_dia->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"}"));

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, label__ho_dia);

        lineEdit_themho = new QLineEdit(formLayoutWidget);
        lineEdit_themho->setObjectName("lineEdit_themho");
        lineEdit_themho->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, lineEdit_themho);

        label_ten_dia = new QLabel(formLayoutWidget);
        label_ten_dia->setObjectName("label_ten_dia");
        label_ten_dia->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"}"));

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, label_ten_dia);

        label_lop_dia = new QLabel(formLayoutWidget);
        label_lop_dia->setObjectName("label_lop_dia");
        label_lop_dia->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"}\n"
""));

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, label_lop_dia);

        label_diem_dia = new QLabel(formLayoutWidget);
        label_diem_dia->setObjectName("label_diem_dia");
        label_diem_dia->setStyleSheet(QString::fromUtf8("QLabel {\n"
"    font: bold 15px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"}"));

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, label_diem_dia);

        lineEdit_themdiem = new QLineEdit(formLayoutWidget);
        lineEdit_themdiem->setObjectName("lineEdit_themdiem");
        lineEdit_themdiem->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout->setWidget(4, QFormLayout::ItemRole::FieldRole, lineEdit_themdiem);

        lineEdit_themlop = new QLineEdit(formLayoutWidget);
        lineEdit_themlop->setObjectName("lineEdit_themlop");
        lineEdit_themlop->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout->setWidget(3, QFormLayout::ItemRole::FieldRole, lineEdit_themlop);

        lineEdit_themma = new QLineEdit(formLayoutWidget);
        lineEdit_themma->setObjectName("lineEdit_themma");
        lineEdit_themma->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, lineEdit_themma);

        lineEdit_themten = new QLineEdit(formLayoutWidget);
        lineEdit_themten->setObjectName("lineEdit_themten");
        lineEdit_themten->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
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

        formLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, lineEdit_themten);

        horizontalLayoutWidget = new QWidget(Dialog_them);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(120, 290, 291, 131));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_them_dia = new QPushButton(horizontalLayoutWidget);
        pushButton_them_dia->setObjectName("pushButton_them_dia");
        pushButton_them_dia->setStyleSheet(QString::fromUtf8("QPushButton {\n"
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

        horizontalLayout->addWidget(pushButton_them_dia);

        pushButton_huy_dia = new QPushButton(horizontalLayoutWidget);
        pushButton_huy_dia->setObjectName("pushButton_huy_dia");
        pushButton_huy_dia->setStyleSheet(QString::fromUtf8("QPushButton#pushButton_huy_dia {\n"
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
"QPushButton#pushButton_huy_dia:hover {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #FF6F61, stop: 1 #FFA07A\n"
"    );\n"
"}\n"
"\n"
"QPushButton#pushButton_huy_dia:pressed {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #B71C1C, stop: 1 #D84315\n"
"    );\n"
"    color: #FFF;\n"
"}\n"
""));

        horizontalLayout->addWidget(pushButton_huy_dia);


        retranslateUi(Dialog_them);

        QMetaObject::connectSlotsByName(Dialog_them);
    } // setupUi

    void retranslateUi(QDialog *Dialog_them)
    {
        Dialog_them->setWindowTitle(QCoreApplication::translate("Dialog_them", "Dialog", nullptr));
        label_ma_dia->setText(QCoreApplication::translate("Dialog_them", "M\303\243 Sinh Vi\303\252n:", nullptr));
        label__ho_dia->setText(QCoreApplication::translate("Dialog_them", "H\341\273\215:", nullptr));
        label_ten_dia->setText(QCoreApplication::translate("Dialog_them", "T\303\252n:", nullptr));
        label_lop_dia->setText(QCoreApplication::translate("Dialog_them", "L\341\273\233p:", nullptr));
        label_diem_dia->setText(QCoreApplication::translate("Dialog_them", "\304\220i\341\273\203m:", nullptr));
        pushButton_them_dia->setText(QCoreApplication::translate("Dialog_them", "Th\303\252m", nullptr));
        pushButton_huy_dia->setText(QCoreApplication::translate("Dialog_them", "H\341\273\247y", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog_them: public Ui_Dialog_them {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_THEM_H
