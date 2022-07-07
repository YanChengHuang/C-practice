#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct stack{
    unsigned int max;
    int top;
    int* array;
} stack;

stack* create_stack(int max){
    stack* create = (stack *)malloc(sizeof(stack));
    create->top = -1;
    create->max = max;
    create->array = (int *)malloc(sizeof(int)*max);
    return create;
}

int is_empty(stack* temp){
    return temp->top == -1;
}

int is_full(stack* temp){
    return temp->top == temp->max - 1;
}

void pop(stack* temp,int val){
    
    if(is_full(temp))   return;
    temp->top += 1;
    temp->array[temp->top] = val;
    return ;
}

int peek(stack* temp){
    // printf("%d\n",temp->top);
    if(is_empty(temp))    return INT_MIN;
    return temp->array[temp->top];
}

int main(){
    stack* St = create_stack(1);
    pop(St,10);
    pop(St,50);
    printf("%d",peek(St));
    return 0;
}