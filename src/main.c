#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <math.h>
#include <assert.h>

// build a number-guess game
// and seperate each game function to files

void strtruncat(char _Str[], const char _Part[])
{
    assert(_Str && _Part);
    
    size_t pos = 0;
    
    pos = strcspn(_Str, _Part);
    _Str[pos] = '\0';
}

// get a number from user in command line
char *user_input(const char *prompt, char *result)
{
    char buffer[BUFSIZ];
    
    // user prompt and input
    printf("%s", prompt); fflush(stdout);
    fgets(buffer, BUFSIZ, stdin);
    
    // cut off the newline in the end of input string
    strtruncat(buffer, "\r\n");


    return strncpy(result, buffer, strlen(buffer) + 1ULL);
}

// generate a random number ranged [_Min, _Max]
int randint(int _Min,int _Max)
{
    return rand() % (_Max - _Min) + (_Min + 1);
}

int main(int argc, char const *argv[])
{
    // initialize the random seed generator
    srand(time(NULL));

    int guess  = 0;
    int times  = 0;
    int answer = randint(0, 100);
    
    // buffer for recieving the input from user
    char result[BUFSIZ];
    char replay[5];
    
    do 
    {
        guess = 0;
        user_input("\nGUESS A NUMBER(1~100): ", result);

        guess = atoi(result);
        
        // printf("You type: %s\n", result); // debug
        // printf("The answer is: %d\n", answer); // debug
        times++;

        if (guess < answer)
        {
            puts("有點小 再大一點");
        }
        else if (guess > answer)
        {
            puts("有點大 再小一點");
        }
        else
        {
            printf("恭喜! 你答對了!");
            printf("共猜了%d次\n", times);
            printf("想繼續嗎?(y/n) ");
            fflush(stdout);

            strtruncat(fgets(replay, BUFSIZ, stdin), "\r\n");

            if (tolower(replay[0]) == 'y')
            {
                answer = randint(0, 100);
                continue;
            }  
            else break;
        }

    } while(result);
    

    puts("遊戲結束");

    return 0;
}
