/**
 * @file blackjack.h
 * @author Lucas Pfeiffer
 * @brief Contains all enums, structs, and functions involving the game blackjack
 * @version 0.1
 * @date 2022-06-05
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef BLACKJACK_H
#define BLACKJACK_H

#define BLACKJACK_VALUE     21
#define DEALER_STAND_VALUE  17

#define FACE_CARD_VALUE     10
#define ACE_CARD_VALUE_HIGH 11
#define ACE_CARD_VALUE_LOW  1

#define USER_DECISION_STAND         's'
#define USER_DECISION_HIT           'h'
#define USER_DECISION_DOUBLE_DOWN   'd'
#define USER_DECISION_SPLIT         'p'
#define USER_DECISION_SURRENDER     'r'

void Blackjack_Game(void);

#endif /* BLACKJACK_H */

/*** end of file ***/