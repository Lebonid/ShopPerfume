#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSqlDatabase>
#include <QSqlTableModel>
#include <QDataWidgetMapper>
#include <QDate>
#include <qpushbutton.h>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QMessageBox>
#include <QSqlQuery>
#include <QFile>
#include <QSqlRelationalDelegate>
#include <QSqlError>
#include <QApplication>
#include <QTextDocument>
#include <QTextCodec>
#include <QSqlQueryModel>
#include <QDebug>
#include <dcreate_user.h>
#include "dialog.h"
#include "dialog2.h"
#include "dialog_insert.h"
#include "auth.h"
#include "d_account.h"
#include "d_sum.h"

MainWindow::MainWindow(QApplication *a, QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTextCodec *codec = QTextCodec::codecForName("CP1251");
    codec = QTextCodec::codecForName("CP1251");
    QTextCodec::setCodecForLocale(codec);
    ui->tw->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tw->setWindowTitle("Информация о системе");
    auth dialogAuth;
    if(dialogAuth.exec()){
        QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName("127.0.0.1");
        db.setPort(3306);
        db.setDatabaseName("bazzar");
        db.setUserName(dialogAuth.login());
        auc.append(dialogAuth.login());
        db.setPassword(dialogAuth.pass());
        if(!db.open()){
            QMessageBox::critical(parent, QObject::tr("Database Error"),db.lastError().text());
        }
        QSqlTableModel *model = new QSqlTableModel;
        model->setTable("deals");
        if(model->lastError().isValid()){
            QMessageBox::critical(parent, QObject::tr("Query Error"), model->lastError().text());
        }else{
        model->setHeaderData(0,Qt::Horizontal, QObject::tr("Номер Заказа"));
        model->setHeaderData(1,Qt::Horizontal, QObject::tr("Дата Заказа"));
        model->setHeaderData(2,Qt::Horizontal, QObject::tr("Количество"));
        model->setHeaderData(3,Qt::Horizontal, QObject::tr("Кому"));
        model->setHeaderData(4,Qt::Horizontal, QObject::tr("Вид"));
        model->setHeaderData(5,Qt::Horizontal, QObject::tr("Брокер"));
        model->setHeaderData(6,Qt::Horizontal, QObject::tr("Код Товара"));

        model->select();
        ui->tw->setModel(model);
        this->model=model;
        ui->tw->show();
        model->submitAll();
        }
    }else{
        QMessageBox::critical(parent, QObject::tr("Ошибка") , "Неверный логин или пароль");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Exit_triggered()
{
    QMessageBox::information(0,"Info","exit pressed.");
}

void MainWindow::on_action_triggered()
{
    QSqlTableModel *model = new QSqlTableModel;

    model->setTable("deals");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Номер Заказа"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Дата Заказа"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Количество"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Кому"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Вид"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Брокер"));
    model->setHeaderData(6,Qt::Horizontal, QObject::tr("Код Товара"));

    model->select();
    ui->tw->setModel(model);
    delete this->model;
    this->model=model;
    ui->tw->show();

}

void MainWindow::on_action_2_triggered(){

    QSqlTableModel *model = new QSqlTableModel;

    model->setTable("supplier");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Номер поставки"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Цена"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Дата"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Количество"));
    model->setHeaderData(4,Qt::Horizontal, QObject::tr("Номер проставщика"));
    model->setHeaderData(5,Qt::Horizontal, QObject::tr("Код продукта"));

    model->select();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    ui->tw->setModel(model);
    delete this->model;
    this->model = model;
    ui->tw->show();
}

void MainWindow::on_action_3_triggered(){
    QSqlTableModel *model = new QSqlTableModel;

    model->setTable("provider");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Номер поставщика"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Поставщик"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Дата регистраций"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Описание"));

    model->select();
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    ui->tw->setModel(model);
    delete this->model;
    this->model = model;
    ui->tw->show();
}

void MainWindow::on_action_16_triggered(){

    QSqlTableModel *model = new QSqlTableModel;

    model->setTable("product");
    model->setHeaderData(0,Qt::Horizontal, QObject::tr("Номер продукта"));
    model->setHeaderData(1,Qt::Horizontal, QObject::tr("Название продукта"));
    model->setHeaderData(2,Qt::Horizontal, QObject::tr("Срок годности"));
    model->setHeaderData(3,Qt::Horizontal, QObject::tr("Описание"));

    model->select();
    ui->tw->setModel(model);
    model->setEditStrategy(QSqlTableModel::OnFieldChange);
    delete this->model;
    this->model = model;
    ui->tw->show();
}

