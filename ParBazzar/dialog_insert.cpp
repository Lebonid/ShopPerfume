#include "dialog_insert.h"
#include "ui_dialog_insert.h"

Dialog_Insert::Dialog_Insert(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_Insert)
{
    ui->setupUi(this);
}

Dialog_Insert::~Dialog_Insert()
{
    delete ui;
}

QString Dialog_Insert::insert1(){
    return ui->dateEdit->text();
}

QString Dialog_Insert::insert2(){
    return ui->spinBox->text();
}

QString Dialog_Insert::insert3(){
    return ui->lineEdit->text();
}

QString Dialog_Insert::insert4(){
    return ui->lineEdit_2->text();
}

QString Dialog_Insert::insert5(){
    return ui->lineEdit_3->text();
}

QString Dialog_Insert::insert6(){
    return ui->lineEdit_4->text();
}
