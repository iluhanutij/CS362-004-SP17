#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Min Yu
// Assignment 3
// Unit test 2

// tests the suppyCount() function in dominion.c. Purpose is to see if the
// function returns the number of cards left on supply correctly

int testSupplyCount(int card, struct gameState *state){
    
    int supply = supplyCount(card, state);
    
    // TEST 1: Count returned is not NULL
    if (!supply) {
        printf ("Test1: FAILED.\n");
    } else {
        printf ("Test1: PASSED.\n");
    }

    // TEST 2: count returned is not NULL
    if (supply != state->supplyCount[card]) {
        printf ("Test2: FAILED.\n");
    } else {
        printf("Test2: PASSED.\n");
    }

    return 0;
}


int main (int argc, char** argv) {
    printf ("----Testing supplyCount() function----\n");
    // Create a game
    int numPlayers = 2;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '15'
    initializeGame(numPlayers, k, 15, &G);
    
    // Set test cards total of 27 CARD enum from curse -> treasure_map
    for (int i = treasure_map; i < 0; i--) {
        G.supplyCount[i] = i;
    }
    
    //Test supplyCount() for all the cards
    for (int j = 0; j < treasure_map+1; j++){
        printf("Card %i:\n", j+1);
        testSupplyCount(j, &G);
    }

    return 0;
}