#include "Sinhvien_sll.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QElapsedTimer>
#include <QCollator>
#include <QRegularExpression>
#include <QVector>
#include <algorithm>
#include <QMap>

Sinhvien_sll::Sinhvien_sll() : First(nullptr), n(0), daSapXepDiem(false) {}
Sinhvien_sll::~Sinhvien_sll() {
    XoaTatCa();
}

PTR_sll Sinhvien_sll::getNodeAt(int index) const {
    if (index < 0 || index >= n) return nullptr;
    PTR_sll p = First;
    for (int i = 0; i < index && p; ++i) {
        p = p->next;
    }
    return p;
}

int Sinhvien_sll::LayKichThuoc() const {
    return n;
}

void Sinhvien_sll::XoaTatCa() {
    PTR_sll p = First;
    while (p) {
        PTR_sll tmp = p->next;
        delete p;
        p = tmp;
    }
    First = nullptr;
    n = 0;
}

void Sinhvien_sll::ThayTheTatCa(const Sinhvien* mangSV, int soLuong) {
    XoaTatCa();
    for (int i = 0; i < soLuong; ++i) {
        QString err;
        ThemSinhVien(mangSV[i], err);
    }
    daSapXepDiem = false;
}

Sinhvien Sinhvien_sll::LayTheoViTri(int viTri) const {
    PTR_sll p = getNodeAt(viTri);
    if (!p) return Sinhvien();
    Sinhvien sv;
    sv.msv  = p->msv;
    sv.ho   = p->ho;
    sv.ten  = p->ten;
    sv.lop  = p->lop;
    sv.diem = p->diem;
    return sv;
}

void Sinhvien_sll::DatTheoViTri(int viTri, const Sinhvien& sv) {
    PTR_sll p = getNodeAt(viTri);
    if (p) {
        p->msv  = sv.msv;
        p->ho   = sv.ho;
        p->ten  = sv.ten;
        p->lop  = sv.lop;
        p->diem = sv.diem;
    }
}

bool Sinhvien_sll::KiemTraTrungMaSV(const QString& msv) const {
    PTR_sll p = First;
    while (p) {
        if (p->msv == msv) return true;
        p = p->next;
    }
    return false;
}

bool Sinhvien_sll::isValidStudentID(const QString& studentID) const {
    QRegularExpression pattern("^[A-Z]\\d{2}[A-Z\\d]{4}\\d{3}$");
    if (studentID.length() != 10) return false;
    return pattern.match(studentID).hasMatch();
}

bool Sinhvien_sll::ThemSinhVien(const Sinhvien& sv, QString& thongBaoLoi) {
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
    PTR_sll node = new node_sll;
    node->msv  = sv.msv;
    node->ho   = sv.ho;
    node->ten  = sv.ten;
    node->lop  = sv.lop;
    node->diem = sv.diem;
    node->next = nullptr;
    if (!First) {
        First = node;
    } else {
        PTR_sll p = First;
        while (p->next) p = p->next;
        p->next = node;
    }
    ++n;
    daSapXepDiem = false; 
    return true;
}

