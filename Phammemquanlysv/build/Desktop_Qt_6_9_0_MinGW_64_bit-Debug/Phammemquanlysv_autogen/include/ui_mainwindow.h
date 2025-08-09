/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionG;
    QAction *actionNon;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout;
    QPushButton *pushButton_ok_timkiem;
    QPushButton *pushButton_ok_sapxep;
    QLineEdit *lineEdit_TimKiem;
    QLabel *label_ChuongTrinh;
    QComboBox *comboBox_timkiem;
    QComboBox *comboBox_sapxep;
    QComboBox *comboBox_tieuchi_timkiem;
    QComboBox *comboBox_tieuchi_sapxep;
    QHBoxLayout *horizontalLayout_tong;
    QGroupBox *groupBox_nutbam;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_in;
    QPushButton *pushButton_them;
    QPushButton *pushButton_xoa;
    QPushButton *pushButton_sua;
    QPushButton *pushButton_file;
    QPushButton *pushButton_diemthap;
    QPushButton *pushButton_diemcao;
    QPushButton *pushButton_trungbinh;
    QPushButton *pushButton_Daoten;
    QVBoxLayout *verticalLayout_tab;
    QTabWidget *tabWidget;
    QWidget *tab_mang;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableWidget_mang;
    QWidget *tab_dslkd;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidget_dslkd;
    QWidget *tab_dslkv;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget_dslkv;
    QWidget *tab_dslkk;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget_dslkk;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 750);
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow, QWidget {\n"
"    background-color: #F4F6F8;\n"
"    font-family: \"Segoe UI\";\n"
"    font-size: 13px;\n"
"    color: #2C3E50; \n"
"}\n"
""));
        actionG = new QAction(MainWindow);
        actionG->setObjectName("actionG");
        actionNon = new QAction(MainWindow);
        actionNon->setObjectName("actionNon");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        pushButton_ok_timkiem = new QPushButton(centralwidget);
        pushButton_ok_timkiem->setObjectName("pushButton_ok_timkiem");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(true);
        font.setItalic(false);
        pushButton_ok_timkiem->setFont(font);
        pushButton_ok_timkiem->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #4FBDBA\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font: bold 14px \"Segoe UI\";\n"
"    padding: 10px 24px;\n"
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
"        stop: 0 #D98E73, stop: 1 #FFE6A7\n"
"    );\n"
"    color: #2C3E50;\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}\n"
""));

        gridLayout->addWidget(pushButton_ok_timkiem, 2, 3, 1, 1);

        pushButton_ok_sapxep = new QPushButton(centralwidget);
        pushButton_ok_sapxep->setObjectName("pushButton_ok_sapxep");
        pushButton_ok_sapxep->setFont(font);
        pushButton_ok_sapxep->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #4FBDBA\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font: bold 14px \"Segoe UI\";\n"
"    padding: 10px 24px;\n"
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
"        stop: 0 #D98E73, stop: 1 #FFE6A7\n"
"    );\n"
"    color: #2C3E50;\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}\n"
""));

        gridLayout->addWidget(pushButton_ok_sapxep, 1, 3, 1, 1);

        lineEdit_TimKiem = new QLineEdit(centralwidget);
        lineEdit_TimKiem->setObjectName("lineEdit_TimKiem");
        lineEdit_TimKiem->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #F1FAEE, stop: 1 #E0F7FA\n"
