#include <stdio.h>
#include <stdlib.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; //

int checkwin();
void board();

int main()
{
    int player = 1 ;  // Here we first assigned player number 1 for divisibility.
    int i; // If the i value is first, we have specified the win condition as the examination and we have assigned the win condition function as int, at the bottom of the code, when we choose to keep the int value as an int value.
    int choice; //here we assign a variable to specify which number to choose

    char mark; // We assigned a char variable to replace the number we chose with the letter X or O and used it in the if else block at the bottom.
    do
    {
        board();
        if(player % 2)
        {                       // here, we have determined the order of the players according to whether the player variable is odd or even.
            player = 1;
        }

        else
        {
            player = 2;
        }


        printf("Player %d, enter a number:  ", player);
        scanf("%d", &choice);

        if(player == 1){ //In this if else block, if the number is odd, the first player will first put the letter X at the point who chose, as of the player++ code at the bottom, respectively.
            mark = 'X';  // The second player will put the letter O.
        }
        else{
            mark = 'O';
        }

        if (choice == 1 && square[1] == '1')  //In all of these codes, if the choice is 1, it is the explanation that the letter X or O is put in the square box 1 according to the order of the players.
            square[1] = mark;

        else if (choice == 2 && square[2] == '2')
            square[2] = mark;

        else if (choice == 3 && square[3] == '3')
            square[3] = mark;

        else if (choice == 4 && square[4] == '4')
            square[4] = mark;

        else if (choice == 5 && square[5] == '5')
            square[5] = mark;

        else if (choice == 6 && square[6] == '6')
            square[6] = mark;

        else if (choice == 7 && square[7] == '7')
            square[7] = mark;

        else if (choice == 8 && square[8] == '8')
            square[8] = mark;

        else if (choice == 9 && square[9] == '9')
            square[9] = mark;

        else
        {
            printf("Invalid move ");  // If any wrong play occurs, a certain player is warned with the text "invalid move".

            player--;
            scanf("%c",&mark);
        }
        i = checkwin(); // here, we have equalized the value of i according to the winning condition and according to the codes we wrote at the bottom;
                        // If i == 1, the game is over, if i == 0, the game ends as a result of error, if i == -1, the game continues.

        player++;
    }while (i ==  - 1);

    board();

    if (i == 1)
        printf("==>\aPlayer %d win ", --player);
    else
        printf("==>\aGame draw");

    scanf("%c",&mark);

    return 0;
}


int checkwin() // This function examines the game win condition within the 9 square block.
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

    else if (square[4] == square[5] && square[5] == square[6])
        return 1;

    else if (square[7] == square[8] && square[8] == square[9])
        return 1;

    else if (square[1] == square[4] && square[4] == square[7])
        return 1;

    else if (square[2] == square[5] && square[5] == square[8])
        return 1;

    else if (square[3] == square[6] && square[6] == square[9])
        return 1;

    else if (square[1] == square[5] && square[5] == square[9])
        return 1;

    else if (square[3] == square[5] && square[5] == square[7])
        return 1;

    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&  // This function examines the game is over and no result.
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0;
    else
        return  - 1; // This function examines the game is not finished yet.
}





void board() // Void is a function type that does not return any output value in the C programming language.
{
    system("cls"); // This code can clear the actions.
    printf("\n\n\tTic Tac Toe\n\n");

    printf("Player 1 (X)  -  Player 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}


