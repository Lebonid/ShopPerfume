#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent):
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}
Dialog::~Dialog(){
    delete ui;
}

QString Dialog::search(){
    return ui->lineEdit->text();
}

QString Dialog::search_2(){
    return ui->lineEdit_2->text();
}
