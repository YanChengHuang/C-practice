#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int times = 60;
    srand(time(0)); //set seed
    for(int i=1;i<=times;i++){
        printf("number1:%d\n",rand()%6 + 1);
    }    
    return 0;
}