#include "card.h"
#include <vector>
#include <random>
#include <algorithm>


#ifndef DECK_H
#define DECK_H



class Deck
{
	private:
		std::vector<Card> cards;
			
	public:
		Deck();
		void shuffle();
		Card draw();
		void printDeck();


};

#endif 
