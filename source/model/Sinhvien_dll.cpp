#include "Sinhvien_dll.h"
#include <QFile>
#include <QTextStream>
#include <QStringList>
#include <QElapsedTimer>
#include <QCollator>
#include <QRegularExpression>
#include <QVector>
#include <algorithm>
#include <QMap>
#include <QString>
#include <QDebug>
#include <chrono>


Sinhvien_dll::Sinhvien_dll() : First(nullptr), Last(nullptr), n(0), daSapXepDiem(false) {}
Sinhvien_dll::~Sinhvien_dll() {
    XoaTatCa();
}

PTR_DLL Sinhvien_dll::getNodeAt(int index) const {
    if (index < 0 || index >= n) return nullptr;
    PTR_DLL p = First;
    for (int i = 0; i < index; ++i) p = p->next;
    return p;
}

int Sinhvien_dll::LayKichThuoc() const {
    return n;
}

void Sinhvien_dll::XoaTatCa() {
    PTR_DLL p = First;
    while (p) {
        PTR_DLL tmp = p;
        p = p->next;
        delete tmp;
    }
    First = Last = nullptr;
    n = 0;
}

void Sinhvien_dll::ThayTheTatCa(const Sinhvien* mangSV, int soLuong) {
    XoaTatCa();
    for (int i = 0; i < soLuong; ++i) {
        QString msg;
        ThemSinhVien(mangSV[i], msg);
    }
    daSapXepDiem = false;
}

Sinhvien Sinhvien_dll::LayTheoViTri(int viTri) const {
    PTR_DLL p = getNodeAt(viTri);
    if (!p) return Sinhvien();
    Sinhvien sv;
    sv.msv = p->msv; sv.ho = p->ho; sv.ten = p->ten;
    sv.lop = p->lop; sv.diem = p->diem;
    return sv;
}

void Sinhvien_dll::DatTheoViTri(int viTri, const Sinhvien& sv) {
    PTR_DLL p = getNodeAt(viTri);
    if (p) {
        p->msv = sv.msv; p->ho = sv.ho;
        p->ten = sv.ten; p->lop = sv.lop;
        p->diem = sv.diem;
    }
}

bool Sinhvien_dll::KiemTraTrungMaSV(const QString& msv) const {
    for (PTR_DLL p = First; p; p = p->next)
        if (p->msv == msv) return true;
    return false;
}

bool Sinhvien_dll::ThemSinhVien(const Sinhvien& sv, QString& thongBaoLoi) {
    static const QRegularExpression reTen("^[a-zA-ZÀ-ỹĂăÂâÊêÔôƠơƯư\\s]+$");
    static const QRegularExpression reLop("^[A-Za-z0-9\\-]+$");
    thongBaoLoi.clear();
    bool hasError = false;
    if (sv.msv.trimmed().isEmpty() || sv.ho.trimmed().isEmpty() ||
        sv.ten.trimmed().isEmpty() || sv.lop.trimmed().isEmpty()) {
        thongBaoLoi += "• Không được để trống bất kỳ trường nào!\n";
        hasError = true;
    }
    if (!sv.ho.trimmed().isEmpty() && !reTen.match(sv.ho.trimmed()).hasMatch()) {
        thongBaoLoi += "• Họ không được chứa ký tự đặc biệt hoặc số!\n";
        hasError = true;
    }
    if (!sv.ten.trimmed().isEmpty() && !reTen.match(sv.ten.trimmed()).hasMatch()) {
        thongBaoLoi += "• Tên không được chứa ký tự đặc biệt hoặc số!\n";
        hasError = true;
    }
    if (std::isnan(sv.diem) || sv.diem < 0.0 || sv.diem > 10.0) {
        thongBaoLoi += "• Điểm phải là số từ 0 đến 10!\n";
        hasError = true;
    }
    if (!sv.msv.trimmed().isEmpty() && KiemTraTrungMaSV(sv.msv)) {
        thongBaoLoi += "• Trùng mã sinh viên!\n";
        hasError = true;
    }
    if (sv.msv.trimmed().contains(' ') || sv.lop.trimmed().contains(' ')) {
        thongBaoLoi += "• Mã sinh viên và lớp không được chứa khoảng trắng!\n";
        hasError = true;
    }
    if (!sv.msv.trimmed().isEmpty() && !isValidStudentID(sv.msv)) {
        thongBaoLoi += "• Mã sinh viên sai định dạng!\n";
        hasError = true;
    }
    if (!sv.lop.trimmed().isEmpty() && !reLop.match(sv.lop.trimmed()).hasMatch()) {
        thongBaoLoi += "• Lớp không được chứa khoảng trắng hoặc ký tự đặc biệt!\n";
        hasError = true;
    }
    if (hasError) {
        thongBaoLoi = thongBaoLoi.trimmed(); 
        return false;
    }

    PTR_DLL node = new node_dll(sv);
    node->prev = Last;
    node->next = nullptr;
    if (Last) Last->next = node;
    else First = node;
    Last = node;
    n++;
    daSapXepDiem = false; 
    return true;
}

