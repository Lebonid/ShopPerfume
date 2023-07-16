#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCodec>
#include <QSqlDatabase>
#include <QSqlRelationalTableModel>
#include <QApplication>
#include <QDataWidgetMapper>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QApplication *a, QWidget *parent = 0);
    ~MainWindow();
    QString auc;

private slots:
    void on_action_Exit_triggered();
    void on_action_triggered();
    void on_action_2_triggered();
    void on_action_3_triggered();
    void on_action_4_triggered();
    void on_action_5_triggered();
    void on_action_6_triggered();
    void on_action_8_triggered();
    void on_action_9_triggered();
    void on_action_10_triggered();
    void on_action_11_triggered();
    void on_action_12_triggered();
    void on_action_15_triggered();
    void on_action_16_triggered();

private:
    Ui::MainWindow *ui;
    QTextCodec *codec;
    QSqlDatabase *db;
    QAbstractTableModel *model;
    bool createConnection();
    void createRelationalTables();
    void initializeModel();
};
#endif // MAINWINDOW_H
