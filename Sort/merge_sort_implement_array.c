/* C program for Merge Sort */
#include <stdio.h>
#include <stdlib.h>
void merge(int *arr,int left, int middle, int right){
    int r_l = middle - left + 1;
    int l_l = right - middle;
    int right_arr[r_l],left_arr[l_l];

    for(int i=0;i<=r_l;i++){
        right_arr[i] = arr[left + i];
    }
    for(int i=0;i<=l_l;i++){
        left_arr[i] = arr[i+middle+1];
    }
    int i=0,j=0;
    int k=left;
    while(i<r_l && j<l_l){
        if(right_arr[i]<=left_arr[j]){
            arr[k] = right_arr[i];
            i++;
        }
        else{
            arr[k] = left_arr[j];
            j++;
        }
        k++;
    }
    while(i<r_l){
        arr[k] = right_arr[i];
        i++;
        k++;
    }
    while(j<l_l){
        arr[k] = left_arr[j];
        j++;
        k++;
    }
}


void mergeSort(int* arr,int left,int right){
    
    if(left<right){
       int middle = left + (right-left)/2; 
        mergeSort(arr,left,middle);
        mergeSort(arr,middle+1,right);
        merge(arr,left,middle,right);
    }
}

/* UTILITY FUNCTIONS */
/* Function to print an array */
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
 
/* Driver code */
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 ,56,15,115,12};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}