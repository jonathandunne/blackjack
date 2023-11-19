// HigherOrLower.hpp
#ifndef HIGHERORLOWER_HPP
#define HIGHERORLOWER_HPP

#include "Card.hpp"
#include "Pack.hpp"
#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>
#include <string>

class HigherOrLower {
public:
    HigherOrLower(int &balance);

    bool haveMoney(int &money);

private:
    Pack pack;
    Card card;
    int streak = 0;
    bool playing;
    bool loss;
};

#endif // HIGHERORLOWER_HPP
