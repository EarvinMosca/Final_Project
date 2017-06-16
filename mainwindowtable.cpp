#include "mainwindowtable.h"
#include "ui_mainwindowtable.h"
#include "mainwindow.h"
#include <QLabel>
#include "blackjack.h"
#include "card.h"
#include "deck.h"
#include <QDebug>
#include <QDialog>
#include <QMessageBox>
#include <QtGui>
#include <QIcon>

MainWindowTable::MainWindowTable(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindowTable)
{
    spaceplayer=250;
    p=Player(bankrollcash);
    ui->setupUi(this);
    ui->pushButtonHit->setEnabled(false);
    ui->pushButtonStay->setEnabled(false);
    ui->cashlabel->setNum(bankrollcash);

}

MainWindowTable::~MainWindowTable()
{
    delete ui;
}

void MainWindowTable::on_pushButtonReturn_clicked()
{
    this->close();
    MainWindow *a = new MainWindow;
    a->show();

}

void MainWindowTable::on_pushButtonDEAL_clicked()
{
    first_deal();
    /*deck.Shuffle();
    player.AddCard(deck.TakeTopCard());
    player.AddCard(deck.TakeTopCard());
    dealer.AddCard(deck.TakeTopCard());
    dealer.AddCard(deck.TakeTopCard());
    player.ShowAllCards();
    dealer.ShowFirstCard();*/
    std::vector<Card> plyrcards=player.get_Cards();
    std::vector<Card> croupiercards=croupier.get_Cards();

    QLabel *cardplyr1 = new QLabel(this);
    QLabel *cardplyr2 = new QLabel(this);
    QLabel *cardcroupier1 = new QLabel(this);
    QLabel *cardcroupier2 = new QLabel(this);

    cardplyr1->setGeometry(QRect(235,300,100,100));
    cardplyr2->setGeometry(QRect(250,300,100,100));
    spacecroupier=200;
    cardcroupier1->setGeometry(QRect(130,75,100,100));
    cardcroupier2->setGeometry(QRect(spacecroupier,75,100,100));

    QString file=plyrcards[0].get_card_image();
    cardplyr1->setStyleSheet("image: url(:"+file+");");
    file=plyrcards[1].get_card_image();
    cardplyr2->setStyleSheet("image: url(:"+file+");");
    file=croupiercards[1].get_card_image();
    cardcroupier2->setStyleSheet("image: url(:"+file+");");
    cardcroupier1->setStyleSheet("image: url(:/cards/backcard.png);");//facedown
    cardplyr1->show();
    cardplyr2->show();
    cardcroupier1->show();
    cardcroupier2->show();
    QString scp; 
    ui->scp->setText(scp.setNum(player.get_score()));
    //qDebug()<<player.get_score();
    ui->pushButtonDEAL->setEnabled(false);
    if(player.get_score()!=21){
        ui->pushButtonHit->setEnabled(true);
        ui->pushButtonStay->setEnabled(true);
    }
    else if(player.get_score() == 21){
        ui->scp->setText(scp.setNum(player.get_score()));
        p.blackjack(ui->betslider->value());
        bankrollcash=p.get_money();
         ui->cashlabel->setNum(p.get_money());
        ui->pushButtonHit->setEnabled(false);
        //QMessageBox::information(this, "RESULT","BLACK JACK 21! You won!");
        QMessageBox res;
        res.setText("BLACK JACK");
        res.setInformativeText("WINNER!! 21!");
        res.setIcon(QMessageBox::Information);
        res.exec();
        this->close();
        z=new MainWindowTable(this);
        z->show();
    }

}

