#include "Sinhvien_mang.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QElapsedTimer>
#include <QCollator>
#include <QRegularExpression>
#include <algorithm> 
#include <QMap>
Sinhvien_mang::Sinhvien_mang() : ds(nullptr), n(0), daSapXepDiem(false) {}
Sinhvien_mang::~Sinhvien_mang() {
    delete[] ds;
    ds = nullptr;
    n = 0;
}

int Sinhvien_mang::LayKichThuoc() const {
    return n;
}

void Sinhvien_mang::XoaTatCa() {
    delete[] ds;
    ds = nullptr;
    n = 0;
}

void Sinhvien_mang::ThayTheTatCa(const Sinhvien* mangSV, int soLuong) {
    delete[] ds;
    ds = new Sinhvien[soLuong];
    for (int i = 0; i < soLuong; ++i)
        ds[i] = mangSV[i];
    n = soLuong;
    daSapXepDiem = false; 
}

Sinhvien Sinhvien_mang::LayTheoViTri(int index) const {
    if (index < 0 || index >= n) return Sinhvien();
    return ds[index];
}

void Sinhvien_mang::DatTheoViTri(int viTri, const Sinhvien& sv) {
    if (viTri < 0 || viTri >= n) return;
    ds[viTri] = sv;
}

bool Sinhvien_mang::KiemTraTrungMaSV(const QString& msv) const {
    for (int i = 0; i < n; ++i) {
        if (ds[i].msv == msv) return true;
    }
    return false;
}

bool Sinhvien_mang::ThemSinhVien(const Sinhvien& sv, QString& thongBaoLoi) {
    static const QRegularExpression reTen("^[a-zA-ZÀ-ỹĂăÂâÊêÔôƠơƯư\\s]+$");
    static const QRegularExpression reLop("^[A-Za-z0-9\\-]+$");
    thongBaoLoi.clear();
    bool hasError = false;
    if (sv.msv.trimmed().isEmpty() || sv.ho.trimmed().isEmpty() ||
        sv.ten.trimmed().isEmpty() || sv.lop.trimmed().isEmpty()) {
        thongBaoLoi += "- Không được để trống bất kỳ trường nào!\n";
        hasError = true;
    }
    if (!sv.ho.trimmed().isEmpty() && !reTen.match(sv.ho.trimmed()).hasMatch()) {
        thongBaoLoi += "- Họ không được chứa ký tự đặc biệt hoặc số!\n";
        hasError = true;
    }
    if (!sv.ten.trimmed().isEmpty() && !reTen.match(sv.ten.trimmed()).hasMatch()) {
        thongBaoLoi += "- Tên không được chứa ký tự đặc biệt hoặc số!\n";
        hasError = true;
    }
    if (std::isnan(sv.diem) || sv.diem < 0.0 || sv.diem > 10.0) {
        thongBaoLoi += "- Điểm phải là số từ 0 đến 10!\n";
        hasError = true;
    }
    if (!sv.msv.trimmed().isEmpty() && KiemTraTrungMaSV(sv.msv)) {
        thongBaoLoi += "- Trùng mã sinh viên!\n";
        hasError = true;
    }
    if (sv.msv.trimmed().contains(' ') || sv.lop.trimmed().contains(' ')) {
        thongBaoLoi += "- Mã sinh viên và lớp không được chứa khoảng trắng!\n";
        hasError = true;
    }
    if (!sv.msv.trimmed().isEmpty() && !isValidStudentID(sv.msv)) {
        thongBaoLoi += "- Mã sinh viên sai định dạng!\n";
        hasError = true;
    }
    if (!sv.lop.trimmed().isEmpty() && !reLop.match(sv.lop.trimmed()).hasMatch()) {
        thongBaoLoi += "- Lớp không được chứa khoảng trắng hoặc ký tự đặc biệt!\n";
        hasError = true;
    }
    if (hasError) {
        thongBaoLoi = thongBaoLoi.trimmed(); 
        return false;
    }
    Sinhvien* newArr = new Sinhvien[n + 1];
    for (int i = 0; i < n; ++i) newArr[i] = ds[i];
    newArr[n] = sv;
    delete[] ds;
    ds = newArr;
    n++;
    daSapXepDiem = false;
    return true;
}


