#include <cassert>
#include <iostream>
#include <array>
#include "Pack.hpp"

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
    Pack top_half;
    Pack bottom_half;
    for (int j = 0; j < (rand() % 15) + 5; j++) {
        for (int i = 0; i < 26; i++) {
            bottom_half.cards[i] = this->cards[i + 12];
            top_half.cards[i] = this->cards[i];
        }
        for (int i = 0; i < 52; i++) {
            if (i % 2 == 0) {
                this->cards[i] = bottom_half.cards[i / 2];
            }
            else {
                this->cards[i] = top_half.cards[i / 2];
            }
        }
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