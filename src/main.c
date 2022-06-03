#include "../inc/main.h"

int main()
{
    Card_t * card = NULL;
    Deck_t * deck = Deck_Initialize();
    int idx = 0;

    Deck_Shuffle(deck);     

    while((card = Deck_RemoveCard(deck)) != NULL)
    {
        printf("idx: %d, suit: %d, value: %s\n", idx++, card->suit, card->value);
    }

    Deck_Destroy(deck);

    return 0;
}