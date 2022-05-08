#include <stdio.h>

int main() {
    int input;
    int times = 0;
    printf("Max: ");
    scanf("%d",&input);
    for(int i=input;i>=0;i--){
        if(i%3 == 2 && i%5 == 3 && i%7 == 2){
            times++;
            printf("%d ",i);
            }  
        if(times == 3)
            break;  
    }
    return 0;
}