#include <stdio.h>

int main(){
    int i =  101;
    int * i_address = &i; //& => 取址運算子 取得變數的記憶體位置
    int get_i_value = *i_address; // *間接運算子 取得該位置的變數
    printf("%d",get_i_value);
    return 0;
    }