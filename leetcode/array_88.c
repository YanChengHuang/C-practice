#include <stdio.h>

void shift_array(int *array,int start,int end){
    for(int i=end-1;i>start;i--){
        // printf("%d ",i);
        array[i] = array[i-1];
    }
}

void print_array(int * array,int N){
    for (int i = 0; i < N; i++){
        printf("%d ",array[i]);
    }
    
}    
//merge(a,5,0,b,5,5);
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
   int j = 0;
    for (int i=m;i<nums1Size;i++){ 
        nums1[i] = nums2[j++];
    }
    print_array(nums1,5);
    for (int sort_nums2=m;sort_nums2<nums1Size;sort_nums2++){
        int position = sort_nums2;
        int temp = nums1[sort_nums2];
        for(int j=0;j<m+sort_nums2;j++){
            if(nums1[j] >= nums1[sort_nums2]){
                position = j;
                temp = nums1[sort_nums2];
                break;
            }
        }
        printf("position: %d sort num: %d  \n",position,sort_nums2);
        shift_array(nums1,position,sort_nums2+1);
        print_array(nums1,5);
        printf("\n");
        nums1[position] = temp;
    }
   
}



int main(){
    int a[5] = {2,2,3,0,0};
    int b[5] = {1,5,0,0,0};
    // shift_array(a,1,4);
    merge(a,5,3,b,5,2);
    print_array(a,5);
    return 0;
}