bool Sinhvien_mang::XoaSinhVien(const QString& msv, QString& thongBaoLoi) {
    for (int i = 0; i < n; ++i) {
        if (ds[i].msv == msv) {
            Sinhvien* newArr = nullptr;
            if (n > 1) {
                newArr = new Sinhvien[n - 1];
                for (int j = 0, k = 0; j < n; ++j) {
                    if (j != i) newArr[k++] = ds[j];
                }
            }
            delete[] ds;
            ds = newArr;
            n--;
            return true;
        }
    }
    thongBaoLoi = "Không tìm thấy mã sinh viên!";
    daSapXepDiem = false; 
    return false;
}

bool Sinhvien_mang::CapNhatSinhVien(const Sinhvien& sv, QString& thongBaoLoi) {
    static const QRegularExpression reTen("^[a-zA-ZÀ-ỹĂăÂâÊêÔôƠơƯư\\s]+$");
    static const QRegularExpression reLop("^[A-Za-z0-9\\-]+$");
    thongBaoLoi.clear();
    bool hasError = false;
    if (sv.msv.trimmed().isEmpty() || sv.ho.trimmed().isEmpty() || sv.ten.trimmed().isEmpty() || sv.lop.trimmed().isEmpty()) {
        thongBaoLoi += "- Không được để trống mã SV, họ, tên, lớp!\n";
        hasError = true;
    }
    if (sv.msv.trimmed().contains(' ')) {
        thongBaoLoi += "- Mã sinh viên không được chứa khoảng trắng!\n";
        hasError = true;
    }
    if (!sv.msv.trimmed().isEmpty() && !isValidStudentID(sv.msv)) {
        thongBaoLoi += "- Mã sinh viên sai định dạng!\n";
        hasError = true;
    }
    if (!sv.ho.trimmed().isEmpty() && !reTen.match(sv.ho.trimmed()).hasMatch()) {
        thongBaoLoi += "- Họ không được chứa ký tự đặc biệt hoặc số!\n";
        hasError = true;
    }
    if (!sv.ten.trimmed().isEmpty() && !reTen.match(sv.ten.trimmed()).hasMatch()) {
        thongBaoLoi += "- Tên không được chứa ký tự đặc biệt hoặc số!\n";
        hasError = true;
    }
    if (std::isnan(sv.diem) || sv.diem < 0.0 || sv.diem > 10.0) {
        thongBaoLoi += "- Điểm phải là số từ 0 đến 10!\n";
        hasError = true;
    }
    if (!sv.lop.trimmed().isEmpty() && !reLop.match(sv.lop.trimmed()).hasMatch()) {
        thongBaoLoi += "- Lớp không được chứa khoảng trắng hoặc ký tự đặc biệt!\n";
        hasError = true;
    }
    if (hasError) {
        thongBaoLoi = thongBaoLoi.trimmed();
        return false;
    }
    for (int i = 0; i < n; ++i) {
        if (ds[i].msv == sv.msv) {
            ds[i] = sv;
            daSapXepDiem = false;
            return true;
        }
    }
    thongBaoLoi = "Không tìm thấy mã sinh viên!";
    return false;
}

