#pragma once
#include "Danhsachsinhvien.h"
#include <QVector>
#include <QPair>
#include <QMap>
#include <QFile>
#include <QTextStream>
#include <QStringList>

struct node {
    QString msv;
    QString ho;
    QString ten;
    QString lop;
    double diem;
    node* next;
    node(const Sinhvien& sv)
        : msv(sv.msv), ho(sv.ho), ten(sv.ten), lop(sv.lop), diem(sv.diem), next(nullptr) {}
    node() : diem(0), next(nullptr) {}
};
typedef struct node* PTR;

class Sinhvien_cll : public DanhSachSinhVien {
private:
    PTR Last;
    int n;
    bool daSapXepDiem = false;
    PTR getNodeAt(int index) const;

public:
    Sinhvien_cll();
    ~Sinhvien_cll();

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

    double SapXep(int loaiSapXep, int tieuChi, bool tangDan) override;

    double TimKiem(const QString& tuKhoa, int tieuChi, bool,Sinhvien* ketQua, int& soLuong) const override;
    void TimKiemTuyenTinhCLL(const QString&, int, Sinhvien*, int&) const;
    void TimKiemNhiPhanCLL(const QString&, int, Sinhvien*, int&) const;

    QString DaoNguocHoTen(int viTri) const override;

    void LayDanhSachTheoDieuKien(bool (*dieuKien)(const Sinhvien&, const QString&), const QString& tuKhoa, Sinhvien* ketQua, int& soLuong) const;
};
