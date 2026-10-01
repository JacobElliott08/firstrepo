#include <stdio.h>
#include <stdlib.h>

void printBoard(char board[3][3])
{
    int i = 0;
    int a = 0;

    for(i = 0; i < 3; i ++)
    {   
        if(i != 0)
        {
            printf("------------\n");
        }
        for (a = 0; a < 3; a ++)
        {   
            if(a != 2)
            {
                printf(" %c |", board[i][a]);   
            }
            else
            {
                printf(" %c ", board[i][a]);
            }
        }
        
        printf("\n");
    }
}

int canPlayerPlayHere(char board[3][3], int row, int col)
{
    /*0 is false*/
    /*1 is true*/
    if(row < 0 || row > 2)
    {
        return 0;
    }

    if(col < 0 || col > 2)
    {
        return 0;
    }

    if(board[row][col] != ' ')
    {
        return 0;
    }
    
    return 1;
}

void doTurn(char board[3][3], char player)
{
    int playerRow = 0;
    int playerColumn = 0;
    int placed = 0; /*represent if the player has successful placed their X/O*/
    int canPlayerPlay = 0;

    while (placed == 0)
    {
        printf("Player %c enter the row that you want to take between 1 - 3 : ", player);
        scanf("%d", &playerRow);
        playerRow -= 1; /*player guessing between 1 - 3, the board is 0 - 2*/

        printf("Player %c enter the column that you want to take between 1 - 3 : ", player);
        scanf("%d", &playerColumn);
        playerColumn -= 1; /*player guessing between 1 - 3, the board is 0 - 2*/

        canPlayerPlay = canPlayerPlayHere(board, playerRow, playerColumn);
        if(canPlayerPlay)
        {
            board[playerRow][playerColumn] = player;
            placed = 1;
        }
        else
        {
            printf("You cannot play at that spot because it is already occupied, please select new coordinates.\n");
        }
    }
}

int checkWinConditions(char board[3][3])
{
    /*0 is false
      1 is true*/
    if(board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return 1;
    }

    if(board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return 1;
    }

    int i = 0;
    for (i = 0; i < 3; i ++)
    {
        if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return 1;
        }
    }

    for (i = 0; i < 3; i ++)
    {
        if(board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return 1;
        }
    }
    return 0;
}

int main()
{

    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    int winner = 0;
    while (winner == 0)
    {
        doTurn(board, 'X');
        printBoard(board);
        winner = checkWinConditions(board);
        if(winner == 1)
        {
            printf("X WINS!\n");
            break;
        }

        doTurn(board, 'O');
        printBoard(board); 
        winner = checkWinConditions(board);
        if(winner == 1)
        {
            printf("O WINS!\n");
            break;
        }
    }
    

    return 0;
}