#include <stdio.h>

int main() {
    int input,input_2;
    printf("plus: ");
    scanf("%d",&input);
    printf("mul: ");
    scanf("%d",&input_2);      
     for(int i=1;i<=input;i++){
        int number2 = input-i;
        if((number2*i==input_2)&&(i<=number2))
            printf("number1:%d, number2=%d\n",i,number2);
    }
    return 0;
}