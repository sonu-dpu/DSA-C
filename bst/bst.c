#include<stdio.h>
#include<stdlib.h>
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
Node* insertNode(Node* root, int data){
    if(root==NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }else if(data>= root->data){
        root->right = insertNode(root->right, data);
    }
    return root;
}
int main(){
    Node* root = NULL;
    root = insertNode(root, 10);
    printf("%d", root->data);
}