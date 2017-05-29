/*  Author: Min Yu
    Assignment #4: Random Testing for 'village' card
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
#define RANDOMTEST "Village"

void testVillage(int *passed, int *failed)
{
    int results;
    int i;
    int seed = 1000;
    int numPlayers = 2;
    int whoseTurn = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, council_room, feast, gardens, mine,
                    remodel, smithy, village, baron, great_hall};

    // create random number for seed and number of players
    seed = rand() % 1000 + 1;
    // allow for players between 1 and 5 to catch corner cases
    numPlayers = rand() % MAX_PLAYERS + 1;
    // generate random number of cards added by village from 0 - 3
    int randomNumCards = rand() % (3 + 1 - 0) + 0;
    // generate random number of actions added by village from 0 - 3
    int randomNumActions = rand() % (3 + 1 - 0) + 0;

    printf("Testing %s - seed = %d, numPlayers = %d, number of cards added = %d, number of action added = %d \n"
        , RANDOMTEST, seed, numPlayers, randomNumCards, randomNumActions);
    //initialize game state
    results = initializeGame(numPlayers, k, seed, &G);
    if (results == -1)
    {
        printf("Test 1 - Game initialization failed.\n");
        (*failed)++;
        return;
    }
    memcpy(&testG, &G, sizeof(struct gameState));

    // give village card to player
    testG.hand[whoseTurn][testG.handCount[whoseTurn]] = smithy;
    testG.handCount[whoseTurn]++;

    //play card
    villageCase(whoseTurn, &testG, 0);
    if (G.handCount[whoseTurn] + randomNumCards == testG.handCount[whoseTurn])
    {
        //printf(" Player gained 1 new cards, discarded 1. net of 0\n");
    }
    else
    {
        printf("Test 2 - Player did not gain/discard correct # of cards.\n");
        (*failed)++;
        return;
    }

    if ((G.numActions + randomNumActions) == testG.numActions) {
        //printf(" player gained 2 new action points");
    }
    else {
        printf("Test 3 - Player did not gain correct # of action.\n");
        (*failed)++;
        return;
    }


    printf("All Test Passed Successfully\n\n");

    (*passed)++;
    return;
}

int main()
{
    int i;
    int passed = 0, failed = 0;

    srand(time(NULL));

    // run test NUM_TESTS times, track number of success and faileds
    for (i = 0; i < NUM_TESTS; i++)
    {
        testVillage(&passed, &failed);
    }
    printf("Total tests: %d\n", NUM_TESTS);
    printf("Successful tests: %d\n", passed);
    printf("Failed tests: %d\n", failed);

    return 0;
}