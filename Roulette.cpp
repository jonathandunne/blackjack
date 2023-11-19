#include <iostream>
#include <string>
#include <map>
using namespace std;

class Roulette {
    public: 
        Roulette();
        void placeBet(int amount, const std::string& betType, const std::string& betOption);
        std::pair<std::string, std::string> spin();
        int calculateWinnings();
        void play(Roulette& rouletteGame);
    private:
        std::map<std::string, std::string> wheel;
        std::string lastNumberSpun;
        std::string lastColorSpun;
        int betAmount;
        std::string betType;
        std::string betOption;
        
};

Roulette::Roulette() : betAmount(0) {
    std::srand(std::time(nullptr));
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

void Roulette::placeBet(int amount, const std::string& betType, const std::string& betOption) {
    this->betAmount = amount;
    this->betType = betType;
    this->betOption = betOption;
}

std::pair<std::string, std::string> Roulette::spin() {
    int randomIndex = std::rand() % wheel.size();
    auto it = std::next(wheel.begin(), randomIndex);
    lastNumberSpun = it->first;
    lastColorSpun = it->second;
    return *it;
}

int Roulette::calculateWinnings() {
    bool isWin = false;
    if (betType == "r/b") {
        isWin = (betOption == lastColorSpun);
    } else if (betType == "o/e") {
        int number = std::stoi(lastNumberSpun);
        isWin = ((betOption == "odd") && (number % 2 != 0)) || ((betOption == "even") && (number % 2 == 0));
    } else if (betType == "h/l") {
        int number = std::stoi(lastNumberSpun);
        isWin = ((betOption == "high") && (number >= 19)) || ((betOption == "low") && (number <= 18));
    }

    if (isWin) {
        return betAmount * 2;
    } else {
        return 0;
    }
}

void play(Roulette& rouletteGame) {
    int betAmount;
    std::string betType, betOption;

    // Ask for the bet details
    std::cout << "Enter bet amount: ";
    std::cin >> betAmount;

    std::cout << "Enter bet type (r/b, o/e, h/l): ";
    std::cin >> betType;

    std::cout << "Enter bet option (red, black, odd, even, high, low): ";
    std::cin >> betOption;

    // Place the bet
    rouletteGame.placeBet(betAmount, betType, betOption);

    // Spin the wheel and display the result
    auto result = rouletteGame.spin();
    std::cout << "The wheel landed on " << result.first << " which is " << result.second << std::endl;

    // Calculate and display winnings
    int winnings = rouletteGame.calculateWinnings();
    if (winnings > 0) {
        std::cout << "You won " << winnings << "!" << std::endl;
    } else {
        std::cout << "You lost your bet." << std::endl;
    }
}
