#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Min Yu
// Assignment 3
// Unit test 1

// tests the HandCard() function in dominion.c. Purpose is to see if the
// function returns the card to player based on the hand position.

int testHandCard(int handPos, struct gameState *state) {
	
    int correctCard = state->hand[state->whoseTurn][handPos];
	int playerCard = 0;
	playerCard = handCard(handPos, state);

	// TEST 1: return card is not NULL
	if (!playerCard) {
		printf("Test1: FAILED\n");
	} else {
		printf("Test1: PASSED\n");
	}

	// TEST 2: return card is correct card
	if (correctCard != playerCard) {
		printf("Test2: FAILED\n");
	} else {
		printf("Test2: PASSED\n");
	}
	return 0;

}

int main (int argc, char** argv) {
    printf ("----Testing handCount() function----\n");
    // Create a game
    int p, c;
    int numPlayers = 2;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '15'
    initializeGame(numPlayers, k, 15, &G);
    
    // Default Player
    G.whoseTurn = 0;
    
    // For each player
    for (p = 0; p < numPlayers; p++) {
        printf("Player %i:\n", p + 1);
        // For each card in the player's hand
        for (c = 0; c < G.handCount[p]; c++) {
            printf("Card %i:\n", c + 1);
            // Test handCard()
            testHandCard(c, &G);
        }
        endTurn(&G);
    }
    return 0;
}