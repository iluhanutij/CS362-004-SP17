#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Min YU
// Assignment 3
// unitt test 4

// This file tests the isGameOver() function. isGameOver() determines if the game is
// over by checking the number of empty provinces and supply piles.

int testIsGameOverFalse (struct gameState *state) {

    if(!isGameOver(state)) {
        printf ("Game is NOT over === PASSED ===\n");
    } else {
        printf ("Game is over === FAILED ===\n");
    }
    return 0;
}

int testIsGameOverTrue (struct gameState *state) {

    if(!isGameOver(state)) {
        printf ("Game is not OVER === FAILED ===\n");
    } else {
        printf ("Game is over === PASSED ===\n");
    }
    return 0;
}

int main (int argc, char** argv) {
    printf ("----Testing isGameOver() function----\n");
    // Create a game
    int numPlayers = 2;
    struct gameState G;
    int k[10] = {adventurer, gardens, embargo, village, minion, mine, cutpurse, sea_hag, tribute, smithy};
    
    // Initialize the game with 2 players; seed is '15'
    initializeGame(numPlayers, k, 15, &G);
    

    // Test 1: when game Initializes, is the game over?
    printf("Test1 - Is game over when initialized: ");
    testIsGameOverFalse(&G);
    
    // Create 3 empty piles and test.
    // TEST 2: 3 empty piles of action cards
    G.supplyCount[adventurer] = 0;
    G.supplyCount[gardens] = 0;
    G.supplyCount[embargo] = 0;  
    printf("Test2 - Check if 3 empty supplies ends the game: ");
    testIsGameOverTrue(&G);

    // TEST 3: 2 empty piles of action cards
    G.supplyCount[adventurer] = 1;
    printf("Test3 - Check if 2 empty supplies ends the game: ");
    testIsGameOverFalse(&G);

    
    // TEST 4: 1 empty pile of action cards
    G.supplyCount[council_room] = 1;
    printf("Test4 - Check if 1 empty supply ends the game: ");
    testIsGameOverFalse(&G);
    
    // TEST 5: Even with enough supply cards will game end with all provice card being empty?
    G.supplyCount[province] = 0;
    printf("Test5 - With Supplies full will the game end with all provinces gone?: ");
    testIsGameOverTrue(&G);

    return 0;
}