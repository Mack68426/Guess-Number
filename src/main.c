#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>


// build a number-guess game
// and seperate each game function to files


int main(int argc, char const *argv[])
{
    int guess  = 0;
    int answer = 0; 
    // int chance = 3;
    int times = 0;

    srand(time(0));

    answer = rand() % 100 + 1;

    do 
    {
        guess = 0;
        printf("\nGUESS A NUMBER: "); fflush(stdout);
        scanf("%d", &guess);

    
        // chance--;
        times++;

        // if (!chance)
        // {
        //     puts("不好意思>< 機會用完囉!");
        //     puts("");
        //     break;
        // }

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

            char yn[5];
            fgets(yn, 5, stdin);

            printf("%s\n", yn);

            if (tolower(yn[0]) == 'y')  continue;
            else break;
        }
    } while(1);
    

    puts("遊戲結束");

    return 0;
}
