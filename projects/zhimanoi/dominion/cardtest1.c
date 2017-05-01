#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

//test smithy card
int main(){
	printf("Start to test Smithy.\n");
	struct gameState state;
	int numCard;
	int kindom[10]={1,2,3,4,5,6,7,8,9,10};
	initializeGame(3, kindom, 2, &state);
	state.hand[0][0] = 13;
	numCard = state.handCount[0];
	//smithy is card #13
	playCard(0, 1, 2, 3, &state);
	//draw 3 cards and discard 1 card
	printf("Testing the card number.\n");
	assert (state.handCount[0] == numCard + 2);
	printf("Test Passed.\n");
	printf("Card Smithy is working.\n");
}

