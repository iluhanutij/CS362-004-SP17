#include "assert.h"
#include "dominion.h"
#include "rngs.h"
#include <stdio.h>
#include <stdlib.h>

void testWhoseTurn(){
	printf("Starting the whoseTurn funtion test.\n");
	struct gameState state;
	//initialization
	printf("Start to test different turns.\n");
	state.whoseTurn = 2;
	assert (whoseTurn(&state)==2);
	state.whoseTurn = 0;
	assert (whoseTurn(&state)==0);
	printf("Passed.\n");
	printf("Function whoseTurn is Working.\n");
}
 
int main(){
	testWhoseTurn();
	return 0;	
}

