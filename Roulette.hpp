// Roulette.hpp
#ifndef ROULETTE_HPP
#define ROULETTE_HPP

#include <iostream>
#include <string>
#include <map>

class Roulette {
public:
    Roulette(int startingMoney);
    void setStartingMoney(int amount);
    void placeBet(int amount, const std::string& betType, const std::string& betOption);
    std::pair<std::string, std::string> spin();
    int calculateWinnings();
    void play();
    int getPlayerMoney() const;

private:
    std::map<std::string, std::string> wheel;
    std::string lastNumberSpun;
    std::string lastColorSpun;
    int betAmount;
    std::string betType;
    std::string betOption;
    int playerMoney;
};

#endif // ROULETTE_HPP
