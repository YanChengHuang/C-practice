#include <stdio.h>
void print_array(int *,int,int);

void print_array(int* array ,int N ,int M){
    printf("input \n:");
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            printf("%d",array[i*N + j]);
        }
     printf("\n");
    }
}

int main() {
    int v[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int p[3] = {1,2,3};
    int (*pointer)[3] = v;
    int *p0 = &*pointer[0];

    // printf("%p\n", pointer);
    // printf("%p\n", ++pointer);
    // print_array(pointer,3,3);
    // printf("%d",pointer);
    printf("%d\n",p0[1]);
    printf("%d\n",*pointer[0]);
   
    // printf("%d\n",*pointer[1]);
    // printf("%d\n",*pointer[2]);
    return 0;
}