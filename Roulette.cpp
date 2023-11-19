#include <iostream>
#include "Roulette.hpp"
#include <string>
#include <map>
using namespace std;

class Roulette {
public: 
    Roulette(int startingMoney);
    void setStartingMoney(int amount);
    void placeBet(int amount, const string& betType, const string& betOption);
    pair<string, string> spin();
    int calculateWinnings();
    void play(Roulette& rouletteGame);
    int getPlayerMoney() const {
        return playerMoney;
    }
private:
    map<string, string> wheel;
    string lastNumberSpun;
    string lastColorSpun;
    int betAmount;
    string betType;
    string betOption;
    int playerMoney;
};

Roulette::Roulette(int startingMoney) : betAmount(0), playerMoney(startingMoney) {
    srand(time(nullptr));
    wheel = { 
        {"00", "g"},
        {"1","r"},
        {"2","b"},
        {"3","r"},
        {"4","b"},
        {"5","r"},
        {"6","b"},
        {"7","r"},
        {"8","b"},
        {"9","r"},
        {"10","b"},
        {"11","b"},
        {"12","r"},
        {"13","b"},
        {"14","r"},
        {"15","b"},
        {"16","r"},
        {"17","b"},
        {"18","r"},
        {"19","r"},
        {"20","b"},
        {"21","r"},
        {"22","b"},
        {"23","r"},
        {"24","b"},
        {"25","r"},
        {"26","b"},
        {"27","r"},
        {"28","b"},
        {"29","b"},
        {"30","r"},
        {"31","b"},
        {"32","r"},
        {"33","b"},
        {"34","r"},
        {"35","b"},
        {"36","r"},
        {"0","g"}
     };
}

void Roulette::setStartingMoney(int amount) {
    playerMoney = amount;
}

void Roulette::placeBet(int amount, const string& betType, const string& betOption) {
    if (amount <= playerMoney) {
        this->betAmount = amount;
        this->betType = betType;
        this->betOption = betOption;
    } else {
        cout << "Insufficient funds for this bet.\n";
        betAmount = 0;
    }
}

pair<string, string> Roulette::spin() {
    int randomIndex = rand() % wheel.size();
    auto it = next(wheel.begin(), randomIndex);
    lastNumberSpun = it->first;
    lastColorSpun = it->second;
    return *it;
}

int Roulette::calculateWinnings() {
    bool isWin = false;
    if (betType == "r/b") {
        isWin = (betOption == lastColorSpun);
    } else if (betType == "o/e") {
        int number = stoi(lastNumberSpun);
        isWin = ((betOption == "odd") && (number % 2 != 0)) || ((betOption == "even") && (number % 2 == 0));
    } else if (betType == "h/l") {
        int number = stoi(lastNumberSpun);
        isWin = ((betOption == "high") && (number >= 19)) || ((betOption == "low") && (number <= 18));
    } else if (betType == "number") {
        int number = stoi(lastNumberSpun);
        isWin = (betOption == to_string(number));
    }

    if (isWin) {
        // win doubles the bet amount
        playerMoney += betAmount; 
        return betAmount * 2;
    } else {
        // lose the bet amount
        playerMoney -= betAmount; 
        return 0;
    }
}

void play(Roulette& rouletteGame) {
    int betAmount;
    string betType, betOption;

    // ask for the bet details
    cout << "Enter bet amount: ";
    cin >> betAmount;

    cout << "Enter bet type (r/b, o/e, h/l, number): ";
    cin >> betType;

    cout << "Enter bet option (for color: red/black, for odd/even: odd/even, for high/low: high/low, for number: any number): ";
    cin >> betOption;

    // place the bet
    rouletteGame.placeBet(betAmount, betType, betOption);

    // spin the wheel and display the result
    auto result = rouletteGame.spin();
    cout << "The wheel landed on number " << result.first << " which is color " << result.second << endl;

    // calculate the winnings
    int winnings = rouletteGame.calculateWinnings();
    if (winnings > 0) {
        cout << "You won " << winnings << "!" << endl;
    } else {
        cout << "You lost your bet." << endl;
    }
    cout << "Your current balance is: " << rouletteGame.getPlayerMoney() << endl;
}
