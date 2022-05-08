#include <stdio.h>

int main() {
    int input;
    printf("Max: ");
    scanf("%d",&input);
    for(int i=input;i>=i;i--){
        if(input%i == 0){
            printf("%d ",i);
            }    
    }
    return 0;
}