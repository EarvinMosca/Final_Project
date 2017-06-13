#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "instrdialog.h"
#include "mainwindowtable.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    /*QPalette *pal = ui->pushButtonPlay->palette();
    pal->setColor(QPalette::ButtonText,QColor(0,0,255));
    ui->pushButtonPlay->setPalette(pal);
    ui->pushButtonPlay->setAutoFillBackground(true);*/
    //pal->setColor(QPalette::ButtonText,Qt::white);
    //ui->pushButtonPlay->testAttribute(colorCount(Qt::white));

    ui->setupUi(this);
   // connect(ui->pushButtonPlay, SIGNAL(clicked()), this, SLOT(exampleButtonClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonInstructions_clicked()
{
    instrDialog instr;
    instr.setModal(true);
    instr.exec();
    //qdialog = new QDialog;
    //qdialog->show();
}

void MainWindow::on_pushButtonPlay_clicked()
{
    this->hide();
    table = new MainWindowTable(this);
    table->show();
}

//void MainWindow::
