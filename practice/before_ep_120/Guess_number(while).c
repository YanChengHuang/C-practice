#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main() {
    int input;
    int sum = 0;
    float times = 0;
    srand(time(0)); //set seed
    printf("Please enter the number(quit: 0):");
    while(1){
        scanf("%d", &input);
//        guess_time++;
        if(input != 0){
            sum += input;
            times++;
        }
        else
            break;
    }
    if(times != 0)
        printf("average: %f",sum/times);
    else
        printf("The average is N/A");
    return 0;
}

