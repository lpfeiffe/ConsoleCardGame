/**
 * @file main.h
 * @author Lucas Pfeiffer
 * @brief 
 * @version 0.1
 * @date 2022-05-31
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>
#include <stdarg.h>
#include <unistd.h>

#include "card.h"
#include "deck.h"
#include "display.h"
#include "blackjack.h"
#include "player.h"

#define ARRAY_SIZE(x) sizeof(x)/sizeof(x[0])

typedef enum GameType
{
    GAME_BLACKJACK = 0,
    GAME_NONE
} GameType_e;

GameType_e DisplayStartScreen(void);

#endif /* MAIN_H */

/*** end of file ***/