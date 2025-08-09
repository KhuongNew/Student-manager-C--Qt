#include "../view/mainwindow.h"
#include "./ui_mainwindow.h"
#include "Sinhvien_cll.h"
#include "Sinhvien_dll.h"
#include "Sinhvien_mang.h"
#include "Sinhvien_sll.h"
#include "dialog_sua.h"
#include "dialog_them.h"
#include "QMessageBox"
#include "QFileDialog"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableWidget_mang->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_dslkd->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_dslkv->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableWidget_dslkk->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    ui->tableWidget_mang->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_dslkd->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_dslkv->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_dslkk->setSelectionBehavior(QAbstractItemView::SelectRows);


    ui->tableWidget_mang->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_dslkd->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_dslkv->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_dslkk->setEditTriggers(QAbstractItemView::NoEditTriggers);

    dslk_kep  = new Sinhvien_dll();
    dslk_vong = new Sinhvien_cll();
    dslk_don  = new Sinhvien_sll();
    ds_mang   = new Sinhvien_mang();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_comboBox_sapxep_currentIndexChanged(int index) {
}

void MainWindow::on_pushButton_them_clicked()
{
    int tab = ui->tabWidget->currentIndex();
    Dialog_them dialog(this);
    while (true) {
        if (dialog.exec() != QDialog::Accepted) break;
        Sinhvien sv = dialog.getSinhvien(); 
        sv.msv = sv.msv.toUpper();
        sv.lop = sv.lop.toUpper();
        QString thongBaoLoi;
        bool ok = false;
        switch(tab) {
            case 0: ok = ds_mang->ThemSinhVien(sv, thongBaoLoi); break;
            case 1: ok = dslk_don->ThemSinhVien(sv, thongBaoLoi); break;
            case 2: ok = dslk_vong->ThemSinhVien(sv, thongBaoLoi); break;
            case 3: ok = dslk_kep->ThemSinhVien(sv, thongBaoLoi); break;
        }
        if (!ok) {
            QMessageBox msgBox(QMessageBox::Warning, "Lỗi", thongBaoLoi, QMessageBox::Ok, this);
            msgBox.setStyleSheet(R"(
                QLabel {
                    color: #2C3E50;
                    font: 15px "Segoe UI";
                    font-weight: bold;
                }
                QPushButton {
                    font: bold 14px "Segoe UI";
                    color: #2C3E50;
                }
            )");
            msgBox.exec();
        } else {
            capNhatBangTab(tab);
            break;
        }
    }
}


