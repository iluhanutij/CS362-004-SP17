#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Min Yu
// Assignment 3
// councilRoomCard() test

// This file tests the councilRoomCard() card effect.


int main (int argc, char** argv) {
    printf ("----Testing councilRoomCard()----\n");
    int i, j, k;
    i = j = k = 0;

    int handPos = 0;
    
    // Create a game
    int numPlayers = 2;
    struct gameState G;     // initial state
    struct gameState G2;    // post council_room card state
    int z[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '10'
    initializeGame(numPlayers, z, 15, &G);
    initializeGame(numPlayers, z, 15, &G2);
    
    // Default whoseTurn
    G.whoseTurn = 0;
    
    // Set Council Room card to handPos
    G.hand[G.whoseTurn][handPos] = council_room;
    
    // Play the card
    councilRoomCase(i, G.whoseTurn, &G2, handPos);
    
    // TEST 1: Check if player's hand == +3 cards (-1 from playing council_room card)
    if (G2.handCount[G.whoseTurn] == G.handCount[G.whoseTurn] + 3)
        printf ("Test1 - Players Hand Count: Expected Value: %i || Returned Value: %i === PASSED ===\n", G2.handCount[G.whoseTurn], G.handCount[G.whoseTurn] + 3);
    else
        printf ("Test1 - Players Hand Count: Expected Value: %i || Returned Value: %i === FAILED ===\n", G2.handCount[G.whoseTurn], G.handCount[G.whoseTurn] + 3);
    

    // TEST 2: Check if player's buy +1
    if (G2.numBuys == G.numBuys + 1)
        printf ("Test2 - Player's Buy: Expected Value: %i || Returned Value: %i === PASSED ===\n", G.numBuys+1, G2.numBuys);
    else
        printf ("Test2 - Player's Buy: Expected Value: %i || Returned Value: %i === FAILED ===\n", G.numBuys+1, G2.numBuys);
    
    // TEST 3: Check if other players gain +1 card
    for (j = 1; j < numPlayers; j++)
        if (G2.handCount[j] == (G.handCount[j] + 1))
            printf ("Test3 - Other Players Hand Count: Player %i. Expected Value: %i || Returned Value: %i === PASSED ===\n", j, G.handCount[j] + 1, G2.handCount[j]);
        else
            printf ("Test3 - Other Players Hand Count: Player %i. Expected Value: %i || Returned Value: %i === FAILED ===\n", j, G.handCount[j] + 1, G2.handCount[j]);
    
    // TEST 4: Check that council_room card has been discarded
    if (G2.hand[G.whoseTurn][handPos] > -1)
        printf ("Test4 - Council Room card is discarded === PASSED ===\n");
    else
        printf ("Test4 - Council Room card is NOT discarded === FAILED ===\n");
    
    
    // TEST 5: Check if player's draw pile reduced by 4 cards (deckcount - 4)
    if (G2.deckCount[G.whoseTurn] == (G.deckCount[G.whoseTurn] - 4))
            printf ("Test5 - Player's Draw Deck Reduced: Expected Value: %i || Returned Value: %i === PASSED ===\n", (G.deckCount[G.whoseTurn]-4), G2.deckCount[G.whoseTurn]);
    else
            printf ("Test5 - Player's Draw Deck Reduced: Expected Value: %i || Returned Value: %i === FAILED ===\n", (G.deckCount[G.whoseTurn]-4), G2.deckCount[G.whoseTurn]);
    
    // TEST 6: Remaining players' draw piles reduced by 1 card each
    for (k = 1; k < numPlayers; k++)
        if (G2.deckCount[k] == (G.deckCount[k] - 1))
            printf ("Test6 - Other Players Deck Count Reduced: Player %i. Expected Value: %i || Returned Value: %i === PASSED ===\n", k, G.deckCount[k]-1,G2.deckCount[k]);
        else
            printf ("Test6 - Other Players Deck Count Reduced: Player %i. Expected Value: %i || Returned Value: %i === FAILED ===\n", k, G.deckCount[k]-1,G2.deckCount[k]);
    
    return 0;
}
