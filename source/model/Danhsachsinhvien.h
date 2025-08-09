#pragma once

#include <QString>
#include "Sinhvien.h"

class DanhSachSinhVien {
public:
    virtual ~DanhSachSinhVien() {}

    virtual int LayKichThuoc() const = 0;
    virtual void XoaTatCa() = 0;
    virtual void ThayTheTatCa(const Sinhvien* mangSV, int soLuong) = 0;
    virtual QStringList ImportFromCSV(const QString& filePath)=0;

    virtual Sinhvien LayTheoViTri(int viTri) const = 0;
    virtual void DatTheoViTri(int viTri, const Sinhvien& sv) = 0;

    virtual bool ThemSinhVien(const Sinhvien& sv, QString& thongBaoLoi) = 0;
    virtual bool XoaSinhVien(const QString& maSV, QString& thongBaoLoi) = 0;
    virtual bool CapNhatSinhVien(const Sinhvien& sv, QString& thongBaoLoi) = 0;
    virtual bool KiemTraTrungMaSV(const QString& maSV) const = 0;

    virtual QVector<QPair<QString, double>> TinhDiemTrungBinhCacLop() const = 0;
    virtual void LayDiemThapNhat(Sinhvien* ketQua, int& soLuong) const = 0;
    virtual void LayDiemCaoNhat(Sinhvien* ketQua, int& soLuong) const = 0;
    virtual QString DaoNguocHoTen(int viTri) const = 0;

    virtual double SapXep(int loaiSapXep, int tieuChi, bool tangDan)= 0;

    virtual double TimKiem(const QString& tuKhoa, int tieuChi, bool kiemTra, Sinhvien* ketQua, int& soLuong) const = 0;
};
