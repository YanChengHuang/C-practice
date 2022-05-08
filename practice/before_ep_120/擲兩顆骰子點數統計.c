#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int times = 100000;
    int dice_scores[11] = {0};
    srand(time(0)); //set seed
    for(int i=1;i<=times;i++){
        int dice = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;
        int sum = dice + dice2;
        dice_scores[sum-2]++;
    }    
    for(int i=2;i<=12;i++){
        printf("score:%d times:%d\n",i,dice_scores[i-2]);
    }
    return 0;
}