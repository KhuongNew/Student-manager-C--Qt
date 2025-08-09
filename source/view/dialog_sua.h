#ifndef DIALOG_SUA_H
#define DIALOG_SUA_H

#include <QDialog>
#include "Danhsachsinhvien.h"

namespace Ui {
class Dialog_sua;
}

class Dialog_sua : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_sua(QWidget *parent = nullptr);
    ~Dialog_sua();
    void setSinhvien(const Sinhvien& sv);
    Sinhvien getSinhvien();

private slots:
    void on_pushButton_sua_dia_clicked();

    void on_pushButton_huy_dia_fix_clicked();

private:
    Ui::Dialog_sua *ui;
};

#endif // DIALOG_SUA_H
