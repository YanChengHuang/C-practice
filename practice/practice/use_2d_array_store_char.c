#include <stdio.h>

void print_array(char(*array)[4] ,int N ,int M){
    printf("input :\n");
    for(int i=0;i<N;i++){
        // for(int j=0;j<M;j++){
            printf("%s",array[i]);
        // }
     printf("\n");
    }
}

int main() {
    char v[3][4] = {"How","are","you"};//每個字元都做修改
    const char *str[3] = {"How","are","you"}; //只記"How","are","you"三個字的開頭位置
    char *str_2[3] = {v[0],v[1],v[2]}; //只記"How","are","you"三個字的開頭位置
    str_2[0] = "what";
    printf("%s",str_2[0]);
    
    return 0;
}