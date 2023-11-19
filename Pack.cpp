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
            // array has 0 to 12 elements
            cards[suit * 13 + rank] = card; 
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
    return cards[next++];
}

void Pack::reset() {
    next = 0;
}

void Pack::shuffle() {
    for (int i = 0; i < 500; ++i) {
        // change 53 to 52
        int x = rand() % 52; 
        int y = rand() % 52; 
        while (y == x) {
            y = rand() % 52; 
        }
        Card temp = cards[y];
        cards[y] = cards[x];
        cards[x] = temp;
    }
    this->reset();
}

bool Pack::empty() const {
    return next == 52;
}