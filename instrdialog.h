#ifndef INSTRDIALOG_H
#define INSTRDIALOG_H

#include <QDialog>

namespace Ui {
class instrDialog;
}

class instrDialog : public QDialog
{
    Q_OBJECT

public:
    explicit instrDialog(QWidget *parent = 0);
    ~instrDialog();

private:
    Ui::instrDialog *ui;
};

#endif // INSTRDIALOG_H
