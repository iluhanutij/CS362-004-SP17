#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

void testIsGameOver() {
	printf("Testing function: isGameOver.\n"); 	
    struct gameState state;
	int i=0;
	//initial state
/*	state.numPlayers=2;
	state.outpostPlayed=0;
	state.coins=5;
	state.phase=0;
	state.numActions=1;
	state.numBuys=1;
	state.playedCardCount=0;
	state.whoseTurn=0;
*/
	for (i=0; i<25; i++){
		state.supplyCount[i] = 1;
	}
	// Check case if game is over
	printf("Checking the over state.\n"); 
    state.supplyCount[province] = 0;
    assert (isGameOver(&state) == 1);
	printf("Passed.\n");
	// Check case if game still ongoing
	printf("Checking the ongoing state\n"); 
	state.supplyCount[province] = 3;
	assert (isGameOver(&state) == 0);
	for (i=0; i<3; i++){
		state.supplyCount[i] = 0;
	}
	assert (isGameOver(&state) == 1);
	printf("TEST SUCCESSFULLY COMPLETED\n");
	printf("Function isGameOver is Working properly\n");

}

int main() {
	testIsGameOver();
	return 0;
}

