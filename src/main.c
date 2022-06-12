#include "../inc/main.h"

static bool isGameValid(GameType_e game)
{
    return (game < GAME_NONE);
}

GameType_e DisplayStartScreen(void)
{
    GameType_e game;
    
    ClearScreen();

    printf(SCREEN_DIVIDER);

    printf(MAG "Welcome to Console Card Game!\n\n" RESET);
    printf("Please select a card game to play by typing in\nthe corresponding number next to the game\nof your choice followed by ENTER.\n\n");
    printf("For the best experience, please increase\nyour terminal window size.\n\n");
    printf("To close the game, press CTRL+C\n\n");
    printf(CYN "0 - Blackjack\n" RESET);

    printf(SCREEN_DIVIDER);

    while(!GetUserFormattedInput(NULL, "%u", 1, &game) || !(isGameValid(game)))
    {
        printf("Game not recognized. Please enter an option from the list above.\n");
    }

    return game;
}

int main()
{
    GameType_e game = DisplayStartScreen();

    switch (game)
    {
        case GAME_BLACKJACK :
            Blackjack_Game();
            break;
        default :
            break;
    }

    return 0;
}

