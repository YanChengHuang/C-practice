#include <stdio.h>
void print_array(int *,int);
void copy_array(int *,int *);

void print_array(int* array ,int N){
    for(int i=0;i<N;i++){
        printf("%d\n",array[i]);
    }
}


int main(){
    int * numbers; // 配置儲存整數空間的空間
    int length = 0; //配置儲存整數的空間
    while(1){
        int input; //配置儲存整數的空間
        scanf("%d",&input);
        if(input == 0) break;
        int larger[length+1];  //產生一個大小為length+1的array  
        for(int i=0;i < length;i++)  larger[i] = numbers[i];
        numbers = larger; //將larger[0]的位置儲存到numbers
        numbers[length] = input;
        length ++ ;
    }//釋放input,larger(在while內定義的變數)
    if(length == 0) printf("no number");
    else print_array(larger,length);//未定義行為(larger記憶體空間已經被釋放)
    
    return 0;
}