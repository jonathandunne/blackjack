#include "Card.hpp"
#include "Pack.hpp"
#include <iostream>
#include <fstream>      
#include <array>
#include <algorithm>

using namespace std;

class Blackjack {
    public: 
        Blackjack(int& balance) {
            pack.shuffle();
            cout << "Place your bet: ";
            cin >> bet;
            cout << endl;
            
            player_hand.push_back(pack.deal_one());
            player_hand.push_back(pack.deal_one());
            dealer_hand.push_back(pack.deal_one());
            dealer_hand.push_back(pack.deal_one());
            
            cout << "You drew " << player_hand[0] << " and " << player_hand[1] << endl;
            cout << "The dealer drew " << dealer_hand[0] << endl;

            if ((player_hand[0].get_rank() == ACE|| player_hand[1].get_rank() == ACE) &&
                (player_hand[0].get_rank() > 7 || player_hand[1].get_rank() > 7 &&
                player_hand[0].get_rank() < 12 || player_hand[1].get_rank() < 12) &&
                dealer_hand[0].get_rank() != ACE && dealer_hand[1].get_rank() != ACE) {
                    cout << "Blackjack! You won $" << ((3 * bet) / 2) << endl;
                    return;
                }
            
        }
    private:
    Pack pack;
    vector<Card> player_hand;
    vector<Card> dealer_hand;
    int bet = 0;
    int dealer_score = 0;
    int player_score = 0;
};