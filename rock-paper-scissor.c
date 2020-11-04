#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int checker(char a, char b);

//RAND_MAX is the upper limit of random number generated

//formula for finding out random number between a range: (rand()%(upper-lower))+lower

int main()
{
    printf("The Rock Paper Scissor Game!\n Play Rock-Paper-Scissor with the computer!\n\n");
    while (1 == 1)
    {
        printf("\nEnter the number of rounds you want to play (The number entered should be a positive integer)\n");
        int rounds;
        scanf(" %d", &rounds);
        int computer_score = 0;
        int user_score = 0;

        for (int i = 0; i < rounds; i++)
        {
            char choices[] = {'r', 'p', 's'};

            srand(time(NULL));
            int randome = rand();
            int random = (randome % (3)) + 1;

            printf("Enter r for Rock, p for Paper, s for Scissor!\n");
            char a;
            scanf(" %c", &a);

            if (a == 'r' || a == 'p' || a == 's')
            {
                char b = choices[random - 1];
                int result = checker(a, b);
                if (result == 0)
                {
                    printf("You chose %c and computer chose %c. You lose!\n\n", a, b);
                    computer_score += 2;
                }
                else if (result == 1)
                {
                    printf("You chose %c and computer chose %c. You win!\n\n ", a, b);
                    user_score += 2;
                }
                else
                {
                    printf("You chose %c and computer chose %c. It's a tie!\n\n ", a, b);
                    computer_score++;
                    user_score++;
                }
            }
            else
            {
                printf("Please enter a valid choice\n\n");
                i--;
                continue;
            }
        }
        if (computer_score == user_score)
        {
            printf("The match is a tie!\n\n");
        }
        else if (computer_score > user_score)
        {
            printf("The computer won the match!\n\n");
        }
        else
        {
            printf("GG! You won the match!\n\n");
        }
    }

    return 0;
}

int checker(char a, char b)
{
    if (a == b)
    {
        return 2;
    }
    else if ((a == 'r' && b == 's') || (a == 's' && b == 'p') || (a == 'p' && b == 'r'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}