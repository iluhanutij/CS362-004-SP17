#include "dominion.h"
#include "headers.h"
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "assert.c"

#define MAX_TESTS 2058

//This randomly tests village




int main() {
	//no villiage in this array
	int k[10] = {adventurer, gardens, embargo, duchy, minion, mine, cutpurse, sea_hag, tribute, smithy};

	int i, test, players, player, seed;
	//struct gameState state;
	struct gameState state1,state2;
	//for error print
	char errorMessage[128];
	srand(time(NULL));
	//where the village card on hand position
	int villageHandpo;
	//announcement 
	printf("This is Random Card Test for Village.\n");
	printf("Test 1 for draw one card and discard 1 card.\n");
	printf("Test 2 for +2 Actions.\n");
	printf("Test 3 for discard card villoage from hand.\n");
	printf("Running Test......\n");
	//for each test 
	for (test = 0; test < MAX_TESTS; test++) {
		//create 2 players
		players = (rand() % 3) + 2;
		//pick random seedv
		seed = rand();		

		/******************Initialization part**********************************/
		//check initilization
		sprintf(errorMessage, "Initialize is Fail on test #%d\n", test);
		assert(initializeGame(players, k, seed, &state1) == 0, errorMessage);
		
		player = rand() % players;
		//Initiate valid state1 variables
		//Pick random deck size out of MAX DECK size
		state1.deckCount[player] = (rand() % (MAX_DECK - 1)) + 1;		
		state1.discardCount[player] = (rand() % (MAX_DECK - 1)) + 1;
		state1.handCount[player] = (rand() % (MAX_HAND - 1)) + 1;
		
		//put this player's turn
		state1.whoseTurn = player;

		//give random deck to the random player
		for (i = 0; i < state1.deckCount[player]; i++) {
			state1.deck[player][i] = k[rand() % 10];
		}
		
		//give random hand cards
		for (i = 0; i < state1.handCount[player]; i++) {
			state1.hand[player][i] = k[rand() % 10];
		}

		//give random discard card
		//check discard is greate than hand cards
		while (state1.discardCount[player] >= state1.handCount[player]){
			state1.discardCount[player] --;
		}

		for (i = 0; i < state1.discardCount[player]; i++) {
			state1.discard[player][i] = k[rand() % 10];
		}
		
		//put a village card on this player
		villageHandpo = rand() % state1.handCount[player];
		state1.hand[player][villageHandpo] = village;
		
		//copy this state, state 2 is after play village card
		state2 = state1;
		sprintf(errorMessage, "Card effect function fail on test #%d\n", test);
		assert(cardEffect(village, 0, 0, 0, &state2, villageHandpo, 0) == 0, errorMessage);		
		
		//test card +1 and discards -1 effect 
		sprintf(errorMessage, "Draw one card file on test #%d\n", test);
		assert(state2.handCount[player] == state1.handCount[player], errorMessage);
		//printf("%d\n%d\n",state2.handCount[player],state1.handCount[player]);

		//test action +2 effect
		sprintf(errorMessage, "Action +2 Fail on test #%d\n", test);
		assert(state2.numActions == state1.numActions + 2, errorMessage);
		//check if no card called village
		for (i = 0; i < state2.handCount[player]; i++){
			sprintf(errorMessage, "Didn't discard village on test #%d\n", test);
			//printf("the card is:%d\n", state2.hand[player][i] );//debug
			assert(state2.hand[player][i] != 14, errorMessage);
		}
	}//end of test loop
		
	printf("Test passed.\n");
	return 0;
}

