#include "deck.h"
#include "card.h"
#include <iostream>
#include <random>
#include <algorithm>



Deck::Deck()
{
	for(int i = Card::Hearts; i <= Card::Spades; ++i)
	{
		for(int j = Card::A; j <= Card::_2; ++j)
		{
			cards.push_back(Card(static_cast<Card::Suit>(i), static_cast<Card::Rank>(j)));
		}
	}
	srand(time(NULL));
}


void Deck::printDeck()
{
	for(Card c: cards)
	{
		std::cout << c.print() << std::endl;
		
	}
	
	
	
}

void Deck::shuffle()
{
	std::random_shuffle(std::begin(cards), std::end(cards));
}

Card Deck::draw()
{
	Card tmp = cards.back();
	cards.pop_back();
	return tmp;
	
}