bool Sinhvien_mang::isValidStudentID(const QString& studentID) const {
    QRegularExpression pattern("^[A-Z]\\d{2}[A-Z\\d]{4}\\d{3}$");
    if (studentID.length() != 10) {
        return false;
    }
    QRegularExpressionMatch match = pattern.match(studentID);
    return match.hasMatch();
}
QStringList Sinhvien_mang::ImportFromCSV(const QString& filePath) {
    QStringList thongBao;
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        thongBao << QString("Không thể mở file CSV: %1").arg(filePath);
        return thongBao;
    }
    QTextStream fin(&file);
    int line_no = 0;
    struct Entry { int line; QString ma, ho, ten, lop, diem_str; QStringList errs; bool hasError; };
    QVector<Entry> entries;
    QMap<QString, QVector<int>> maLineMap;
    if (!fin.atEnd()) {
        fin.readLine();
        ++line_no;
    }
    static const QRegularExpression reTen("^[A-Za-zÀ-ỹ\\s]+$");
    static const QRegularExpression reLop("^[A-Za-z0-9\\-]+$");
    static const QRegularExpression reMSV("^[A-Za-z]\\d{2}[A-Za-z\\d]{4}\\d{3}$");
    while (!fin.atEnd()) {
        QString line = fin.readLine();
        ++line_no;
        if (line.trimmed().isEmpty()) continue;
        QStringList fields = line.split(',');
        Entry e;
        e.line = line_no;
        e.hasError = false;
        e.errs.clear();
        if (fields.size() != 5) {
            e.hasError = true;
            e.errs << "Sai số trường (cần đúng 5 trường)";
            entries.append(e);
            continue;
        }
        e.ma = fields[0].trimmed();
        e.ho = fields[1].trimmed();
        e.ten = fields[2].trimmed();
        e.lop = fields[3].trimmed();
        e.diem_str = fields[4].trimmed();
        if (e.ma.isEmpty() || e.ho.isEmpty() || e.ten.isEmpty() || e.lop.isEmpty() || e.diem_str.isEmpty()) {
            e.hasError = true;
            e.errs << "Không được để trống bất kỳ trường nào";
        }
        if (!e.ma.isEmpty()) {
            if (e.ma.contains(' ')) {
                e.hasError = true;
                e.errs << "Mã sinh viên không được chứa khoảng trắng bên trong";
            }
            if (!reMSV.match(e.ma).hasMatch()) {
                e.hasError = true;
                e.errs << "Mã sinh viên sai định dạng";
            }
        }
        if (!e.ho.isEmpty() && !reTen.match(e.ho).hasMatch()) {
            e.hasError = true;
            e.errs << "Họ không được chứa số hoặc ký tự đặc biệt";
        }
        if (!e.ten.isEmpty() && !reTen.match(e.ten).hasMatch()) {
            e.hasError = true;
            e.errs << "Tên không được chứa số hoặc ký tự đặc biệt";
        }
        if (!e.lop.isEmpty()) {
            if (e.lop.contains(' ')) {
                e.hasError = true;
                e.errs << "Lớp không được chứa khoảng trắng bên trong";
            }
            if (!reLop.match(e.lop).hasMatch()) {
                e.hasError = true;
                e.errs << "Lớp không được chứa ký tự đặc biệt, chỉ (-), chữ và số";
            }
        }
        if (!e.diem_str.isEmpty()) {
            if (e.diem_str.contains(',')) {
                e.hasError = true;
                e.errs << "Điểm chứa dấu phẩy không hợp lệ (phải dùng dấu chấm)";
            }
            QRegularExpression reSo("^\\d*(?:\\.\\d+)?$");
            if (!reSo.match(e.diem_str).hasMatch()) {
                e.hasError = true;
                e.errs << "Điểm phải là số, không chứa chữ cái hoặc ký tự khác";
            } else {
                bool ok;
                double diem = e.diem_str.toDouble(&ok);
                if (!ok) {
                    e.hasError = true;
                    e.errs << "Không thể chuyển điểm sang số";
                } else if (diem < 0.0 || diem > 10.0) {
                    e.hasError = true;
                    e.errs << "Điểm vượt ngoài khoảng quy định 0 đến 10";
                }
            }
        }
        if (!e.ma.isEmpty()) {
            maLineMap[e.ma].append(entries.size());
        }
        entries.append(e);
    }
    file.close();
    for (auto it = maLineMap.constBegin(); it != maLineMap.constEnd(); ++it) {
        const QVector<int>& idxs = it.value();
        if (idxs.size() > 1) {
            for (int idx : idxs) {
                Entry &e = entries[idx];
                e.hasError = true;
                e.errs << "Trùng mã sinh viên trong file";
            }
        }
    }
    for (int i = 0; i < entries.size(); ++i) {
        Entry &e = entries[i];
        if (!e.ma.isEmpty() && !e.hasError) {
            if (KiemTraTrungMaSV(e.ma)) {
                e.hasError = true;
                e.errs << "Trùng mã sinh viên với danh sách hiện tại";
            }
        }
    }
    QList<Sinhvien> validStudents;
    bool anyError = false;
    for (const Entry &e : entries) {
        if (e.hasError) {
            anyError = true;
            QString msg = QString("LỖI: Dòng %1").arg(e.line);
            for (const QString &er : e.errs) {
                msg += "\n- " + er;
            }
            thongBao << msg;
        } else {
            Sinhvien sv;
            sv.msv = e.ma;
            sv.ho  = e.ho;
            sv.ten = e.ten;
            sv.lop = e.lop;
            sv.diem = e.diem_str.toDouble();
            validStudents.append(sv);
        }
    }
    if (anyError) {
        thongBao << "Không thể thêm sinh viên vì dữ liệu có lỗi!";
        return thongBao;
    }
    int added = 0;
    for (const Sinhvien &sv : validStudents) {
        QString err;
        if (ThemSinhVien(sv, err))
            ++added;
        else
            thongBao << QString("LỖI khi thêm SV %1: %2").arg(sv.msv, err);
    }
    thongBao << (added > 0
        ? QString("Đã thêm thành công %1 sinh viên.").arg(added)
        : "Không có dữ liệu hợp lệ để thêm.");
    return thongBao;
}

