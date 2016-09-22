#include "card_functions.h"
#include "card.h"
#include <algorithm>
#include <iostream>

Card get_high_card(std::vector<Card> hand)
{
	Card max = hand.at(0);
	for(Card c: hand)
	{
		if(c.getRank() > max.getRank())
		{
			max = c;
		}
	}
	return max;
}
bool compare_rank(Card a, Card b)
{
	return a.getRank() > b.getRank();
}

bool compare_suit(Card a, Card b)
{
	return a.getSuit() > b.getSuit();
}

std::vector<Card> sort_hand_by_rank(std::vector<Card> hand)
{
	std::sort(std::begin(hand), std::end(hand), compare_rank);
	return hand;
}

std::vector<Card> sort_hand_by_suit(std::vector<Card> hand)
{
	std::sort(std::begin(hand), std::end(hand), compare_suit);
	return hand;
}

std::vector<Card> sort_hand(std::vector<Card> hand)
{
	return sort_hand_by_suit(sort_hand_by_rank(hand));
}

Hand_Type get_hand_type(std::vector<Card> hand)
{
	int flush_flag = 1;
	hand = sort_hand_by_suit(hand);
	if(hand.front().getSuit() != hand.back().getSuit())
	{
		flush_flag = 0;
	}
	int straight_flag = 1;
	hand = sort_hand_by_rank(hand);
	for(int i = 0; i < 4; i++)
	{
		if(hand.at(i+1).getRank()+1 != hand.at(i).getRank())
		{
			
			straight_flag = 0;
			break;
		}
	}
	if(flush_flag && straight_flag)
	{
		return STRAIGHT_FLUSH;
	}
	if(flush_flag)
	{
		return FLUSH;
	}
	if(straight_flag)
	{
		return STRAIGHT;
	}
	std::vector<std::pair<int, Card::Rank>> counts = get_counts(hand);
	
	if(counts.back().first == 4)
	{
		return FOUR;
	}
	if(counts.back().first == 3)
	{
		if(counts.at(counts.size() - 2).first == 2)
		{
			return FULL_HOUSE;
		}
		return THREE;
	}
	if(counts.back().first == 2)
	{
		if(counts.at(counts.size() - 2).first == 2)
		{
			return TWO_PAIR;
		}
		return PAIR;
	}
	return HIGH_CARD;
	
	
	
	
	
}
std::vector<std::pair<int, Card::Rank>> get_counts(std::vector<Card> hand)
{
	hand = sort_hand_by_rank(hand);
	std::vector<std::pair<int, Card::Rank>> counts;
	counts.push_back(std::make_pair(1, hand.front().getRank()));
	int j = 0;
	for(int i = 1; i < 5; i++)
	{
		if(hand.at(i).getRank() == counts.at(j).second)
		{
			counts.at(j).first += 1;
		}
		else
		{
			counts.push_back(std::make_pair(1, hand.at(i).getRank()));
			j += 1;
		}
	}
	std::sort(std::begin(counts), std::end(counts));
	return counts;
}


//Compare two hands
int compare_hands(std::vector<Card> hand_a, std::vector<Card> hand_b)
{
	//First get the rank of each hand. This should take care of most cases.
	Hand_Type t1 = get_hand_type(hand_a);
	Hand_Type t2 = get_hand_type(hand_b);
	if(t1 > t2)
	{
		return -1;
	}
	if(t2 > t1)
	{
		return 1;
	}
	//But if it doesn't, we have to go through and check each rank individually
	hand_a = sort_hand_by_rank(hand_a);
	hand_b = sort_hand_by_rank(hand_b);
	Card::Rank r1;
	Card::Rank r2;
	
	if(t1 == 8 || t1 == 4)
	{
		r1 = hand_a.back().getRank();
		r2 = hand_b.back().getRank();
		if(r1 > r2)
		{
			return -1;
		}
		if(r1 < r2)
		{
			return 1;
		}
		return 0;
	}
	std::vector<std::pair<int, Card::Rank>> c1 = get_counts(hand_a);
	std::vector<std::pair<int, Card::Rank>> c2 = get_counts(hand_b);
	for(int i = c1.size()-1; i >= 0; i--)
	{
		if(c1.at(i).second > c2.at(i).second)
		{
			return -1;
		}
		if(c1.at(i).second < c2.at(i).second)
		{
			return 1;
		}
	}
	return 0;
	
}
