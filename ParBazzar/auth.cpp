#include "auth.h"
#include "ui_auth.h"

auth::auth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::auth)
{
    ui->setupUi(this);
}

auth::~auth()
{
    delete ui;
}

QString auth::login(){
    return ui->lineEdit->text();
}

QString auth::pass(){
    return ui->lineEdit_2->text();
}