"    );\n"
"    border: 1.5px solid #B0BEC5;\n"
"    border-radius: 6px;\n"
"    padding: 6px 10px;\n"
"    font: bold 14px \"Segoe UI\";          \n"
"    color: #2C3E50;                     \n"
"    selection-background-color: #D6EAF8;\n"
"    selection-color: #2C3E50;\n"
"}\n"
"\n"
"QLineEdit:focus {\n"
"    border: 1.5px solid #2C7DA0;\n"
"    background: #FFFFFF;\n"
"}\n"
"QLineEdit[echoMode=\"0\"]::placeholder {\n"
"    color: #AAB2BD;\n"
"    font-style: italic;\n"
"}\n"
"\n"
""));

        gridLayout->addWidget(lineEdit_TimKiem, 2, 0, 1, 1);

        label_ChuongTrinh = new QLabel(centralwidget);
        label_ChuongTrinh->setObjectName("label_ChuongTrinh");
        label_ChuongTrinh->setStyleSheet(QString::fromUtf8("QLabel#label_ChuongTrinh {\n"
"    font: bold 20px \"Segoe UI\";\n"
"qproperty-alignment: AlignCenter; \n"
"    color: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #48C9B0\n"
"    );\n"
"}\n"
""));

        gridLayout->addWidget(label_ChuongTrinh, 1, 0, 1, 1);

        comboBox_timkiem = new QComboBox(centralwidget);
        comboBox_timkiem->addItem(QString());
        comboBox_timkiem->addItem(QString());
        comboBox_timkiem->setObjectName("comboBox_timkiem");
        comboBox_timkiem->setFont(font);
        comboBox_timkiem->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #E0F7FA, stop: 1 #F1FAEE\n"
"    );\n"
"    border: 1.5px solid #B0BEC5;\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font: bold 14px \"Segoe UI\";          \n"
"    color: #2C3E50;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1.5px solid #2C7DA0;\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #D9F0F7, stop: 1 #ECFFF6\n"
"    );\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 28px;\n"
"    border-left: 1px solid #B0BEC5;\n"
"    background-color: #D6EAF8;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/arrow-down.png); \n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #FFFFFF;\n"
"    selection"
                        "-background-color: #B5D8F3;\n"
"    selection-color: #2C3E50;\n"
"    border: 1px solid #B0BEC5;\n"
"    font: bold 14px \"Segoe UI\";         \n"
"    outline: none;\n"
"    padding: 4px;\n"
"}\n"
""));

        gridLayout->addWidget(comboBox_timkiem, 2, 1, 1, 1);

        comboBox_sapxep = new QComboBox(centralwidget);
        comboBox_sapxep->addItem(QString());
        comboBox_sapxep->addItem(QString());
        comboBox_sapxep->addItem(QString());
        comboBox_sapxep->addItem(QString());
        comboBox_sapxep->addItem(QString());
        comboBox_sapxep->addItem(QString());
        comboBox_sapxep->setObjectName("comboBox_sapxep");
        comboBox_sapxep->setFont(font);
        comboBox_sapxep->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #E0F7FA, stop: 1 #F1FAEE\n"
"    );\n"
"    border: 1.5px solid #B0BEC5;\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font: bold 14px \"Segoe UI\";          \n"
"    color: #2C3E50;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1.5px solid #2C7DA0;\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #D9F0F7, stop: 1 #ECFFF6\n"
"    );\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 28px;\n"
"    border-left: 1px solid #B0BEC5;\n"
"    background-color: #D6EAF8;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/arrow-down.png); \n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #FFFFFF;\n"
"    selection"
                        "-background-color: #B5D8F3;\n"
"    selection-color: #2C3E50;\n"
"    border: 1px solid #B0BEC5;\n"
"    font: bold 14px \"Segoe UI\";         \n"
"    outline: none;\n"
"    padding: 4px;\n"
"}\n"
""));

        gridLayout->addWidget(comboBox_sapxep, 1, 1, 1, 1);

        comboBox_tieuchi_timkiem = new QComboBox(centralwidget);
        comboBox_tieuchi_timkiem->addItem(QString());
        comboBox_tieuchi_timkiem->addItem(QString());
        comboBox_tieuchi_timkiem->addItem(QString());
        comboBox_tieuchi_timkiem->addItem(QString());
        comboBox_tieuchi_timkiem->addItem(QString());
        comboBox_tieuchi_timkiem->setObjectName("comboBox_tieuchi_timkiem");
        comboBox_tieuchi_timkiem->setFont(font);
        comboBox_tieuchi_timkiem->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #E0F7FA, stop: 1 #F1FAEE\n"
