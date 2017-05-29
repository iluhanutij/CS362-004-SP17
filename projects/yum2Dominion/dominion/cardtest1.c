#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Min Yu
// Assignment 3
// smithyCard() test

// This file tests the smithyCard() card effect.

int main (int argc, char** argv) {
    printf ("----Testing smithyCard()----\n");
    // Create a game
    int handCount, otherPlayerHandCount;
    int i = 0;
    int numPlayers = 2;
    int handPos = 0;
    struct gameState G;
    
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '10'
    initializeGame(numPlayers, k, 10, &G);
    
    
    // Get hand count for hand count for test
    handCount = G.handCount[G.whoseTurn];
    
    // Get other player's hand count for test
    otherPlayerHandCount = G.handCount[1];
    
    // Default current player
    G.whoseTurn = 0;
    
    // Set Smith card to handPos
    G.hand[G.whoseTurn][handPos] = smithy;
    
    // Play the card
    smithyCase(i, G.whoseTurn, &G, handPos);
    
    // TEST 1: Add net of 2 cards to the player's hand (-1 from smithy card being played)
    if (G.handCount[G.whoseTurn] < (handCount + 2) || G.handCount[G.whoseTurn] > (handCount + 2))
        printf ("Test1 - +3 Cards to Players hand: Expected Value: %i || Returned Value: %i === FAILED ===\n", (handCount+2), G.handCount[G.whoseTurn]);
    else
        printf ("Test1 - +3 Cards to Players hand: Expected Value: %i || Returned Value: %i === PASSED ===\n", (handCount+2), G.handCount[G.whoseTurn]);

    // TEST 2: Check remaining player's hand
    if(G.handCount[1] == otherPlayerHandCount)
        printf ("Test2 - See if other players hand remains same. Expected Value: 0 || Returned Value: %i === PASSED ===\n", otherPlayerHandCount);
    else
        printf ("Test2 - See if other players hand remains same. Expected Value: 0 || Returned Value: %i === FAILED ===\n", otherPlayerHandCount);
    
    // TEST 3: Discard
    if(G.hand[G.whoseTurn][handPos] > -1)
        printf ("Test3 - Smithy card discarded === PASSED ===\n");
    else
        printf ("Test3 - Smithy card discarded === FAILED ===\n");
 
    return 0;
    
}