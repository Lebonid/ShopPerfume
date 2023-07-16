#ifndef DCREATE_USER_H
#define DCREATE_USER_H

#include <QComboBox>
#include <QDialog>

namespace Ui {
class dCreate_user;
}

class dCreate_user : public QDialog
{
    Q_OBJECT

public:
    explicit dCreate_user(QWidget *parent = nullptr);
    ~dCreate_user();
    QString dlogin();
    QString dpass();
    QString dname();
    bool sel1();
    bool inst1();
    bool del1();
    bool upd1();
    bool sel2();
    bool inst2();
    bool del2();
    bool upd2();
    bool sel3();
    bool inst3();
    bool del3();
    bool upd3();
    bool sel4();
    bool inst4();
    bool del4();
    bool upd4();

private:
    Ui::dCreate_user *ui;
};

#endif // DCREATE_USER_H
