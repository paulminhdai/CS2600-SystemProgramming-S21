/*
 * Who: Paul (Dai) Vuong
 * When: Feb 11, 2021
 * why: Homeword 1 - Game of Nim
 */

#include <stdio.h>	
#include <stdlib.h>	
#include <time.h>		
#include <stdbool.h>	


/* 
 * User Choice
 * -----------
 * maximum: maximum marbles user can take
 * 
 * returns: user choice in the range 1 and maximum
 */
int user_turn(int maximum) {
    int choice;
    // Prompt and get user choice, if invalid, re-prompt
    while (true) {
        printf("You can take from 1 to %d marbles: ", maximum);
        scanf(" %d", &choice);

        // Check if user choice is valid
        if (choice >= 1 && choice <= maximum) {
            break; // break the loop if user enter valid input
        }
        printf("Your input is BAD! "); // notice and re-prompt
    }
    return choice;
}

/* 
 * Computer Choice
 * ---------------
 * maximum: maximum marbles user can take
 * 
 * returns: computer choice in the range 1 and maximum by random
 */
int computer_turn(int maximum) {
    srand(time(0));
    printf("Computer can take from 1 to %d marbles.\n", maximum);
    return rand() % maximum + 1;
}

/*
 * Check the winner and exit the program
 * -------------------------------------
 * count: array contains marbles count in 3 piles
 * player: current player
 */
void check_winner(int count, int player) {
    if (count <= 1) {
        if (player == 1) {
            printf("\nYOU WON! Because computer takes the last marble\n");
        } else {
            printf("\nYOU LOSE! Because you takes the last marble\n");
        }
        exit(0);
    }
}

int main() {
    srand(time(0));
    
    int player = 1; // Keep track current player.
    int count = rand() % 91 + 10; // Random marbles
    int maximum;

    do {
        printf("\nTotal marbles is: %d\n", count);

        // User's turn
        maximum = count >> 1;
        int user = user_turn(maximum);
        printf("User chosed: %d\n", user);
        count -= user; // re-count count
        check_winner(count, player); // check winner
        player = 2;


        printf("\nTotal marbles is: %d\n", count);

        // Computer's turn
        maximum = count >> 1;
        int computer = computer_turn(maximum);
        printf("Computer chosed: %d\n", computer);
        count -= computer; // re-count count
        check_winner(count, player); // check winner
        player = 1;

    } while (count > 1);

}

