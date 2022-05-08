#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void printarray(int array[10]);

void printarray(int array[10]){
    printf("Your array is : \n");
    for(int i=0;i<10;i++){
        printf("%d\n",array[i]);
    }
    
}

int main(){
    srand(time(0)); //set seed
    
    int i , j ,n[10];
    int isUsed = 0;
    for(i=0;i<10;i++){
        do {
            n[i] = rand() % 10 + 1;
            for(j=0;j<i;j++){
                if(n[i] == n[j]){
                    isUsed = 1;
                    break;
                }
            }
        }while(j != i);
    }


    printarray(n);
}