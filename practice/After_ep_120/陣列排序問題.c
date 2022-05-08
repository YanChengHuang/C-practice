#include <stdio.h>
void scanarray(int array[10]);
void printarray(int array[10]);


void scanarray(int array[10]){ //不用回傳陣列，在C中array不會複製值進行修改而是直接對main中的array本身進行修改
    for(int i=0;i<10;i++){
        scanf("%d",&array[i]);
    }
}

void printarray(int array[10]){
    printf("Your array is : \n");
    for(int i=0;i<10;i++){
        printf("%d\n",array[i]);
    }
    
}

int main() {
    int N[10];
    
    scanarray(N);
    
    for(int i=0;i<10;i++){
        int max = N[i];
        int position = i;
        for(int j=i;j<10;j++){
            if(N[j]<max){
                max = N[j];
                position = j;
            }    
        } 
        int temp = N[i];
        N[i] = max;
        N[position] = temp;
    }
    printarray(N);
    return 0;
}