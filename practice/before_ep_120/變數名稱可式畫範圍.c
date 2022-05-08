#include <stdio.h>
//變數要可以使用 1.全域變數 2.在大括號內事先定義
//都符合使用較近的
int i = 1;

int main() {
    printf("%d",i); //1
    int i = 2;
    printf("%d",i); //2
    {
        printf("%d",i); //2
        int i = 3;
        printf("%d",i); //3
    }
    printf("%d",i); //2
    return 0;
}