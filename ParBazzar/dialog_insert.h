#ifndef DIALOG_INSERT_H
#define DIALOG_INSERT_H

#include <QDialog>

namespace Ui {
class Dialog_Insert;
}

class Dialog_Insert : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_Insert(QWidget *parent = nullptr);
    ~Dialog_Insert();
    QString insert1();
    QString insert2();
    QString insert3();
    QString insert4();
    QString insert5();
    QString insert6();
    private:
    Ui::Dialog_Insert *ui;
};



#endif // DIALOG_INSERT_H
