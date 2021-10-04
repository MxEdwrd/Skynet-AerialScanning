/*
    Author: Max Edward
    Email: maxedwar@uat.edu
    Assignment Name: Skynet - AerialScanning
*/

// Skynet - HK-Aerial

#include <stdio.h> // Used for std I/O.
#include <stdlib.h> // Used for calloc (allocates memory for an array).
#include <iostream> // Used for cin at the end for endChoice. 
#include <ctime> // Used for getting the system time for random numbers.

#define searchGrid 64 // Creates the grid that is 64 spaces, 8x8.

int mySearch(int* ary, int search, int len) { // Used for the ary, search, and led variables used later for outputting where the enemy was found.


    int ret = -1; // Definition for if the enemy was found or not.

    //Below is for the Binary Search Pattern. Was unable to implement properly.
    int searchHighNum = 63; // Definition for the highest search variable, 63.
    int searchLowNum = 0; // Definition for the lowest search variable, 0.
    int targetLocationPrediction = ((searchHighNum - searchLowNum) / 2) + searchLowNum; // Defines the prediction. Takes the difference of the high and low variables and divides them by 2. Finally adds the low variable to that.

    // Below is for the search pattern. It will go through the spaces until it finds the enemy.
    for (int i = 0; i < len; ++i) {
        if (ary[i] == search) {
            return i;
        }
    }
    return ret;
}

int main()
{
    char endChoice; // Defines the end choice for the player to be able to restart or quit the simulation.
    int x, y; // Defines x and y for coordinate readouts.
    srand(time(0)); // Generates time for the random number.

gameStart:
    int randNum = rand() % 64; // Used for creating the random number and then finding the modulus.
    printf("\n------------------------------------\n\n");
    printf("Welcome to Skynet, HK-Aerial Division.\n\n");
    printf("The simulation will start shortly.\n");
    printf("Once you press a button, the enemy will randomly hide and the Aerial Drone will search.\n");
    printf("\n------------------------------------\n");
    system("pause"); // Pause to make sure the player is ready to play. Almost like a "Click start to start game".

    //calloc routine allocates n amount of items of size s, and sets each
    //item to zero

    int* ary = (int*)calloc(searchGrid, sizeof(int)); // Defines the array.

    ary[randNum] = 1; //Assigns the enemy location to a one dimensional space using the random number.

    int _1dPosition = mySearch(ary, 1, searchGrid); // Defines the 1D position using the mySearch function.
    x = _1dPosition / 8; // Defines the x to the 1D position / 8.
    y = _1dPosition % 8; // Defines the y to the 1D position with modulus 8.

    if (_1dPosition != -1) {
        printf("\nEnemy found at %d in 1 Dimension\n", mySearch(ary, 1, searchGrid)); // Prints out where the enemy is exactly, outputing an exact position (0-63).
        printf("or at %d, %d in 2 Dimensions.", x, y); // Prints out where the enemy is at the x and y coordinate (range is from 0-7).
    }
    else {
        printf("\nEnemy Not Found. Outside of Range\n");
    }

endChoice: // Below is for the ending choice for the player to be able to restart or quit the simulation.
    printf("\nTo restart simulation, type R. To quit simulation, type Q.\n\n");
    std::cin >> endChoice;
    if (endChoice == 'r' || endChoice == 'R') {
        goto gameStart;
    }
    if (endChoice == 'q' || endChoice == 'Q') {
        return 0;
    }
    else {
        goto endChoice;
    }
}