void MainWindowTable::on_pushButtonHit_clicked()
{
    std::vector<Card> plyrcards=player.get_Cards();
    //if(player.get_score()<=21){
        player.AddCard(deck.TakeTopCard());
        player.ShowAllCards();
        plyrcards=player.get_Cards();        
        QString scp;
        ui->scp->setText(scp.setNum(player.get_score()));
        QLabel *card = new QLabel(this);
        spaceplayer+=15;
        card->setGeometry(QRect(spaceplayer,300,100,100));

        QString file=plyrcards[plyrcards.size()-1].get_card_image();

        card->setStyleSheet("image: url(:"+file+");");
        card->show();
        //qDebug()<<player.get_score();
        if(player.get_score()>21){
            plyrcards=player.get_Cards();
            p.lose_bet(ui->betslider->value());
            *cash_p=p.get_money();
             ui->cashlabel->setNum(p.get_money());
            ui->pushButtonHit->setEnabled(false);
            //QMessageBox::information(this, "RESULT","Bust! You lost." );
            QMessageBox res;
            res.setText("You Lost.");
            res.setInformativeText("Bust!!");
            res.setIcon(QMessageBox::Warning);
            res.exec();
            this->close();
            z=new MainWindowTable(this);
            z->show();
        }
        else if(player.get_score()==21){
            plyrcards=player.get_Cards();
            p.blackjack(ui->betslider->value());
            *cash_p=p.get_money();
             ui->cashlabel->setNum(p.get_money());
            ui->pushButtonHit->setEnabled(false);
            //QMessageBox::information(this, "RESULT","BLACK JACK 21! You won!");
            QMessageBox res;
            res.setText("You Won!");
            res.setInformativeText("Black Jack 21!");
            res.setIcon(QMessageBox::Information);
            res.exec();
            this->close();
            z=new MainWindowTable(this);
            z->show();
        }

}

void MainWindowTable::first_deal(){

   deck.Shuffle();
   player.AddCard(deck.TakeTopCard());
   player.AddCard(deck.TakeTopCard());
   croupier.AddCard(deck.TakeTopCard());
   croupier.AddCard(deck.TakeTopCard());
   player.ShowAllCards();
   croupier.ShowFirstCard();
ui->cashlabel->setNum(p.get_money());

}


