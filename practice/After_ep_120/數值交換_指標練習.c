# include <stdio.h>
void swap(int *a ,int *b);
void sort(int *a, int *b);

int main(){
    int a = 4;
    int b = 3;
    sort(&a,&b);
    printf("a: %d , b: %d",a,b);
}

void sort(int *a , int *b){
    if(*b > *a){
        swap(&*a,&*b);
    }
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}