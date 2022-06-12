#include "../inc/main.h"

static bool isAce(char * value)
{
   return !strcmp(value, CARD_VALUE_ACE);
}

static bool isFace(char * value)
{
   return (!strcmp(value, CARD_VALUE_JOKER) ||
           !strcmp(value, CARD_VALUE_QUEEN) ||
           !strcmp(value, CARD_VALUE_KING));
}

static int getWager(void)
{
   int wager = 0;
   while(!GetUserFormattedInput("Please place a wager: ", "%u", 1, &wager))
   {
      printf("You must enter a valid wager.\n");
   }
   return wager;
}

static bool dealCards(Player_t * player, Deck_t * deck, int numCards)
{
   Card_t * tmpCard = NULL;
   int cardsInHand = player->hand.numCards;

   if (((deck->currentCard + numCards) >= NUM_CARDS_IN_DECK) ||
       ((player->hand.numCards + numCards) > NUM_CARDS_IN_DECK))
      return false;

   for (int i = cardsInHand; i < (cardsInHand + numCards); i++)
   {
      tmpCard = Deck_RemoveCard(deck);
      player->hand.card[i].suit = tmpCard->suit;
      strcpy(player->hand.card[i].value, tmpCard->value);
      player->hand.numCards++;
   }

   return true;
}

static int calculateHandValue(Player_t * player)
{
   int numAces = 0;
   player->hand.value = 0;

   for (int i = 0; i < player->hand.numCards; i++)
   {
      if (isAce(player->hand.card[i].value))
      {
         player->hand.value += ACE_CARD_VALUE_HIGH;
         numAces++;
      }
      else if (isFace(player->hand.card[i].value))
      {
         player->hand.value += FACE_CARD_VALUE;
      }
      else
      {
         player->hand.value += atoi(player->hand.card[i].value);
      }
   }   

   if (numAces > 0)
   {
      for(int i = numAces; i > 0; i--)
      {
         if (player->hand.value > BLACKJACK_VALUE)
         {
            //Since counting an Ace as 11 caused the player to bust,
            //we will count the Ace as a 1
            player->hand.value -= ACE_CARD_VALUE_HIGH;
            player->hand.value += ACE_CARD_VALUE_LOW;
         }
      }
   }

   return player->hand.value;
}

static void printHand(Hand_t * hand)
{
   int i = 0;

   //print top line
   for (i = 0; i < hand->numCards; i++)
   {
      printf("------------");
      printf(" ");
   }
   printf("\n");

   //print second line with numbers
   for (i = 0; i < hand->numCards; i++)
   {
      if (strlen(hand->card[i].value) > 1)
         printf("| %s    %s |", hand->card[i].value, hand->card[i].value);
      else
         printf("| %s      %s |", hand->card[i].value, hand->card[i].value); 
      printf(" ");
   }
   printf("\n");

   //print third line
   for (i = 0; i < hand->numCards; i++)
   {
      printf("|          |");
      printf(" ");
   }
   printf("\n");

   //print fourth line
   for (i = 0; i < hand->numCards; i++)
   {
      printf("|          |");
      printf(" ");
   }
   printf("\n");

   //print fifth line
   for (i = 0; i < hand->numCards; i++)
   {
      if (strlen(hand->card[i].value) > 1)
         printf ("|    %s    |", hand->card[i].value);
      else
         printf ("|    %s     |", hand->card[i].value);
      printf(" ");
   }
   printf("\n");   

   //print sixth line
   for (i = 0; i < hand->numCards; i++)
   {
      printf("|          |");
      printf(" ");
   }
   printf("\n");

   //print seventh line
   for (i = 0; i < hand->numCards; i++)
   {
      printf("|          |");
      printf(" ");
   }
   printf("\n");

   //print eigth line with numbers
   for (i = 0; i < hand->numCards; i++)
   {
      if (strlen(hand->card[i].value) > 1)
         printf("| %s    %s |", hand->card[i].value, hand->card[i].value);
      else
         printf("| %s      %s |", hand->card[i].value, hand->card[i].value); 
      printf(" ");
   }
   printf("\n");

   //print bottom line
   for (i = 0; i < hand->numCards; i++)
   {
      printf("------------");
      printf(" ");
   }
   printf("\n");
}

static void updateTable(Player_t * player, Player_t * dealer)
{
   ClearScreen();

   printf(SCREEN_DIVIDER);
   printf(MAG "You are playing Blackjack!\n\n" RESET);

   printf("Dealer's Hand (value: %d)\n", calculateHandValue(dealer));
   printHand(&dealer->hand);
   printf("\n\n");

   printf("Your Hand (value: %d)\n", calculateHandValue(player));
   printHand(&player->hand);
   printf("\n");

   printf(SCREEN_DIVIDER);
}

static int displayWagerScreen(void)
{
   int wager = 0;

   ClearScreen();

   printf(SCREEN_DIVIDER);
   printf(MAG "Welcome to Blackjack!\n\n" RESET);

   wager = getWager();

   printf("\nThe dealer will now deal two cards to you and one for themselves...\n\n");
   printf(SCREEN_DIVIDER);

   sleep(2);

   return wager;
}

void Blackjack_Game(void)
{
   Deck_t * deck = Deck_Initialize();

   Player_t player = {
      .name = "Player",
      .balance = 50,
      .wager = 0,
      .hand.numCards = 0,
      .hand.value = 0
   };
   Player_t dealer = {
      .name = "Dealer",
      .balance = 0,
      .wager = 0,
      .hand.numCards = 0,
      .hand.value = 0
   };

   char userDecision = USER_DECISION_STAND;

   player.wager = displayWagerScreen();

   dealCards(&player, deck, 2);
   dealCards(&dealer, deck, 1);

   updateTable(&player, &dealer);

   while (player.hand.value < BLACKJACK_VALUE)
   {
      printf("\nWould you like to stand (s) or hit (h)?\n");

      GetUserFormattedInput(NULL, "%c", 1, &userDecision);

      if (userDecision == USER_DECISION_HIT)
      {
         //Give the user another card
         dealCards(&player, deck, 1);
         updateTable(&player, &dealer);
      }
      else
         break;
   }

   printf("\nThe dealer will now draw another card.\n");
   dealCards(&dealer, deck, 1);
   updateTable(&player, &dealer);

   if (player.hand.value < BLACKJACK_VALUE)
   {
      while (dealer.hand.value < DEALER_STAND_VALUE)
      {
         //Give the dealer another card
         dealCards(&dealer, deck, 1);
         updateTable(&player, &dealer);
         sleep(1);
      }
   }

   printf("Your hand value: %d\nThe dealer hand value: %d\n", player.hand.value, dealer.hand.value);
   printf("\n");

   if (player.hand.value > BLACKJACK_VALUE)
   {
      printf(RED "You busted and lost!\n" RESET);
   }
   else if (dealer.hand.value > BLACKJACK_VALUE)
   {
      printf(GRN "The dealer busted! You won!\n" RESET);
   }
   else if (dealer.hand.value > player.hand.value)
   {
      printf(RED "The dealer's hand is better than yours, you lost!\n" RESET);
   }
   else if (dealer.hand.value == player.hand.value)
   {
      printf(GRN "Tie! No win or loss.\n" RESET);
   }
   else
   {
      printf(GRN "Congratulations! You won!\n" RESET);
   }
   
   printf(SCREEN_DIVIDER);

   Deck_Destroy(deck);
}