QVector<QPair<QString, double>> Sinhvien_mang::TinhDiemTrungBinhCacLop() const {
    QMap<QString, double> tong;
    QMap<QString, int> dem;
    QVector<QPair<QString, double>> kq;
    for (int i = 0; i < n; ++i) {
        tong[ds[i].lop] += ds[i].diem;
        dem[ds[i].lop]++;
    }
    for (auto it = tong.begin(); it != tong.end(); ++it) {
        double tb = it.value() / dem[it.key()];
        kq.append(qMakePair(it.key(), tb));
    }
    return kq;
}

void Sinhvien_mang::LayDiemThapNhat(Sinhvien* ketQua, int& soLuong) const {
    if (n == 0) {
        soLuong = 0;
        return;
    }
    if (daSapXepDiem) {
        double minDiem = ds[0].diem;
        soLuong = 0;
        for (int i = 0; i < n && ds[i].diem == minDiem; ++i)
            ketQua[soLuong++] = ds[i];
    } else {
        double minDiem = ds[0].diem;
        for (int i = 1; i < n; ++i)
            if (ds[i].diem < minDiem)
                minDiem = ds[i].diem;
        soLuong = 0;
        for (int i = 0; i < n; ++i)
            if (ds[i].diem == minDiem)
                ketQua[soLuong++] = ds[i];
    }
}

void Sinhvien_mang::LayDiemCaoNhat(Sinhvien* ketQua, int& soLuong) const {
    if (n == 0) {
        soLuong = 0;
        return;
    }
    if (daSapXepDiem) {
        double maxDiem = ds[n - 1].diem;
        soLuong = 0;
        for (int i = n - 1; i >= 0 && ds[i].diem == maxDiem; --i)
            ketQua[soLuong++] = ds[i];
    } else {
        double maxDiem = ds[0].diem;
        for (int i = 1; i < n; ++i)
            if (ds[i].diem > maxDiem)
                maxDiem = ds[i].diem;
        soLuong = 0;
        for (int i = 0; i < n; ++i)
            if (ds[i].diem == maxDiem)
                ketQua[soLuong++] = ds[i];
    }
}

QString Sinhvien_mang::DaoNguocHoTen(int viTri) const {
    Sinhvien sv = LayTheoViTri(viTri);
    QString full = sv.ho + " " + sv.ten;
    QString reversed;
    reversed.reserve(full.size());
    for (auto it = full.rbegin(); it != full.rend(); ++it) {
        reversed.append(*it);
    }
    return reversed;
}

void Sinhvien_mang::LayDanhSachTheoDieuKien(bool (*dieuKien)(const Sinhvien&, const QString&), const QString& tuKhoa, Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    for (int i = 0; i < n; ++i) {
        if (dieuKien(ds[i], tuKhoa))
            ketQua[soLuong++] = ds[i];
    }
}

static bool soSanhTieuChi(const Sinhvien& a, const Sinhvien& b, int tieuChi, bool tangDan) {
    int cmp = 0;
    switch (tieuChi) {
        case 0:
            cmp = QString::compare(a.msv, b.msv, Qt::CaseInsensitive);
            break;
        case 1: {
            static QCollator collator(QLocale(QLocale::Vietnamese, QLocale::Vietnam));
            cmp = collator.compare(a.ten, b.ten);
            if (cmp == 0) cmp = collator.compare(a.ho, b.ho);
            if (cmp == 0) cmp = QString::compare(a.msv, b.msv, Qt::CaseInsensitive);
            break;
        }
        case 2: {
            cmp = (a.diem < b.diem ? -1 : (a.diem > b.diem ? 1 : 0));
            if (cmp == 0) {
                static QCollator collator(QLocale(QLocale::Vietnamese, QLocale::Vietnam));
                cmp = collator.compare(a.ten, b.ten);
                if (cmp == 0) cmp = collator.compare(a.ho, b.ho);
                if (cmp == 0) cmp = QString::compare(a.msv, b.msv, Qt::CaseInsensitive);
            }
            break;
        }
        default: cmp = 0;
    }
    return tangDan ? (cmp < 0) : (cmp > 0);
}


static void swapSinhvien(Sinhvien& a, Sinhvien& b) {
    std::swap(a, b);
}

