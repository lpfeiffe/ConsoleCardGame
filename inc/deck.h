/**
 * @file deck.h
 * @author Lucas Pfeiffer
 * @brief Contains all enums, structs, and functions involving decks
 * @version 0.1
 * @date 2022-06-02
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef DECK_H
#define DECK_H

#include "card.h"

#define NUM_CARDS_IN_DECK   52

typedef struct Deck
{
    Card_t card[NUM_CARDS_IN_DECK];
    int currentCard;
} Deck_t;

Deck_t * Deck_Initialize(void);
void Deck_Shuffle(Deck_t * deck);
bool Deck_IsEmpty(Deck_t * deck);
Card_t * Deck_Peek(Deck_t * deck);
Card_t * Deck_RemoveCard(Deck_t * deck);
void Deck_Destroy(Deck_t * deck);

#endif /* DECK_H */

/*** end of file ***/