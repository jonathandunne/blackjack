#include "Card.hpp"
#include "Pack.hpp"
#include "HigherOrLower.hpp"
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <string>


using namespace std;

HigherOrLower::HigherOrLower(int &balance) : streak(0), playing(true), loss(false) {
    pack.shuffle();
    cout << "Place your bet: ";
    string bet_string;
    cin >> bet_string;
    double bet = stoi(bet_string);
    cout << endl;
    while (bet > balance || bet <= 0) {
        cout << "Invalid Bet" << endl;
        cout << "Place your bet: ";
        cin >> bet_string;
        bet = stoi(bet_string);
        cout << endl;
    }
    balance -= bet;
    card = (pack.deal_one());
    string guess;
    while (playing && !pack.empty() && !loss) {
        cout << "The current card is the " << card << endl;
        int initialRank = card.get_rank();
        cout << "Is the next card higher or lower?" << endl;
        cin >> guess;
        for (int i = 0; i < guess.size(); ++i) {
            guess.at(i) = tolower(guess.at(i));
        }
        while (guess != "higher" && guess != "lower") {
            cout << "Invalid Input. Please enter 'higher' or 'low': " << endl;
            cin >> guess;
            for (int i = 0; i < guess.size(); ++i) {
                guess.at(i) = tolower(guess.at(i));
            }
        }
        card = pack.deal_one();
        cout << "The new card is the " << card << endl;
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
            bet *= 1.0 / ((13 - initialRank) / 13.0);
        } else if (guess == "lower" && secondRank < initialRank) {
            streak += 1;
            bet *= 1.0 / ((initialRank) / 13.0);
        } else {
            loss = true;
            playing = false;
        }
        if (playing) {
            cout << "Your bet is now worth: $" << floor(bet) << endl;
            cout << "Do you want to continue (Y/N)?" << endl;
            string choice;
            cin >> choice;
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

bool HigherOrLower::haveMoney(int &money) {
    if(money < 10) {
        return false;
    }
    return true;
}