static void bubbleSortMang(Sinhvien* ds, int n, int tieuChi, bool tangDan) {
    if (!ds || n <= 1) return;
    bool swapped;
    do {
        swapped = false;
        for (int i = 0; i < n - 1; ++i) {
            if (!soSanhTieuChi(ds[i], ds[i + 1], tieuChi, tangDan)) {
                swapSinhvien(ds[i], ds[i + 1]);
                swapped = true;
            }
        }
    } while (swapped);
}

static void insertionSortMang(Sinhvien* ds, int n, int tieuChi, bool tangDan) {
    for (int i = 1; i < n; ++i) {
        Sinhvien key = ds[i];
        int j = i - 1;
        while (j >= 0 && !soSanhTieuChi(ds[j], key, tieuChi, tangDan)) {
            ds[j + 1] = ds[j];
            j--;
        }
        ds[j + 1] = key;
    }
}

static void selectionSortMang(Sinhvien* ds, int n, int tieuChi, bool tangDan) {
    for (int i = 0; i < n - 1; ++i) {
        int minmaxIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (!soSanhTieuChi(ds[minmaxIdx], ds[j], tieuChi, tangDan)) {
                minmaxIdx = j;
            }
        }
        if (minmaxIdx != i) {
            swapSinhvien(ds[i], ds[minmaxIdx]);
        }
    }
}

static void mergeMang(Sinhvien* ds, int left, int mid, int right, int tieuChi, bool tangDan) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Sinhvien* L = new Sinhvien[n1];
    Sinhvien* R = new Sinhvien[n2];
    for (int i = 0; i < n1; ++i)
        L[i] = ds[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = ds[mid + 1 + j];
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (soSanhTieuChi(L[i], R[j], tieuChi, tangDan))
            ds[k++] = L[i++];
        else
            ds[k++] = R[j++];
    }
    while (i < n1) ds[k++] = L[i++];
    while (j < n2) ds[k++] = R[j++];
    delete[] L;
    delete[] R;
}

static void mergeSortMang(Sinhvien* ds, int left, int right, int tieuChi, bool tangDan) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSortMang(ds, left, mid, tieuChi, tangDan);
        mergeSortMang(ds, mid + 1, right, tieuChi, tangDan);
        mergeMang(ds, left, mid, right, tieuChi, tangDan);
    }
}

static void heapifyMang(Sinhvien* ds, int n, int i, int tieuChi, bool tangDan) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && soSanhTieuChi(ds[largest], ds[l], tieuChi, tangDan))
        largest = l;
    if (r < n && soSanhTieuChi(ds[largest], ds[r], tieuChi, tangDan))
        largest = r;
    if (largest != i) {
        swapSinhvien(ds[i], ds[largest]);
        heapifyMang(ds, n, largest, tieuChi, tangDan);
    }
}

static void heapSortMang(Sinhvien* ds, int n, int tieuChi, bool tangDan) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapifyMang(ds, n, i, tieuChi, tangDan);
    for (int i = n - 1; i > 0; --i) {
        swapSinhvien(ds[0], ds[i]);
        heapifyMang(ds, i, 0, tieuChi, tangDan);
    }
}

static int partitionMang(Sinhvien* ds, int low, int high, int tieuChi, bool tangDan) {
    Sinhvien pivot = ds[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (soSanhTieuChi(ds[j], pivot, tieuChi, tangDan)) {
            ++i;
            swapSinhvien(ds[i], ds[j]);
        }
    }
    swapSinhvien(ds[i + 1], ds[high]);
    return i + 1;
}

static void quickSortMang(Sinhvien* ds, int low, int high, int tieuChi, bool tangDan) {
    if (low < high) {
        int pi = partitionMang(ds, low, high, tieuChi, tangDan);
        quickSortMang(ds, low, pi - 1, tieuChi, tangDan);
        quickSortMang(ds, pi + 1, high, tieuChi, tangDan);
    }
}

double Sinhvien_mang::SapXep(int loai, int tieuChi, bool tangDan) {
    if (n <= 1 || ds == nullptr) return 0;
    auto start = std::chrono::high_resolution_clock::now();
    switch (loai) {
        case 0: bubbleSortMang(ds, n, tieuChi, tangDan); break;
        case 1: insertionSortMang(ds, n, tieuChi, tangDan); break;
        case 2: selectionSortMang(ds, n, tieuChi, tangDan); break;
        case 3: mergeSortMang(ds, 0, n - 1, tieuChi, tangDan); break;
        case 4: quickSortMang(ds, 0, n - 1, tieuChi, tangDan); break;
        case 5: heapSortMang(ds, n, tieuChi, tangDan); break;
        default: break;
    }
    daSapXepDiem = (tieuChi == 2 && tangDan);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}

