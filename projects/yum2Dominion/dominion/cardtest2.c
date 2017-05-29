#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Min Yu
// Assignment 3
// adventurerCard() test

// This file tests the adventurerCard() card effect.

int main (int argc, char** argv) {
    printf ("----Testing adventurerCard()----\n");
    int initialHandCount, initialDeckCount, z, cardDrawn;
    z = 0;
    cardDrawn = 0;
    int drawnTreasure = 0;
    int temphand[MAX_HAND];
    int handPos = 0;
    
    // Create a game
    int numPlayers = 2;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '10'
    initializeGame(numPlayers, k, 15, &G);

    // Get before metrics:
    initialHandCount = G.handCount[G.whoseTurn];
    initialDeckCount = G.deckCount[G.whoseTurn];
    
    // Default current player
    G.whoseTurn = 0;
    
    // Set Adventurer card to handPos
    G.hand[G.whoseTurn][handPos] = adventurer;
    
    // Play the card
    adventurerCase(drawnTreasure, &G, G.whoseTurn, z, temphand, cardDrawn);
    
    // TEST 1: Check that handCount has 2 additional cards
    if (G.handCount[G.whoseTurn] == initialHandCount + 2)
        printf ("Test1 - Check players hand count increment: Expected Value: %i || Returned Value: %i === PASSED ===\n", initialHandCount+2, G.handCount[G.whoseTurn]);
    else
        printf ("Test1 - Check players hand count increment: Expected Value: %i || Returned Value: %i === FAILED ===\n", initialHandCount+2, G.handCount[G.whoseTurn]);
    // TEST 2: Check that all drawn cards are treasure cards
    int i;
    for (i = 0; i < 2; i++){
        if (G.hand[G.whoseTurn][G.handCount[G.whoseTurn] - 1 - i] == copper ||
            G.hand[G.whoseTurn][G.handCount[G.whoseTurn] - 1 - i] == silver ||
            G.hand[G.whoseTurn][G.handCount[G.whoseTurn] - 1 - i] == gold)
            printf ("Test2 - card%i is Treasure card === PASSED ===\n", i+1);
        else
            printf ("Test2-  card%i is NOT Treasure card === FAILED ===\n", i+1);
    }
    
    // TEST 3: Check that the deckcount decreased by at least 2
    if (G.deckCount[G.whoseTurn] <= (initialDeckCount - 2))
        printf ("Test3 - Deck count decreased by least 2: Expected Value: > 2 || Returned Value: %i === PASSED ===\n", (initialDeckCount-G.deckCount[G.whoseTurn]));
    else
        printf ("Test3 - Deck count decreased by least 2: Expected Value: > 2 || Returned Value: %i === FAILED ===\n", (initialDeckCount-G.deckCount[G.whoseTurn]));
    
    return 0;
}