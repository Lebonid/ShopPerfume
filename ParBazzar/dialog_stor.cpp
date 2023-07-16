#include "dialog_stor.h"
#include "ui_dialog_stor.h"

dialog_stor::dialog_stor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::dialog_stor)
{
    ui->setupUi(this);
}

dialog_stor::~dialog_stor()
{
    delete ui;
}

QString dialog_stor::search(){
    return ui->lineEdit->text();
}
