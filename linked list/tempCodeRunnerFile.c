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
