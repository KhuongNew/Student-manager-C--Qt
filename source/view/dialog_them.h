#ifndef DIALOG_THEM_H
#define DIALOG_THEM_H

#include <QDialog>
#include "Danhsachsinhvien.h"

namespace Ui {
class Dialog_them;
}

class Dialog_them : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_them(QWidget *parent = nullptr);
    ~Dialog_them();
    Sinhvien getSinhvien() const;

private slots:
    void on_pushButton_them_dia_clicked();

    void on_pushButton_huy_dia_clicked();

private:
    Ui::Dialog_them *ui;
};

#endif // DIALOG_THEM_H
