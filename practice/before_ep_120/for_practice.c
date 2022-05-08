#include <stdio.h>

int main() {
    int input;
    int sum = 0;
    int i=0 ;
    for(i=1;i<=10;i++){
        if((i%3 != 0) &&(i%2 == 0))
        printf("%d\n",i);
    }
    return 0;
}