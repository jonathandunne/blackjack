#include <cassert>
#include <iostream>
#include <array>
#include "Pack.hpp"
#include <cstdlib>

using namespace std;

Pack::Pack() {
    next = 0;
    for (int suit = SPADES; suit <= DIAMONDS; suit++) {
        for (int rank = TWO; rank <= ACE; rank++) {
            Rank r = static_cast<Rank>(rank);
            Suit s = static_cast<Suit>(suit);
            Card card(r, s);
            cards[(suit * 6) + rank - 7] = card;
        }
    }
}

Pack::Pack(std::istream& pack_input) {
    next = 0;
    for (int i = 0; i < 52; i++) {
        pack_input >> cards[i];
    }

}

Card Pack::deal_one() {
    next++;
    return cards[next - 1];
}

void Pack::reset() {
    next = 0;
}

void Pack::shuffle() {
    for (int i = 0; i < 500; ++i) {
        int x = rand() % 53;
        while (x >= 52) {
            x = rand() % 53;
        }
        int y = rand() % 53;
        while (y == x || y >= 52) {
            y = rand() % 53;
        }
        Card temp = cards[y];
        cards[y] = cards[x];
        cards[x] = temp;
    }
    this->reset();
}

bool Pack::empty() const {
    if (next == 52) {
        return true;
    }
    else {
        return false;
    }
}