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

#define CARD_VALUE_ACE      "A"
#define CARD_VALUE_TWO      "2"
#define CARD_VALUE_THREE    "3"
#define CARD_VALUE_FOUR     "4"
#define CARD_VALUE_FIVE     "5"
#define CARD_VALUE_SIX      "6"
#define CARD_VALUE_SEVEN    "7"
#define CARD_VALUE_EIGHT    "8"
#define CARD_VALUE_NINE     "9"
#define CARD_VALUE_TEN      "10"
#define CARD_VALUE_JOKER    "J"
#define CARD_VALUE_QUEEN    "Q"
#define CARD_VALUE_KING     "K"

typedef enum Suit
{
    SUIT_SPADE  = 0,
    SUIT_HEART,
    SUIT_DIAMOND,
    SUIT_CLOVER,
    NUM_SUITS
} Card_Suit_e;

/*
    A Card has a value of A, 2 - 10, J, Q, or K
    Value can be a max of 2 characters (for "10")
    Suit corresponds to either spade, heart, diamond, or clover
*/
typedef struct Card
{
    char value[3];
    Card_Suit_e suit;
} Card_t;

#endif /* CARD_H */

/*** end of file ***/