/**
 * @file card.h
 * @author Lucas Pfeiffer
 * @brief Contains all enums, structs, and functions involving cards
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef CARD_H
#define CARD_H

#define NUM_CARD_VALUES     13

typedef enum Suit
{
    SUIT_SPADE  = 0,
    SUIT_HEART,
    SUIT_DIAMOND,
    SUIT_CLOVER,
    NUM_SUITS
} Card_Suit_t;

/*
    A Card has a value of A, 2 - 10, J, Q, or K
    Value can be a max of 2 characters (for "10")
    Suit corresponds to either spade, heart, diamond, or clover
*/
typedef struct Card
{
    char value[3];
    Card_Suit_t suit;
} Card_t;

#endif /* CARD_H */

/*** end of file ***/