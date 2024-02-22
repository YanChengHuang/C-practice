#include <iostream>
#include <cstdlib>

using namespace std;

class Node{
public:   
    int num;
    Node* next;
    void PushRandom(Node**, int);
    void Print(string);
};

void Node::PushRandom(Node** head, int size){
    for(int i=0;i<size;i++){
        Node* new_node = new Node;
        new_node->num = rand()%30;
        new_node->next = *head;
        *head = new_node; 
    }    
    return;
}

void Node::Print(string postfix=""){
    cout<<postfix<<endl;
    Node* head = this;
    while(head){
        cout<<(head->num)<<" ";
        head = head->next;
    }
    cout<<endl;
    return;
}

class UseForDisplayArray
{
protected:
    int* Array_head;
    int Size;

public:
    UseForDisplayArray(int* head, int size)
    {
        Array_head = head;
        Size = size;
    }
    void PrintArray(string Postfix = "")
    {
        cout << Postfix;
        for (int i = 0; i < Size; i++)
            cout << Array_head[i] << " ";
        cout << endl;
    }
    virtual void Run(void) = 0;
};

class MergeSort : public UseForDisplayArray
{
private:
    int begin;
    int end;

public:
    MergeSort(int *head, int size) : UseForDisplayArray(head, size)
    {
        begin = 0;
        end = Size - 1;
    };

    void merge(int *head, int begin, int mid, int end)
    {
        int left_size = mid - begin + 1;
        int right_size = end - mid;
        int *left_array = new int(left_size);
        int *right_array = new int(right_size);

        for (int i = 0; i < left_size; i++)
        {
            left_array[i] = head[begin + i];
        }
        for (int i = 0; i < right_size; i++)
        {
            right_array[i] = head[mid + 1 + i];
        }

        int left_idx = 0, right_idx = 0, head_idx = 0;
        while ((left_idx < left_size) && (right_idx < right_size))
        {
            if (left_array[left_idx] < right_array[right_idx])
            {
                head[begin + head_idx] = left_array[left_idx];
                left_idx++;
            }
            else
            {
                head[begin + head_idx] = right_array[right_idx];
                right_idx++;
            }
            head_idx++;
        }
        while ((left_idx != left_size) || (right_idx != right_size))
        {
            if (left_idx != left_size)
            {
                head[begin + head_idx] = left_array[left_idx];
                left_idx++;
            }
            else
            {
                head[begin + head_idx] = right_array[right_idx];
                right_idx++;
            }
            head_idx++;
        }
        delete left_array, right_array;
        return;
    }

    void Sort(int *head, int begin, int end)
    {
        if (end <= begin)
            return;
        int mid = begin + (end - begin) / 2;
        Sort(head, begin, mid);
        Sort(head, mid + 1, end);
        merge(head, begin, mid, end);
    }

    void Run()
    {
        Sort(Array_head, begin, end);
    }
};

class QuickSort : public UseForDisplayArray
{
private:
    int begin;
    int end;
    int pivot;

public:
    QuickSort(int *head, int size) : UseForDisplayArray(head, size)
    {
        begin = 0;
        end = size - 1;
        pivot = end;
    };
    void Swap(int *i, int *j)
    {
        int temp = *i;
        *i = *j;
        *j = temp;

        // int *temp;
        // *temp = *i;
        // *i = *j;
        // *j = *temp;
        return;
    }
    void Sort(int* head, int start, int end){
        int interval = end-start;
        if(interval <= 1) return;
        int pivot=head[end];
        int change_point=start;
        for(int i=0;i<interval;i++) if(head[start+i]<pivot) Swap(&head[start+i], &head[change_point++]);
        Swap(&head[end], &head[change_point]);
        Sort(head, start, change_point-1);
        Sort(head, change_point+1, end);
    };
    void Run()
    {
        Sort(Array_head, begin, end);
        return;
    }
};

class MergeSortForList{
private:
    Node* list_head;

public:
    MergeSortForList(Node* head){
        list_head = head;
    }

    Node* Split(Node* head){
        Node* fast=head,*slow=head;
        if(!(slow->next)) return slow;
        while(fast->next){ 
            Node* temp = slow;
            if(!(fast->next->next)||!(fast->next->next->next)){
                slow = slow->next;
                fast = fast->next;
                temp->next = NULL;
            } 
            else{
                slow = slow->next;
                fast = fast->next;
            }
            if(fast->next) fast=fast->next;
        }
        return slow;
    }

    Node* Merge(Node* left, Node* right){
        Node* head = new Node;
        Node* temp = head; 
        Node node;
        while(left && right){
            if(left->num < right->num){
                temp->next = left;
                left = left->next;
            }
            else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        while(left || right){
            if(left){
                temp->next = left;
                left = left->next;
            }
            else{
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        return head->next;
    }

    Node* MergeSort(Node* left, Node* right){
        Node node;
        Node* left_right = Split(left);
        Node* left_left = left;
        Node* right_right = Split(right);
        Node* right_left = right;

        if((left_right == left_left) && (right_right == right_left)) return Merge(left, right);
        else if((left_right != left_left) && (right_right == right_left)) return Merge(MergeSort(left_left, left_right), right);
        else if((left_right == left_left) && (right_right != right_left)) return Merge(left, MergeSort(right_left, right_right));
        else return Merge(MergeSort(left_left, left_right), MergeSort(right_left, right_right));
    }

    void Run(){
        
        Node* right = Split(list_head);
        Node* result = MergeSort(list_head, right);
        (*result).Print("Final result: ");
    }
};

int main()
{
    // int arr[] = {13,12,11,10,9,8,7,4,2};
    // int arr_size = sizeof(arr) / sizeof(arr[0]);
    // MergeSort Msort(arr, arr_size);
    // QuickSort Qsort(arr, arr_size);
    // cout << "Given array is \n";
    // Qsort.PrintArray();
    // Qsort.Run();
    // cout << "Sorted array is \n";
    // Msort.PrintArray();
    // Qsort.PrintArray();

    
    Node* head=NULL;
    (*head).PushRandom(&head, 30);
    (*head).Print("Whole list");
    MergeSortForList Msort_l(head);
    Msort_l.Run();
    return 0;
}