"    );\n"
"    border: 1.5px solid #B0BEC5;\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font: bold 14px \"Segoe UI\";          \n"
"    color: #2C3E50;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1.5px solid #2C7DA0;\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #D9F0F7, stop: 1 #ECFFF6\n"
"    );\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 28px;\n"
"    border-left: 1px solid #B0BEC5;\n"
"    background-color: #D6EAF8;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/arrow-down.png); \n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #FFFFFF;\n"
"    selection"
                        "-background-color: #B5D8F3;\n"
"    selection-color: #2C3E50;\n"
"    border: 1px solid #B0BEC5;\n"
"    font: bold 14px \"Segoe UI\";         \n"
"    outline: none;\n"
"    padding: 4px;\n"
"}\n"
""));

        gridLayout->addWidget(comboBox_tieuchi_timkiem, 2, 2, 1, 1);

        comboBox_tieuchi_sapxep = new QComboBox(centralwidget);
        comboBox_tieuchi_sapxep->addItem(QString());
        comboBox_tieuchi_sapxep->addItem(QString());
        comboBox_tieuchi_sapxep->addItem(QString());
        comboBox_tieuchi_sapxep->setObjectName("comboBox_tieuchi_sapxep");
        comboBox_tieuchi_sapxep->setFont(font);
        comboBox_tieuchi_sapxep->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #E0F7FA, stop: 1 #F1FAEE\n"
"    );\n"
"    border: 1.5px solid #B0BEC5;\n"
"    border-radius: 8px;\n"
"    padding: 6px 12px;\n"
"    font: bold 14px \"Segoe UI\";          \n"
"    color: #2C3E50;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border: 1.5px solid #2C7DA0;\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #D9F0F7, stop: 1 #ECFFF6\n"
"    );\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    subcontrol-origin: padding;\n"
"    subcontrol-position: top right;\n"
"    width: 28px;\n"
"    border-left: 1px solid #B0BEC5;\n"
"    background-color: #D6EAF8;\n"
"    border-top-right-radius: 8px;\n"
"    border-bottom-right-radius: 8px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    image: url(:/icons/arrow-down.png); \n"
"    width: 12px;\n"
"    height: 12px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #FFFFFF;\n"
"    selection"
                        "-background-color: #B5D8F3;\n"
"    selection-color: #2C3E50;\n"
"    border: 1px solid #B0BEC5;\n"
"    font: bold 14px \"Segoe UI\";         \n"
"    outline: none;\n"
"    padding: 4px;\n"
"}\n"
""));

        gridLayout->addWidget(comboBox_tieuchi_sapxep, 1, 2, 1, 1);


        verticalLayout_4->addLayout(gridLayout);

        horizontalLayout_tong = new QHBoxLayout();
        horizontalLayout_tong->setObjectName("horizontalLayout_tong");
        groupBox_nutbam = new QGroupBox(centralwidget);
        groupBox_nutbam->setObjectName("groupBox_nutbam");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setBold(false);
        font1.setItalic(false);
        font1.setUnderline(false);
        font1.setStrikeOut(false);
        font1.setKerning(true);
        groupBox_nutbam->setFont(font1);
        groupBox_nutbam->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"    border: 1px solid #B0BEC5;\n"
"    border-radius: 8px;\n"
"    margin-top: 20px;\n"
"    background-color: #FFFFFF;\n"
"    font: 13px \"Segoe UI\";\n"
"    color: #2C3E50;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 4px 10px;\n"
"    background-color: transparent;\n"
"    font: bold 14px \"Segoe UI\";     \n"
"    color: #2C7DA0;\n"
"}\n"
""));
        groupBox_nutbam->setFlat(false);
        groupBox_nutbam->setCheckable(false);
        verticalLayout = new QVBoxLayout(groupBox_nutbam);
        verticalLayout->setObjectName("verticalLayout");
        pushButton_in = new QPushButton(groupBox_nutbam);
        pushButton_in->setObjectName("pushButton_in");
        pushButton_in->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #4FBDBA\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font: bold 14px \"Segoe UI\";\n"
"    padding: 10px 24px;\n"
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
"        stop: 0 #D98E73, stop: 1 #FFE6A7\n"
"    );\n"
"    color: #2C3E50;\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}\n"
""));

        verticalLayout->addWidget(pushButton_in);

        pushButton_them = new QPushButton(groupBox_nutbam);
        pushButton_them->setObjectName("pushButton_them");
        pushButton_them->setFont(font);
        pushButton_them->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #4FBDBA\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font: bold 14px \"Segoe UI\";\n"
