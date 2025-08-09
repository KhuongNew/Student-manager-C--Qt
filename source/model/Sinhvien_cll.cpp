#include "Sinhvien_cll.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QElapsedTimer>
#include <QCollator>
#include <QRegularExpression>
#include <algorithm>
#include <chrono>

Sinhvien_cll::Sinhvien_cll() : Last(nullptr), n(0), daSapXepDiem(false) {}

Sinhvien_cll::~Sinhvien_cll() {
    XoaTatCa();
}

PTR Sinhvien_cll::getNodeAt(int index) const {
    if (index < 0 || index >= n || !Last) return nullptr;
    PTR p = Last->next;
    for (int i = 0; i < index; ++i) p = p->next;
    return p;
}
int Sinhvien_cll::LayKichThuoc() const { return n; }

void Sinhvien_cll::XoaTatCa() {
    if (!Last) return;
    PTR p = Last->next;
    for (int i = 0; i < n; ++i) {
        PTR tmp = p;
        p = p->next;
        delete tmp;
    }
    Last = nullptr;
    n = 0;
}

void Sinhvien_cll::ThayTheTatCa(const Sinhvien* mangSV, int soLuong) {
    XoaTatCa();
    for (int i = 0; i < soLuong; ++i) {
        QString dummy;
        ThemSinhVien(mangSV[i], dummy);
    }
    daSapXepDiem = false;
}
Sinhvien Sinhvien_cll::LayTheoViTri(int viTri) const {
    PTR p = getNodeAt(viTri);
    if (!p) return Sinhvien();
    Sinhvien sv;
    sv.msv = p->msv;
    sv.ho = p->ho;
    sv.ten = p->ten;
    sv.lop = p->lop;
    sv.diem = p->diem;
    return sv;
}
void Sinhvien_cll::DatTheoViTri(int viTri, const Sinhvien& sv) {
    PTR p = getNodeAt(viTri);
    if (p) {
        p->msv = sv.msv;
        p->ho = sv.ho;
        p->ten = sv.ten;
        p->lop = sv.lop;
        p->diem = sv.diem;
    }
}
bool Sinhvien_cll::KiemTraTrungMaSV(const QString& msv) const {
    if (!Last) return false;
    PTR p = Last->next;
    for (int i = 0; i < n; ++i) {
        if (p->msv == msv) return true;
        p = p->next;
    }
    return false;
}
bool Sinhvien_cll::ThemSinhVien(const Sinhvien& sv, QString& thongBaoLoi) {
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
    PTR node = new ::node(sv);
    if (!Last) {
        Last = node;
        node->next = node;
    } else {
        node->next = Last->next;
        Last->next = node;
        Last = node;
    }
    ++n;
    daSapXepDiem = false;
    return true;
}
bool Sinhvien_cll::XoaSinhVien(const QString& msv, QString& thongBaoLoi) {
    if (!Last) {
        thongBaoLoi = "Danh sách trống!";
        return false;
    }
    PTR prev = Last;
    PTR curr = Last->next;
    for (int i = 0; i < n; ++i) {
        if (curr->msv == msv) {
            if (curr == Last && curr == Last->next) {
                delete curr;
                Last = nullptr;
            } else {
                prev->next = curr->next;
                if (curr == Last) Last = prev;
                delete curr;
            }
            --n;
            daSapXepDiem = false;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    thongBaoLoi = "Không tìm thấy mã sinh viên!";
    return false;
}

bool Sinhvien_cll::CapNhatSinhVien(const Sinhvien& sv, QString& thongBaoLoi) {
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
    PTR p = Last->next;
    for (int i = 0; i < n; ++i) {
        if (p->msv == sv.msv) {
            p->ho = sv.ho;
            p->ten = sv.ten;
            p->lop = sv.lop;
            p->diem = sv.diem;
            daSapXepDiem = false;
            return true;
        }
        p = p->next;
    }
    thongBaoLoi = "Không tìm thấy mã sinh viên!";
    return false;
}

bool Sinhvien_cll::isValidStudentID(const QString& studentID) const {
    static const QRegularExpression pattern("^([A-Z]\\d{2}[A-Z\\d]{4}\\d{3})$");
    if (studentID.length() != 10) {
        return false;
    }
    QRegularExpressionMatch match = pattern.match(studentID);
    return match.hasMatch();
}

QStringList Sinhvien_cll::ImportFromCSV(const QString& filePath) {
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


QVector<QPair<QString, double>> Sinhvien_cll::TinhDiemTrungBinhCacLop() const {
    QMap<QString, double> tongDiem;
    QMap<QString, int> soLuong;
    QVector<QPair<QString, double>> ketQua;

    if (!Last || n == 0) return ketQua;
    PTR p = Last->next;
    for (int i = 0; i < n; ++i) {
        tongDiem[p->lop] += p->diem;
        soLuong[p->lop]++;
        p = p->next;
    }
    for (auto it = tongDiem.begin(); it != tongDiem.end(); ++it) {
        double tb = it.value() / soLuong[it.key()];
        ketQua.append(qMakePair(it.key(), tb));
    }
    return ketQua;
}

void Sinhvien_cll::LayDiemThapNhat(Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    if (!Last || n == 0) return;
    if (daSapXepDiem) {
        double minDiem = Last->next->diem;
        PTR p = Last->next;
        int count = 0;
        do {
            if (qFuzzyCompare(p->diem + 1.0, minDiem + 1.0)) {
                Sinhvien sv;
                sv.msv = p->msv; sv.ho = p->ho; sv.ten = p->ten; sv.lop = p->lop; sv.diem = p->diem;
                ketQua[soLuong++] = sv;
            } else {
                break; 
            }
            p = p->next;
            ++count;
        } while (p != Last->next && count < n);
    } else {
        double minDiem = Last->next->diem;
        PTR p = Last->next->next;
        for (int i = 1; i < n; ++i) {
            if (p->diem < minDiem) minDiem = p->diem;
            p = p->next;
        }
        p = Last->next;
        for (int i = 0; i < n; ++i) {
            if (qFuzzyCompare(p->diem + 1.0, minDiem + 1.0)) {
                Sinhvien sv;
                sv.msv = p->msv; sv.ho = p->ho; sv.ten = p->ten; sv.lop = p->lop; sv.diem = p->diem;
                ketQua[soLuong++] = sv;
            }
            p = p->next;
        }
    }
}

void Sinhvien_cll::LayDiemCaoNhat(Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    if (!Last || n == 0) return;
    if (daSapXepDiem) {
        double maxDiem = Last->diem;
        PTR p = Last->next;
        int count = 0;
        do {
            p = p->next;
            ++count;
        } while (p != Last && count < n - 1);
        p = Last->next;
        count = 0;
        do {
            if (qFuzzyCompare(p->diem + 1.0, maxDiem + 1.0)) {
                Sinhvien sv;
                sv.msv = p->msv; sv.ho = p->ho; sv.ten = p->ten; sv.lop = p->lop; sv.diem = p->diem;
                ketQua[soLuong++] = sv;
            }
            p = p->next;
            ++count;
        } while (p != Last->next && count < n);
    } else {
        double maxDiem = Last->next->diem;
        PTR p = Last->next->next;
        for (int i = 1; i < n; ++i) {
            if (p->diem > maxDiem) maxDiem = p->diem;
            p = p->next;
        }
        p = Last->next;
        for (int i = 0; i < n; ++i) {
            if (qFuzzyCompare(p->diem + 1.0, maxDiem + 1.0)) {
                Sinhvien sv;
                sv.msv = p->msv; sv.ho = p->ho; sv.ten = p->ten; sv.lop = p->lop; sv.diem = p->diem;
                ketQua[soLuong++] = sv;
            }
            p = p->next;
        }
    }
}
QString Sinhvien_cll::DaoNguocHoTen(int viTri) const {
    PTR p = getNodeAt(viTri);
    if (!p) return "";
    QString full = p->ho + " " + p->ten;
    QString reversed;
    reversed.reserve(full.size());
    for (auto it = full.rbegin(); it != full.rend(); ++it) {
        reversed.append(*it);
    }
    return reversed;
}

void Sinhvien_cll::LayDanhSachTheoDieuKien(bool (*dieuKien)(const Sinhvien&, const QString&), const QString& tuKhoa, Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    if (!Last || n == 0) return;
    PTR p = Last->next;
    for (int i = 0; i < n; ++i) {
        Sinhvien sv;
        sv.msv = p->msv; sv.ho = p->ho; sv.ten = p->ten; sv.lop = p->lop; sv.diem = p->diem;
        if (dieuKien(sv, tuKhoa))
            ketQua[soLuong++] = sv;
        p = p->next;
    }
}

static bool soSanhTieuChi(const node& a, const node& b, int tieuChi, bool tangDan) {
    int cmp = 0;
    switch (tieuChi) {
        case 0: cmp = QString::compare(a.msv, b.msv, Qt::CaseInsensitive); break;
        case 1: {
            static QCollator collator(QLocale(QLocale::Vietnamese, QLocale::Vietnam));
            cmp = collator.compare(a.ten, b.ten);
            if (cmp == 0) cmp = collator.compare(a.ho, b.ho);
            if (cmp == 0) cmp = QString::compare(a.msv, b.msv, Qt::CaseInsensitive);
            break;
        }
        case 2: {cmp = (a.diem < b.diem ? -1 : (a.diem > b.diem ? 1 : 0));
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

static void swapNodeData(PTR a, PTR b) {
    std::swap(a->msv, b->msv);
    std::swap(a->ho, b->ho);
    std::swap(a->ten, b->ten);
    std::swap(a->lop, b->lop);
    std::swap(a->diem, b->diem);
}

static void bubbleSortCLL(PTR Last, int n, int tieuChi, bool tangDan) {
    if (!Last || n <= 1) return;
    bool swapped;
    do {
        swapped = false;
        PTR p = Last->next;
        for (int i = 0; i < n - 1; ++i) {
            PTR q = p->next;
            if (!soSanhTieuChi(*p, *q, tieuChi, tangDan)) {
                swapNodeData(p, q);
                swapped = true;
            }
            p = p->next;
        }
    } while (swapped);
}

static void insertionSortCLL(PTR &Last, int n, int tieuChi, bool tangDan) {
    if (!Last || n <= 1) return;
    PTR sorted = nullptr;
    PTR curr = Last->next;
    for (int i = 0; i < n; ++i) {
        PTR next = curr->next;
        if (!sorted) {
            sorted = curr;
            sorted->next = sorted;
        } else {
            PTR s = sorted, prev = nullptr;
            do {
                if (soSanhTieuChi(*curr, *s, tieuChi, tangDan)) break;
                prev = s;
                s = s->next;
            } while (s != sorted);
            if (!prev) {
                PTR tail = sorted;
                while (tail->next != sorted) tail = tail->next;
                tail->next = curr;
                curr->next = sorted;
                sorted = curr;
            } else {
                prev->next = curr;
                curr->next = s;
            }
        }
        curr = next;
    }
    PTR p = sorted;
    while (p->next != sorted) p = p->next;
    Last = p;
    Last->next = sorted;
}

static void selectionSortCLL(PTR Last, int n, int tieuChi, bool tangDan) {
    if (!Last || n <= 1) return;
    PTR start = Last->next;
    for (int i = 0; i < n - 1; ++i) {
        PTR minmax = start;
        PTR p = start->next;
        for (int j = i + 1; j < n; ++j) {
            if (!soSanhTieuChi(*minmax, *p, tieuChi, tangDan)) {
                minmax = p;
            }
            p = p->next;
        }
        if (minmax != start) swapNodeData(start, minmax);
        start = start->next;
    }
}

static PTR splitCLL(PTR head, int n) {
    PTR mid = head;
    for (int i = 0; i < n / 2 - 1; ++i) mid = mid->next;
    PTR second = mid->next;
    mid->next = head;
    return second;
}
static PTR mergeCLL(PTR a, int na, PTR b, int nb, int tieuChi, bool tangDan) {
    PTR head = nullptr, tail = nullptr;
    int ia = 0, ib = 0;
    while (ia < na && ib < nb) {
        PTR &pick = soSanhTieuChi(*a, *b, tieuChi, tangDan) ? a : b;
        if (!head) {
            head = pick;
            tail = pick;
        } else {
            tail->next = pick;
            tail = pick;
        }
        if (pick == a) { a = a->next; ++ia; }
        else { b = b->next; ++ib; }
    }
    while (ia < na) { tail->next = a; tail = a; a = a->next; ++ia; }
    while (ib < nb) { tail->next = b; tail = b; b = b->next; ++ib; }
    tail->next = head;
    return head;
}
static PTR mergeSortCLLUtil(PTR head, int n, int tieuChi, bool tangDan) {
    if (n <= 1) return head;
    int n1 = n / 2, n2 = n - n1;
    PTR mid = splitCLL(head, n);
    PTR left = mergeSortCLLUtil(head, n1, tieuChi, tangDan);
    PTR right = mergeSortCLLUtil(mid, n2, tieuChi, tangDan);
    return mergeCLL(left, n1, right, n2, tieuChi, tangDan);
}
static void mergeSortCLL(PTR &Last, int n, int tieuChi, bool tangDan) {
    if (!Last || n <= 1) return;
    PTR head = Last->next;
    head = mergeSortCLLUtil(head, n, tieuChi, tangDan);
    PTR p = head;
    for (int i = 0; i < n - 1; ++i) p = p->next;
    Last = p;
    Last->next = head;
}

double Sinhvien_cll::SapXep(int loaiSapXep, int tieuChi, bool tangDan) {
    if (n <= 1) return 0;
    auto start = std::chrono::high_resolution_clock::now();
    switch (loaiSapXep) {
        case 0: bubbleSortCLL(Last, n, tieuChi, tangDan); break;
        case 1: insertionSortCLL(Last, n, tieuChi, tangDan); break;
        case 2: selectionSortCLL(Last, n, tieuChi, tangDan); break;
        case 3: mergeSortCLL(Last, n, tieuChi, tangDan); break;
        default: break;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    daSapXepDiem = (tieuChi == 2);
    return elapsed.count();
}

void Sinhvien_cll::TimKiemTuyenTinhCLL(const QString& tuKhoa, int tieuChi, Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    if (!Last || n == 0) return;
    QString key = tuKhoa.trimmed().toLower();
    bool isDouble = false;
    double doubleKey = tuKhoa.toDouble(&isDouble);
    PTR p = Last->next;
    int count = 0;
    do {
        bool match = false;
        switch (tieuChi) {
            case 0: match = p->msv.trimmed().toLower().contains(key); break;
            case 1: match = p->ho.trimmed().toLower().contains(key); break;
            case 2: match = p->ten.trimmed().toLower().contains(key); break;
            case 3: match = p->lop.trimmed().toLower().contains(key); break;
            case 4:
                if (isDouble) match = qFuzzyCompare(p->diem + 1, doubleKey + 1);
                else match = QString::number(p->diem).contains(key);
                break;
            default: break;
        }
        if (match) {
            ketQua[soLuong].msv = p->msv;
            ketQua[soLuong].ho = p->ho;
            ketQua[soLuong].ten = p->ten;
            ketQua[soLuong].lop = p->lop;
            ketQua[soLuong].diem = p->diem;
            ++soLuong;
        }
        p = p->next;
        ++count;
    } while (p != Last->next && count < n);
}
double Sinhvien_cll::TimKiem(const QString& tuKhoa, int tieuChi,bool , Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    if (!Last || n == 0) return 0;
    auto start = std::chrono::high_resolution_clock::now();
    TimKiemTuyenTinhCLL(tuKhoa, tieuChi, ketQua, soLuong);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}