bool Sinhvien_sll::XoaSinhVien(const QString& msv, QString& thongBaoLoi) {
    if (!First) {
        thongBaoLoi = "Danh sách trống!";
        return false;
    }
    if (First->msv == msv) {
        PTR_sll tmp = First;
        First = First->next;
        delete tmp;
        --n;
        daSapXepDiem = false;
        return true;
    }
    PTR_sll prev = First;
    PTR_sll curr = First->next;
    while (curr) {
        if (curr->msv == msv) {
            prev->next = curr->next;
            delete curr;
            --n;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    thongBaoLoi = "Không tìm thấy mã sinh viên!";
    return false;
}

bool Sinhvien_sll::CapNhatSinhVien(const Sinhvien& sv, QString& thongBaoLoi) {
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
    PTR_sll p = First;
    while (p) {
        if (p->msv == sv.msv) {
            p->ho   = sv.ho;
            p->ten  = sv.ten;
            p->lop  = sv.lop;
            p->diem = sv.diem;
            daSapXepDiem = false;
            return true;
        }
        p = p->next;
    }
    thongBaoLoi = "Không tìm thấy mã sinh viên!";
    return false;
}

QStringList Sinhvien_sll::ImportFromCSV(const QString& filePath) {
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

QVector<QPair<QString, double>> Sinhvien_sll::TinhDiemTrungBinhCacLop() const {
    QVector<QPair<QString, double>> ketQua;
    if (!First || n == 0) return ketQua;
    QMap<QString, double> tongDiem;
    QMap<QString, int> soLuong;
    PTR_sll p = First;
    while (p) {
        tongDiem[p->lop] += p->diem;
        soLuong[p->lop]++;
        p = p->next;
    }
    for (auto it = tongDiem.begin(); it != tongDiem.end(); ++it) {
        double trungBinh = it.value() / soLuong[it.key()];
        ketQua.append(qMakePair(it.key(), trungBinh));
    }
    return ketQua;
}

void Sinhvien_sll::LayDiemThapNhat(Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    if (!First || n == 0) return;
    if (daSapXepDiem) {
        double minD = First->diem;
        PTR_sll p = First;
        while (p && qFuzzyCompare(p->diem + 1.0, minD + 1.0)) {
            Sinhvien sv;
            sv.msv  = p->msv;
            sv.ho   = p->ho;
            sv.ten  = p->ten;
            sv.lop  = p->lop;
            sv.diem = p->diem;
            ketQua[soLuong++] = sv;
            p = p->next;
        }
    } else {
        double minD = First->diem;
        PTR_sll p = First->next;
        while (p) {
            if (p->diem < minD) minD = p->diem;
            p = p->next;
        }
        p = First;
        while (p) {
            if (qFuzzyCompare(p->diem + 1.0, minD + 1.0)) {
                Sinhvien sv;
                sv.msv  = p->msv;
                sv.ho   = p->ho;
                sv.ten  = p->ten;
                sv.lop  = p->lop;
                sv.diem = p->diem;
                ketQua[soLuong++] = sv;
            }
            p = p->next;
        }
    }
}

void Sinhvien_sll::LayDiemCaoNhat(Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    if (!First || n == 0) return;
    if (daSapXepDiem) {
        PTR_sll p = First;
        while (p->next) p = p->next;
        double maxD = p->diem;
        p = First;
        while (p && qFuzzyCompare(p->diem + 1.0, maxD + 1.0)) {
            p = p->next;
        }
        p = First;
        while (p) {
            if (qFuzzyCompare(p->diem + 1.0, maxD + 1.0)) {
                Sinhvien sv;
                sv.msv  = p->msv;
                sv.ho   = p->ho;
                sv.ten  = p->ten;
                sv.lop  = p->lop;
                sv.diem = p->diem;
                ketQua[soLuong++] = sv;
            }
            p = p->next;
        }
    } else {
        double maxD = First->diem;
        PTR_sll p = First->next;
        while (p) {
            if (p->diem > maxD) maxD = p->diem;
            p = p->next;
        }
        p = First;
        while (p) {
            if (qFuzzyCompare(p->diem + 1.0, maxD + 1.0)) {
                Sinhvien sv;
                sv.msv  = p->msv;
                sv.ho   = p->ho;
                sv.ten  = p->ten;
                sv.lop  = p->lop;
                sv.diem = p->diem;
                ketQua[soLuong++] = sv;
            }
            p = p->next;
        }
    }
}
QString Sinhvien_sll::DaoNguocHoTen(int viTri) const {
    PTR_sll p = getNodeAt(viTri);
    if (!p) return "";
    QString full = p->ho + " " + p->ten;
    QString reversed;
    reversed.reserve(full.size());
    for (auto it = full.rbegin(); it != full.rend(); ++it) {
        reversed.append(*it);
    }
    return reversed;
}

void Sinhvien_sll::LayDanhSachTheoDieuKien(bool (*dieuKien)(const Sinhvien&, const QString&), const QString& tuKhoa, Sinhvien* ketQua, int& soLuong) const
{
    soLuong = 0;
    if (!First || n == 0) return;
    PTR_sll p = First;
    while (p) {
        Sinhvien sv;
        sv.msv  = p->msv;
        sv.ho   = p->ho;
        sv.ten  = p->ten;
        sv.lop  = p->lop;
        sv.diem = p->diem;
        if (dieuKien(sv, tuKhoa)) {
            ketQua[soLuong++] = sv;
        }
        p = p->next;
    }
}

static bool soSanhTieuChi(const node_sll& a, const node_sll& b, int tieuChi, bool tangDan) {
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

static void swapNodeData(PTR_sll a, PTR_sll b) {
    if (!a || !b || a == b) return;
    std::swap(a->msv, b->msv);
    std::swap(a->ho, b->ho);
    std::swap(a->ten, b->ten);
    std::swap(a->lop, b->lop);
    std::swap(a->diem, b->diem);
}

static void bubbleSortSLL(PTR_sll First, int n, int tieuChi, bool tangDan) {
    if (!First || n <= 1) return;
    bool swapped;
    do {
        swapped = false;
        PTR_sll p = First;
        while (p && p->next) {
            if (!soSanhTieuChi(*p, *(p->next), tieuChi, tangDan)) {
                swapNodeData(p, p->next);
                swapped = true;
            }
            p = p->next;
        }
    } while (swapped);
}

static void selectionSortSLL(PTR_sll First, int n, int tieuChi, bool tangDan) {
    for (PTR_sll p = First; p; p = p->next) {
        PTR_sll minmax = p;
        for (PTR_sll q = p->next; q; q = q->next) {
            if (!soSanhTieuChi(*minmax, *q, tieuChi, tangDan)) {
                minmax = q;
            }
        }
        if (minmax != p) {
            swapNodeData(p, minmax);
        }
    }
}

static void insertionSortSLL(PTR_sll& First, int n, int tieuChi, bool tangDan) {
    if (!First || !First->next) return;
    PTR_sll sorted = nullptr;
    PTR_sll curr = First;
    while (curr) {
        PTR_sll next = curr->next;
        if (!sorted || soSanhTieuChi(*curr, *sorted, tieuChi, tangDan)) {
            curr->next = sorted;
            sorted = curr;
        } else {
            PTR_sll p = sorted;
            while (p->next && !soSanhTieuChi(*curr, *(p->next), tieuChi, tangDan)) {
                p = p->next;
            }
            curr->next = p->next;
            p->next = curr;
        }
        curr = next;
    }
    First = sorted;
}

static PTR_sll mergeSLL(PTR_sll a, PTR_sll b, int tieuChi, bool tangDan) {
    if (!a) return b;
    if (!b) return a;
    if (soSanhTieuChi(*a, *b, tieuChi, tangDan)) {
        a->next = mergeSLL(a->next, b, tieuChi, tangDan);
        return a;
    } else {
        b->next = mergeSLL(a, b->next, tieuChi, tangDan);
        return b;
    }
}
static void splitSLL(PTR_sll head, PTR_sll& a, PTR_sll& b) {
    PTR_sll slow = head, fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    a = head;
    b = slow->next;
    slow->next = nullptr;
}
static void mergeSortSLL(PTR_sll& head, int tieuChi, bool tangDan) {
    if (!head || !head->next) return;
    PTR_sll a, b;
    splitSLL(head, a, b);
    mergeSortSLL(a, tieuChi, tangDan);
    mergeSortSLL(b, tieuChi, tangDan);
    head = mergeSLL(a, b, tieuChi, tangDan);
}

static PTR_sll getNodeAtSLL(PTR_sll First, int idx) {
    PTR_sll p = First;
    while (idx-- && p) p = p->next;
    return p;
}

static void timKiemTuyenTinhSLL(PTR_sll First, int n, const QString& tuKhoa, int tieuChi, int* chiSo, int& soLuong) {
    soLuong = 0;
    QString key = tuKhoa.trimmed().toLower();
    bool isDouble = false;
    double doubleKey = tuKhoa.toDouble(&isDouble);

    int idx = 0;
    for (PTR_sll p = First; p; p = p->next, ++idx) {
        if (tieuChi == 4 && isDouble) { 
            if (qFuzzyCompare(p->diem + 1, doubleKey + 1)) {
                chiSo[soLuong++] = idx;
            }
        } else {
            QString fieldValue;
            switch (tieuChi) {
                case 0: fieldValue = p->msv.toLower(); break;
                case 1: fieldValue = p->ho.toLower(); break;
                case 2: fieldValue = p->ten.toLower(); break;
                case 3: fieldValue = p->lop.toLower(); break;
                case 4: fieldValue = QString::number(p->diem); break;
            }
            if (fieldValue.contains(key)) {
                chiSo[soLuong++] = idx;
            }
        }
    }
}

double Sinhvien_sll::SapXep(int loai, int tieuChi, bool tangDan) {
    if (n <= 1) return 0;
    auto start = std::chrono::high_resolution_clock::now();
    switch (loai) {
        case 0: bubbleSortSLL(First, n, tieuChi, tangDan); break;
        case 1: insertionSortSLL(First, n, tieuChi, tangDan); break;
        case 2: selectionSortSLL(First, n, tieuChi, tangDan); break;
        case 3: mergeSortSLL(First, tieuChi, tangDan); break;
        default: break;
    }
    daSapXepDiem = (tieuChi == 2 && tangDan);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}

double Sinhvien_sll::TimKiem(const QString& tuKhoa, int tieuChi, bool, Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    if (!First || n == 0) return 0;
    int* chiSo = new int[n];
    auto start = std::chrono::high_resolution_clock::now();
    timKiemTuyenTinhSLL(First, n, tuKhoa, tieuChi, chiSo, soLuong);
    for (int i = 0; i < soLuong; ++i) {
        PTR_sll node = getNodeAtSLL(First, chiSo[i]);
        ketQua[i].msv = node->msv;
        ketQua[i].ho = node->ho;
        ketQua[i].ten = node->ten;
        ketQua[i].lop = node->lop;
        ketQua[i].diem = node->diem;
    }
    delete[] chiSo;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}
