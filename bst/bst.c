#include<stdio.h>
#include<stdlib.h>

int scanInt(char* prompt){
    int n;
    printf("%s", prompt);
    scanf("%d", &n);
    return n;
}

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* insert(Node* root, int data){
    if(root==NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }else if(data>= root->data){
        root->right = insert(root->right, data);
    }
    return root;
}
void inOrder(Node* root){
     if(root==NULL) return;
     inOrder(root->left);
     printf("%d ", root->data);
     inOrder(root->right);
}

void preOrder(Node* root){
    if(root==NULL) return;

    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(Node* root){
    if(root==NULL) return;
    preOrder(root->left);
    preOrder(root->right);
    printf("%d ", root->data);
}
// Function to search for a value in the BST
 Node* search(Node* root, int key) {
    // Base case: root is NULL or key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's data, search in right subtree
    if (key > root->data)
        return search(root->right, key);

    // Key is smaller than root's data, search in left subtree
    return search(root->left, key);
}

// Function to find the minimum value node in a tree
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// Function to delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;

    // Traverse to find the node to be deleted
    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node found: Now handle the 3 cases
        // Case 1: Node has no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: Node with one child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Node with two children
        struct Node* temp = findMin(root->right); // Find in-order successor
        root->data = temp->data; // Copy the in-order successor's content to this node
        root->right = deleteNode(root->right, temp->data); // Delete the in-order successor
    }
    return root;
}

int countLeafNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}
int countNonLeafNodes(Node* root){
    if(root==NULL || (root->left==NULL && root->right==NULL)){
        return 0;
    }

  return 1+countNonLeafNodes(root->left) + countNonLeafNodes(root->right);
}

int main(){
    Node* root = NULL;
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);
    
    printf("In-order : ");
    inOrder(root);
    printf("\n");

    int key = 6;
    // Node* result = search(root, key);

    // if (result != NULL) {
    //     printf("Node with value %d found in the BST.\n", key);
    // } else {
    //     printf("Node with value %d not found in the BST.\n", key);
    // }
    // deleteNode(root,key);
    // inOrder(root);
    printf("Pre Order: ");
    preOrder(root);
    printf("\n");
    printf("post Order: ");
    postOrder(root);
    printf("\n");
    printf("Count of leaf nodes : %d", countLeafNodes(root));
    printf("\n");
    printf("Count of non leaf nodes : %d", countNonLeafNodes(root));
}




/* our binary tree structure 

       8
      / \
     3   10
    / \    \
   1   6    14
      / \   /
     4   7 13

*/