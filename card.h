#ifndef CARD_H
#define CARD_H
#include <string>

class Card
{
	public:
		enum Suit{Hearts, Diamonds, Clubs, Spades};
		enum Rank{A, K, Q, J, _10, _9, _8, _7, _6, _5, _4, _3, _2};
		Card(Suit s, Rank r);
		Suit getSuit();
		Rank getRank();
		std::string printSuit();
		std::string printRank();
		std::string print();
	private:
		Suit suit;
		Rank rank;
	
	
};


#endif 
