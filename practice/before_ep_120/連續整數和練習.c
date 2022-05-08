#include <stdio.h>

int main() {
    int input;
    int sum = 0;
    int i=0 ;
    scanf("%d",&input);
    for(i=1;i<=input;i++){
        sum += i;     
    }
    printf("Sum: %d\n",sum);
    return 0;
}