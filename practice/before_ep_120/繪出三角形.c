#include <stdio.h>

int main() {
    int input;
    printf("N: ");
    scanf("%d",&input);   
    // for(int i=1;i<=input;i++){
    //     for(int j=1;j<=i;j++){
    //         if(i<=2 || i==input ||j==1||j==i)
    //             printf("*");
    //         else
    //             printf(" ");
    //     }   
    // printf("\n");
    // }
     for(int i=1;i<=input;i++){
        for(int j=1;j<=input;j++){
            if(i==j)
                printf(" ");
            if(i+j==input+1)
                printf(" ");
            else
                printf("*");
        }   
    printf("\n");
    }
    return 0;
}