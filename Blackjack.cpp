#include "Card.hpp"
#include "Pack.hpp"
#include "Blackjack.hpp"
#include <iostream>
#include <fstream>      
#include <array>
#include <algorithm>

using namespace std;

        Blackjack::Blackjack() {
        }
        void Blackjack::play(int& balance) {
            pack.shuffle();
            cout << "Place your bet: ";
            cin >> bet;
            cout << endl;
            while (bet > balance) {
                if (bet > balance) {
                    cout << "Your bet exceeds your balance. Please bet again." << endl;
                }
                cout << "Place your bet: ";
                cin >> bet;
                cout << endl;
            }
        
            player_hand.push_back(pack.deal_one());
            player_hand.push_back(pack.deal_one());
            dealer_hand.push_back(pack.deal_one());
            dealer_hand.push_back(pack.deal_one());
            
            cout << "You drew " << player_hand[0] << " and " << player_hand[1] << endl;
            cout << "The dealer drew " << dealer_hand[0] << endl;

            //Blackjack Check
            if ((player_hand[0].get_rank() == ACE|| player_hand[1].get_rank() == ACE) &&
                (player_hand[0].get_rank() > 7 || player_hand[1].get_rank() > 7) &&
                (player_hand[0].get_rank() < 12 || player_hand[1].get_rank() < 12) &&
                (dealer_hand[0].get_rank() != ACE && dealer_hand[1].get_rank() != ACE)) {
                    cout << "Blackjack! You won $" << ((3 * bet) / 2) << endl;
                    balance += ((3 * bet) / 2);
                    return;
                }

            add_score(score_card(player_hand[0], 'p'), 'p');
            add_score(score_card(player_hand[1], 'p'), 'p');
            add_score(score_card(dealer_hand[0], 'd'), 'd');
            add_score(score_card(dealer_hand[0], 'd'), 'd');

            string input;
            int index = 2;
            //Hit or pass stage
            cout << "You have " << player_score << " points" << endl;
                    cout << "Would you like to hit or stand?" << endl;
                    cin >> input;
                    cout << endl;
            while ((player_score < 22) && (input != "stand") && (!player_bust)) {
                while (input != "hit") {
                    if (input != "hit") {
                        cout << "Invalid input, please try again" << endl;
                    }
                    cout << "You have " << player_score << " points" << endl;
                    cout << "Would you like to hit or stand?" << endl;
                    cin >> input;
                    cout << endl;
                }
                
                
                if (input == "hit") {
                    player_hand.push_back(pack.deal_one());
                    cout << "You drew " << player_hand[index] << endl;
                    add_score(score_card(player_hand[index], 'p'), 'p');
                    cout << "Your new score is " << player_score << endl;
                    index++;
                }
            }
            int index2 = 2;
            if (input == "stand") {
                cout << "The dealer flipped over " << dealer_hand[1] << endl;
                while ((dealer_score < 17) && (!dealer_bust)) {
                    cout << "Dealer hits" << endl;
                    dealer_hand.push_back(pack.deal_one());
                    cout << "Dealer draws " << dealer_hand[index2] << endl;
                    add_score(score_card(dealer_hand[index2], 'd'), 'd');
                    cout << "Dealer's score is " << dealer_score;
                    index2++;
                }
                if (!dealer_bust) {
                    cout << "Dealer stands with " << dealer_score << " points";
                }
            }

            //Results
            if (dealer_score < player_score || dealer_bust) {
                cout << "You win! You won $" << bet << endl;
                balance += bet;
                return;
            }
            else if (dealer_score > player_score || player_bust) {
                cout << "You lose. You lost $" << bet << endl;
                balance -= bet;
                return;
            }
            else {
                cout << "It's a push. You get your bet back." << endl;
                return;
            }
            
        }

        //Returns the score of the given card and player type
        int Blackjack::score_card(Card c, char p) {
            if (c.get_rank() < 9) {
                return c.get_rank() + 2;
            }
            else if (c.get_rank() > 8 && c.get_rank() < 12) {
                return 10;
            }
            else {
                if (p == 'p') {
                    if (player_score + 11 > 21) {
                        return 1;
                    }
                    else {
                        player_high_aces++;
                        return 11;
                    }
                }
                else {
                    if (dealer_score + 11 > 21) {
                        return 1;
                    }
                    else {
                        dealer_high_aces++;
                        return 11;
                    }
                }
            }
        }
        void Blackjack::add_score(int points, char p) {
            if (p == 'p') {
                if ((points + player_score > 21) && (player_high_aces > 0)) {
                    player_score += points - 10;
                    player_high_aces--;
                }
                else if (points + player_score > 21) {
                    cout << "Bust!" << endl;
                    player_score += points;
                }
                else {
                    player_score += points;
                }
            }
            else {
                if ((points + dealer_score > 21) && (dealer_high_aces > 0)) {
                    dealer_score += points - 10;
                    dealer_high_aces--;
                }
                else if (points + dealer_score > 21) {
                    cout << "Dealer busted!" << endl;
                    dealer_score += points;
                }
                else {
                    dealer_score += points;
                }
            }
        }
