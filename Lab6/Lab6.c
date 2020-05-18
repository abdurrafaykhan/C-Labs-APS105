#include <stdio.h>
#include <stdbool.h>

//Function to print the Tic-Tac-Toe Board
void printBoard(int board[], int playerA, int playerB) {
    
    //Declaration of variables for the construction of the board
    int i;
    
    printf("\n");
    
    //Creates a Tic-Tac-Toe Board filled with integers in sequential order
    for (i = 1; i < 10; i++) {
        printf(" ");
        printf("%c",board[i-1]);
        if (i % 3 == 0) {
            printf("\n");
        }
    }
    
    printf("\n");
    
}

//Function that scans input and returns only a valid input
int requestValidInput(int board[], int playerA, int playerB) {
    
    //Declaration of variables used to validate inputs
    int placement;
    
    //a loop that scans input from user and repeatedly asks for additional inputs if previous ones are invalid
    do {
        //Scans input from the user
        scanf("%d", &placement);
        
        //Prints statements telling user to input another value thats valid if current one is invalid
        if(placement < 1 || placement > 9) {
            printf("Invalid input, please try again.\n")
        }
        if(board[placement-1] == 65 || board[placement-1] == 66) {
            printf("That position has already been played, please try again.\n");
        }
    }
    //The loop repeats if the user inputted an invalid input
    while(placement < 1 || placement > 9 || board[placement-1] == 65 || board[placement-1] == 66);
    
    //Subtracts one from the users input to return the index value of the array
    placement = placement - 1;
    
    //Returns index of value of the array
    return placement;
    
}

//Function that checks if the game is won
int checkForWinner(int board[], int playerA, int playerB) {
    
    
    
    //Scenarios for Player A winning
    if (board[0] == 65 && board[1] == 65 && board[2] == 65) {
        return playerA;
    }
    
    if (board[3] == 65 && board[4] == 65 && board[5] == 65) {
        return playerA;
    }
    
    if (board[6] == 65 && board[7] == 65 && board[8] == 65) {
        return playerA;
    }
    
    if (board[0] == 65 && board[3] == 65 && board[6] == 65) {
        return playerA;
    }
    
    if (board[1] == 65 && board[4] == 65 && board[7] == 65) {
        return playerA;
    }
    
    if (board[2] == 65 && board[5] == 65 && board[8] == 65) {
        return playerA;
    }
    
    if (board[0] == 65 && board[4] == 65 && board[8] == 65) {
        return playerA;
    }
    
    if (board[2] == 65 && board[4] == 65 && board[6] == 65) {
        return playerA;
    }
    
    //Scenarios for Player B winning
    if (board[0] == 66 && board[1] == 66 && board[2] == 66) {
        return playerB;
    }
    
    if (board[3] == 66 && board[4] == 66 && board[5] == 66) {
        return playerB;
    }
    
    if (board[6] == 66 && board[7] == 66 && board[8] == 66) {
        return playerB;
    }
    
    if (board[0] == 66 && board[3] == 66 && board[6] == 66) {
        return playerB;
    }
    
    if (board[1] == 66 && board[4] == 66 && board[7] == 66) {
        return playerB;
    }
    
    if (board[2] == 66 && board[5] == 66 && board[8] == 66) {
        return playerB;
    }
    
    if (board[0] == 66 && board[4] == 66 && board[8] == 66) {
        return playerB;
    }
    
    if (board[2] == 66 && board[4] == 66 && board[6] == 66) {
        return playerB;
    }
}


int main()
{
    //Declaration of variables that will execute the Tic-tac-toe game
    int placement,j,currentPlayer,check,count=0,playerA=100,playerB=200,board[9] = {49, 50, 51, 52, 53, 54, 55, 56, 57};
    
    //Assigns gameOver to false because the game is not over
    bool gameOver = false;
    
    //Sets the inital player to play
    currentPlayer=playerA;

    //Performs loop when the game is not over
    while (gameOver!=true) {
        
        //Prints statement displaying the current state of the board
        printf("The current state of the Tic-tac-toe Board:\n");
        
        //Calls function to print the board
        printBoard(board,playerA,playerB);
        
        //Print whose turn it is
        if (currentPlayer==playerA) {
            printf("It is Player A's turn.\n");
        }
        else {
            printf("It is Player B's turn.\n");
        }
        
        //Asks the user to input a value
        printf("Please enter a valid position to play.\n");
        
        //Calls function to return value of valid input
        placement=requestValidInput(board, playerA,playerB);
        
        //Performs turn and prints the players letter in the index they inputted. Also adds 1 to a counter that represents the number of turns
        if (currentPlayer==playerA) {
            board[placement]=65;
            count=count+1;
        }
        else {
            board[placement]=66;
            count=count+1;
        }        
        
        //Switches players at the end of the turn
        if (currentPlayer==playerA) {
            currentPlayer=playerB;
        }
        else {
            currentPlayer=playerA;
        }    
        
        //Calls function that returns values representing if the game has been won
        check=checkForWinner(board,playerA,playerB);
        
        //Prints statement if player A wins and sets game over to true
        if (check==playerA) {
            printf("Player A wins!\n");
            gameOver=true;
        }
        
        //Prints statement if player B wins and sets game over to true
        if (check==playerB) {
            printf("Player B wins!\n");
            gameOver=true;
        }
        
        //If the counter reaches 9 and no player has won, the game is a draw and the game is over
        if (count==9) {
            printf("It's a draw!\n");
            gameOver=true;
        }

    }
    
    //Prints the final board after the game is over
    printBoard(board,playerA,playerB);
    
    
    

}
