#ifndef AUTH_H
#define AUTH_H

#include <QDialog>

namespace Ui {
class auth;
}

class auth : public QDialog
{
    Q_OBJECT

public:
    explicit auth(QWidget *parent = nullptr);
    ~auth();
    QString login();
    QString pass();

private:
    Ui::auth *ui;
};

#endif // AUTH_H
