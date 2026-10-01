#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int gameSetup()
{
    int seed = (unsigned int)time(NULL);
    srand(seed);
    int lowRange = 0; 
    int highRange = 100;

    printf("Hello! Welcome to our guessing game\n");
    printf("Please start by entering the low range of the number to guess : ");
    scanf("%d", &lowRange);

    printf("Please enter the high range of the number to guess : ");
    scanf("%d", &highRange);

    printf("I will generate a random number for you to guess between %d and %d\n",lowRange, highRange);
    int numberToGuess = lowRange + rand() % (highRange - lowRange + 1);

    return numberToGuess;
}


void gameLoop(int guessingNumber)
{
    int userGuess = 0;
    printf("[DEBUG] Number to Guess = %d\n",guessingNumber);
    
    while(userGuess != guessingNumber)
    {
        printf("Enter a number : \n");
        scanf("%d", &userGuess);

        if(userGuess == guessingNumber)
        {
            printf("You win!\n");
        }
        else if (userGuess < guessingNumber)
        {
            printf("Too low!\n");
        }
        else
        {
            printf("Too high\n");
        }
    }
}


int main()
{
    int theGoldenNumber = 0;
    theGoldenNumber = gameSetup();
    gameLoop(theGoldenNumber);
    
    return 0;
}