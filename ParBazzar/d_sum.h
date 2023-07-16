#ifndef D_SUM_H
#define D_SUM_H

#include <QDialog>

namespace Ui {
class d_sum;
}

class d_sum : public QDialog
{
    Q_OBJECT

public:
    explicit d_sum(QWidget *parent = nullptr);
    ~d_sum();
    QString line();

private:
    Ui::d_sum *ui;
};

#endif // D_SUM_H
