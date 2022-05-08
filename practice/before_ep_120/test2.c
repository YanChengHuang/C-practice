#include <stdio.h>

int main() {
    int a,b;
    float ans;
    char op;
    scanf("%d%c%d", &a, &op, &b);
    switch(op){
        case '+':
            ans = a+b;
            break;
        case '-':
            ans = a-b;
            break;
        case '*':
            ans = a*b;
            break;
        case '/':
            ans = (float)a/b;
            break;
    }
    printf("ANS: %f\n",ans);
    return 0;
}
