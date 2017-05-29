#include "dominion.h"
#include "dominion_helpers.h"
#include <stdio.h>
#include <stdlib.h>

// Min Yu
// Assignment 3
// Unit test 3

// This unit test checks the getCost() function. It's purpose is to see if
// the reutrn of the cost for each cards in the dominion.c returns correct
//.

int testGetCost (int actual_cost, int expected_cost, char* msg) {
    if (actual_cost != expected_cost) {
        printf("Testing %s: Actual Cost = %i: Correct Cost = %i: FAILED\n", msg, actual_cost, expected_cost);
    } else {
        printf("Testing %s: Actual Cost = %i: Correct Cost = %i: PASSED\n", msg, actual_cost, expected_cost);
    }
    return 0;
}

int main(int argc, char **argv) {
    printf("----Testing getCost() function----\n");
    // Tests all the cards with 
    testGetCost(getCost(curse), 0, "curse");
    testGetCost(getCost(estate), 2, "estate");
    testGetCost(getCost(duchy) , 5, "duchy");
    testGetCost(getCost(province) , 8, "province");
    testGetCost(getCost(copper) , 0, "copper");
    testGetCost(getCost(silver) , 3, "silver");
    testGetCost(getCost(gold) , 6, "gold");
    testGetCost(getCost(adventurer) , 6, "adventurer");
    testGetCost(getCost(council_room) , 5, "council_room");
    testGetCost(getCost(feast) , 4, "feast");
    testGetCost(getCost(gardens) , 4, "gardens");
    testGetCost(getCost(mine) , 5, "mine");
    testGetCost(getCost(remodel) , 4, "remodel");
    testGetCost(getCost(smithy) , 4, "smithy");
    testGetCost(getCost(village) , 3, "village");
    testGetCost(getCost(baron) , 4, "baron");
    testGetCost(getCost(great_hall) , 3, "great_hall");
    testGetCost(getCost(minion) , 5, "minion");
    testGetCost(getCost(steward) , 3, "steward");
    testGetCost(getCost(tribute) , 5, "tribute");
    testGetCost(getCost(ambassador) , 3, "ambassador");
    testGetCost(getCost(cutpurse) , 4, "cutpurse");
    testGetCost(getCost(embargo) , 2, "embargo");
    testGetCost(getCost(outpost) , 5, "outpost");
    testGetCost(getCost(salvager) , 4, "salvager");
    testGetCost(getCost(sea_hag) , 4, "sea_hag");
    testGetCost(getCost(treasure_map) , 4, "treasure_map");
    /* just checking if the getCsot(curse) returned a correct value of 0 
    printf("Cost of Curse card: %i", getCost(curse));
    */
    return 0;
}