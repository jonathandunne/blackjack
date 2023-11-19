#include "Card.hpp"
#include "Pack.hpp"
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <string>


using namespace std;

class HigherOrLower {
public:
    HigherOrLower(int &balance) {
        pack.shuffle();
        cout << "Place your bet: ";
        cin >> bet;
        cout << endl;
        while (bet > balance) {
            cout << "Bet too large" << endl;
            cout << "Place your bet: ";
            cin >> bet;
            cout << endl;
        }
        balance -= bet;
        card = (pack.deal_one());
        string guess;
        while (playing && !pack.empty() && !loss) {
            cout << "The current card is the " << card.get_rank() << " of " << card.get_suit() << endl;
            int initialRank = card.get_rank();
            cout << "Is the next card higher or lower?" << endl;
            cin >> guess;
            for (int i = 0; i < guess.size(); ++i) {
                guess.at(i) = tolower(guess.at(i));
            }
            while (guess != "higher" && guess != "lower") {
                cin >> guess;
                for (int i = 0; i < guess.size(); ++i) {
                    guess.at(i) = tolower(guess.at(i));
                }
            }
            card = (pack.deal_one());
            cout << "The new card is the " << card.get_rank() << " of " << card.get_suit() << endl;
            int secondRank = card.get_rank();
            if (initialRank == 12) {
                initialRank = -1;
            } else if (secondRank == 12) {
                secondRank = -1;
            }
            initialRank +=2;
            secondRank+=2;

            if (guess == "higher" && initialRank < secondRank) {
                streak += 1;
                bet *= 1/(initialRank/13);
            } else if (guess == "lower" && secondRank < initialRank) {
                streak += 1;
                bet *=1/((13-initialRank)/13);
            } else {
                loss = true;
                playing = false;
            }
            if (playing) {
                cout << "Do you want to continue (Y/N)?" << endl;
                string choice;
                if (choice == "N" || choice == "n"
                || choice == "No" || choice == "nO"
                || choice == "NO" || choice == "no") {
                    playing = false;
                }
            }
        }
        if (loss) {
            bet = 0;
        }
        balance += bet;
    }

private:
    Pack pack;
    Card card;
    double bet = 0;
    int streak = 0;
    bool playing = true;
    bool loss = false;
};