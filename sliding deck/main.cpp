#include "ppt.h"

int main()
{
    list<Deck> deck1;               //creating decks
    list<Deck> deck2;

    deck1 = addSlides1(deck1);       //adding slides to deck
    deck2 = addSlides2(deck2);

    displayAll(&deck1, &deck2);               //displaying both decks one by one
    displayAll(&deck2, &deck1);

    return 0;
}