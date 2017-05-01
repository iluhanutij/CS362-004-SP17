#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

void testNumHandCards() {
	printf("Starting test numHandCards functions.\n");
	struct gameState state;
	state.numPlayers=2;
/*	state.outpostPlayed=0;
	state.coins=5;
	state.phase=0;
	state.numActions=1;
	state.numBuys=1;
	state.playedCardCount=0;
	state.whoseTurn=0;
*/
	state.handCount[1] = 1;
	state.handCount[2] = 2;
	state.whoseTurn = 1;
	printf("Start to test different turns.\n");
	assert (numHandCards(&state) == 1);
	state.whoseTurn = 2;
	assert (numHandCards(&state) == 2);
	printf("Passed.\n");
	printf("Function numHandCards is working.\n");
}

int main() {
    testNumHandCards();
	return 0;
}

