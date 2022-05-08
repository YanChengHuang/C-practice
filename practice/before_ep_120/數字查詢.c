#include <stdio.h>

int main() {
    int scores[5] = {0};
    int id;
    for(int i=1;i<=5;i++){
        printf("%d:",i);
        scanf("%d",&scores[i-1]);
    }
    while(1){
        printf("Q:");
        scanf("%d",&id);
        if(id == 0 || id > 5) break;
        printf("%d\n",scores[id-1]);
               
    }
 
    return 0;
}