void MainWindowTable::on_pushButtonStay_clicked()
{
    croupier.ShowAllCards();
    std::vector<Card> croupiercards=croupier.get_Cards();
    QString scp;
    ui->scp->setText(scp.setNum(player.get_score()));
    QLabel *croupiercard1 = new QLabel(this);
    croupiercard1->setGeometry(QRect(130,75,100,100));
    QString file=croupiercards[0].get_card_image();
    croupiercard1->setStyleSheet("image: url(:"+file+");");
    croupiercard1->show();
    bool a = false;

    while(croupier.get_score()<17){
        a = true;

        croupier.AddCard(deck.TakeTopCard());
        croupier.ShowAllCards();
        croupiercards=croupier.get_Cards();
        QLabel *card = new QLabel(this);
        spacecroupier+=15;
        card->setGeometry(QRect(spacecroupier,75,100,100));
        QString file=croupiercards[croupiercards.size()-1].get_card_image();
        card->setStyleSheet("image: url(:"+file+");");
        card->show();
        //QString scp;
        //ui->scc->setText(scp.setNum(croupier.get_score()));

        if(croupier.get_score()>21){
            QString scrp;
            QString scrc;
            QString msg2 = "The dealer has busted! \nYour Score: "+scrp.setNum(player.get_score())+" \nDealer's Score: "+scrc.setNum(croupier.get_score());
            p.win_bet(ui->betslider->value());
            *cash_p=p.get_money();
            ui->cashlabel->setNum(p.get_money());
            QMessageBox res;
            res.setText("You Won!");
            res.setInformativeText(msg2);
            res.setIcon(QMessageBox::Information);
            res.exec();
            this->close();
            z=new MainWindowTable(this);
            z->show();
            break;
        }
        else if((player.get_score()>croupier.get_score()) && (croupier.get_score() >= 17 && croupier.get_score() <= 20)){
                QString scrp;
                QString scrc;
                QString msg2 = "You've got the dealer beat! \nYour score: "+scrp.setNum(player.get_score())+"\n Dealer's Score: "+scrc.setNum(croupier.get_score());
                p.win_bet(ui->betslider->value());
                *cash_p=p.get_money();
                 ui->cashlabel->setNum(p.get_money());
                QMessageBox res;
                res.setText("You Won!");
                res.setInformativeText(msg2);
                res.setIcon(QMessageBox::Information);
                res.exec();
                this->close();
                z=new MainWindowTable(this);
                z->show();
                break;
        }
        else if((player.get_score()==croupier.get_score())){
                QString scrp;
                QString scrc;
                QString msg2 = "Your Score: "+scrp.setNum(player.get_score())+" \nDealer's Score: "+scrc.setNum(croupier.get_score());
                QMessageBox res;
                res.setText("Tie!");
                res.setIcon(QMessageBox::Warning);
                res.setInformativeText(msg2);
                res.exec();
                this->close();
                z=new MainWindowTable(this);
                z->show();
                break;
        }
        else if(player.get_score() < 21 && croupier.get_score() == 21){

            QString scrp;
            QString scrc;
            QString msg2 = "Your score: "+scrp.setNum(player.get_score())+" \nDealer's score: "+scrc.setNum(croupier.get_score());
            p.lose_bet(ui->betslider->value());
            *cash_p=p.get_money();
             ui->cashlabel->setNum(p.get_money());
            QMessageBox res;
            res.setText("You Lost!");
            res.setInformativeText(msg2);
            res.setIcon(QMessageBox::Critical);
            res.exec();
            this->close();
            z=new MainWindowTable(this);
            z->show();
            break;
        }
        else if(croupier.get_score() > player.get_score() && croupier.get_score() <= 21){
            QString scrp;
            QString scrc;
            QString msg2 = "Your Score: "+scrp.setNum(player.get_score())+" \nDealer's Score: "+scrc.setNum(croupier.get_score());
            p.lose_bet(ui->betslider->value());
            *cash_p=p.get_money();
             ui->cashlabel->setNum(p.get_money());
            QMessageBox res;
            res.setText("You Lost!");
            res.setInformativeText(msg2);
            res.setIcon(QMessageBox::Critical);
            res.exec();
            this->close();
            z=new MainWindowTable(this);
            z->show();
            break;

        }

    }
    if(a == false){
        if((player.get_score()<croupier.get_score()) && croupier.get_score()<22){
            QString scrp;
            QString scrc;
            QString msg2 = "The dealer has you beat! \nYour score: "+scrp.setNum(player.get_score())+" \nDealer's score: "+scrc.setNum(croupier.get_score());
            p.lose_bet(ui->betslider->value());
            *cash_p=p.get_money();
             ui->cashlabel->setNum(p.get_money());
            QMessageBox res;
            res.setText("You lost!");
            res.setIcon(QMessageBox::Critical);
            res.setInformativeText(msg2);
            res.exec();
            this->close();
            z=new MainWindowTable(this);
            z->show();
        }
        else if(croupier.get_score() < player.get_score() && croupier.get_score()<22){
            QString scrp;
            QString scrc;
            QString msg2 = "Your score: "+scrp.setNum(player.get_score())+" \nDealer's score: "+scrc.setNum(croupier.get_score());
            p.win_bet(ui->betslider->value());
            *cash_p=p.get_money();
             ui->cashlabel->setNum(p.get_money());
            QMessageBox res;
            res.setText("You won!");
            res.setIcon(QMessageBox::Information);
            res.setInformativeText(msg2);
            res.exec();
            this->close();
            z=new MainWindowTable(this);
            z->show();
        }
        else if((player.get_score()==croupier.get_score())&& croupier.get_score()<22){
                QString scrp;
                QString scrc;
                QString msg2 = "Your score: "+scrp.setNum(player.get_score())+" \nDealer's score: "+scrc.setNum(croupier.get_score());
                QMessageBox res;
                res.setText("TIE!");
                res.setInformativeText(msg2);
                res.setIcon(QMessageBox::Warning);
                res.exec();
                this->close();
                z=new MainWindowTable(this);
                z->show();
        }
    }



}
