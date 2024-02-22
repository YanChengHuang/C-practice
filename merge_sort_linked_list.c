#include <stdio.h>
#include <stdlib.h>
struct list{
    int val;
    struct list *next;
};

typedef struct list node;

void add_node(node** head, int value){
    
    node *new = (node *) malloc(sizeof(node));
    new -> val = value;
    new -> next = NULL;
    if(!(*head)){
       *head = new;
    }
    else{
        node *tmp = *head;
        while(tmp->next)    tmp = tmp->next;       
        tmp->next = new;    
    }
    return;
}

void print_node(node* head){
    while(head){
        printf("%d ",head->val);
        head = head->next;
    }
    printf("\n");
    return;
}

node *middle(node *head){
    node* fast, *slow;
    slow = fast = head;
    while(fast->next){
        
        fast = fast->next;
        if(fast->next){
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

node *merge(node *left, node *right){
    node* head;
    node* temp;
    if(left->val <= right->val){
        head = temp = left;
        left = left->next;
    }
    else{
        head = temp = right;
        right = right->next;
    }
    while(left && right){
        // printf("in while");
        if(left->val <= right->val){
            temp->next = left;   
            left = left->next;   
        }
        else{
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    if(left){
        temp->next = left;
        
    }
    if(right){
        temp->next = right;
    }
    return head;
}

node *sort(node *head){
    if(!(head->next))   return head;
    node* mid = middle(head);
    node* head2 = mid->next;
    mid->next = NULL;;
    node *left = sort(head);
    node *right = sort(head2);
    node *final = merge(left,right);
    return final;
}

int main(){
    srand(2022); //set seed
    node *head = NULL;
    for(int i=0;i<=30;i++){
        add_node(&head,rand()%60);
    }
    print_node(head);
    node *sorted_head = sort(head);
    print_node(sorted_head);
    return 0;
}