#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

//test village card
int main(){
	printf("Start to test Village card.\n");
	struct gameState state;
	int numCard, numAction;
	int kindom[10] = {1,2,3,4,5,6,7,8,9,10};
	initializeGame(3, kindom, 2, &state);
	state.hand[0][0] = 14;
	numCard = state.handCount[0];
	numAction = state.numActions;
	//village is card #14
	playCard(0, 1, 2, 3, &state);
	//draw 1 card and discard 1 card
	printf("Testing the card number and the action.\n");
	assert (state.handCount[0] == numCard );
	assert (state.numActions == numAction + 1);
	printf("Test Passed.\n");
	printf("Card Village is working.\n");
}

