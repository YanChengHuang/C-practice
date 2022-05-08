#include <stdio.h>
void scanarray(int array[10], int scan__length);
void printarray(int array[10]);
void maxarray(int array[]);


void scanarray(int array[10], int scan__length){ //不用回傳陣列，在C中array不會複製值進行修改而是直接對main中的array本身進行修改
    
    for(int i=0;i<scan__length;i++){
        scanf("%d",&array[i]);
    }
}



void maxarray(int N[]){//作為函示參數 陣列大小值不重要 甚至可以不用給
    int max = N[0];
    size_t length = (sizeof(N)/sizeof(N[0]));
    printf("length is %zu\n",length);
    for(int i=1;i<length;i++){
        if(N[i]>max){
            max = N[i];
        }
    }
    printf("Maximun value is %d",max);
}

void printarray(int array[10]){
    printf("Your array is : \n");
    for(int i=0;i<10;i++){
        printf("%d\n",array[i]);
    }
    
}

int main() {
    int scan_length;
    scanf("%d",&scan_length);
    int N[scan_length];
    
    scanarray(N,scan_length);
    
    maxarray(N);

    return 0;
}