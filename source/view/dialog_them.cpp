#include "dialog_them.h"
#include "ui_dialog_them.h"
#include "Sinhvien.h"

Dialog_them::Dialog_them(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog_them)
{
    ui->setupUi(this);
    setWindowTitle("Thêm thông tin Sinh Viên");
}

Dialog_them::~Dialog_them()
{
    delete ui;
}

Sinhvien Dialog_them::getSinhvien() const {
    Sinhvien sv;
    sv.msv = ui->lineEdit_themma->text().trimmed();
    sv.ho = ui->lineEdit_themho->text().trimmed();
    sv.ten = ui->lineEdit_themten->text().trimmed();
    sv.lop = ui->lineEdit_themlop->text().trimmed();
    sv.diem = ui->lineEdit_themdiem->text().toDouble();

    QString diemText = ui->lineEdit_themdiem->text().trimmed();
    bool ok = false;
    double diem = diemText.toDouble(&ok);

    if (!ok || diemText.isEmpty()) {
        sv.diem = std::numeric_limits<double>::quiet_NaN();
    } else {
        sv.diem = diem;
    }

    return sv;
}
void Dialog_them::on_pushButton_them_dia_clicked()
{
    accept();
}


void Dialog_them::on_pushButton_huy_dia_clicked()
{
    reject();
}

