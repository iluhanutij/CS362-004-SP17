#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "dominion.c"
#include "rngs.h"

int main()
{	
	printf("Starting the shuffle function test.\n");
	struct gameState state;
	//count of same card positions
	int sameCard = 0;
	//use max cards
	state.deckCount[0] = MAX_DECK;
	
	for (int i = 0; i < MAX_DECK; i++)
		state.deck[0][i] = i;
	//call shuffle
	shuffle(0, &state);
	printf("Start to shuffle the deck.\n");
	 for (int i = 0; i < MAX_DECK; i++)
	 	if (state.deck[0][i] == i)
				  sameCard++;

	assert(sameCard != state.deckCount[0]);
	printf("Passed.\n");
	printf("The number of same card positions is: %d\n", sameCard);
	printf("Function shuffle is working.\n");
}

