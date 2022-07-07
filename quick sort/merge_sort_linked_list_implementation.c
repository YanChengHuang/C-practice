#include <stdio.h>
#include <stdlib.h>
// Node structure
typedef struct Node {
    int val;
    struct Node* next;
} Node;

void insert(int val,Node **head){
    if(!(*head)){
        Node *temp = (Node *)malloc(sizeof(Node));
        temp->val = val;
        temp->next = NULL;
        *head = temp;
        return;
    }
    insert(val,&((*head)->next));
}

void print(Node* head)
{
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

Node * middle(Node * head){
    Node *slow = head;
    Node *fast = head;
    while(fast->next){
        fast=fast->next;
        if(fast->next){
            fast = fast->next;
            slow=slow->next;
        }
    }
    return slow;
}

Node *merge(Node * left,Node * right){
    Node *temp = (Node *)malloc(sizeof(Node));
    Node *fake_head = temp;
    
    while(left && right){
        if(left->val<=right->val){
            temp->next = left;
            left=left->next;
        }
        else{
            temp->next = right;
            right=right->next;
        }
        temp = temp->next;
    }
    if(right)   temp->next = right;
    if(left)    temp->next = left;
    return fake_head->next;
}


Node *sort(Node * head){
    if(!(head->next)){
        return head;
    }

    Node* mid = (Node*)malloc(sizeof(Node));
    Node* head2 = (Node*)malloc(sizeof(Node));
    mid = middle(head);
    head2 = mid->next;
    mid->next = NULL;
    // print(head);
    // print(head2);
    Node* finalhead = merge(sort(head), sort(head2));
    return finalhead;
}

int main(void)
{
    Node* head = NULL;
    int n[] = { 7, 10, 5, 20, 3, 2 };
    for (int i = 0; i < 6; i++) {
        insert(n[i], &head); // inserting in the list
    }
    printArray(n, sizeof(n)/sizeof(int));
    printf("Sorted Linked List is: \n");
    print(sort(head)); // printing the sorted list returned
                       // by sort()
    return 0;
}