"    padding: 10px 24px;\n"
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
"        stop: 0 #D98E73, stop: 1 #FFE6A7\n"
"    );\n"
"    color: #2C3E50;\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}\n"
""));

        verticalLayout->addWidget(pushButton_them);

        pushButton_xoa = new QPushButton(groupBox_nutbam);
        pushButton_xoa->setObjectName("pushButton_xoa");
        pushButton_xoa->setFont(font);
        pushButton_xoa->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #4FBDBA\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font: bold 14px \"Segoe UI\";\n"
"    padding: 10px 24px;\n"
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
"        stop: 0 #D98E73, stop: 1 #FFE6A7\n"
"    );\n"
"    color: #2C3E50;\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}\n"
""));

        verticalLayout->addWidget(pushButton_xoa);

        pushButton_sua = new QPushButton(groupBox_nutbam);
        pushButton_sua->setObjectName("pushButton_sua");
        pushButton_sua->setFont(font);
        pushButton_sua->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #4FBDBA\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font: bold 14px \"Segoe UI\";\n"
"    padding: 10px 24px;\n"
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
"        stop: 0 #D98E73, stop: 1 #FFE6A7\n"
"    );\n"
"    color: #2C3E50;\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}\n"
""));

        verticalLayout->addWidget(pushButton_sua);

        pushButton_file = new QPushButton(groupBox_nutbam);
        pushButton_file->setObjectName("pushButton_file");
        pushButton_file->setFont(font);
        pushButton_file->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #4FBDBA\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font: bold 14px \"Segoe UI\";\n"
"    padding: 10px 24px;\n"
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
"        stop: 0 #D98E73, stop: 1 #FFE6A7\n"
"    );\n"
"    color: #2C3E50;\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}\n"
""));

        verticalLayout->addWidget(pushButton_file);

        pushButton_diemthap = new QPushButton(groupBox_nutbam);
        pushButton_diemthap->setObjectName("pushButton_diemthap");
        pushButton_diemthap->setFont(font);
        pushButton_diemthap->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #4FBDBA\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font: bold 14px \"Segoe UI\";\n"
"    padding: 10px 24px;\n"
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
"        stop: 0 #D98E73, stop: 1 #FFE6A7\n"
"    );\n"
"    color: #2C3E50;\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}\n"
""));

        verticalLayout->addWidget(pushButton_diemthap);

        pushButton_diemcao = new QPushButton(groupBox_nutbam);
        pushButton_diemcao->setObjectName("pushButton_diemcao");
        pushButton_diemcao->setFont(font);
        pushButton_diemcao->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #4FBDBA\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font: bold 14px \"Segoe UI\";\n"
"    padding: 10px 24px;\n"
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
"        stop: 0 #D98E73, stop: 1 #FFE6A7\n"
"    );\n"
"    color: #2C3E50;\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}\n"
""));

        verticalLayout->addWidget(pushButton_diemcao);

        pushButton_trungbinh = new QPushButton(groupBox_nutbam);
        pushButton_trungbinh->setObjectName("pushButton_trungbinh");
        pushButton_trungbinh->setFont(font);
        pushButton_trungbinh->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #4FBDBA\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font: bold 14px \"Segoe UI\";\n"
"    padding: 10px 24px;\n"
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
"        stop: 0 #D98E73, stop: 1 #FFE6A7\n"
"    );\n"
"    color: #2C3E50;\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}\n"
""));

        verticalLayout->addWidget(pushButton_trungbinh);

        pushButton_Daoten = new QPushButton(groupBox_nutbam);
        pushButton_Daoten->setObjectName("pushButton_Daoten");
        pushButton_Daoten->setFont(font);
        pushButton_Daoten->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #4FBDBA\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-radius: 12px;\n"
