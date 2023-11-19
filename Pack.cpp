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
            // change from cards[(suit * 6) + rank - 7] = card
            cards[(suit * 13) + rank] = card;
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
    srand(time(NULL));

    // Implementing Fisher-Yates shuffle
    for (int i = 51; i > 0; --i) {
        int j = rand() % (i + 1);
        Card temp = cards[i];
        cards[i] = cards[j];
        cards[j] = temp;
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