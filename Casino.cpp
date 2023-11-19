#include <iostream>
#include <cassert>
#include <iostream>
#include "Blackjack.cpp"

using namespace std;

int main(int argc, char *argv[]) {
    if(argc == 2) {
        cout << "Please only include starting money in declaration!";
        return -1;
    }
    int startingMoney = stoi(argv[1]);
    int gamenum = -1;
    bool haveMoney = true;
    while(gamenum != 0) {
        cout << "Enter 1 for Blackjack\n";
        cout << "Enter 0 for Quit\n";
        cout << "Select which game you want to play: ";
        cin >> gamenum;
        if(gamenum == 0) {
            cout << "Thanks for playing!";
            cout << "This is your current balance: " << startingMoney; 
            cout << "\n";
        }
        if(gamenum == 1) {
            Blackjack game = Blackjack(startingMoney);
            haveMoney = game.play();
            cout << "Thanks for playing Blackjack!";
            cout << "This is your current balance: " << startingMoney; 
            cout << "\n";
        }
        if(haveMoney == false) {
            cout << "You don't have the money for that";
            cout << "Thanks for playing though . . .";
            return 0;
        }
        cout << "You should play again!\n";
        cout << "\n";
    }
    
};

// ./Casino.exe 10000