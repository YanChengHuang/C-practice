#include <stdio.h>
#include <stdlib.h>

//基本資料 : 只能儲存單一整數 例如: int
//複合資料 : 可以儲存多個基本資料


//結構宣告
struct node{
    int data;//整數
    struct node *next; //指標
};

typedef struct node Node;

int main(){
    int i,num;
    Node *first,*current,*previous;
    printf("Number of nodes: ");
    scanf("%d",&num);
    
    for(i=0;i<num;i++){
        current=(Node *) malloc(sizeof(Node));//得到建立新節點位置
        printf("Data for node %d: ",i+1);
        scanf("%d",&(current->data)); //輸入節點的data成員
        if(i == 0) first = current;
        else previous -> next = current;
        current -> next = NULL;
        previous=current; //把前一個節點設成目前的節點
    }
    
   current = first;
    while(current!=NULL){
       printf("address %p ",current);
       printf("data %d ",current -> data);
       printf("next %p\n",current -> next);
       current = current -> next;
    } 
    
    system("PAUSE");	 
    return 0;
}