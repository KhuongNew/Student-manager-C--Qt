#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Danhsachsinhvien.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_sapxep_currentIndexChanged(int index);

    void on_pushButton_them_clicked();

    void on_pushButton_xoa_clicked();

    void capNhatBangTab(int tab);

    void on_pushButton_sua_clicked();

    void on_pushButton_file_clicked();

    void on_pushButton_diemthap_clicked();

    void on_pushButton_diemcao_clicked();

    void on_pushButton_trungbinh_clicked();

    void on_pushButton_Daoten_clicked();

    void on_pushButton_ok_sapxep_clicked();

    void on_pushButton_ok_timkiem_clicked();

    void on_pushButton_in_clicked();

private:
    Ui::MainWindow *ui;
    DanhSachSinhVien* dslk_kep;
    DanhSachSinhVien* dslk_vong;   
    DanhSachSinhVien* dslk_don;  
    DanhSachSinhVien* ds_mang; 
    QVector<int> viTriKetQuaTimKiem; 
     
};
#endif // MAINWINDOW_H