"    font: bold 14px \"Segoe UI\";\n"
"    padding: 10px 24px;\n"
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
"        stop: 0 #D98E73, stop: 1 #FFE6A7\n"
"    );\n"
"    color: #2C3E50;\n"
"    padding-left: 12px;\n"
"    padding-top: 12px;\n"
"}\n"
""));

        verticalLayout->addWidget(pushButton_Daoten);


        horizontalLayout_tong->addWidget(groupBox_nutbam);

        verticalLayout_tab = new QVBoxLayout();
        verticalLayout_tab->setObjectName("verticalLayout_tab");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setFont(font);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabWidget::pane {\n"
"    border: 1px solid #B0BEC5;\n"
"    border-radius: 8px;\n"
"    background-color: #F4F6F8;\n"
"    padding: 5px;\n"
"}\n"
"QTabBar::tab {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #2C7DA0, stop: 1 #4FBDBA\n"
"    );\n"
"    color: white;\n"
"    border: none;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    padding: 8px 18px;\n"
"    font: bold 13px \"Segoe UI\";\n"
"    margin-right: 2px;\n"
"}\n"
"QTabBar::tab:selected {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #D98E73, stop: 1 #FFE6A7\n"
"    );\n"
"    color: #2C3E50;\n"
"    font: bold 14px \"Segoe UI\";\n"
"    border: 2px solid #E6B87A;\n"
"}\n"
"QTabBar::tab:hover {\n"
"    background: qlineargradient(\n"
"        x1: 0, y1: 0, x2: 1, y2: 0,\n"
"        stop: 0 #368DB2, stop: 1 #6FDCD1\n"
"    );\n"
"}\n"
""));
        tab_mang = new QWidget();
        tab_mang->setObjectName("tab_mang");
        verticalLayout_5 = new QVBoxLayout(tab_mang);
        verticalLayout_5->setObjectName("verticalLayout_5");
        tableWidget_mang = new QTableWidget(tab_mang);
        if (tableWidget_mang->columnCount() < 5)
            tableWidget_mang->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_mang->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_mang->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_mang->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_mang->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_mang->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidget_mang->setObjectName("tableWidget_mang");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setBold(false);
        font2.setItalic(false);
        tableWidget_mang->setFont(font2);
        tableWidget_mang->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #F9FAFB;\n"
