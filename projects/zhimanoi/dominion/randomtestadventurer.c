#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "my_assert.h"
#include <time.h>

#define MAX_TESTS 100

//This randomly tests Adventurer

int main() {

	  int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, 
	       sea_hag, tribute, smithy};

	  int i, j, n, players, player, handCount, deckCount, seed, address, drawncard;
	  //struct gameState state;
	  struct gameState state;
	  struct gameState stat;
	  struct gameState sta;
	 
	  srand(time(NULL));


	  printf("Running Random Adventurer Test\n");

	  /*
										--- Author's Note ---
	  So, I had problems running out of memory when I used the same gameState variable more than 12 times, and
	  I honestly don't know why. I momentarily solved this problem by adding more for loops and creating more gamestates;
	  I was still able to get decent coverage, though not up to the amount of tests I originally had in mind.

	  */

	  for (i = 0; i < MAX_TESTS; i++) {

		 players = (rand()%3) + 2;

		 seed = rand();		//pick random seed
		      
		 initializeGame(players, k, seed, &state);	//initialize Gamestate 

		 //Initiate valid state variables
	   
	  	  player = state.whoseTurn; 
		  state.deckCount[player] = rand() % (MAX_DECK/3); //Pick random deck size out of MAX DECK size
		  state.discardCount[player] = rand() % (MAX_DECK/3);
		  state.handCount[player] = rand() % (MAX_HAND/3);


		  //Copy state variables
		  handCount = state.handCount[player];
		  deckCount = state.deckCount[player];

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			state.deckCount[player] = 0;
		  }
		  cardEffect(adventurer, 1, 1, 1, &state,0,0);		//Run adventurer card

		  //Test that handCount got two extra cards
		  printf("Test Handcount incremented by two: ");
		  _assert(handCount+2 == state.handCount[player]);

		  //Test that the top two cards are treasure cards
		  drawncard = state.hand[player][state.handCount[player]-2];
		  printf("%d .. Test carddrawn1 is valid: ",i+1);
		  _assert(drawncard == copper || drawncard == silver || drawncard == gold);

		  drawncard = state.hand[player][state.handCount[player]-1];
		  printf("%d .. Test carddrawn2 is valid: ",i+1);
		  _assert(drawncard == copper || drawncard == silver || drawncard == gold);
	  }
	  
	   for (i = 0; i < MAX_TESTS; i++) {

  		  players = rand() % 4;
		  seed = rand();		//pick random seed
		
		  initializeGame(players, k, seed, &stat);	//initialize Gamestate

		  //Initiate valid state variables
	  	  player = stat.whoseTurn; 
		  stat.deckCount[player] = rand() % (MAX_DECK/3); //Pick random deck size out of MAX DECK size
		  stat.discardCount[player] = rand() % (MAX_DECK/3);
		  stat.handCount[player] = rand() % (MAX_HAND/3);


		  //Copy state variables
		  handCount = stat.handCount[player];
		  deckCount = stat.deckCount[player];

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			stat.deckCount[player] = 0;
		  }

		  cardEffect(adventurer, 1, 1, 1, &stat,0,0);		//Run adventurer card

		  printf("Test Handcount incremented by two: ");
		  _assert(handCount+2 == stat.handCount[player]);

		  drawncard = stat.hand[player][stat.handCount[player]-2];
		  printf("%d .. Test carddrawn1 is valid: ",i+1);
		  _assert(drawncard == copper || drawncard == silver || drawncard == gold);

		  drawncard = stat.hand[player][stat.handCount[player]-1];
		  printf("%d .. Test carddrawn2 is valid: ",i+1);
		  _assert(drawncard == copper || drawncard == silver || drawncard == gold);

	  }

	   for (i = 0; i < MAX_TESTS; i++) {

  		  players = rand() % 4;
		  seed = rand();		//pick random seed
		
		  initializeGame(players, k, seed, &sta);	//initialize Gamestate

		  //Initiate valid state variables
	  	  player = sta.whoseTurn; 
		  sta.deckCount[player] = rand() % (MAX_DECK/3); //Pick random deck size out of MAX DECK size
		  sta.discardCount[player] = rand() % (MAX_DECK/3);
		  sta.handCount[player] = rand() % (MAX_HAND/3);


		  //Copy state variables
		  handCount = sta.handCount[player];
		  deckCount = sta.deckCount[player];

		  //1 in 3 chance of making empty deck for coverage
		  if (seed % 3 == 0) {

			sta.deckCount[player] = 0;
		  }
		  cardEffect(adventurer, 1, 1, 1, &sta,0,0);		//Run adventurer card

		  printf("Test Handcount incremented by two: ");
		  _assert(handCount+2 == sta.handCount[player]);

		  drawncard = sta.hand[player][sta.handCount[player]-2];
		  printf("%d .. Test carddrawn1 is valid: ",i+1);
		  _assert(drawncard == copper || drawncard == silver || drawncard == gold);

		  drawncard = sta.hand[player][sta.handCount[player]-1];
		  printf("%d .. Test carddrawn2 is valid: ",i+1);
		  _assert(drawncard == copper || drawncard == silver || drawncard == gold);
	   }

	  printf("Tests Complete\n");

	  return 0;
}
