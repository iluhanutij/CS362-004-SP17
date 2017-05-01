#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

//test council room card
int main(){
	printf("Start to test minion card.\n");
	struct gameState state;
	int numCard0, numCard1, numCard2, numCard3, numAct0;
	int kindom[10] = {1,2,3,4,5,6,7,8,9,10};
	initializeGame(4, kindom, 2, &state);
	//player0 get2 2 cards in hand
	state.handCount[0] = 2;
	state.handCount[1] = 2;
	state.handCount[2] = 5;
	//the first card is minion
	state.hand[0][0] = minion;
	//player 0's turn
	state.whoseTurn = 0;
	//card number for 3 players
	numCard0 = state.handCount[0];
	numCard1 = state.handCount[1];
	numCard2 = state.handCount[2];
	numCard3 = state.handCount[3];
	//action of current player
	numAct0 = state.numActions;
	//printf("numCard1 is: %d\n", numCard1 );
	playCard(0, 0, 1, 0, &state);
	//draw 4 card and discard 1 card
	//printf("numCard1 is now: %d\n", state.handCount[1]);
	printf("Testing handCount for player1 choice2 .\n");
	assert (state.handCount[0] == 4);
	printf("Passed.\n");
	printf("Testing handCount for other players, choice2.\n");
	assert (state.handCount[1] == numCard1);
	assert (state.handCount[2] == 4);
	printf("Passed.\n");
	printf ("Testing the number of action.\n");
	assert (numAct0 == state.numActions);
	printf ("Passed.\n");
	printf("Testing coins, choice1.\n");
	state.handCount[0] = 1;
	state.coins = 0;	
	state.hand[0][0] = minion;
	state.whoseTurn = 0;
	playCard(0, 1, 0, 0, &state);
	printf("coins=");
	assert (state.coins == 2);
	printf("Bug found in line 910 of dominion.c.\n");
	//assert (state.numBuys == numBuy + 1);
	printf("Passed.\n");
	printf("Card minion is working.\n");
}

