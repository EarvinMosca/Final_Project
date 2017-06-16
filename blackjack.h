#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "card.h"
#include "deck.h"

class BlackJack
{
    // Fields
    const int MAX_HAND_VALUE;
    std::vector<Card> cards;
    //int Score;

public:
    bool hit;
    BlackJack();
    // getters
    int get_score(); // gets the score for the hand
    std::vector<Card> get_Cards(); // get the cards
    //methods
    void AddCard(Card); // adds a card to the hand
    void ShowFirstCard(); // shows the first card in the hand by making it face up
    void ShowAllCards(); // shows all the cards in the hand
    void HitOrNot(Deck);
    void Print();
};

class Player {
public:
    // Constructor.
    //    Assigns initial amount of money
    Player(int m);
    Player();
    //Accessors
    int get_money() const;

    //Mutators
    void blackjack(int b);
    void lose_bet(int b);
    void win_bet(int b);



private:
    int money;

};

#endif // BLACKJACK_H
