#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

//function to roll 2 dices and returns the sum of the two rolls
int rollDice(void) {
    int diceOne,diceTwo,sum;
    diceOne=rand()%6+1;
    diceTwo=rand()%6+1;
    sum=diceOne+diceTwo;
    return sum;
}

//function that plays the game of Craps once
bool playGame(void) {
    //initalizes variables
    int point,sum;
    //assigns value of first roll to "point"
    point=rollDice();
    
    //condition for winning on the first turn
    if (point==7 || point==11) {
        printf("You rolled: %d\n",point);
        printf("You win!\n");
        return true;
    }
    
    //condition for losing on the first turn
    else if (point==2 || point==3 || point==12) {
        printf("You rolled: %d\n",point);
        printf("You lose!\n");
        return false;
    }
    
    //if the user does not win on the first turn, then outputs what they rolled and the point for the game while rolling again 
    else {
        
        printf("You rolled: %d\n",point);
        printf("Your point is: %d\n",point);
        sum=rollDice();
        
        //if the second roll is not the same as the point, the condition is met
        while (sum!=point){
            
            //if the roll results in 7, the user loses
            if (sum==7) {
                printf("You rolled: %d\n",sum);
                printf("You lose!\n");
                return false;
            }
            
            //if the roll does not result in 7 or the same value as the point, then the user rolls again
            printf("You rolled: %d\n",sum);
            sum=rollDice();
        }
    }
    
    //if the second roll is the same as the point, then the user wins
    if (sum==point) {
        printf("You rolled: %d\n",sum);
        printf("You win!\n");
        return true;
    }
}
        
        
//function that calls the play game function for as long as the user wants
void winLoss(void) {
    
    //initializes variables
    int numOfWins,numOfLosses;
    char playAgain;
    numOfWins=0;
    numOfLosses=0;
    
    do {
        //plays one game of scraps
        bool x=playGame();
        //if the user wins, then add one to the number of wins
        if (x == true) {
            numOfWins=numOfWins+1;
        }
        
        //if the user loses, then add one to the number of losses
        else {
            numOfLosses=numOfLosses+1;
        }
        
        //ask the user whether or not they want to play again
        printf("Play again? ");
        //scans input of the user
        scanf(" %c", &playAgain);

    }
    //if the user inputs 'y' or 'Y', then the above loop is ran again until the user says otherwise
    while (playAgain == 'Y' || playAgain == 'y');
    
    //if the user inputs something other than 'y' or 'Y', then the code outputs the toal number of wins and losses for the game
    if (playAgain != "Y" || playAgain !='y') {
        printf("\nWins: %d\n",numOfWins);
        printf("Losses: %d",numOfLosses);
        
    }
}



int main() {
    winLoss();
}