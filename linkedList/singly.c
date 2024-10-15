#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
int scanInt(char* prompt){
    int n;
    printf("%s", prompt);
    scanf("%d", &n);
    return n;
}
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
struct Node* create(struct Node* head, int n){
    printf("enter data part of %d nodes : ", n);
    for(int i =0 ; i<n; i++){
        int data;
        scanf("%d", &data);
        head = insertFirst(head, data);
    }
    return head;
}

int countNodes(struct Node* head){
    struct Node* temp=head;
    int cnt = 0;
    while (temp!=NULL){
        temp=temp->next;
        cnt++;
    }
    printf("List has %d nodes ", cnt);
    return cnt;
}
int main(){
    struct Node* slist=NULL;
    int n;
    slist = create(slist, scanInt("Enter number of nodes to be inserted : "));
    countNodes(slist);
    display(slist);
}