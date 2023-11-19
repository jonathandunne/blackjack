// Blackjack.hpp
#ifndef BLACKJACK_HPP
#define BLACKJACK_HPP

#include "Card.hpp"
#include "Pack.hpp"
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>

class Blackjack {
public:
    Blackjack();
    void play(int& balance);

private:
    Pack pack;
    std::vector<Card> player_hand;
    std::vector<Card> dealer_hand;
    bool dealer_bust;
    bool player_bust;
    int dealer_high_aces;
    int player_high_aces;
    int bet;
    int dealer_score;
    int player_score;

    int score_card(Card c, char p);
    void add_score(int points, char p);
};

#endif // BLACKJACK_HPP
