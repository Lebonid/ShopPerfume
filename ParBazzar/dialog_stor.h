#ifndef DIALOG_STOR_H
#define DIALOG_STOR_H

#include <QDialog>

namespace Ui {
class dialog_stor;
}

class dialog_stor : public QDialog
{
    Q_OBJECT

public:
    explicit dialog_stor(QWidget *parent = nullptr);
    ~dialog_stor();
    QString search();

private:
    Ui::dialog_stor *ui;
};

#endif // DIALOG_STOR_H
