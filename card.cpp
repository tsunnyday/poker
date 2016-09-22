#include "card.h"

Card::Card(Card::Suit s, Card::Rank r)
{
	suit = s;
	rank = r;
}

Card::Suit Card::getSuit()
{
	return suit;
}

Card::Rank Card::getRank()
{
	return static_cast<Card::Rank>(13 - rank);
}

std::string Card::print()
{
	return printRank() + " of " + printSuit();
}

std::string Card::printSuit()
{
	if(suit == Card::Hearts)
	{
		return "Hearts";
	}
	if(suit == Card::Clubs)
	{
		return "Clubs";
	}
	if(suit == Card::Diamonds)
	{
		return "Diamonds";
	}
	if(suit == Card::Spades)
	{
		return "Spades";
	}
}

std::string Card::printRank()
{
	if(rank == Card::A)
	{
		return "Ace";
	}
	if(rank == Card::K)
	{
		return "King";
	}
	if(rank == Card::Q)
	{
		return "Queen";
	}
	if(rank == Card::J)
	{
		return "Jack";
	}
	if(rank == Card::_10)
	{
		return "10";
	}
	if(rank == Card::_9)
	{
		return "9";
	}
	if(rank == Card::_8)
	{
		return "8";
	}
	if(rank == Card::_7)
	{
		return "7";
	}
	if(rank == Card::_6)
	{
		return "6";
	}
	if(rank == Card::_5)
	{
		return "5";
	}
	if(rank == Card::_4)
	{
		return "4";
	}
	if(rank == Card::_3)
	{
		return "3";
	}
	if(rank == Card::_2)
	{
		return "2";
	}
	
	
	
}
