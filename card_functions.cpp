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
	for(Card c: hand)
	{
		std::cout << c.getRank() << std::endl;
	}
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
