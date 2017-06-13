#-------------------------------------------------
#
# Project created by QtCreator 2017-06-11T10:43:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PIC10C_Final_Project
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    mainwindowtable.cpp \
    blackjack.cpp \
    card.cpp \
    deck.cpp \
    dialog.cpp \
    instrdialog.cpp

HEADERS  += mainwindow.h \
    mainwindowtable.h \
    blackjack.h \
    card.h \
    deck.h \
    dialog.h \
    instrdialog.h \
    rank_and_suit.h

FORMS    += mainwindow.ui \
    mainwindowtable.ui \
    dialog.ui \
    instrdialog.ui

DISTFILES += \
    BlackjackHand.cs \
    Card.cs \
    Rank.cs \
    Deck.cs \
    Suit.cs \
    playingcards/playing cards/PNG-cards-1.3/2_of_clubs.png \
    playingcards/playing cards/PNG-cards-1.3/2_of_diamonds.png \
    playingcards/playing cards/PNG-cards-1.3/2_of_hearts.png \
    playingcards/playing cards/PNG-cards-1.3/2_of_spades.png \
    playingcards/playing cards/PNG-cards-1.3/3_of_clubs.png \
    playingcards/playing cards/PNG-cards-1.3/3_of_diamonds.png \
    playingcards/playing cards/PNG-cards-1.3/3_of_hearts.png \
    playingcards/playing cards/PNG-cards-1.3/3_of_spades.png \
    playingcards/playing cards/PNG-cards-1.3/4_of_clubs.png \
    playingcards/playing cards/PNG-cards-1.3/4_of_diamonds.png \
    playingcards/playing cards/PNG-cards-1.3/4_of_hearts.png \
    playingcards/playing cards/PNG-cards-1.3/4_of_spades.png \
    playingcards/playing cards/PNG-cards-1.3/5_of_clubs.png \
    playingcards/playing cards/PNG-cards-1.3/5_of_diamonds.png \
    playingcards/playing cards/PNG-cards-1.3/5_of_hearts.png \
    playingcards/playing cards/PNG-cards-1.3/5_of_spades.png \
    playingcards/playing cards/PNG-cards-1.3/6_of_clubs.png \
    playingcards/playing cards/PNG-cards-1.3/6_of_diamonds.png \
    playingcards/playing cards/PNG-cards-1.3/6_of_hearts.png \
    playingcards/playing cards/PNG-cards-1.3/6_of_spades.png \
    playingcards/playing cards/PNG-cards-1.3/7_of_clubs.png \
    playingcards/playing cards/PNG-cards-1.3/7_of_diamonds.png \
    playingcards/playing cards/PNG-cards-1.3/7_of_hearts.png \
    playingcards/playing cards/PNG-cards-1.3/7_of_spades.png \
    playingcards/playing cards/PNG-cards-1.3/8_of_clubs.png \
    playingcards/playing cards/PNG-cards-1.3/8_of_diamonds.png \
    playingcards/playing cards/PNG-cards-1.3/8_of_hearts.png \
    playingcards/playing cards/PNG-cards-1.3/8_of_spades.png \
    playingcards/playing cards/PNG-cards-1.3/9_of_clubs.png \
    playingcards/playing cards/PNG-cards-1.3/9_of_diamonds.png \
    playingcards/playing cards/PNG-cards-1.3/9_of_hearts.png \
    playingcards/playing cards/PNG-cards-1.3/9_of_spades.png \
    playingcards/playing cards/PNG-cards-1.3/10_of_clubs.png \
    playingcards/playing cards/PNG-cards-1.3/10_of_diamonds.png \
    playingcards/playing cards/PNG-cards-1.3/10_of_hearts.png \
    playingcards/playing cards/PNG-cards-1.3/10_of_spades.png \
    playingcards/playing cards/PNG-cards-1.3/ace_of_clubs.png \
    playingcards/playing cards/PNG-cards-1.3/ace_of_diamonds.png \
    playingcards/playing cards/PNG-cards-1.3/ace_of_hearts.png \
    playingcards/playing cards/PNG-cards-1.3/ace_of_spades.png \
    playingcards/playing cards/PNG-cards-1.3/ace_of_spades2.png \
    playingcards/playing cards/PNG-cards-1.3/black_joker.png \
    playingcards/playing cards/PNG-cards-1.3/jack_of_clubs.png \
    playingcards/playing cards/PNG-cards-1.3/jack_of_clubs2.png \
    playingcards/playing cards/PNG-cards-1.3/jack_of_diamonds.png \
    playingcards/playing cards/PNG-cards-1.3/jack_of_diamonds2.png \
    playingcards/playing cards/PNG-cards-1.3/jack_of_hearts.png \
    playingcards/playing cards/PNG-cards-1.3/jack_of_hearts2.png \
    playingcards/playing cards/PNG-cards-1.3/jack_of_spades.png \
    playingcards/playing cards/PNG-cards-1.3/jack_of_spades2.png \
    playingcards/playing cards/PNG-cards-1.3/king_of_clubs.png \
    playingcards/playing cards/PNG-cards-1.3/king_of_clubs2.png \
    playingcards/playing cards/PNG-cards-1.3/king_of_diamonds.png \
    playingcards/playing cards/PNG-cards-1.3/king_of_diamonds2.png \
    playingcards/playing cards/PNG-cards-1.3/king_of_hearts.png \
    playingcards/playing cards/PNG-cards-1.3/king_of_hearts2.png \
    playingcards/playing cards/PNG-cards-1.3/king_of_spades.png \
    playingcards/playing cards/PNG-cards-1.3/king_of_spades2.png \
    playingcards/playing cards/PNG-cards-1.3/queen_of_clubs.png \
    playingcards/playing cards/PNG-cards-1.3/queen_of_clubs2.png \
    playingcards/playing cards/PNG-cards-1.3/queen_of_diamonds.png \
    playingcards/playing cards/PNG-cards-1.3/queen_of_diamonds2.png \
    playingcards/playing cards/PNG-cards-1.3/queen_of_hearts.png \
    playingcards/playing cards/PNG-cards-1.3/queen_of_hearts2.png \
    playingcards/playing cards/PNG-cards-1.3/queen_of_spades.png \
    playingcards/playing cards/PNG-cards-1.3/queen_of_spades2.png \
    playingcards/playing cards/PNG-cards-1.3/red_joker.png

RESOURCES += \
    rsc.qrc
