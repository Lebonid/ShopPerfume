#include "d_account.h"
#include "ui_d_account.h"

d_account::d_account(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::d_account)
{
    ui->setupUi(this);
}

d_account::~d_account()
{
    delete ui;
}

QString d_account::upd1(){
    return ui->lineEdit->text();
}

QString d_account::upd2(){
    return ui->dateEdit->text();
}

QTableView *d_account::tb(){
    return ui->tableView;
}
