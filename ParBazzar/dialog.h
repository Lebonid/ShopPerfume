#ifndef DIALOG_H
#define DIALOG_H
#include <QDialog>


namespace Ui{
 class Dialog;
}
class Dialog: public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget *parent=0);
    ~Dialog();
    QString search();
    QString search_2();
    QString search_3();
    QString search_4();
private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
