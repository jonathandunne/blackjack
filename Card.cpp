#include <cassert>
#include <iostream>
#include <array>
#include "Card.hpp"

using namespace std;

constexpr const char *const RANK_NAMES[] = {
  "Two",   // TWO
  "Three", // THREE
  "Four",  // FOUR
  "Five",  // FIVE
  "Six",   // SIX
  "Seven", // SEVEN
  "Eight", // EIGHT
  "Nine",  // NINE
  "Ten",   // TEN
  "Jack",  // JACK
  "Queen", // QUEEN
  "King",  // KING
  "Ace"    // ACE
};

Rank string_to_rank(const std::string &str) {
  for(int r = TWO; r <= ACE; ++r) {
    if (str == RANK_NAMES[r]) {
      return static_cast<Rank>(r);
    }
  }
  assert(false); // Input string didn't match any rank
  return {};
}

std::ostream & operator<<(std::ostream &os, Rank rank) {
  os << RANK_NAMES[rank];
  return os;
}

std::istream & operator>>(std::istream &is, Rank &rank) {
  string str;
  if(is >> str) {
    rank = string_to_rank(str);
  }
  return is;
}

constexpr const char *const SUIT_NAMES[] = {
  "Spades",   // SPADES
  "Hearts",   // HEARTS
  "Clubs",    // CLUBS
  "Diamonds", // DIAMONDS
};

//REQUIRES str represents a valid suit ("Spades", "Hearts", "Clubs", or "Diamonds")
Suit string_to_suit(const std::string &str) {
  for(int s = SPADES; s <= DIAMONDS; ++s) {
    if (str == SUIT_NAMES[s]) {
      return static_cast<Suit>(s);
    }
  }
  assert(false); // Input string didn't match any suit
  return {};
}

//EFFECTS Prints Suit to stream, for example "Spades"
std::ostream & operator<<(std::ostream &os, Suit suit) {
  os << SUIT_NAMES[suit];
  return os;
}

//REQUIRES If any input is read, it must be a valid suit
//EFFECTS Reads a Suit from a stream, for example "Spades" -> SPADES
std::istream & operator>>(std::istream &is, Suit &suit) {
  string str;
  if (is >> str) {
    suit = string_to_suit(str);
  }
  return is;
}

Card::Card() {
    rank = TWO;
    suit = SPADES;
}

Card::Card(Rank rank_in, Suit suit_in){
   rank = rank_in;
   suit = suit_in;
}

std::ostream & operator<<(std::ostream &os, const Card &card) {
  os << RANK_NAMES[card.get_rank()] << " of " << SUIT_NAMES[card.get_suit()];
  return os;
}

std::istream & operator>>(std::istream &is, Card &card) {
  string of = " of ";
  is >> card.rank >> of >> card.suit;
  return is;
}

Rank Card::get_rank() const{
  return rank;
}

Suit Card::get_suit() const{
  return suit;
}