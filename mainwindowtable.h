#ifndef MAINWINDOWTABLE_H
#define MAINWINDOWTABLE_H

#include <QMainWindow>
#include"blackjack.h"

namespace Ui {
class MainWindowTable;
}

class MainWindowTable : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindowTable(QWidget *parent = 0);
    ~MainWindowTable();
    BlackJack player;
    MainWindowTable *z;
    BlackJack croupier;
    Deck deck;
    int spaceplayer;
    int spacecroupier;
    Player p;
    // methods
    void first_deal();

private slots:
    void on_pushButtonReturn_clicked();

    void on_pushButtonDEAL_clicked();

    void on_pushButtonHit_clicked();

    void on_pushButtonStay_clicked();

private:
    Ui::MainWindowTable *ui;
};

#endif // MAINWINDOWTABLE_H
