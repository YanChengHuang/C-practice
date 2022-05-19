#include <stdio.h>
#include <stdlib.h>
void print_array(int *,int);
void copy_array(int *,int *);

void print_array(int* array ,int N){
    printf("input :");
    for(int i=0;i<N;i++){
        printf("%d\n",array[i]);
    }
}


int main(){
    int * numbers = 0; // 配置儲存整數空間的空間 0表示空指標
    int length = 0; //配置儲存整數的空間
    while(1){
        int input; //配置儲存整數的空間
        scanf("%d",&input);
        if(input == 0) break;
        
        int *larger = malloc(sizeof(int)*(length+1));//產生每次大一格的array記憶體位置 且不會被歸還
        for(int i=0;i < length;i++)  larger[i] = numbers[i];//將舊資料搬到新的記憶體空間
        free(numbers);//free會檢查是否為空指標 如果不是才會釋放記憶體空間
        numbers = larger; //將larger[0]的位置儲存到numbers
        //以上四行可簡化成  numbers = realloc(numbers,sizeof(int)*(length+1));
        
        numbers[length] = input;
        length ++ ;
    }//釋放input,larger(在while內定義的變數)
    if(length == 0) printf("no number");
    else print_array(numbers,length);
    
    return 0;
}