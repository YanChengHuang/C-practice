#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};
typedef struct node Node;

Node *createList(int*,int); //串列建立函數 
void printList(Node *);  //串列列印函數 
void freeList(Node *);    //釋放串列記憶空間函數
Node *searchNode(Node *,int); //搜尋節點函數 
void insertNode(Node *,int); //插入節點函數  
Node* deleteNode(Node *,Node *); //刪除節點函數  

int main(int argc, char *argv[])
{

  Node *first, *node, *delete_node;
  int arr[]={14,27,32,46};
  first=createList(arr,4);
  printList(first);
  node=searchNode(first,32); //找出節點值為38的位址
  printf("\n");
  insertNode(node,52); //將節點46插入在節點38之後
  printList(first); 
  printf("\n");
  delete_node = searchNode(first,14);
  first = deleteNode(first,delete_node); //將節點46插入在節點38之後
  printList(first);
  freeList(first);
  
  system("PAUSE");	 
  return 0;
}

//串列建立函數 
Node *createList(int *arr,int len){
	Node *first ,*current ,*previous;
    for(int i=0;i<len;i++){
        current = (Node *)malloc(sizeof(Node));
        if (i==0) first = current;
        else previous->next=current;
        current -> data = arr[i];
        current -> next = NULL;
        previous = current;
    }
	return first;
}

//串列列印函數
void printList(Node *first){
	Node *current = first;
    while(current != NULL){
        printf("%d ",current->data);
        current = current -> next;
    }
} 

//釋放串列記憶空間函數
void freeList(Node *first){
	Node *current,*tmp;
	current=first;
	while(current!=NULL){
		tmp=current;
		current=current->next;
		free(tmp);
	}
}

Node *searchNode(Node *first,int num){
    Node *current = first;
    if(current == NULL){
        return NULL;
    }
    while(current != NULL){
        if(current -> data == num) return current;
        current = current -> next;
    }
    return NULL;
}



void insertNode(Node *node,int item){
	Node *insert_node;
    insert_node = malloc(sizeof(Node));
    insert_node->data = item;
    insert_node->next = node->next;
    node->next = insert_node;

}

Node* deleteNode(Node *first,Node *node){
	
    if(first==NULL){ //如果串列是空的，則印出Nothing to delete! */ 
		printf("Nothing to delete!\n");
		return NULL;
	}
    Node *current = first;
    Node *previous,*temp;
    while(current != NULL){
        if(first == node){
            temp = first;
            first = node->next;
            return first;
        }
        else if(current == node){
            temp = current;
            previous->next = current->next;
        }
        previous = current;
        current = current->next;
    }
    free(temp);
    return first;
}