#include <stdio.h>

int main() {
    int guess,guess_time = 0;
    int ans = 87;
    while(1){
        printf("Please enter ur guess:");
        scanf("%d", &guess);
        guess_time++;
        if(ans > guess)
            printf("answer is larger than ur guess (%d)\n",guess_time);
        else if(ans < guess)
            printf("answer is smaller than ur guess (%d)\n",guess_time);
        else{
            printf("You are right! Guess %d time!(%d)\n",guess_time);
            break;
        }
    }
    return 0;
}