void MainWindow::on_action_8_triggered(){
    QSqlError sqlError;
    Dialog_Insert dialog;
    if(dialog.exec()){
        QString d = dialog.insert1();
        QString p1 = dialog.insert2();
        QString p2 = dialog.insert3();
        QString p3 = dialog.insert4();
        QString p4 = dialog.insert5();
        QString p5 = dialog.insert6();
        QSqlQuery query;
        query.prepare("insert into deals(date_deal, Col_sold, whsale, View_prod, broker_name_brok, product_id_prod) values(:date_deal, :Col_sum, :whsale, :View_prod, :broker_name_brok, :product_id_prod)");
        query.bindValue(0,d);
        query.bindValue(1,p1);
        query.bindValue(2,p2);
        query.bindValue(3,p3);
        query.bindValue(4,p4);
        query.bindValue(5,p5);
        query.exec();

        sqlError=query.lastError();
        if(sqlError.type()!=QSqlError::NoError){
            QMessageBox::critical(this,"SQL ERROR", sqlError.text());
        }
    }
}
void MainWindow::on_action_9_triggered(){

}
void MainWindow::on_action_10_triggered(){
    Dialog dialog;
    if(dialog.exec()){
        QString p = dialog.search();
        QString d = dialog.search_2();
        QSqlError sqlError;
        QSqlQueryModel *model = new QSqlQueryModel;
        if(d==""){
            model->setQuery("SELECT *FROM deals WHERE broker_name_brok=\'"+p+"\' ");
            model->setHeaderData(0,Qt::Horizontal, QObject::tr("Номер Заказа"));
            model->setHeaderData(1,Qt::Horizontal, QObject::tr("Дата Заказа"));
            model->setHeaderData(2,Qt::Horizontal, QObject::tr("Количество"));
            model->setHeaderData(3,Qt::Horizontal, QObject::tr("Кому"));
            model->setHeaderData(4,Qt::Horizontal, QObject::tr("Вид"));
            model->setHeaderData(5,Qt::Horizontal, QObject::tr("Брокер"));
            model->setHeaderData(6,Qt::Horizontal, QObject::tr("Номер Товара"));
        }
        sqlError=model->lastError();
        if(sqlError.type()!=QSqlError::NoError){
            QMessageBox::critical(this,"SQL ERROR", sqlError.text());
        }
        ui->tw->setModel(model);
        delete this->model;
        this->model = model;
    }
}
void MainWindow::on_action_11_triggered(){
    d_sum dialog;
    QString d;
    QSqlError sqlError;
    QSqlQueryModel *model = new QSqlQueryModel;
    if(dialog.exec()){
        d.append(dialog.line());
        model->setQuery("SELECT name_prod ,SUM((col_supp - Col_sold)) FROM deals a,supplier b,product c WHERE c.name_prod = \'"+d+"\' AND a.product_id_prod = c.id_prod AND b.product_id_prod = c.id_prod;");
        model->setHeaderData(0,Qt::Horizontal, QObject::tr("Название товара"));
        model->setHeaderData(1,Qt::Horizontal, QObject::tr("Количество товара на складе"));
        if(sqlError.type()!=QSqlError::NoError){
            QMessageBox::critical(this,"SQL ERROR", sqlError.text());
        }
        ui->tw->setModel(model);
        delete this->model;
        this->model = model;
    }
}
void MainWindow::on_action_12_triggered(){
    Dialog2 dialog;
    if(dialog.exec()){
        QString p = dialog.search();
        QString d = dialog.search2();
        QSqlError sqlError;

        QSqlQueryModel *model = new QSqlQueryModel;
        if(d==""){
            model->setQuery("SELECT id_supp, price_sold, date_supp, col_supp,  Provider_id_Provid, name_prod FROM product a, supplier b WHERE a.name_prod=\'"+p+"\' AND a.id_prod = b.product_id_prod;");
            model->setHeaderData(0,Qt::Horizontal, QObject::tr("Номер Поставки"));
            model->setHeaderData(1,Qt::Horizontal, QObject::tr("Цена"));
            model->setHeaderData(2,Qt::Horizontal, QObject::tr("Дата поставки"));
            model->setHeaderData(3,Qt::Horizontal, QObject::tr("Количество"));
            model->setHeaderData(4,Qt::Horizontal, QObject::tr("Номер поставщика"));
            model->setHeaderData(5,Qt::Horizontal, QObject::tr("Название продукта"));
        }else if(p==""){
            model->setQuery("SELECT id_supp, price_sold, date_supp, col_supp, Name_provid, product_id_prod FROM provider a, supplier b WHERE a.Name_provid=\'"+d+"\' AND a.id_Provid = b.Provider_id_Provid;");
            model->setHeaderData(0,Qt::Horizontal, QObject::tr("Номер Поставки"));
            model->setHeaderData(1,Qt::Horizontal, QObject::tr("Цена"));
            model->setHeaderData(2,Qt::Horizontal, QObject::tr("Дата поставки"));
            model->setHeaderData(3,Qt::Horizontal, QObject::tr("Количество"));
            model->setHeaderData(4,Qt::Horizontal, QObject::tr("Название поставщика"));
            model->setHeaderData(5,Qt::Horizontal, QObject::tr("Номер продукта"));
        }
        sqlError=model->lastError();
        if(sqlError.type()!=QSqlError::NoError){
            QMessageBox::critical(this,"SQL ERROR", sqlError.text());
        }
        ui->tw->setModel(model);
        delete this->model;
        this->model = model;
    }
}

