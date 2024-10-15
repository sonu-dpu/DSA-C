#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node *createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
void display(struct Node* n1){
    struct Node* temp=n1;
    while (temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL");

}
struct Node* insertFirst(struct Node* slist, int data){
    struct Node* newNode = createNode(data);
    if(slist==NULL){
        return newNode;
    }else{
        newNode->next=slist;
        slist = newNode;
        return slist;
    }
    
}
int main(){
    struct Node* slist=NULL;
    int n;
    scanf("%d", &n);
    for(int i =0 ; i<n; i++){
        int data;
        scanf("%d", &data);
        slist = insertFirst(slist, data);
    }

    display(slist);
}