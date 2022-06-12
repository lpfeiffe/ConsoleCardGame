/**
 * @file player.h
 * @author Lucas Pfeiffer
 * @brief Contains all enums, structs, and functions involving a player
 * @version 0.1
 * @date 2022-06-11
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef PLAYER_H
#define PLAYER_H

typedef struct Hand
{
    Card_t card[NUM_CARDS_IN_DECK];
    int numCards;
    int value;
} Hand_t;

typedef struct Player
{
    char * name;
    int balance;
    int wager;
    Hand_t hand;
} Player_t;

#endif /* PLAYER_H */

/*** end of file ***/