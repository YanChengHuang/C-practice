#include <stdio.h>

void swap(int* right, int* left){
    int t = *right;
    *right = *left;
    *left = t;
}
// function to print array elements
void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int know_pos(int * array,int low,int high){
    int i=low-1;

    for(int j=low;j<high;j++){
        
        if(array[j]<=array[high]){
            i++;
            swap(&array[i],&array[j]);
        }      

    }
    swap(&array[i + 1], &array[high]);
    printArray(array, 7);
    printf("%d\n",i+1);
    
    return i+1;
}

void quickSort(int * array,int low,int high){
    if(low<high){
        
        int pos = know_pos(array,low,high);

        quickSort(array,low,pos-1);
        quickSort(array,pos+1,high);
    }
}

int main(){
    int data[] = {8, 7, 2, 1, 0, 9, 6};
  
    int n = sizeof(data) / sizeof(data[0]);
  
    printf("Unsorted Array\n");
    printArray(data, n);
  
    // perform quicksort on data
    quickSort(data, 0, n - 1);
  
    printf("Sorted array in ascending order: \n");
    printArray(data, n);
}
