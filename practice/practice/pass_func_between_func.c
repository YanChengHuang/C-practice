#include <stdio.h>
int add(int,int);
int multiple(int,int);
int cal(int (*)(int,int));

int main(){
    
    printf("%d",cal(multiple));
}

int cal(int (*op)(int,int)){ //int (*op)(int,int) op回傳類別 *op(op參數類別,op參數類別)
    int res = 1;
    for(int i=1;i<=5;i++){
        res = op(res,i);
    }
    return res;
}

int add(int a,int b){
    return a+b;
}

int multiple(int a,int b){
    return a*b;
}