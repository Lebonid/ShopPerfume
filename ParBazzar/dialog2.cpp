#include "dialog2.h"
#include "ui_dialog2.h"

Dialog2::Dialog2(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2(){
    delete ui;
}

QString Dialog2::search(){
    return ui->lineEdit->text();
}

QString Dialog2::search2(){
    return ui->lineEdit_2->text();
}
