/*
 * Who: Paul (Dai) Vuong
 * When: Feb 11, 2021
 * Why: Homeword 1 - Game of Nim (with 3 piles)
 */

#include <stdio.h>	
#include <stdlib.h>	
#include <time.h>		
#include <stdbool.h>	

int count[3]; // Global array count contains marbles in three piles.

/* 
 * User Choice
 * -----------
 * count: The array contains number marbles of three piles.
 */
void user_turn(int count[]) {
    // User pick one in three piles
    int pile;
    while(true) {
        printf("Pick a pile (1,2,3): ");
        scanf(" %d", &pile);
        // Re-prompt if enter number other than 1,2,3
        if(pile >= 1 && pile <=3) {
            pile--;
            // Break the loop if the pile still has marbles
            if(count[pile] > 0 ) {
                break;
            } else { // Continue the loop if the pile doesn't have marble.
                printf("No more marbles in pile %d. Pick another pile.\n", pile+1);
                continue;
            }
        }
        printf("Your input is BAD! ");
    }
    
    int maximum;
    // If the pile has one marble while other piles still have one or more marbles, can pick that marble left
    if(count[pile] == 1) {
        maximum = 1;
    } else {
        maximum = count[pile] >> 1; // Set maxinum marble can be taken
    }
    
    // User chooses marbles to take out
    int choice = -1;
    while (choice < 1 || choice > maximum) {
        printf("You can take from 1 to %d marbles in pile %d: ", maximum, pile+1);
        scanf(" %d", &choice);
        // If the choice in 1 - maximum, break the loop
        if (choice >= 1 && choice <= maximum) {
            break;
        }
        printf("Your input is BAD! ");
    }
    count[pile] = count[pile] -choice; // Re-count the marbles in the picked pile.
}

/* 
 * Computer Choice
 * ---------------
 * count: The array contains number marbles of three piles.
 */
void computer_turn(int count[]) {
    srand(time(0));
    int pile;
    // Computer picks pile
    while(true) {
        printf("Computer picks: ");
        pile = rand() % 3;
        // Break the loop if the pile still has marbles
        if(count[pile] > 0 ) {
            printf("pile %d\n", pile+1);
            break;
        } else { // Continue the loop if the pile doesn't have marble.
            printf("No more marbles in pile %d. Let me pick again.\n", pile+1);
            continue;
        }
    }

    int maximum;
    // If the pile has one marble while other piles still have one or more marbles, can pick that marble left
    if(count[pile] == 1) {
        maximum = 1;
    } else {
        maximum = count[pile] >> 1; // Set maxinum marble can be taken
    }

    // Random pick marbles from 1 to maximum
    int choice = rand() % maximum + 1;
    printf("From 1 to %d marbles in pile %d: Computer picks %d\n", maximum, pile+1, choice);
    
    count[pile] = count[pile] - choice; // Re-count the marbles in the picked pile.
}

/*
 * Check the winner and exit the program
 * -------------------------------------
 * count: array contains marbles count in 3 piles
 * player: current player
 */
void check_winner(int count[], int player) {
    if ((count[0] == 1 && count[1] < 1 && count[2] < 1) ||
        (count[0] < 1 && count[1] == 1 && count[2] <= 1) ||
        (count[0] < 1 && count[1] < 1 && count[2] == 1)) {
        if (player == 1) {
            printf("\nYOU WON! Because computer takes the last marble\n");
        } else {
            printf("\nYOU LOSE! Because you take the last marble\n");
        }
        exit(0);
    }
}

/*
 * Print current marbles in 3 piles
 * --------------------------------
 * count: array contains marbles count in 3 piles
 */
void printCurrentMarbles(int count[]) {
    printf("\n<<<<<   Current marble(s) in 3 piles.  >>>>>\n");
    printf("|%12s | %12s | %12s|\n", "Pile 1   ", "Pile 2   ", "Pile 3   ");
    printf("|%2d marble(s) | %2d marble(s) | %2d marble(s)|\n", count[0], count[1], count[2]);
}

int main() {
    srand(time(0));
    // Initialize marbles for three piles ramdomly.
    for(int i = 0; i < 3; i++) {
        count[i] = rand() % 91 + 10;
    }
    // count[0] = 35;
    // count[1] = 1;
    // count[2] = 21;

    int player = 1; // Keep track current player.

    do {
        printCurrentMarbles(count); // Print current marbles
        // User turn
        printf(">>> YOUR TURN\n");
        user_turn(count);
        check_winner(count, player); // Check winner
        player = 2;

        printCurrentMarbles(count); // Print current marbles
        // Computer turn
        printf(">>> COMPUTER's TURN\n");
        computer_turn(count);
        check_winner(count, player); // Check winner
        player = 1;

    } while (true);

}

