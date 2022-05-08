#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int guess;
    srand(time(0));
    int answer = (rand()%10)+1;
    do{
        printf("please enter ur guess:");
        scanf("%d", &guess);
        if(answer > guess)
            printf("answer is larger than ur guess \n" );
        else if(answer < guess)
            printf("answer is smaller than ur guess \n");
        else{
            printf("You are right! \n");
        }
    }while(guess!=answer);
}