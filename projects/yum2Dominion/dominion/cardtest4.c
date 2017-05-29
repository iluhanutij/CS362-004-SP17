#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Min Yu
// Assignment 3
// villageCase() test

// This file tests the villageCase() card effect.


int main (int argc, char** argv) {
    printf ("----Testing villageCase()----\n");
    int i, j, k;
    i = j = k = 0;

    int handPos = 0;
    
    // Create a game
    int numPlayers = 2;
    struct gameState G;     // initial state
    struct gameState G2;    // post village card state
    int z[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '15'
    initializeGame(numPlayers, z, 15, &G);
    initializeGame(numPlayers, z, 15, &G2);
    
    // Default whoseTurn
    G.whoseTurn = 0;
    
    // Set village Room card to handPos
    G.hand[G.whoseTurn][handPos] = village;
    
    // Play the card
    villageCase(G.whoseTurn, &G2, handPos);
    
    // TEST 1: Check if player's hand +- 0 cards (-1 from playing village card)
    if (G2.handCount[G.whoseTurn] == G.handCount[G.whoseTurn])
        printf ("Test1 - Players Hand Count: Expected Value: %i || Returned Value: %i === PASSED ===\n", G2.handCount[G.whoseTurn], G.handCount[G.whoseTurn]);
    else
        printf ("Test1 - Players Hand Count: Expected Value: %i || Returned Value: %i === FAILED ===\n", G2.handCount[G.whoseTurn], G.handCount[G.whoseTurn]);
    

    // TEST 2: Check if player's action +2
    if (G2.numActions == G.numActions + 2)
        printf ("Test2 - Player's Actions: Expected Value: %i || Returned Value: %i === PASSED ===\n", G.numActions+2, G2.numActions);
    else
        printf ("Test2 - Player's Actions: Expected Value: %i || Returned Value: %i === FAILED ===\n", G.numActions+2, G2.numActions);
    
    // TEST 3: Check that village card has been discarded
    if (G2.hand[G.whoseTurn][handPos] > -1)
        printf ("Test3 - village card is discarded === PASSED ===\n");
    else
        printf ("Test3 - village card is NOT discarded === FAILED ===\n");
    
    // TEST 4: Check if player's draw pile reduced by 1 cards (deckcount - 1)
    if (G2.deckCount[G.whoseTurn] == (G.deckCount[G.whoseTurn] - 1))
            printf ("Test5 - Player's Draw Deck Reduced: Expected Value: %i || Returned Value: %i === PASSED ===\n", (G.deckCount[G.whoseTurn]-1), G2.deckCount[G.whoseTurn]);
    else
            printf ("Test5 - Player's Draw Deck Reduced: Expected Value: %i || Returned Value: %i === FAILED ===\n", (G.deckCount[G.whoseTurn]-1), G2.deckCount[G.whoseTurn]);

    return 0;
}