bool Sinhvien_dll::XoaSinhVien(const QString& msv, QString& thongBaoLoi) {
    PTR_DLL p = First;
    while (p) {
        if (p->msv == msv) {
            if (p->prev) p->prev->next = p->next;
            else First = p->next;
            if (p->next) p->next->prev = p->prev;
            else Last = p->prev;
            delete p;
            n--;
            daSapXepDiem = false;
            return true;
        }
        p = p->next;
    }
    thongBaoLoi = "Không tìm thấy mã sinh viên!";
    return false;
}

bool Sinhvien_dll::CapNhatSinhVien(const Sinhvien& sv, QString& thongBaoLoi) {
    static const QRegularExpression reTen("^[a-zA-ZÀ-ỹĂăÂâÊêÔôƠơƯư\\s]+$");
    static const QRegularExpression reLop("^[A-Za-z0-9\\-]+$");
    thongBaoLoi.clear();
    bool hasError = false;
    if (sv.msv.trimmed().isEmpty() || sv.ho.trimmed().isEmpty() || sv.ten.trimmed().isEmpty() || sv.lop.trimmed().isEmpty()) {
        thongBaoLoi += "• Không được để trống mã SV, họ, tên, lớp!\n";
        hasError = true;
    }
    if (sv.msv.trimmed().contains(' ')) {
        thongBaoLoi += "• Mã sinh viên không được chứa khoảng trắng!\n";
        hasError = true;
    }
    if (!sv.msv.trimmed().isEmpty() && !isValidStudentID(sv.msv)) {
        thongBaoLoi += "• Mã sinh viên sai định dạng!\n";
        hasError = true;
    }
    if (!sv.ho.trimmed().isEmpty() && !reTen.match(sv.ho.trimmed()).hasMatch()) {
        thongBaoLoi += "• Họ không được chứa ký tự đặc biệt hoặc số!\n";
        hasError = true;
    }
    if (!sv.ten.trimmed().isEmpty() && !reTen.match(sv.ten.trimmed()).hasMatch()) {
        thongBaoLoi += "• Tên không được chứa ký tự đặc biệt hoặc số!\n";
        hasError = true;
    }
    if (std::isnan(sv.diem) || sv.diem < 0.0 || sv.diem > 10.0) {
        thongBaoLoi += "• Điểm phải là số từ 0 đến 10!\n";
        hasError = true;
    }
    if (!sv.lop.trimmed().isEmpty() && !reLop.match(sv.lop.trimmed()).hasMatch()) {
        thongBaoLoi += "• Lớp không được chứa khoảng trắng hoặc ký tự đặc biệt!\n";
        hasError = true;
    }
    if (hasError) {
        thongBaoLoi = thongBaoLoi.trimmed();
        return false;
    }
    PTR_DLL p = First;
    while (p) {
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

bool Sinhvien_dll::isValidStudentID(const QString& studentID) const {
    QRegularExpression pattern("^[A-Z]\\d{2}[A-Z\\d]{4}\\d{3}$");
    if (studentID.length() != 10) {
        return false;
    }
    QRegularExpressionMatch match = pattern.match(studentID);
    return match.hasMatch();
}

QStringList Sinhvien_dll::ImportFromCSV(const QString& filePath) {
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
QVector<QPair<QString, double>> Sinhvien_dll::TinhDiemTrungBinhCacLop() const {
    QMap<QString, double> tong;
    QMap<QString, int> dem;
    QVector<QPair<QString, double>> kq;
    for (PTR_DLL p = First; p; p = p->next) {
        tong[p->lop] += p->diem;
        dem[p->lop]++;
    }
    for (auto it = tong.begin(); it != tong.end(); ++it) {
        double tb = it.value() / dem[it.key()];
        kq.append(qMakePair(it.key(), tb));
    }
    return kq;
}

void Sinhvien_dll::LayDiemThapNhat(Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    if (!First) return;
    if (daSapXepDiem) {
        double minDiem = First->diem;
        PTR_DLL p = First;
        while (p && qFuzzyCompare(p->diem + 1.0, minDiem + 1.0)) {
            ketQua[soLuong++] = {p->msv, p->ho, p->ten, p->lop, p->diem};
            p = p->next;
        }
    } else {
        double minDiem = First->diem;
        for (PTR_DLL p = First->next; p; p = p->next)
            if (p->diem < minDiem) minDiem = p->diem;
        for (PTR_DLL p = First; p; p = p->next)
            if (qFuzzyCompare(p->diem + 1.0, minDiem + 1.0))
                ketQua[soLuong++] = {p->msv, p->ho, p->ten, p->lop, p->diem};
    }
}

void Sinhvien_dll::LayDiemCaoNhat(Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    if (!Last) return;
    if (daSapXepDiem) {
        double maxDiem = Last->diem;
        QVector<Sinhvien> temp;
        PTR_DLL p = Last;
        while (p && qFuzzyCompare(p->diem + 1.0, maxDiem + 1.0)) {
            temp.append({p->msv, p->ho, p->ten, p->lop, p->diem});
            p = p->prev;
        }
        std::reverse(temp.begin(), temp.end());
        for (const Sinhvien& sv : temp) {
            ketQua[soLuong++] = sv;
        }
    } else {
        double maxDiem = First->diem;
        for (PTR_DLL p = First->next; p; p = p->next)
            if (p->diem > maxDiem) maxDiem = p->diem;
        for (PTR_DLL p = First; p; p = p->next)
            if (qFuzzyCompare(p->diem + 1.0, maxDiem + 1.0))
                ketQua[soLuong++] = {p->msv, p->ho, p->ten, p->lop, p->diem};
    }
}

QString Sinhvien_dll::DaoNguocHoTen(int viTri) const {
    Sinhvien sv = LayTheoViTri(viTri);
    QString full = sv.ho + " " + sv.ten;
    QString reversed;
    reversed.reserve(full.size());
    for (auto it = full.rbegin(); it != full.rend(); ++it) {
        reversed.append(*it);
    }
    return reversed;
}

void Sinhvien_dll::LayDanhSachTheoDieuKien(bool (*dieuKien)(const Sinhvien&, const QString&), const QString& tuKhoa, Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    if (!First || n == 0) return;
    PTR_DLL p = First;
    while (p) {
        Sinhvien sv = {p->msv, p->ho, p->ten, p->lop, p->diem};
        if (dieuKien(sv, tuKhoa)) {
            ketQua[soLuong++] = sv;
        }
        p = p->next;
    }
}

static bool soSanhTieuChi(const node_dll& a, const node_dll& b, int tieuChi, bool tangDan) {
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

static void swapSinhvienNode(PTR_DLL a, PTR_DLL b) {
    if (!a || !b || a == b) return;
    std::swap(a->msv, b->msv);
    std::swap(a->ho, b->ho);
    std::swap(a->ten, b->ten);
    std::swap(a->lop, b->lop);
    std::swap(a->diem, b->diem);
}

static void bubbleSortDLL(PTR_DLL First, int n, int tieuChi, bool tangDan) {
    if (!First || n <= 1) return;
    bool swapped;
    do {
        swapped = false;
        PTR_DLL p = First;
        while (p && p->next) {
            if (!soSanhTieuChi(*p, *(p->next), tieuChi, tangDan)) { 
                swapSinhvienNode(p, p->next);
                swapped = true;
            }
            p = p->next;
        }
    } while (swapped);
}

static void insertionSortDLL(PTR_DLL& First, int n, int tieuChi, bool tangDan) {
    if (!First || !First->next) return;
    PTR_DLL sorted = nullptr;
    PTR_DLL curr = First;
    while (curr) {
        PTR_DLL next = curr->next;
        curr->prev = curr->next = nullptr;
        if (!sorted) {
            sorted = curr;
        } else if (soSanhTieuChi(*curr, *sorted, tieuChi, tangDan)) {
            curr->next = sorted;
            sorted->prev = curr;
            sorted = curr;
        } else {
            PTR_DLL p = sorted;
            while (p->next && !soSanhTieuChi(*curr, *(p->next), tieuChi, tangDan)) {
                p = p->next;
            }
            curr->next = p->next;
            if (p->next) p->next->prev = curr;
            p->next = curr;
            curr->prev = p;
        }
        curr = next;
    }
    First = sorted;
}
static void selectionSortDLL(PTR_DLL First, int n, int tieuChi, bool tangDan) {
    for (PTR_DLL p = First; p; p = p->next) {
        PTR_DLL minmax = p;
        for (PTR_DLL q = p->next; q; q = q->next) {
            if (!soSanhTieuChi(*minmax, *q, tieuChi, tangDan)) {
                minmax = q;
            }
        }
        if (minmax != p) {
            swapSinhvienNode(p, minmax);
        }
    }
}
static PTR_DLL mergeDLL(PTR_DLL first, PTR_DLL second, int tieuChi, bool tangDan) {
    if (!first) return second;
    if (!second) return first;
    if (soSanhTieuChi(*first, *second, tieuChi, tangDan)) {
        first->next = mergeDLL(first->next, second, tieuChi, tangDan);
        if (first->next) first->next->prev = first;
        first->prev = nullptr;
        return first;
    } else {
        second->next = mergeDLL(first, second->next, tieuChi, tangDan);
        if (second->next) second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

static void splitDLL(PTR_DLL head, PTR_DLL& first, PTR_DLL& second) {
    PTR_DLL slow = head, fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    first = head;
    second = slow->next;
    slow->next = nullptr;
    if (second) second->prev = nullptr;
}

static void mergeSortDLL(PTR_DLL& head, int tieuChi, bool tangDan) {
    if (!head || !head->next) return;
    PTR_DLL first, second;
    splitDLL(head, first, second);
    mergeSortDLL(first, tieuChi, tangDan);
    mergeSortDLL(second, tieuChi, tangDan);
    head = mergeDLL(first, second, tieuChi, tangDan);
}
static PTR_DLL getNodeAt(PTR_DLL head, int idx) {
    PTR_DLL p = head;
    while (idx-- && p) p = p->next;
    return p;
}

static void heapifyDLL(PTR_DLL head, int n, int i, int tieuChi, bool tangDan) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    PTR_DLL nodeLargest = getNodeAt(head, largest);
    PTR_DLL nodeLeft = getNodeAt(head, left);
    PTR_DLL nodeRight = getNodeAt(head, right);

    if (left < n && soSanhTieuChi(*nodeLargest, *nodeLeft, tieuChi, tangDan))
        largest = left, nodeLargest = nodeLeft;
    if (right < n && soSanhTieuChi(*nodeLargest, *nodeRight, tieuChi, tangDan))
        largest = right, nodeLargest = nodeRight;
    if (largest != i) {
        PTR_DLL nodeI = getNodeAt(head, i);
        swapSinhvienNode(nodeI, nodeLargest);
        heapifyDLL(head, n, largest, tieuChi, tangDan);
    }
}

static void heapSortDLL(PTR_DLL head, int n, int tieuChi, bool tangDan) {
    for (int i = n / 2 - 1; i >= 0; --i)
        heapifyDLL(head, n, i, tieuChi, tangDan);
    for (int i = n - 1; i > 0; --i) {
        PTR_DLL node0 = getNodeAt(head, 0);
        PTR_DLL nodeI = getNodeAt(head, i);
        swapSinhvienNode(node0, nodeI);
        heapifyDLL(head, i, 0, tieuChi, tangDan);
    }
}
static PTR_DLL partitionDLL(PTR_DLL low, PTR_DLL high, int tieuChi, bool tangDan) {
    QString pivotMSV = high->msv;
    QString pivotHo = high->ho;
    QString pivotTen = high->ten;
    QString pivotLop = high->lop;
    double pivotDiem = high->diem;
    PTR_DLL i = low->prev;
    for (PTR_DLL j = low; j != high; j = j->next) {
        Sinhvien svJ{j->msv, j->ho, j->ten, j->lop, j->diem};
        Sinhvien svPivot{pivotMSV, pivotHo, pivotTen, pivotLop, pivotDiem};
        if (soSanhTieuChi(svJ, svPivot, tieuChi, tangDan)) {
            i = (i == nullptr) ? low : i->next;
            swapSinhvienNode(i, j);
        }
    }
    i = (i == nullptr) ? low : i->next;
    swapSinhvienNode(i, high);
    return i;
}

static void quickSortDLL(PTR_DLL low, PTR_DLL high, int tieuChi, bool tangDan) {
    if (high && low != high && low != high->next) {
        PTR_DLL p = partitionDLL(low, high, tieuChi, tangDan);
        quickSortDLL(low, p->prev, tieuChi, tangDan);
        quickSortDLL(p->next, high, tieuChi, tangDan);
    }
}

double Sinhvien_dll::SapXep(int loai, int tieuChi, bool tangDan) {
    if (n <= 1) return 0;
    auto start = std::chrono::high_resolution_clock::now();
    switch (loai) {
        case 0: bubbleSortDLL(First, n, tieuChi, tangDan); break;
        case 1: insertionSortDLL(First, n, tieuChi, tangDan); break;
        case 2: selectionSortDLL(First, n, tieuChi, tangDan); break;
        case 3: mergeSortDLL(First, tieuChi, tangDan); break;
        case 4: quickSortDLL(First, Last, tieuChi, tangDan); break;
        case 5: heapSortDLL(First, n, tieuChi, tangDan); break;
        default: break;
    }
    PTR_DLL p = First;
    while (p && p->next) p = p->next;
    Last = p;
    daSapXepDiem = (tieuChi == 2);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    return elapsed.count();
}

static void timKiemTuyenTinhDLL(PTR_DLL First, int n, const QString& tuKhoa, int tieuChi, int* chiSo, int& soLuong) {
    soLuong = 0;
    QString key = tuKhoa.trimmed().toLower();
    bool isDouble = false;
    double doubleKey = tuKhoa.toDouble(&isDouble);
    int idx = 0;
    for (PTR_DLL p = First; p; p = p->next, ++idx) {
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

static PTR_DLL getNodeAtDLL(PTR_DLL First, int idx) {
    PTR_DLL p = First;
    while (idx-- && p) p = p->next;
    return p;
}

static void timKiemNhiPhanDLL(PTR_DLL First, int n, const QString& tuKhoa, int tieuChi, int* chiSo, int& soLuong) {
    soLuong = 0;
    QString key = tuKhoa.trimmed().toLower();
    bool isDouble = false;
    double doubleKey = tuKhoa.toDouble(&isDouble);
    QCollator collator(QLocale(QLocale::Vietnamese, QLocale::Vietnam));
    if (tieuChi == 4 && isDouble) {
        int l = 0, r = n - 1, found = -1;
        while (l <= r) {
            int m = (l + r) / 2;
            PTR_DLL node = getNodeAtDLL(First, m);
            if (qFuzzyCompare(node->diem + 1, doubleKey + 1)) {
                found = m;
                break;
            } else if (node->diem < doubleKey) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        if (found != -1) {
            int left = found, right = found;
            while (left > 0 && qFuzzyCompare(getNodeAtDLL(First, left - 1)->diem + 1, doubleKey + 1)) --left;
            while (right < n - 1 && qFuzzyCompare(getNodeAtDLL(First, right + 1)->diem + 1, doubleKey + 1)) ++right;
            for (int i = left; i <= right; ++i) chiSo[soLuong++] = i;
        }
    } else {
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            PTR_DLL node = getNodeAtDLL(First, m);
            QString val;
            switch (tieuChi) {
                case 0: val = node->msv.toLower(); break;
                case 1: val = node->ho.toLower(); break;
                case 2: val = node->ten.toLower(); break;
                case 3: val = node->lop.toLower(); break;
                case 4: val = QString::number(node->diem); break;
            }
            int cmp = 0;
            if (tieuChi == 1 || tieuChi == 2) {
                cmp = collator.compare(val, key);
            } else {
                cmp = QString::compare(val, key, Qt::CaseInsensitive);
            }
            if (cmp == 0) {
                int left = m, right = m;
                while (left > 0) {
                    PTR_DLL nleft = getNodeAtDLL(First, left - 1);
                    QString v;
                    switch (tieuChi) {
                        case 0: v = nleft->msv.toLower(); break;
                        case 1: v = nleft->ho.toLower(); break;
                        case 2: v = nleft->ten.toLower(); break;
                        case 3: v = nleft->lop.toLower(); break;
                        case 4: v = QString::number(nleft->diem); break;
                    }
                    int cmp2 = (tieuChi == 1 || tieuChi == 2) ? collator.compare(v, key) : QString::compare(v, key, Qt::CaseInsensitive);
                    if (cmp2 == 0) --left; else break;
                }
                while (right < n - 1) {
                    PTR_DLL nright = getNodeAtDLL(First, right + 1);
                    QString v;
                    switch (tieuChi) {
                        case 0: v = nright->msv.toLower(); break;
                        case 1: v = nright->ho.toLower(); break;
                        case 2: v = nright->ten.toLower(); break;
                        case 3: v = nright->lop.toLower(); break;
                        case 4: v = QString::number(nright->diem); break;
                    }
                    int cmp2 = (tieuChi == 1 || tieuChi == 2) ? collator.compare(v, key) : QString::compare(v, key, Qt::CaseInsensitive);
                    if (cmp2 == 0) ++right; else break;
                }
                for (int i = left; i <= right; ++i)
                    chiSo[soLuong++] = i;
                return;
            }
            if (cmp < 0) l = m + 1;
            else r = m - 1;
        }
    }
}

double Sinhvien_dll::TimKiem(const QString& tuKhoa, int tieuChi, bool kiemTra, Sinhvien* ketQua, int& soLuong) const {
    soLuong = 0;
    if (n == 0 || First == nullptr) return 0;
    int* chiSo = new int[n];
    auto start = std::chrono::high_resolution_clock::now();
    if (kiemTra) {
        timKiemTuyenTinhDLL(First, n, tuKhoa, tieuChi, chiSo, soLuong);
    } else {
        timKiemNhiPhanDLL(First, n, tuKhoa, tieuChi, chiSo, soLuong);
    }
    PTR_DLL p = First;
    for (int i = 0; i < soLuong; ++i) {
        PTR_DLL node = getNodeAtDLL(First, chiSo[i]);
        ketQua[i].msv = node->msv;
        ketQua[i].ho = node->ho;
        ketQua[i].ten = node->ten;
        ketQua[i].lop = node->lop;
        ketQua[i].diem = node->diem;
    }
    delete[] chiSo;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> timer = end - start;
    return timer.count();
}
