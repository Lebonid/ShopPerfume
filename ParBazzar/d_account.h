#ifndef D_ACCOUNT_H
#define D_ACCOUNT_H

#include <QDialog>
#include <QTableView>

namespace Ui {
class d_account;
}

class d_account : public QDialog
{
    Q_OBJECT

public:
    explicit d_account(QWidget *parent = nullptr);
    ~d_account();
    QString upd1();
    QString upd2();
    QString login;
    QTableView *tb();

private:
    Ui::d_account *ui;
};

#endif // D_ACCOUNT_H
