#include <stdio.h>
#include <stdlib.h>
#include <math.h>
struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
      int height;
};
 
typedef struct TreeNode TreeNode;
TreeNode* createNode(int key);
int getHeight(TreeNode* node);
int getBalancedFactor(TreeNode* node);

TreeNode* createNode(int key){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode*));
    node->val = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getHeight(TreeNode* node){//取得高度
    if(node == NULL) return 0;
    return node->height;
}

int getBalancedFactor(TreeNode* node){
    if(node == NULL) return 0;
    return (getHeight(node->left) - getHeight(node->right));
}

TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct Node* root = NULL;
    for(int i=0; i<numsSize; i++){
        root = insert(root, nums[i]);
        
    }
    return root;
}

TreeNode* rightRotate(TreeNode* y){
    TreeNode* x = y->left;
    TreeNode* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = fmax(getHeight(y->left), getHeight(y->right))+1;
    x->height = fmax(getHeight(x->left), getHeight(x->right))+1;
    
    return x;
}

TreeNode* leftRotate(TreeNode* x){
    TreeNode* y = x->right;
    TreeNode* T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    y->height = fmax(getHeight(y->left), getHeight(y->right))+1;
    x->height = fmax(getHeight(x->left), getHeight(x->right))+1;
    
    return y;
}

TreeNode* insert(TreeNode* node, int val){
    if(node == NULL) return createNode(val);//沒有root先建root
    if(val < node->val){
        node->left = insert(node->left, val);
    }
    else if(val > node->val){
        node->right = insert(node->right, val);
    }
    node->height = fmax(getHeight(node->left), getHeight(node->right))+1;
    int bf = getBalancedFactor(node);
    
    if(bf>1 && val<node->left->val) return rightRotate(node);
    if(bf<-1 && val>node->right->val) return leftRotate(node);
    if(bf>1 && val>node->left->val){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(bf<-1 && val<node->right->val){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}
int* inorderTraversal(TreeNode* root){
    inorderTraversal(root->left);
    printf("%d  ",root->val);
    inorderTraversal(root->right);
    return 0;
} 
int main(){
    int a[5] = {5,6,11,7,9};
    // int a[2] = {-11,-9};
    TreeNode *root = NULL;
    
    root = sortedArrayToBST(a,5);
    inorderTraversal(root);
    printf("Display tree \n");
    return 0;
}