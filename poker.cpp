#include <iostream>
#include "card.h"
#include "deck.h"
#include "card_functions.h"
#include <vector>

using namespace std;


int main()
{
/*	Deck d;
	d.shuffle();
	vector<Card> h1;
	for(size_t i = 0; i < 5; i++)
	{
		h1.push_back(d.draw());
	}
	*/
	
	
	vector<Card> h1;
	h1.push_back(Card(Card::Hearts, Card::_3));
	h1.push_back(Card(Card::Clubs, Card::_3));
	h1.push_back(Card(Card::Spades, Card::K));
	h1.push_back(Card(Card::Hearts, Card::K));
	h1.push_back(Card(Card::Diamonds, Card::_6));
	vector<Card> h2;
	h2.push_back(Card(Card::Hearts, Card::_2));
	h2.push_back(Card(Card::Clubs, Card::_2));
	h2.push_back(Card(Card::Spades, Card::K));
	h2.push_back(Card(Card::Hearts, Card::K));
	h2.push_back(Card(Card::Diamonds, Card::_6));
	cout << compare_hands(h1, h2) << std::endl;
	
}
