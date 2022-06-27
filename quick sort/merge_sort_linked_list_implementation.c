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
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

Node * middle(head){
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
    Node *fake_head = (Node *)malloc(sizeof(Node));
    Node *temp = fake_head;
    while(!left && !right){
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
    while(right){
        temp->next = right;
        right=right->next;
        temp = temp->next;
    }
     while(left){
        left->next = left;
        left=left->next;
        temp = temp->next;
    }
    temp->next = NULL;
    return fake_head->next;
}


Node *sort(Node * head){
    if(!head->next){
        return head;
    }

    Node* mid = middle(head);
    Node* head2 = mid->next;
    mid->next = NULL;
    print(head);
    print(head2);
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

