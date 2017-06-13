#include "instrdialog.h"
#include "ui_instrdialog.h"

instrDialog::instrDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::instrDialog)
{
    ui->setupUi(this);
}

instrDialog::~instrDialog()
{
    delete ui;
}