"    alternate-background-color: #EEF4F7;\n"
"    gridline-color: #D0D7DE;\n"
"    color: #2C3E50;\n"
"    border: 1px solid #B0BEC5;\n"
"    border-radius: 6px;\n"
"    font: 13px \"Segoe UI\";\n"
"    selection-background-color: #D6EAF8;\n"
"    selection-color: #2C3E50;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 6px;\n"
"    border: none;\n"
"}\n"
"QTableWidget::item:alternate {\n"
"    background-color: #EEF4F7;\n"
"}\n"
"QTableWidget::item:hover {\n"
"    background-color: #E0F3F9;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #2C7DA0;\n"
"    color: white;\n"
"    font: bold 13px \"Segoe UI\";\n"
"    padding: 6px;\n"
"    border: none;\n"
"    border-right: 1px solid #B0BEC5;\n"
"}\n"
"QTableCornerButton::section {\n"
"    background-color: #2C7DA0;\n"
"    border: none;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: #A5D6F9;    \n"
"    color: #1A2930;\n"
"    font-weight: bold;\n"
"}\n"
""));
        tableWidget_mang->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget_mang->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget_mang->verticalHeader()->setVisible(true);

        verticalLayout_5->addWidget(tableWidget_mang);

        tabWidget->addTab(tab_mang, QString());
        tab_dslkd = new QWidget();
        tab_dslkd->setObjectName("tab_dslkd");
        verticalLayout_3 = new QVBoxLayout(tab_dslkd);
        verticalLayout_3->setObjectName("verticalLayout_3");
        tableWidget_dslkd = new QTableWidget(tab_dslkd);
        if (tableWidget_dslkd->columnCount() < 5)
            tableWidget_dslkd->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_dslkd->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_dslkd->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_dslkd->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_dslkd->setHorizontalHeaderItem(3, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_dslkd->setHorizontalHeaderItem(4, __qtablewidgetitem9);
        tableWidget_dslkd->setObjectName("tableWidget_dslkd");
        tableWidget_dslkd->setFont(font2);
        tableWidget_dslkd->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #F9FAFB;\n"
"    alternate-background-color: #EEF4F7;\n"
"    gridline-color: #D0D7DE;\n"
"    color: #2C3E50;\n"
"    border: 1px solid #B0BEC5;\n"
"    border-radius: 6px;\n"
"    font: 13px \"Segoe UI\";\n"
"    selection-background-color: #D6EAF8;\n"
"    selection-color: #2C3E50;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 6px;\n"
"    border: none;\n"
"}\n"
"QTableWidget::item:alternate {\n"
"    background-color: #EEF4F7;\n"
"}\n"
"QTableWidget::item:hover {\n"
"    background-color: #E0F3F9;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #2C7DA0;\n"
"    color: white;\n"
"    font: bold 13px \"Segoe UI\";\n"
"    padding: 6px;\n"
"    border: none;\n"
"    border-right: 1px solid #B0BEC5;\n"
"}\n"
"QTableCornerButton::section {\n"
"    background-color: #2C7DA0;\n"
"    border: none;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: #A5D6F9;    \n"
"    color: #1A2930;\n"
"    font-weight: bold;\n"
"}\n"
""));
        tableWidget_dslkd->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget_dslkd->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget_dslkd->verticalHeader()->setVisible(true);

        verticalLayout_3->addWidget(tableWidget_dslkd);

        tabWidget->addTab(tab_dslkd, QString());
        tab_dslkv = new QWidget();
        tab_dslkv->setObjectName("tab_dslkv");
        verticalLayout_2 = new QVBoxLayout(tab_dslkv);
        verticalLayout_2->setObjectName("verticalLayout_2");
        tableWidget_dslkv = new QTableWidget(tab_dslkv);
        if (tableWidget_dslkv->columnCount() < 5)
            tableWidget_dslkv->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_dslkv->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget_dslkv->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget_dslkv->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget_dslkv->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget_dslkv->setHorizontalHeaderItem(4, __qtablewidgetitem14);
        tableWidget_dslkv->setObjectName("tableWidget_dslkv");
        tableWidget_dslkv->setFont(font2);
        tableWidget_dslkv->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #F9FAFB;\n"
