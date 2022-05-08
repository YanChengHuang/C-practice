#include <stdio.h>
//屬階梯 (一次最多只能走兩格)
int sum(int);

int sum(int i){
    if (i==1) {
        return 1;
    }
    if (i==2) {
        return 2;
    }
    return sum(i-1) + sum(i-2);
}

int main() {
    int N = 5;
   
    printf("%d",sum(N));
    return 0;
}