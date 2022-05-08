#include <stdio.h>

int main() {
    int scores[10] = {0};
    int id,L,R;
    for(int i=1;i<=10;i++){
        printf("%d:",i);
        scanf("%d",&scores[i-1]);
    }
    while(1){
        printf("L R:");
        scanf("%d%d",&L,&R);
        if(L == 0 || R == 0) break;
        for(int i=0;i<10;i++){
            if((scores[i]>=L)&&(scores[i]<=R))
                printf("%d ",scores[i]);
        }
        printf("\n");
               
    }
 
    return 0;
}