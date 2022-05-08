#include <stdio.h>

int main() {
    int input;
    int times;
    printf("Max: ");
    scanf("%d",&input);
    for(int i=1;i<=input;i++){
        times = 0;
        for(int j=1;j<=i;j++){
            if(i%j == 0){
                times++;
            }
        }
        if(times == 2){
            printf("%d ",i);
        }
    }
    return 0;
}