static void timKiemTuyenTinhMang(Sinhvien* ds, int n, const QString& tuKhoa, int tieuChi, int* chiSo, int& soLuong) {
    soLuong = 0;
    QString key = tuKhoa.trimmed().toLower();
    bool isDouble = false;
    double doubleKey = tuKhoa.toDouble(&isDouble);
    for (int i = 0; i < n; ++i) {
        if (tieuChi == 4 && isDouble) {
            if (qFuzzyCompare(ds[i].diem + 1, doubleKey + 1)) {
                chiSo[soLuong++] = i;
            }
        } else {
            QString fieldValue;
            switch (tieuChi) {
                case 0: fieldValue = ds[i].msv.toLower(); break;
                case 1: fieldValue = ds[i].ho.toLower(); break;
                case 2: fieldValue = ds[i].ten.toLower(); break;
                case 3: fieldValue = ds[i].lop.toLower(); break;
                case 4: fieldValue = QString::number(ds[i].diem); break;
                default: fieldValue = ""; break;
            }
            if (fieldValue.contains(key)) {
                chiSo[soLuong++] = i;
            }
        }
    }
}

static void timKiemNhiPhanMang(Sinhvien* ds, int n, const QString& tuKhoa, int tieuChi, int* chiSo, int& soLuong) {
    soLuong = 0;
    QString key = tuKhoa.trimmed().toLower();
    bool isDouble = false;
    double doubleKey = tuKhoa.toDouble(&isDouble);
    if (tieuChi == 4 && isDouble) {
        int l = 0, r = n - 1, found = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (qFuzzyCompare(ds[m].diem + 1, doubleKey + 1)) {
                found = m;
                break;
            } else if (ds[m].diem < doubleKey) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (found != -1) {
            int left = found, right = found;
            while (left > 0 && qFuzzyCompare(ds[left - 1].diem + 1, doubleKey + 1)) --left;
            while (right < n - 1 && qFuzzyCompare(ds[right + 1].diem + 1, doubleKey + 1)) ++right;
            for (int i = left; i <= right; ++i)
                chiSo[soLuong++] = i;
        }
    } else {
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            QString val;
            switch (tieuChi) {
                case 0: val = ds[m].msv.toLower(); break;
                case 1: val = ds[m].ho.toLower(); break;
                case 2: val = ds[m].ten.toLower(); break;
                case 3: val = ds[m].lop.toLower(); break;
                case 4: val = QString::number(ds[m].diem); break;
                default: val = ""; break;
            }
            if (val == key) {
                int left = m, right = m;
                while (left > 0) {
                    QString v;
                    switch (tieuChi) {
                        case 0: v = ds[left - 1].msv.toLower(); break;
                        case 1: v = ds[left - 1].ho.toLower(); break;
                        case 2: v = ds[left - 1].ten.toLower(); break;
                        case 3: v = ds[left - 1].lop.toLower(); break;
                        case 4: v = QString::number(ds[left - 1].diem); break;
                        default: v = ""; break;
                    }
                    if (v == key) --left; else break;
                }
                while (right < n - 1) {
                    QString v;
                    switch (tieuChi) {
                        case 0: v = ds[right + 1].msv.toLower(); break;
                        case 1: v = ds[right + 1].ho.toLower(); break;
                        case 2: v = ds[right + 1].ten.toLower(); break;
                        case 3: v = ds[right + 1].lop.toLower(); break;
                        case 4: v = QString::number(ds[right + 1].diem); break;
                        default: v = ""; break;
                    }
                    if (v == key) ++right; else break;
                }
                for (int i = left; i <= right; ++i)
                    chiSo[soLuong++] = i;
                return;
            }
            if (val < key) l = m + 1;
            else r = m - 1;
        }
    }
}

double Sinhvien_mang::TimKiem(const QString& tuKhoa, int tieuChi, bool kiemTra, Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    if (n == 0 || ds == nullptr) return 0;
    int* chiSo = new int[n];
    auto start = std::chrono::high_resolution_clock::now();
    if (kiemTra) {
        timKiemTuyenTinhMang(ds, n, tuKhoa, tieuChi, chiSo, soLuong);
    } else {
        timKiemNhiPhanMang(ds, n, tuKhoa, tieuChi, chiSo, soLuong);
    }
    for (int i = 0; i < soLuong; ++i)
        ketQua[i] = ds[chiSo[i]];
    delete[] chiSo;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}
