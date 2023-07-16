#include "dcreate_user.h"
#include "ui_dcreate_user.h"

dCreate_user::dCreate_user(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dCreate_user)
{
    ui->setupUi(this);
}

dCreate_user::~dCreate_user()
{
    delete ui;
}

QString dCreate_user::dlogin(){
    return ui->lineEdit->text();
}

QString dCreate_user::dpass(){
    return ui->lineEdit_2->text();
}

QString dCreate_user::dname(){
    return ui->lineEdit_3->text();
}
//select
bool dCreate_user::sel1(){
    return ui->cB_select->isChecked();
}bool dCreate_user::sel2(){
    return ui->cB_select_2->isChecked();
}bool dCreate_user::sel3(){
    return ui->cB_select_3->isChecked();
}bool dCreate_user::sel4(){
    return ui->cB_select_4->isChecked();
}

//insert
bool dCreate_user::inst1(){
    return ui->cB_insert->isChecked();
}bool dCreate_user::inst2(){
    return ui->cB_insert_2->isChecked();
}bool dCreate_user::inst3(){
    return ui->cB_insert_3->isChecked();
}bool dCreate_user::inst4(){
    return ui->cB_insert_4->isChecked();
}

//delete
bool dCreate_user::del1(){
    return  ui->cB_delete->isChecked();
}bool dCreate_user::del2(){
    return  ui->cB_delete_2->isChecked();
}bool dCreate_user::del3(){
    return  ui->cB_delete_3->isChecked();
}bool dCreate_user::del4(){
    return  ui->cB_delete_4->isChecked();
}

// update
bool dCreate_user::upd1(){
    return ui->cB_update->isChecked();
}bool dCreate_user::upd2(){
    return ui->cB_update_2->isChecked();
}bool dCreate_user::upd3(){
    return ui->cB_update_3->isChecked();
}bool dCreate_user::upd4(){
    return ui->cB_update_4->isChecked();
}
