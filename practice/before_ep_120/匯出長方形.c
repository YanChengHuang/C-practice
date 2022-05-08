#include <stdio.h>

int main() {
    int input;
    printf("N: ");
    scanf("%d",&input);   
    for(int i=1;i<=input;i++){
        for(int j=1;j<=input;j++){
            if((i==1) || (j==1) || (i==input) || (j==input)){
                printf("*");
            }
            else
                printf(" ");
        }    
    printf("\n");
    }
    return 0;
}