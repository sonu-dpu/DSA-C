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
Node* search(Node* root, int key){
    if(root==NULL) return NULL;
    if(root->data==key) return root;
    if(key < root->data){
        return search(root->left, key);
    }else if(key >= root->data){
        return search(root->right, key);
    }
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
    inOrder(root);
    printf("\n");
    Node* node = search(root, scanInt(""));
    if(node==NULL){
        printf("Element not found :" );
    }else{
        printf("Node found %d", node->data);
    }

}