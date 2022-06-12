#include "../inc/main.h"

static char * cardValues[NUM_CARD_VALUES] = {
    CARD_VALUE_ACE, CARD_VALUE_TWO, CARD_VALUE_THREE,
    CARD_VALUE_FOUR, CARD_VALUE_FIVE, CARD_VALUE_SIX, 
    CARD_VALUE_SEVEN, CARD_VALUE_EIGHT, CARD_VALUE_NINE,
    CARD_VALUE_TEN, CARD_VALUE_JOKER, CARD_VALUE_QUEEN,
    CARD_VALUE_KING
};

Deck_t * Deck_Initialize(void)
{
    Deck_t * deck = (Deck_t *) malloc(sizeof(Deck_t));

    int cardIdx = 0;

    for (int i = 0; i < NUM_SUITS; i++)
    {
        for (int j = 0; j < NUM_CARD_VALUES; j++)
        {
            cardIdx = (i * NUM_CARD_VALUES) + j;
            deck->card[cardIdx].suit = i;
            strcpy(deck->card[cardIdx].value, cardValues[j]);
        }
    }

    Deck_Shuffle(deck);

    deck->currentCard = 0;

    return deck;
}

void Deck_Shuffle(Deck_t * deck)
{
    /*
    Implementing Fisher-Yates shuffling algorithm:
    https://stackoverflow.com/questions/42321370/fisher-yates-shuffling-algorithm-in-c
    */
    
    Card_t tmpCard = {0};
    int j = 0;
    srand(time(NULL));

    for (int i = NUM_CARDS_IN_DECK - 1; i > 0; i--)
    {
        j = rand() % (i + 1);
        tmpCard = deck->card[j];
        deck->card[j] = deck->card[i];
        deck->card[i] = tmpCard;
    }
}

bool Deck_IsEmpty(Deck_t * deck)
{
    return (deck->currentCard < 0);
}

Card_t * Deck_Peek(Deck_t * deck)
{
    return (Deck_IsEmpty(deck)) ? NULL : &(deck->card[deck->currentCard]);
}

Card_t * Deck_RemoveCard(Deck_t * deck)
{
    Card_t * card = NULL;

    if (Deck_IsEmpty(deck))
    {
        return NULL;
    }

    card = &(deck->card[deck->currentCard]);

    if (++(deck->currentCard) == NUM_CARDS_IN_DECK)
    {
        //All cards have been removed from the deck
        //therefore we need to invalidate the currentCard
        //index to prevent buffer overflows
        deck->currentCard = -1;
    }

    return card;
}

void Deck_Destroy(Deck_t * deck)
{
    free(deck);
}