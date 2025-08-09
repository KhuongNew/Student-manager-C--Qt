#include "dialog_sua.h"
#include "source/view/ui_dialog_sua.h"

Dialog_sua::Dialog_sua(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_sua)
{
    ui->setupUi(this);
    setWindowTitle("Sửa thông tin Sinh Vien");
}

Dialog_sua::~Dialog_sua()
{
    delete ui;
}

void Dialog_sua::setSinhvien(const Sinhvien& sv) {
    ui->lineEdit_suama->setText(sv.msv);
    ui->lineEdit_suaho->setText(sv.ho);
    ui->lineEdit_suaten->setText(sv.ten);
    ui->lineEdit_sualop->setText(sv.lop);
    ui->lineEdit_suadiem->setText(QString::number(sv.diem));
}

Sinhvien Dialog_sua::getSinhvien()  {
    Sinhvien sv;
    sv.msv = ui->lineEdit_suama->text().trimmed();
    sv.ho = ui->lineEdit_suaho->text().trimmed();
    sv.ten = ui->lineEdit_suaten->text().trimmed();
    sv.lop = ui->lineEdit_sualop->text().trimmed();
    sv.diem = ui->lineEdit_suadiem->text().toDouble();
    QString diemText = ui->lineEdit_suadiem->text().trimmed();
    bool ok = false;
    double diem = diemText.toDouble(&ok);
    if (!ok || diemText.isEmpty()) {
        sv.diem = std::numeric_limits<double>::quiet_NaN();
    } else {
        sv.diem = diem;
    }
    return sv;
}

void Dialog_sua::on_pushButton_sua_dia_clicked()
{
    accept();
}


void Dialog_sua::on_pushButton_huy_dia_fix_clicked()
{
    reject();
}

