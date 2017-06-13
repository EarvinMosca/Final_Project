#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include "mainwindowtable.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    //void on_pushButtonPlay_2_clicked();

    void on_pushButtonInstructions_clicked();

    void on_pushButtonPlay_clicked();

private:
    QDialog *qdialog;
    Ui::MainWindow *ui;
    MainWindowTable *table;
};

#endif // MAINWINDOW_H
