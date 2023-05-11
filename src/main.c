#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <assert.h>


// build a number-guess game
// and seperate each game function to files

    
int main(int argc, char const *argv[])
{
    int guess  = 0;
    int answer = 0; 
    int chance = 3;
    
    srand(0);

    answer = rand() % 100 + 1;

    printf("GUESS A NUMBER: ");
    scanf("%d", &guess);
    
    printf("YOUR GUESS: %2d\n", guess);
    printf("ANSWER    : %2d\n", answer);


    return 0;
}
