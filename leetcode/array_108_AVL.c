// #include <stdio.h>
#include <stdlib.h>
// #include <math.h>
#define COUNT 5
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};
typedef struct Node TreeNode;
TreeNode * createNode(int key);
int getHeight(struct Node* node);
int getBalancedFactor(struct Node* node);
struct Node* rightRotate(struct Node* y);
struct Node* leftRotate(struct Node* x);
struct Node* insert(struct Node* node, int val);
TreeNode* sortedArrayToBST(int* nums, int numsSize);
void print2DUtil(TreeNode *root, int space);
void print2D(struct Node *root);

struct Node * createNode(int key){
    struct Node * node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getHeight(struct Node* node){//取得高度
    if(node == NULL) return 0;
    return node->height;
}

int getBalancedFactor(struct Node* node){
    if(node == NULL) return 0;
    return (getHeight(node->left) - getHeight(node->right));
}

struct Node* rightRotate(struct Node* y){
    struct Node* x = y->left;
    struct Node* T2 = x->right;
    
    x->right = y;
    y->left = T2;
    
    y->height = fmax(getHeight(y->left), getHeight(y->right))+1;
    x->height = fmax(getHeight(x->left), getHeight(x->right))+1;
    
    return x;
}

struct Node* leftRotate(struct Node* x){
    struct Node* y = x->right;
    struct Node *T2 = y->left;
    
    y->left = x;
    x->right = T2;
    
    y->height = fmax(getHeight(y->left), getHeight(y->right))+1;
    x->height = fmax(getHeight(x->left), getHeight(x->right))+1;
    
    return y;
}

struct Node* insert(struct Node* node, int val){
    if(node == NULL) return createNode(val);//沒有root先建root
    if(val < node->key){
        node->left = insert(node->left, val);
    }
    else if(val > node->key){
        node->right = insert(node->right, val);
    }
    node->height = fmax(getHeight(node->left), getHeight(node->right))+1;
    int bf = getBalancedFactor(node);
    if(bf>1 && val<node->left->key) return rightRotate(node);//LL型 right rotate即可

    if(bf<-1 && val>node->right->key) return leftRotate(node);//RR型 left rotate即可
        
    if(bf>1 && val>node->left->key){ //LR型 先left再right rotate
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if(bf<-1 && val<node->right->key){ //RL型 先right再left rotate
        node->right = rightRotate(node->right);    
        return leftRotate(node);
    }
    return node;
}



TreeNode* sortedArrayToBST(int* nums, int numsSize){
    struct Node* root = NULL;
    for(int i=0; i<numsSize; i++){
        
        root = insert(root, nums[i]);
        printf("------------\n");
        print2D(root);
        
    }
    return root;
}
// Function to print binary tree in 2D
// It does reverse inorder traversal
void print2DUtil(TreeNode *root, int space)
{
    // Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d(%d)\n", root->key, root->height);
 
    // Process left child
    print2DUtil(root->left, space);
}
 
// Wrapper over print2DUtil()
void print2D(struct Node *root)
{
   // Pass initial space count as 0
   print2DUtil(root, 0);
}
int main(){
    int a[8] = {9,7,4,5,21,65,1,3};
    // int a[2] = {-11,-9};
    TreeNode *root = NULL;
    
    root = sortedArrayToBST(a,8);
    printf("Display tree \n");
    // printf("point : %p\n", root);
    
    return 0;
}
