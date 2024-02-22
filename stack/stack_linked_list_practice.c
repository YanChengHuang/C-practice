// C program for linked list implementation of stack
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

// A structure to represent a stack
typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

StackNode *CreateNode(int data){
    StackNode * New = (StackNode *)malloc(sizeof(StackNode));
    New->data = data;
    New->next = NULL;
    return New;
}

void push(StackNode **Node,int data){
    StackNode *NewNode = CreateNode(data);
    NewNode->next = *Node;
    *Node = NewNode;
    printf("%d pushed to stack\n", data);
    return;
}

int isempty(StackNode *root){
    return !root;
}

int pop(StackNode **Node){
    if(isempty(*Node))   return INT_MIN;
    int popped = (*Node)->data;
    *Node = (*Node)->next;
    return popped;
}

int peek(StackNode *Node){
    if(isempty(Node))   return INT_MIN;
    return Node->data;
}

int main()
{
    StackNode* root = NULL;
  
    push(&root, 10);
    push(&root, 20);
    // push(&root, 30);
  
    // printf("%d popped from stack\n", pop(&root));
  
    printf("Top element is %d\n", peek(root));
  
    return 0;
}
