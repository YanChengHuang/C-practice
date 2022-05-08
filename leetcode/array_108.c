#include <stdio.h>
#include <stdlib.h>
struct bin_tree {
    int val;
    struct bin_tree * right, * left;
    };
typedef struct bin_tree TreeNode;


void insert(TreeNode ** tree, int val){
    TreeNode *temp = NULL;
    if(!(*tree)){ //*tree = NULL進入
        temp = (TreeNode *)malloc(sizeof(TreeNode));
        temp->left = temp->right = NULL;
        temp->val = val;
        *tree = temp;
        return;
    }
    if(val < (*tree)->val)  insert(&(*tree)->left, val);
    else insert(&(*tree)->right, val);
}
TreeNode* sample(TreeNode* root, int *array,int start,int end){
    int mid = ((int) (start + end)/2);  
    insert(&root, array[mid]);
    printf("mid : %d\n", mid);
    if(mid+1<end) sample(root,array,mid,end);
    if(mid>start+1) sample(root,array,start,mid);
    return root;
    

}
TreeNode* sortedArrayToBST(int* nums, int numsSize){
    TreeNode *root = NULL;
    int first = -1;
    int final = numsSize;
    root = sample(root,nums,first,final);
    // insert(&root, nums[first]);
    // insert(&root, nums[final]);
    return root;
}
void print_inorder(TreeNode * tree){
    if (tree){
        print_inorder(tree->left);
        printf("%d\n",tree->val);
        print_inorder(tree->right);
    }
}
int main(){
    // int a[8] = {-11,-10,-3,5,6,7,9,11};
    int a[2] = {-11,-9};
    TreeNode *root = NULL;
    
    root = sortedArrayToBST(a,2);
    printf("Pre Order Display\n");
    printf("point : %p\n", root);
    print_inorder(root);
    return 0;
}