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
#define RANDOMTEST "Smithy"

void testSmithy(int *passed, int *failed)
{
    int results;
    int i;
    int seed;
    int numPlayers;
    int whosePlayer = 0;
    struct gameState G, testG;
    int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};

    // create random number for seed and number of players
    seed = rand() % 1000 + 1;
    // allow for players between 2 and 4 to catch corner cases
    numPlayers = rand() % MAX_PLAYERS + 2;
    // generate random number of cards that will be added by the smithy card ranges from 0 - 5
    int randomCardsAdded = rand() % (5 + 1 - 0) + 0;

    printf("Testing - seed = %d, numPlayers = %d, cards added by Smtihy = %d\n", seed, numPlayers, randomCardsAdded);
    //initialize game state
    results = initializeGame(numPlayers, k, seed, &G);
    if (results == -1)
    {
        printf("Test 1 - Game initialization failed.\n");
        (*failed)++;
        return;
    }
    memcpy(&testG, &G, sizeof(struct gameState));

    //give smithy card to player
    testG.hand[whosePlayer][testG.handCount[whosePlayer]] = smithy;
    testG.handCount[whosePlayer]++;

    //play card
    smithyCase(i, whosePlayer, &testG, 0);
    if (G.handCount[whosePlayer] + randomCardsAdded == testG.handCount[whosePlayer])
    {
        // print if successful.
    }
    else
    {
        printf("Test 2 - Player did not gain/discard correct # of cards.\n");
        (*failed)++;
        return;
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
        testSmithy(&passed, &failed);
    }
    printf("Total tests: %d\n", NUM_TESTS);
    printf("Successful tests: %d\n", passed);
    printf("Failed tests: %d\n", failed);

    return 0;
}