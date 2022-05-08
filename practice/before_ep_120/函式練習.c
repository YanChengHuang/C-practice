#include <stdio.h>
#include <math.h>
int find_max(int,int,int); //可以是先定義較佳 (int,int,int)不需要定義參數名稱 只需要定義型態
void print_triangle(int);

int find_max(int x, int y, int z){
    int max = x;
    if(max<y)
        max = y;
    if(max<z)
        max = z;
    return max;    
}

void print_triangle(int N){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(i>=j){
                printf("*");
            }
        }
    printf("\n");
    }
    return;    
}

int main() {
    int A,B,C;
    printf("A:");
    scanf("%d",&A);
    // printf("B:");
    // scanf("%d",&B);
    // printf("C:");
    // scanf("%d",&C);
    print_triangle(A);
    // float op = div2(4);
    // printf("%d",printf("Hello12"));
    
    return 0;
}