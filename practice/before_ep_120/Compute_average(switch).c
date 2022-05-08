#include <stdio.h>

int main() {
    int input;
    int sum = 0;
    printf("Please enter the ID(quit: 0):");
    do{
        scanf("%d", &input);
            switch(input){
                case(1):
                    sum += 90;
                    break;
                case(2):
                    sum += 75;
                    break;
                case(3):
                    sum += 83;
                    break;
                case(4):
                    sum += 89;
                    break;
                default:
                    sum += 0;
                    break;   
            }
    }
    while(input!=0);
    printf("Total: %d",sum);
    return 0;
}