"    alternate-background-color: #EEF4F7;\n"
"    gridline-color: #D0D7DE;\n"
"    color: #2C3E50;\n"
"    border: 1px solid #B0BEC5;\n"
"    border-radius: 6px;\n"
"    font: 13px \"Segoe UI\";\n"
"    selection-background-color: #D6EAF8;\n"
"    selection-color: #2C3E50;\n"
"}\n"
"QTableWidget::item {\n"
"    font: bold 13px \"Segoe UI\";\n"
"}\n"
"QTableWidget::item:alternate {\n"
"    background-color: #EEF4F7;\n"
"}\n"
"QTableWidget::item:hover {\n"
"    background-color: #E0F3F9;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: #A5D6F9;    \n"
"    color: #1A2930;\n"
"    font-weight: bold;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #2C7DA0;\n"
"    color: white;\n"
"    font: bold 13px \"Segoe UI\";\n"
"    padding: 6px;\n"
"    border: none;\n"
"    border-right: 1px solid #B0BEC5;\n"
"}\n"
"QTableCornerButton::section {\n"
"    background-color: #2C7DA0;\n"
"    border: none;\n"
"}"));
        tableWidget_dslkv->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget_dslkv->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget_dslkv->verticalHeader()->setVisible(true);

        verticalLayout_2->addWidget(tableWidget_dslkv);

        tabWidget->addTab(tab_dslkv, QString());
        tab_dslkk = new QWidget();
        tab_dslkk->setObjectName("tab_dslkk");
        verticalLayout_6 = new QVBoxLayout(tab_dslkk);
        verticalLayout_6->setObjectName("verticalLayout_6");
        tableWidget_dslkk = new QTableWidget(tab_dslkk);
        if (tableWidget_dslkk->columnCount() < 5)
            tableWidget_dslkk->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget_dslkk->setHorizontalHeaderItem(0, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget_dslkk->setHorizontalHeaderItem(1, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget_dslkk->setHorizontalHeaderItem(2, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget_dslkk->setHorizontalHeaderItem(3, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget_dslkk->setHorizontalHeaderItem(4, __qtablewidgetitem19);
        tableWidget_dslkk->setObjectName("tableWidget_dslkk");
        tableWidget_dslkk->setFont(font2);
        tableWidget_dslkk->setStyleSheet(QString::fromUtf8("QTableWidget {\n"
"    background-color: #F9FAFB;\n"
"    alternate-background-color: #EEF4F7;\n"
"    gridline-color: #D0D7DE;\n"
"    color: #2C3E50;\n"
"    border: 1px solid #B0BEC5;\n"
"    border-radius: 6px;\n"
"    font: 13px \"Segoe UI\";\n"
"    selection-background-color: #D6EAF8;\n"
"    selection-color: #2C3E50;\n"
"}\n"
"QTableWidget::item {\n"
"    padding: 6px;\n"
"    border: none;\n"
"}\n"
"QTableWidget::item:alternate {\n"
"    background-color: #EEF4F7;\n"
"}\n"
"QTableWidget::item:hover {\n"
"    background-color: #E0F3F9;\n"
"}\n"
"QHeaderView::section {\n"
"    background-color: #2C7DA0;\n"
"    color: white;\n"
"    font: bold 13px \"Segoe UI\";\n"
"    padding: 6px;\n"
"    border: none;\n"
"    border-right: 1px solid #B0BEC5;\n"
"}\n"
"QTableCornerButton::section {\n"
"    background-color: #2C7DA0;\n"
"    border: none;\n"
"}\n"
"QTableWidget::item:selected {\n"
"    background-color: #A5D6F9;    \n"
"    color: #1A2930;\n"
"    font-weight: bold;\n"
"}\n"
""));
        tableWidget_dslkk->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget_dslkk->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidget_dslkk->verticalHeader()->setVisible(true);

        verticalLayout_6->addWidget(tableWidget_dslkk);

        tabWidget->addTab(tab_dslkk, QString());

        verticalLayout_tab->addWidget(tabWidget);


        horizontalLayout_tong->addLayout(verticalLayout_tab);


        verticalLayout_4->addLayout(horizontalLayout_tong);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1100, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionG->setText(QCoreApplication::translate("MainWindow", "G\303\240", nullptr));
        actionNon->setText(QCoreApplication::translate("MainWindow", "Non", nullptr));
        pushButton_ok_timkiem->setText(QCoreApplication::translate("MainWindow", "T\303\254m Ki\341\272\277m", nullptr));
        pushButton_ok_sapxep->setText(QCoreApplication::translate("MainWindow", "S\341\272\257p X\341\272\277p", nullptr));
        label_ChuongTrinh->setText(QCoreApplication::translate("MainWindow", "H\341\273\206 TH\341\273\220NG QU\341\272\242N L\303\235 SINH VI\303\212N", nullptr));
        comboBox_timkiem->setItemText(0, QCoreApplication::translate("MainWindow", "Nh\341\273\213 Ph\303\242n", nullptr));
        comboBox_timkiem->setItemText(1, QCoreApplication::translate("MainWindow", "V\303\251t C\341\272\241n", nullptr));

        comboBox_sapxep->setItemText(0, QCoreApplication::translate("MainWindow", "Bubble Sort", nullptr));
        comboBox_sapxep->setItemText(1, QCoreApplication::translate("MainWindow", "Insertion Sort", nullptr));
        comboBox_sapxep->setItemText(2, QCoreApplication::translate("MainWindow", "Selection Sort", nullptr));
        comboBox_sapxep->setItemText(3, QCoreApplication::translate("MainWindow", "Merge Sort", nullptr));
        comboBox_sapxep->setItemText(4, QCoreApplication::translate("MainWindow", "Quick Sort", nullptr));
        comboBox_sapxep->setItemText(5, QCoreApplication::translate("MainWindow", "Heap Sort", nullptr));

        comboBox_tieuchi_timkiem->setItemText(0, QCoreApplication::translate("MainWindow", "M\303\243 Sinh Vi\303\252n", nullptr));
        comboBox_tieuchi_timkiem->setItemText(1, QCoreApplication::translate("MainWindow", "H\341\273\215", nullptr));
        comboBox_tieuchi_timkiem->setItemText(2, QCoreApplication::translate("MainWindow", "T\303\252n", nullptr));
        comboBox_tieuchi_timkiem->setItemText(3, QCoreApplication::translate("MainWindow", "L\341\273\233p", nullptr));
        comboBox_tieuchi_timkiem->setItemText(4, QCoreApplication::translate("MainWindow", "\304\220i\341\273\203m", nullptr));

        comboBox_tieuchi_sapxep->setItemText(0, QCoreApplication::translate("MainWindow", "M\303\243 Sinh Vi\303\252n", nullptr));
        comboBox_tieuchi_sapxep->setItemText(1, QCoreApplication::translate("MainWindow", "T\303\252n", nullptr));
        comboBox_tieuchi_sapxep->setItemText(2, QCoreApplication::translate("MainWindow", "\304\220i\341\273\203m", nullptr));

        groupBox_nutbam->setTitle(QCoreApplication::translate("MainWindow", "Ch\341\273\251c N\304\203ng Ch\303\255nh", nullptr));
        pushButton_in->setText(QCoreApplication::translate("MainWindow", "In", nullptr));
        pushButton_them->setText(QCoreApplication::translate("MainWindow", "Th\303\252m", nullptr));
        pushButton_xoa->setText(QCoreApplication::translate("MainWindow", "X\303\263a", nullptr));
        pushButton_sua->setText(QCoreApplication::translate("MainWindow", "S\341\273\255a", nullptr));
        pushButton_file->setText(QCoreApplication::translate("MainWindow", "T\341\272\243i File", nullptr));
        pushButton_diemthap->setText(QCoreApplication::translate("MainWindow", "\304\220i\341\273\203m Th\341\272\245p Nh\341\272\245t", nullptr));
        pushButton_diemcao->setText(QCoreApplication::translate("MainWindow", "\304\220i\341\273\203m Cao Nh\341\272\245t", nullptr));
        pushButton_trungbinh->setText(QCoreApplication::translate("MainWindow", "Trung B\303\254nh", nullptr));
        pushButton_Daoten->setText(QCoreApplication::translate("MainWindow", "\304\220\341\272\243o T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_mang->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "M\303\243 Sinh Vi\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_mang->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "H\341\273\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_mang->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_mang->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "L\341\273\233p", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_mang->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "\304\220i\341\273\203m", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_mang), QCoreApplication::translate("MainWindow", "M\341\272\243ng", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_dslkd->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "M\303\243 Sinh Vi\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_dslkd->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "H\341\273\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_dslkd->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_dslkd->horizontalHeaderItem(3);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "L\341\273\233p", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_dslkd->horizontalHeaderItem(4);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "\304\220i\341\273\203m", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_dslkd), QCoreApplication::translate("MainWindow", "Danh s\303\241ch li\303\252n k\341\272\277t \304\221\306\241n", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_dslkv->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "M\303\243 Sinh Vi\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget_dslkv->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "H\341\273\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget_dslkv->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget_dslkv->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "L\341\273\233p", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget_dslkv->horizontalHeaderItem(4);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "\304\220i\341\273\203m", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_dslkv), QCoreApplication::translate("MainWindow", "Danh s\303\241ch li\303\252n k\341\272\277t v\303\262ng", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget_dslkk->horizontalHeaderItem(0);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "M\303\243 Sinh Vi\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget_dslkk->horizontalHeaderItem(1);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "H\341\273\215", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget_dslkk->horizontalHeaderItem(2);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "T\303\252n", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget_dslkk->horizontalHeaderItem(3);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "L\341\273\233p", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget_dslkk->horizontalHeaderItem(4);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "\304\220i\341\273\203m", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_dslkk), QCoreApplication::translate("MainWindow", "Danh s\303\241ch li\303\252n k\341\272\277t k\303\251p", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
