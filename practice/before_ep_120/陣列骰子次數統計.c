#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int times = 6000;
    int counter[6]={0,0,0,0,0,0};
    //初始化最少需要指定一個值其他都會預設為0
    // int counter[6]={0};也可以
    srand(time(0)); //set seed
    for(int i=1;i<=times;i++){
       int dice = rand()%6 + 1;
       counter[dice-1]++;
    }  
   for(int i=0;i<6;i++){
       printf("%d:%d\n",i+1,counter[i]);
    }  
    return 0;
}