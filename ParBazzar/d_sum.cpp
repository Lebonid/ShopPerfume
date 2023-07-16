#include "d_sum.h"
#include "ui_d_sum.h"

d_sum::d_sum(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::d_sum)
{
    ui->setupUi(this);
}

d_sum::~d_sum()
{
    delete ui;
}

QString d_sum::line(){
    return ui->lineEdit->text();
}
