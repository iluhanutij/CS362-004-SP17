#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("Start to test advanturer card.\n");
	struct gameState state;
	int numCard1, numCard2, numCard3, numBuy;
	int kindom[10] = {1,2,3,4,5,6,7,8,9,10};
	initializeGame(4, kindom, 2, &state);
	state.handCount[0] = 2;
	state.hand[0][0] = 8;
	state.whoseTurn = 0;
	//card number for 3 players
	numCard1 = state.handCount[0];
	numCard2 = state.handCount[2];
	numCard3 = state.handCount[3];
	numBuy = state.numBuys;
	//printf("numCard1 is: %d\n", numCard1 );
	//council is card #8
	playCard(0, 1, 2, 3, &state);
	//draw 4 card and discard 1 card
	//printf("numCard1 is now: %d\n", state.handCount[1]);
	printf("Testing handCount for player 1, 2 and 3.\n");
	assert (state.handCount[0] == numCard1 + 3);
	assert (state.handCount[2] == numCard2 + 1);
	assert (state.handCount[3] == numCard3 + 1);
	printf("Test Passed.\n");
	printf("Testing number of buys.\n");
	assert (state.numBuys == numBuy + 1);
	printf("Test Passed\n");
	printf("Card advanturer is working properly.\n");
}

