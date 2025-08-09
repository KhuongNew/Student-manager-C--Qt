#pragma once
#include "Danhsachsinhvien.h"
#include <QVector>
#include <QPair>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QStringList>

class Sinhvien_mang : public DanhSachSinhVien {
private:
    Sinhvien* ds;
    int n;
    bool daSapXepDiem;

public:
    Sinhvien_mang();
    ~Sinhvien_mang();

    int LayKichThuoc() const override;
    void XoaTatCa() override;
    void ThayTheTatCa(const Sinhvien* mangSV, int soLuong) override;

    Sinhvien LayTheoViTri(int viTri) const override;
    void DatTheoViTri(int viTri, const Sinhvien& sv) override;

    bool ThemSinhVien(const Sinhvien& sv, QString& thongBaoLoi) override;
    bool XoaSinhVien(const QString& msv, QString& thongBaoLoi) override;
    bool CapNhatSinhVien(const Sinhvien& sv, QString& thongBaoLoi) override;
    bool KiemTraTrungMaSV(const QString& msv) const override;
    QStringList ImportFromCSV(const QString& filePath) override;
    bool isValidStudentID(const QString& studentID) const;

    QVector<QPair<QString, double>> TinhDiemTrungBinhCacLop() const override;
    void LayDiemThapNhat(Sinhvien* ketQua, int& soLuong) const override;
    void LayDiemCaoNhat(Sinhvien* ketQua, int& soLuong) const override;

    double SapXep(int loai, int tieuChi, bool tangDan) override;

    double TimKiem(const QString& tuKhoa, int tieuChi, bool kiemTra, Sinhvien* ketQua, int& soLuong) const override;

    QString DaoNguocHoTen(int viTri) const override;

    void LayDanhSachTheoDieuKien(bool (*dieuKien)(const Sinhvien&, const QString&), const QString& tuKhoa, Sinhvien* ketQua, int& soLuong) const;
};