/*  Author: Min Yu
    Assignment #4: Random Testing for 'Smithy' card
*/
#include "dominion.h"
#include "dominion_helpers.h"
#include "rngs.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TESTS 10000
#define RANDOMTEST "Adventurer"

void testAdventurer(int *passed, int *failed)
{
    int results;
    int i;
    int seed;
    int numPlayers;
    int whoseTurn = 0;
    struct gameState G, testG;
    int z = 0;
    int cardDrawn = 0;
    int drawnTreasure = 0;
    int temphand[MAX_HAND];
    int handPos = 0;

    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};

    // create random number for seed and number of players
    seed = rand() % (1000 + 1 -1) + 1;
    // allow for players between 1 and 5 to catch corner cases
    numPlayers = rand() % (MAX_PLAYERS + 1 - 2) + 2;
    drawnTreasure = rand() % (5 + 1 - 0) + 0;

    printf("Testing - seed = %d, numPlayers = %d, drawnTreasure = %d\n", 
        seed, numPlayers, drawnTreasure);
    //initialize game state
    results = initializeGame(numPlayers, k, seed, &G);
    if (results == -1)
    {
        printf("Test 1 - Game initialization failed.\n");
        (*failed)++;
        return;
    }
    memcpy(&testG, &G, sizeof(struct gameState));

    //give adventurer card to player
    testG.hand[whoseTurn][testG.handCount[whoseTurn]] = adventurer;
    testG.handCount[whoseTurn]++;


    //play card
    adventurerCase(drawnTreasure, &testG, whoseTurn, z, temphand, cardDrawn);

    // TEST 1: Check that handCount has 2 additional cards
    if ((G.handCount[whoseTurn] + drawnTreasure) == testG.handCount[whoseTurn]) {
        //printf ("Test1 - Check players hand count increment: Expected Value: %i || Returned Value: %i === PASSED ===\n", initialHandCount+2, G.handCount[G.whoseTurn]);
    }
    else {
        printf("Test 2 - %s card increment of count is wrong.\n", RANDOMTEST);
        (*failed)++;
        return;
    }

        // TEST 3: Check that the deckcount decreased by at least 2
    if (testG.deckCount[whoseTurn] <= (G.deckCount[whoseTurn] - 2)) {
        //printf ("Test 3 - Deck count decreased by least 2");
    }
    else {
        //printf ("Test3 - Deck count decreased by least 2: Expected Value: > 2 || Returned Value: %i === FAILED ===\n", (initialDeckCount-G.deckCount[G.whoseTurn]));
        printf("test 3 %s - cards deckcount is wrong.\n", RANDOMTEST);
        (*failed)++;
        return;
    }
    
    // TEST 2: Check that all drawn cards are treasure cards
    for (i = 0; i < 2; i++){
        if (testG.hand[whoseTurn][testG.handCount[whoseTurn] - 1 - i] == copper ||
            testG.hand[whoseTurn][testG.handCount[whoseTurn] - 1 - i] == silver ||
            testG.hand[whoseTurn][testG.handCount[whoseTurn] - 1 - i] == gold) {
            printf ("Test 4 - card%i is Treasure card === PASSED ===\n", i+1);
        } else {
            printf ("Test 4 - card%i is NOT Treasure card === FAILED ===\n", i+1);
            (*failed)++;
            return;
        }
    }
    

    printf("All Tests Passed Successfully\n\n");

    (*passed)++;
    return;
}

int main()
{
    int i;
    int passed = 0, failed = 0;

    srand(time(NULL));

    for (i = 0; i < NUM_TESTS; i++)
    {
        testAdventurer(&passed, &failed);
    }
    printf("Total tests: %d\n", NUM_TESTS);
    printf("Successful tests: %d\n", passed);
    printf("Failed tests: %d\n", failed);

    return 0;
}