void MainWindow::on_pushButton_xoa_clicked()
{
    int tab = ui->tabWidget->currentIndex();
    QTableWidget* table = nullptr;
    DanhSachSinhVien* ds = nullptr;

    switch(tab) {
    case 0:
        table = ui->tableWidget_mang;
        ds = ds_mang;
        break;
    case 1:
        table = ui->tableWidget_dslkd;
        ds = dslk_don;
        break;
    case 2:
        table = ui->tableWidget_dslkv;
        ds = dslk_vong;
        break;
    case 3:
        table = ui->tableWidget_dslkk;
        ds = dslk_kep;
        break;
    }
    if (!table || !ds) return;

    int row = table->currentRow();
    int totalRows = table->rowCount();
    if (row < 0 && totalRows > 0) {
        QMessageBox msgBox(QMessageBox::Warning, "Lỗi", "Hãy chọn một dòng để xóa!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QMessageBox { font: 15px "Segoe UI"; }
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold;}
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }else if (totalRows == 0) {
        QMessageBox msgBox(QMessageBox::Warning, "Lỗi", "Danh sách trống!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }
    int viTri = -1;
    if (!viTriKetQuaTimKiem.isEmpty() && row < viTriKetQuaTimKiem.size()) {
        viTri = viTriKetQuaTimKiem[row];
    } else {
        viTri = row;
    }
    if (viTri < 0) {
        QMessageBox msgBox(QMessageBox::Warning, "Lỗi", "Không tìm thấy sinh viên trong danh sách gốc!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }
    QString msv = ds->LayTheoViTri(viTri).msv;
    QString thongBaoLoi;
    if (!ds->XoaSinhVien(msv, thongBaoLoi)) {
        QMessageBox msgBox(QMessageBox::Warning, "Lỗi", thongBaoLoi, QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QMessageBox { font: 15px "Segoe UI"; }
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold;}
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }
    capNhatBangTab(tab);
}

void MainWindow::capNhatBangTab(int tab) {
    QTableWidget* table = nullptr;
    DanhSachSinhVien* ds = nullptr;
    switch(tab) {
    case 0:
        table = ui->tableWidget_mang;
        ds = ds_mang;
        break;
    case 1:
        table = ui->tableWidget_dslkd;
        ds = dslk_don;
        break;
    case 2:
        table = ui->tableWidget_dslkv;
        ds = dslk_vong;
        break;
    case 3:
        table = ui->tableWidget_dslkk;
        ds = dslk_kep;
        break;
    }
    if (!table || !ds) return;
    table->setColumnCount(5);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    int n = ds->LayKichThuoc();
    table->setRowCount(n);
    QFont font("Segoe UI", 13, QFont::Normal);
    viTriKetQuaTimKiem.clear();
    for (int i = 0; i < n; ++i) {
        Sinhvien sv = ds->LayTheoViTri(i);
        QTableWidgetItem* item0 = new QTableWidgetItem(sv.msv);
        QTableWidgetItem* item1 = new QTableWidgetItem(sv.ho);
        QTableWidgetItem* item2 = new QTableWidgetItem(sv.ten);
        QTableWidgetItem* item3 = new QTableWidgetItem(sv.lop);
        QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(sv.diem));
        item0->setFont(font);
        item1->setFont(font);
        item2->setFont(font);
        item3->setFont(font);
        item4->setFont(font);
        table->setItem(i, 0, item0);
        table->setItem(i, 1, item1);
        table->setItem(i, 2, item2);
        table->setItem(i, 3, item3);
        table->setItem(i, 4, item4);

        viTriKetQuaTimKiem.append(i);
    }
    table->clearSelection();
}

void MainWindow::on_pushButton_sua_clicked()
{
    int tab = ui->tabWidget->currentIndex();
    QTableWidget* table = nullptr;
    DanhSachSinhVien* ds = nullptr;

    switch(tab) {
    case 0: table = ui->tableWidget_mang; ds = ds_mang; break;
    case 1: table = ui->tableWidget_dslkd; ds = dslk_don; break;
    case 2: table = ui->tableWidget_dslkv; ds = dslk_vong; break;
    case 3: table = ui->tableWidget_dslkk; ds = dslk_kep; break;
    }
    if (!table || !ds) return;

    int row = table->currentRow();
    int totalRows = table->rowCount();
    if (totalRows > 0 && row < 0) {
        QMessageBox msgBox(QMessageBox::Warning, "Lỗi", "Hãy chọn một dòng để sửa!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    } else if (totalRows == 0) {
        QMessageBox msgBox(QMessageBox::Warning, "Lỗi", "Danh sách trống!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }
    int viTri = -1;
    if (!viTriKetQuaTimKiem.isEmpty() && row < viTriKetQuaTimKiem.size()) {
        viTri = viTriKetQuaTimKiem[row];
    } else {
        viTri = row;
    }
    if (viTri < 0) {
        QMessageBox msgBox(QMessageBox::Warning, "Lỗi", "Không tìm thấy sinh viên trong danh sách gốc!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }
    Sinhvien sv = ds->LayTheoViTri(viTri);
    Dialog_sua dialog(this);
    dialog.setSinhvien(sv);
        if (dialog.exec() == QDialog::Accepted) {
        Sinhvien svMoi = dialog.getSinhvien();
        svMoi.msv = svMoi.msv.toUpper();
        svMoi.lop = svMoi.lop.toUpper();
        QString thongBaoLoi; 
        if (svMoi.msv != sv.msv) {
            QString loiThemMoi;
            if (!ds->ThemSinhVien(svMoi, loiThemMoi)) {
                QMessageBox msgBox(QMessageBox::Warning, "Lỗi cập nhật", loiThemMoi, QMessageBox::Ok, this);
                msgBox.setStyleSheet(R"(
                    QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
                    QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
                )");
                msgBox.exec();
                return; 
            }
            QString loiXoaCu; 
            if (!ds->XoaSinhVien(sv.msv, loiXoaCu)) {
                QMessageBox msgBox(QMessageBox::Warning, "Lỗi phụ khi xóa",
                                   QString("Sinh viên mới (MSV: %1) đã được thêm, nhưng có lỗi khi xóa sinh viên cũ (MSV: %2).\nLỗi: %3")
                                   .arg(svMoi.msv, sv.msv, loiXoaCu),
                                   QMessageBox::Ok, this);
                msgBox.setStyleSheet(R"(
                    QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
                    QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
                )");
                msgBox.exec();
            }
        } else {
            if (!ds->CapNhatSinhVien(svMoi, thongBaoLoi)) {
                QMessageBox msgBox(QMessageBox::Warning, "Lỗi", thongBaoLoi, QMessageBox::Ok, this);
                msgBox.setStyleSheet(R"(
                    QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
                    QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
                )");
                msgBox.exec();
                return;
            }
        }
        capNhatBangTab(tab);
    }
}


void MainWindow::on_pushButton_file_clicked()
{
    int tab = ui->tabWidget->currentIndex();
    QString filePath = QFileDialog::getOpenFileName(
        this,
        "Chọn file CSV",
        "",
        "CSV Files (*.csv);;All Files (*)"
        );

    if (filePath.isEmpty())
        return;
    QStringList thongBao;
    switch(tab) {
    case 0:
        if (ds_mang)
            thongBao = ds_mang->ImportFromCSV(filePath);
        break;
    case 1:
        if (dslk_don)
            thongBao = dslk_don->ImportFromCSV(filePath);
        break;
    case 2:
        if (dslk_vong)
            thongBao = dslk_vong->ImportFromCSV(filePath);
        break;
    case 3:
        if (dslk_kep)
            thongBao = dslk_kep->ImportFromCSV(filePath);
        break;
    default:
        QMessageBox::warning(this, "Lỗi", "Không xác định tab đang chọn.");
        return;
    }
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Kết quả import");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Chi tiết quá trình import:");
    msgBox.setInformativeText(thongBao.join("\n"));
    msgBox.setStyleSheet(R"(
        QLabel {
            font: 13px "Segoe UI";
            color: #2C3E50;
        }
        QPushButton {
            font: bold 13px "Segoe UI";
            padding: 4px 14px;
        }
    )");
    msgBox.exec();

    capNhatBangTab(tab);
}

void MainWindow::on_pushButton_diemthap_clicked()
{
    int index = ui->tabWidget->currentIndex();
    DanhSachSinhVien* ds = nullptr;
    switch (index) {
    case 0: ds = ds_mang; break;
    case 1: ds = dslk_don; break;
    case 2: ds = dslk_vong; break;
    case 3: ds = dslk_kep; break;
    }
    if (!ds) return;
    int soLuong = 0;
    Sinhvien* ketQua = new Sinhvien[ds->LayKichThuoc()];
    ds->LayDiemThapNhat(ketQua, soLuong);

    if (soLuong == 0) {
        QMessageBox msgBox(QMessageBox::Warning, "Thông báo", "Không tìm thấy sinh viên có điểm thấp nhất!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        delete[] ketQua;
        return;
    }
    QTableWidget* table = nullptr;
    switch (index) {
    case 0: table = ui->tableWidget_mang; break;
    case 1: table = ui->tableWidget_dslkd; break;
    case 2: table = ui->tableWidget_dslkv; break;
    case 3: table = ui->tableWidget_dslkk; break;
    }
    if (!table) {
        delete[] ketQua;
        return;
    }
    table->clearContents();
    table->setRowCount(soLuong);
    QFont font("Segoe UI", 13, QFont::Normal);
    viTriKetQuaTimKiem.clear();
    for (int i = 0; i < soLuong; ++i) {
        const Sinhvien& sv = ketQua[i];
        QTableWidgetItem* item0 = new QTableWidgetItem(sv.msv);
        QTableWidgetItem* item1 = new QTableWidgetItem(sv.ho);
        QTableWidgetItem* item2 = new QTableWidgetItem(sv.ten);
        QTableWidgetItem* item3 = new QTableWidgetItem(sv.lop);
        QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(sv.diem));
        item0->setFont(font);
        item1->setFont(font);
        item2->setFont(font);
        item3->setFont(font);
        item4->setFont(font);
        table->setItem(i, 0, item0);
        table->setItem(i, 1, item1);
        table->setItem(i, 2, item2);
        table->setItem(i, 3, item3);
        table->setItem(i, 4, item4);
        
        int viTri = -1;
        for (int j = 0; j < ds->LayKichThuoc(); ++j) {
            if (ds->LayTheoViTri(j).msv == sv.msv) {
                viTri = j;
                break;
            }
        }
        viTriKetQuaTimKiem.append(viTri);
    }
    table->resizeColumnsToContents();
    delete[] ketQua;
}

void MainWindow::on_pushButton_diemcao_clicked()
{
    int index = ui->tabWidget->currentIndex();
    Sinhvien* ketQua = nullptr;
    int soLuong = 0;
    DanhSachSinhVien* ds = nullptr;
    switch (index) {
    case 0: ds = ds_mang; break;
    case 1: ds = dslk_don; break;
    case 2: ds = dslk_vong; break;
    case 3: ds = dslk_kep; break;
    }
    if (!ds) return;
    ketQua = new Sinhvien[ds->LayKichThuoc()];
    ds->LayDiemCaoNhat(ketQua, soLuong);
    if (soLuong == 0 || ketQua == nullptr) {
        QMessageBox msgBox(QMessageBox::Warning, "Thông báo", "Không tìm thấy sinh viên có điểm cao nhất!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }
    QTableWidget* table = nullptr;
    switch (index) {
    case 0: table = ui->tableWidget_mang; break;
    case 1: table = ui->tableWidget_dslkd; break;
    case 2: table = ui->tableWidget_dslkv; break;
    case 3: table = ui->tableWidget_dslkk; break;
    }
    if (!table) {
        delete[] ketQua;
        return;
    }
    table->clearContents();
    table->setRowCount(soLuong);
    QFont font("Segoe UI", 13, QFont::Normal);
    viTriKetQuaTimKiem.clear(); 
    for (int i = 0; i < soLuong; ++i) {
        const Sinhvien& sv = ketQua[i];
        QTableWidgetItem* item0 = new QTableWidgetItem(sv.msv);
        QTableWidgetItem* item1 = new QTableWidgetItem(sv.ho);
        QTableWidgetItem* item2 = new QTableWidgetItem(sv.ten);
        QTableWidgetItem* item3 = new QTableWidgetItem(sv.lop);
        QTableWidgetItem* item4 = new QTableWidgetItem(QString::number(sv.diem));
        item0->setFont(font);
        item1->setFont(font);
        item2->setFont(font);
        item3->setFont(font);
        item4->setFont(font);
        table->setItem(i, 0, item0);
        table->setItem(i, 1, item1);
        table->setItem(i, 2, item2);
        table->setItem(i, 3, item3);
        table->setItem(i, 4, item4);

        int viTri = -1;
        for (int j = 0; j < ds->LayKichThuoc(); ++j) {
            if (ds->LayTheoViTri(j).msv == sv.msv) {
                viTri = j;
                break;
            }
        }
        viTriKetQuaTimKiem.append(viTri);
    }
    table->resizeColumnsToContents();
    delete[] ketQua;
}


void MainWindow::on_pushButton_trungbinh_clicked()
{
    int index = ui->tabWidget->currentIndex();
    QVector<QPair<QString, double>> ketQua;

    switch (index) {
    case 0:
        if (ds_mang)
            ketQua = ds_mang->TinhDiemTrungBinhCacLop();
        break;
    case 1:
        if (dslk_don)
            ketQua = dslk_don->TinhDiemTrungBinhCacLop();
        break;
    case 2:
        if (dslk_vong)
            ketQua = dslk_vong->TinhDiemTrungBinhCacLop();
        break;
    case 3:
        if (dslk_kep)
            ketQua = dslk_kep->TinhDiemTrungBinhCacLop();
        break;
    }

    if (ketQua.isEmpty()) {
        QMessageBox msgBox(QMessageBox::Warning, "Thông báo", "Không có dữ liệu để tính!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }

    QString msg = "Điểm trung bình theo lớp:\n\n";
    for (const auto& pair : ketQua) {
        msg += QString("Lớp: %1 - Điểm TB: %2\n")
                   .arg(pair.first)
                   .arg(QString::number(pair.second, 'f', 2));
    }

    QMessageBox box(this);
    box.setWindowTitle("Kết quả");
    box.setText(msg);
    box.setStyleSheet(R"(
        QLabel {
            font: 15px "Segoe UI";
            color: #2C3E50;
        }
        QPushButton {
            font: bold 15px "Segoe UI";
            padding: 4px 14px;
        }
    )");
    box.exec();
}


void MainWindow::on_pushButton_Daoten_clicked()
{
    int tab = ui->tabWidget->currentIndex();
    QTableWidget* table = nullptr;
    QString ketQua;

    switch (tab) {
    case 0: table = ui->tableWidget_mang; break;
    case 1: table = ui->tableWidget_dslkd; break;
    case 2: table = ui->tableWidget_dslkv; break;
    case 3: table = ui->tableWidget_dslkk; break;
    }

    if (!table) return;

    int row = table->currentRow();
    if (row < 0) {
        QMessageBox msgBox(QMessageBox::Warning, "Lỗi", "Hãy chọn một dòng!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }

    switch (tab) {
    case 0:
        if (ds_mang)
            ketQua = ds_mang->DaoNguocHoTen(row);
        break;
    case 1:
        if (dslk_don)
            ketQua = dslk_don->DaoNguocHoTen(row);
        break;
    case 2:
        if (dslk_vong)
            ketQua = dslk_vong->DaoNguocHoTen(row);
        break;
    case 3:
        if (dslk_kep)
            ketQua = dslk_kep->DaoNguocHoTen(row);
        break;
    }
    if (ketQua.isEmpty()) {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Kết quả");
        msgBox.setText("<b style='font-size: 16px; color: #C0392B;'>Không thể đảo họ tên.</b>");
        msgBox.exec();
        return;
    }

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Chuỗi đảo ngược");
    msgBox.setText(QString("<b style='font-size: 20px; color: #2C3E50;'>%1</b>").arg(ketQua));
    msgBox.exec();

}


void MainWindow::on_pushButton_ok_sapxep_clicked()
{
    int tab = ui->tabWidget->currentIndex();
    DanhSachSinhVien* ds = nullptr;
    switch (tab) {
    case 0: ds = ds_mang; break;
    case 1: ds = dslk_don; break;
    case 2: ds = dslk_vong; break;
    case 3: ds = dslk_kep; break;
    }
    if (!ds || ds->LayKichThuoc() == 0) {
        QMessageBox msgBox(QMessageBox::Information, "Thông báo", "Danh sách sinh viên hiện đang trống!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }
    int loaiSapXep = ui->comboBox_sapxep->currentIndex();
    int tieuChi = ui->comboBox_tieuchi_sapxep->currentIndex();
    bool tangDan = true;
    if ((tab == 1 || tab == 2) && (loaiSapXep == 5 || loaiSapXep == 4)) {
        QString dsName = (tab == 1) ? "liên kết đơn" : "liên kết vòng";
        QMessageBox msgBox(QMessageBox::Warning, "Không hỗ trợ",
            QString("Không hỗ trợ kiểu sắp xếp này cho danh sách %1!").arg(dsName),
            QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }
    double elapsed = 0.0;

    switch (tab) {
    case 0:
        if (ds_mang)
            elapsed = ds_mang->SapXep(loaiSapXep, tieuChi, tangDan);
        break;
    case 1:
        if (dslk_don)
            elapsed = dslk_don->SapXep(loaiSapXep, tieuChi, tangDan);
        break;
    case 2:
        if (dslk_vong)
            elapsed = dslk_vong->SapXep(loaiSapXep, tieuChi, tangDan);
        break;
    case 3:
        if (dslk_kep)
            elapsed = dslk_kep->SapXep(loaiSapXep, tieuChi, tangDan);
        break;
    }

    capNhatBangTab(tab);
    QMessageBox msgBox(QMessageBox::Information, "Kết quả sắp xếp",
        QString("Đã sắp xếp thành công.\nThời gian thực hiện: %1 ms").arg(QString::number(elapsed, 'f', 3)),
        QMessageBox::Ok, this);
    msgBox.setStyleSheet(R"(
        QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
        QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
    )");
    msgBox.exec();
}


void MainWindow::on_pushButton_ok_timkiem_clicked()
{
    int tab = ui->tabWidget->currentIndex();
    int tieuChi = ui->comboBox_tieuchi_timkiem->currentIndex();
    bool kiemTra = ui->comboBox_timkiem->currentIndex();
    QString tuKhoa = ui->lineEdit_TimKiem->text().trimmed();

    if (tuKhoa.isEmpty()) {
        QMessageBox msgBox(QMessageBox::Warning, "Lỗi", "Vui lòng nhập từ khóa tìm kiếm!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }
    
    if ((tab == 1 || tab == 2) && kiemTra == 0) {
        QString dsName = (tab == 1) ? "liên kết đơn" : "liên kết vòng";
        QMessageBox msgBox(QMessageBox::Warning, "Không hỗ trợ",
            QString("Không hỗ trợ tìm kiếm nhị phân cho danh sách %1!").arg(dsName),
            QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }    

    DanhSachSinhVien* ds = nullptr;
    switch (tab) {
    case 0: ds = ds_mang; break;
    case 1: ds = dslk_don; break;
    case 2: ds = dslk_vong; break;
    case 3: ds = dslk_kep; break;
    }

    if (!ds || ds->LayKichThuoc() == 0) {
        QMessageBox msgBox(QMessageBox::Information, "Thông báo", "Danh sách sinh viên hiện đang trống!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }

    Sinhvien* ketQua = new Sinhvien[ds->LayKichThuoc()];
    int soLuong = 0;
    double thoiGian = ds->TimKiem(tuKhoa, tieuChi, kiemTra, ketQua, soLuong);

    QTableWidget* table = nullptr;
    switch (tab) {
    case 0: table = ui->tableWidget_mang; break;
    case 1: table = ui->tableWidget_dslkd; break;
    case 2: table = ui->tableWidget_dslkv; break;
    case 3: table = ui->tableWidget_dslkk; break;
    }

    if (!table) {
        delete[] ketQua;
        return;
    }
    table->clearContents();
    table->setRowCount(soLuong);
    table->setColumnCount(5);
    viTriKetQuaTimKiem.clear();
    for (int i = 0; i < soLuong; ++i) {
        const Sinhvien& sv = ketQua[i];
        table->setItem(i, 0, new QTableWidgetItem(sv.msv));
        table->setItem(i, 1, new QTableWidgetItem(sv.ho));
        table->setItem(i, 2, new QTableWidgetItem(sv.ten));
        table->setItem(i, 3, new QTableWidgetItem(sv.lop));
        table->setItem(i, 4, new QTableWidgetItem(QString::number(sv.diem, 'f', 2)));
        QTableWidgetItem* itemCheck = table->item(i, tieuChi);
        if (itemCheck && itemCheck->text().toLower().contains(tuKhoa.toLower())) {
            itemCheck->setForeground(Qt::red);
            QFont f = itemCheck->font();
            f.setBold(true);
            itemCheck->setFont(f);
        }
        int viTri = -1;
        for (int j = 0; j < ds->LayKichThuoc(); ++j) {
            if (ds->LayTheoViTri(j).msv == sv.msv) {
                viTri = j;
                break;
            }
        }
        viTriKetQuaTimKiem.append(viTri);
    }
    table->resizeColumnsToContents();
    if (soLuong == 0) {
        QMessageBox msgBox(QMessageBox::Information, "Kết quả tìm kiếm",
            "Không tìm thấy sinh viên nào!",
            QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        delete[] ketQua;
        return;
    }
    QMessageBox msgBox(QMessageBox::Information, "Kết quả tìm kiếm",
        QString("Tìm thấy %1 sinh viên.\nThời gian thực hiện: %2 ms")
            .arg(soLuong)
            .arg(QString::number(thoiGian, 'f', 3)),
        QMessageBox::Ok, this);
    msgBox.setStyleSheet(R"(
        QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
        QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
    )");
    msgBox.exec();
    if (soLuong > 0) {  
    QMessageBox msgBox(QMessageBox::Question, "Đảo tên", "Bạn có muốn đảo tên các sinh viên vừa tìm kiếm không?", QMessageBox::Yes | QMessageBox::No, this);
    msgBox.setStyleSheet(R"(
        QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
        QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
    )");
    QMessageBox::StandardButton reply = static_cast<QMessageBox::StandardButton>(msgBox.exec());
    if (reply == QMessageBox::Yes) {
        table->setColumnCount(6);
        table->setHorizontalHeaderItem(5, new QTableWidgetItem("Tên đảo"));
        for (int i = 0; i < soLuong; ++i) {
            QString fullName = ketQua[i].ho + " " + ketQua[i].ten;
            QString reversed;
            for (int j = fullName.size() - 1; j >= 0; --j)
                reversed.append(fullName[j]);
            QTableWidgetItem* item = new QTableWidgetItem(reversed);
            QFont font = item->font();
            font.setBold(true);
            item->setFont(font);
            table->setItem(i, 5, item);
        }
        table->resizeColumnsToContents();
    }
}   
    delete[] ketQua;
}


void MainWindow::on_pushButton_in_clicked()
{
    int tab = ui->tabWidget->currentIndex();
    DanhSachSinhVien* ds = nullptr;
    switch (tab) {
    case 0: ds = ds_mang; break;
    case 1: ds = dslk_don; break;
    case 2: ds = dslk_vong; break;
    case 3: ds = dslk_kep; break;
    }
    if (!ds || ds->LayKichThuoc() == 0) {
        QMessageBox msgBox(QMessageBox::Information, "Thông báo", "Danh sách sinh viên đang trống!", QMessageBox::Ok, this);
        msgBox.setStyleSheet(R"(
            QLabel { color: #2C3E50; font: 15px "Segoe UI"; font-weight: bold; }
            QPushButton { font: bold 14px "Segoe UI"; color: #2C3E50; }
        )");
        msgBox.exec();
        return;
    }
    capNhatBangTab(tab);
}

