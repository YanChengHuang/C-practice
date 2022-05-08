#include <stdio.h>

void addone(int *n);

void addone(int *n){ //定義變數為指標 這邊德*跟下面的意義不同
    *n = *n + 1; //取n的值
}

int main(){
    int a = 1;
    addone(&a);//傳入變數n的位置
    printf("%d",a);
}