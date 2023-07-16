#ifndef DIALOG2_H
#define DIALOG2_H

#include <QDialog>

namespace Ui {
    class Dialog2;
}

class Dialog2 : public QDialog
{
    Q_OBJECT

public:
    Dialog2(QWidget *parent=0);
    ~Dialog2();
    QString search();
    QString search2();
private:
    Ui::Dialog2 *ui;
};

#endif // DIALOG2_H