void MainWindow::on_action_15_triggered(){
/*
    ui->tw->setModel(model);
    QPrinter printer;
    QTextDocument doc;
    QString html;
    QPrintDialog printDialog(&printer,this);
    if (printDialog.exec()) {
        html+="<table bordercolor='green' border='2' width='100%'cols='10'>";
        html += "<tr>";
            for (int l=0,p=model->columnCount();l<p;++l) {
                html += "<td>" + model->headerData(l,Qt::Horizontal,0).toString() + "</td>";
            }
            html += "</tr>";
        for (int i=0,n=model->rowCount();i<n;++i) {

                html += "<tr>";
                for (int j=0,m=model->columnCount();j<m;++j) {
                    html += "<td>" + model->data(model->index(i,j)).toString() + "</td>";
                }
                html += "</tr>";
            }
            html+="</table>";
            doc.setHtml(html);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setOutputFileName("example.pdf");
            doc.print(&printer);*/
}

void MainWindow::on_action_4_triggered(){

    dCreate_user dialog;
    QSqlError sqlError;
    QSqlQuery query;
    QString d_name;
    d_name.append(dialog.dname());
    QString buffStr = "CREATE USER `";
    QString buff1;
    QString buff2;
    QString buff3;
    QString buff4;
    QString buff5;
    QString userStr;
    QString buffTut ="INSERT INTO broker VALUES('";
    //QSqlQueryModel *model = new QSqlQueryModel;
    if(auc == "root"){
    if(dialog.exec()){
        buffStr.append(dialog.dlogin());
        buffStr.append("`@`%` IDENTIFIED BY '");
        buffStr.append(dialog.dpass());
        buffStr.append("';");
        query.prepare(buffStr);
        userStr.append(dialog.dlogin());
        if(query.exec()){
            buffTut.append(dialog.dname());
            buffTut.append("',0,0,'");
            buffTut.append(dialog.dlogin());
            buffTut.append("');");
            query.prepare(buffTut);
            query.exec();

            //deals table
                   if(dialog.sel1() == true & dialog.inst1() == true & dialog.del1() == true & dialog.upd1() == true){
                      buff1.append("GRANT SELECT, INSERT, DELETE, UPDATE ON `bazzar`.`deals` TO`");
                      buff1.append(userStr);
                      buff1.append("`@`%`;");
                      query.prepare(buff1);
                   }else if(dialog.sel1() == true | dialog.inst1() == true | dialog.upd1() == true){
                      buff1.append("GRANT SELECT, INSERT, UPDATE ON `bazzar`.`deals` TO`");
                      buff1.append(userStr);
                      buff1.append("`@`%`;");
                      query.prepare(buff1);
                   }else if(dialog.del1() == true | dialog.upd1() == true){
                      buff1.append("GRANT SELECT, DELETE, UPDATE ON `bazzar`.`deals` TO`");
                      buff1.append(userStr);
                      buff1.append("`@`%`;");
                      query.prepare(buff1);
                   }else if(dialog.sel1() == true | dialog.inst1() == true){
                      buff1.append("GRANT SELECT, INSERT ON `bazzar`.`deals` TO`");
                      buff1.append(userStr);
                      buff1.append("`@`%`;");
                      query.prepare(buff1);
                   }else{
                       qDebug() << "Non privelege";
                   }
        query.exec();
        //suppplier table
        if(dialog.sel3() == true | dialog.inst3() == true){
            buff2.append("GRANT SELECT, INSERT ON `bazzar`.`supplier` TO`");
            buff2.append(userStr);
            buff2.append("`@`%`;");
            query.prepare(buff2);
        }else if(dialog.del3() == true | dialog.upd3() == true){
            buff2.append("GRANT SELECT, DELETE, UPDATE ON `bazzar`.`supplier` TO`");
            buff2.append(userStr);
            buff2.append("`@`%`;");
            query.prepare(buff2);
        }else if(dialog.sel3() == true | dialog.inst3() == true | dialog.upd3() == true | dialog.del1() == true){
            buff2.append("GRANT SELECT, INSERT, UPDATE, DELETE ON `bazzar`.`supplier` TO`");
            buff2.append(userStr);
            buff2.append("`@`%`;");
            query.prepare(buff2);
        }else if(dialog.sel3() == true | dialog.inst3() == true | dialog.upd3() == true){
            buff2.append("GRANT SELECT, INSERT, UPDATE ON `bazzar`.`supplier` TO`");
            buff2.append(userStr);
            buff2.append("`@`%`;");
            query.prepare(buff2);
        }else{
            qDebug() << "Non privelege";
        }
        query.exec();
        //product table
        if(dialog.sel2() == true || dialog.upd2() == true){
            buff3.append("GRANT SELECT, UPDATE ON `bazzar`.`product` TO`");
            buff3.append(userStr);
            buff3.append("`@`%`;");
            query.prepare(buff3);
        }else if(dialog.sel2() == true || dialog.inst2() == true ){
            buff3.append("GRANT SELECT, INSERT ON `bazzar`.`product` TO`");
            buff3.append(userStr);
            buff3.append("`@`%`;");
            query.prepare(buff3);
        }else if(dialog.sel2() == true || dialog.upd2() == true || dialog.inst2() == true){
            buff3.append("GRANT SELECT, INSERT, UPDATE ON `bazzar`.`product` TO`");
            buff3.append(userStr);
            buff3.append("`@`%`;");
            query.prepare(buff3);
        }else{
            qDebug() << "Non privelege";
        }
        query.exec();
        //provider table
        if(dialog.sel4() == true || dialog.upd4() == true){
            buff4.append("GRANT SELECT, UPDATE ON `bazzar`.`provider` TO`");
            buff4.append(userStr);
            buff4.append("`@`%`;");
            query.prepare(buff4);
        }else if(dialog.sel4() == true || dialog.inst4() == true){
            buff4.append("GRANT SELECT, INSERT ON `bazzar`.`provider` TO`");
            buff4.append(userStr);
            buff4.append("`@`%`;");
            query.prepare(buff4);
        }else if(dialog.sel4() == true || dialog.upd4() == true || dialog.inst4() == true){
            buff4.append("GRANT SELECT, INSERT, UPDATE ON `bazzar`.`provider` TO`");
            buff4.append(userStr);
            buff4.append("`@`%`;");
            query.prepare(buff4);
        }else{
            qDebug() << "Non privelege";
        }
        query.exec();
        buff5.append("GRANT SELECT, UPDATE ON `bazzar`.`broker` TO`");
        buff5.append(userStr);
        buff5.append("`@`%`;");
        query.prepare(buff5);
        query.exec();
        }
       }
        sqlError=query.lastError();
        if(sqlError.type()!=QSqlError::NoError){
            QMessageBox::critical(this,"SQL ERROR", sqlError.text());
        }else{
            QMessageBox::information(this, "Сообщение", "Пользователь создан");
        }
    }else{
        QMessageBox::information(this, "Сообщение", "У вас нет доступа");
    }

}
void MainWindow::on_action_5_triggered(){
    QMessageBox::information(0,"Info","exit pressed.");
}
void MainWindow::on_action_6_triggered(){
    d_account dialog;
    QSqlError sqlError;
    QSqlQuery query;
    QString str2 = "UPDATE broker SET adress_brok = '";
    QSqlQueryModel *model2 = new QSqlQueryModel;
    model2->setQuery("SELECT * from broker WHERE login_brok = \'"+auc+"\';");
    model2->setHeaderData(3,Qt::Vertical, QObject::tr("Имя"));
    model2->setHeaderData(2,Qt::Vertical, QObject::tr("Дата Рождения"));
    model2->setHeaderData(1,Qt::Vertical, QObject::tr("Почта"));
    model2->setHeaderData(0,Qt::Vertical, QObject::tr("Логин"));
    dialog.tb()->setModel(model2);
    dialog.tb()->show();
    if(dialog.exec()){
        str2.append(dialog.upd1());
        str2.append("', date_brok= '");
        str2.append(dialog.upd2());
        str2.append("' WHERE login_brok = '");
        str2.append(auc);
        str2.append("';");
        query.prepare(str2);
        query.exec();
        sqlError = query.lastError();
        if(sqlError.type()!=QSqlError::NoError){
            QMessageBox::critical(this,"SQL ERROR", sqlError.text());
        }else{
            QMessageBox::information(this, "Сообщение", "Данные изменены");
        }
    }
}

