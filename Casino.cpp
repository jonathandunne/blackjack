#include <iostream>
#include <cassert>
#include <iostream>
#include "Blackjack.hpp"
#include "Roulette.hpp"
#include "HigherOrLower.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    if(argc != 2) {
        cout << "Please only include starting money in declaration!\n";
        return -1;
    }
    int startingMoney = stoi(argv[1]);
    int gamenum = -1;
    bool haveMoney = true;
    while(gamenum != 0) {
        cout << "Enter 1 for Roulette\n";
        cout << "Enter 2 for Higher-Lower\n";
        cout << "Enter 0 for Quit\n";
        cout << "Select which game you want to play: ";
        cin >> gamenum;
        if(gamenum == 0) {
            cout << "Thanks for playing!\n";
            cout << "This is your current balance: $" << startingMoney; 
            cout << "\n";
        }
        else if(gamenum == 1) {
            Roulette game = Roulette(startingMoney);
            startingMoney = game.play();
            cout << "Thanks for playing Roulette!\n";
            cout << "This is your current balance: " << startingMoney; 
            cout << "\n";
        } else if(gamenum == 2) {
            HigherOrLower game = HigherOrLower(startingMoney);
            haveMoney = game.haveMoney(startingMoney);
            cout << "Thanks for playing Higher-or-Lower!\n";
            cout << "This is your current balance: $" << startingMoney; 
            cout << "\n";
        } else {
            cout << "There is no game corresponding to this number, try another one!\n";
        }
        if(haveMoney == false) {
            cout << "You don't have the money for that\n";
            cout << "Thanks for playing though . . .";
            return 0;
        }
        cout << "You should play again!\n";
        cout << "\n";
    }
    
};

// ./Casino.exe 10000