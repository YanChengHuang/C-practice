#include <stdio.h>

int main() {
    int input;
    int sum = 0;
    float times = 0;
    printf("Please enter the number(quit: 0):");
    do{
        printf("times = %d",times);
    }
    while (times>3);
    if(times != 0)
        printf("average: %f",sum/times);
    else
        printf("The average is N/A");
    return 0;
}

