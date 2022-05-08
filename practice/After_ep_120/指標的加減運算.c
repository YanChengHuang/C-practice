# include <stdio.h>

int main(){
    int v[5] = {0,1,2,3,4};
    printf("%d\n",*(&v[0]+1));//指標array位置加1就是下一個array之值 v[0] => v[1]
    
    int *n = v;//把v[0]的位置傳給n,v的真實意義其實是指標
    printf("%d\n",*(n+2));
    
    printf("for\n");
    for(int i=0;i<5;i++){
        printf("%d\n",*(n+i));
    }
    
    printf("n[0]\n");
    printf("%d\n%d",n[0],0[n]);//a[b]真實意義是*(a+b) 故n[0] == 0[n]

    return 0;
}

