#include <vector>
#include "card.h"

#ifndef CARD_FUNCTIONS_H
#define CARD_FUNCTIONS_H

enum Hand_Type{HIGH_CARD, PAIR, TWO_PAIR, THREE, STRAIGHT, FLUSH, FULL_HOUSE, FOUR, STRAIGHT_FLUSH};

int compare_hands(std::vector<Card> hand1, std::vector<Card> hand2);
Hand_Type get_hand_type(std::vector<Card> hand);
Card get_high_card(std::vector<Card> hand);
std::vector<Card> sort_hand(std::vector<Card> hand);
std::vector<Card> sort_hand_by_rank(std::vector<Card> hand);
std::vector<Card> sort_hand_by_suit(std::vector<Card> hand);
bool compare_rank(Card a, Card b);
bool compare_suit(Card a, Card b);

#endif
