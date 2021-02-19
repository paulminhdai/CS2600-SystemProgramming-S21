## The game Nim

The game is played with one pile of marbles, starting with between 10 and 100 marbles. Two players take turns removing marbles from the pile, and whichever player takes the last marble loses. Each player must take at least one marble and at most half of the marbles. ​Note: on the last turn, there will be one marble in the pile: the loser has to take this marble, even though this is more than half of the marbles!

Steps of the program.
1. Pick a number between 10 and 100. This value should be placed in the variable ​count​.
2. Inform the player of the number of marbles, ​count.​
3. Determine the largest value the user can take, which is half of ​count​ (or 1 at the end of the
game.
4. Prompt the user to enter a value between 1 and the limit determined in step 3.
5. Check the user's input to make sure the value is in range. If not, complain to the user and get a
new value.
6. Subtract the value from count.
7. Determine the number of marbles to be taken by the program. Print this value for the user, then
subtract this number from count.
8. Go back to step 2, unless either the program or the user wins.

*Extra credit part:*
Rather than having just 1 pile, make your game with 3 piles of marbles (each pile has its own starting count from 10 to 100). When the player (and computer) take a turn, first ask which pile, then ask the number of marbles to take.
