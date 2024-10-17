#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
int scanInt(char* prompt){
    int n;
    printf("%s", prompt);
    scanf("%d", &n);
    return n;
}
 Node *createNode(int data){
    struct Node* newNode = (Node*)malloc(sizeof( Node));
    newNode->data=data;
    newNode->next=newNode->prev=NULL;
    return newNode;
}

void createList(Node** head, int n){
    Node* newNode;
    Node* temp = NULL;
    for(int i=0; i<n; i++){
        int data = scanInt("Enter data part : ");
        if(*head==NULL){
            temp = createNode(data);
            *head = temp;
        }else{
            newNode = createNode(data);
            temp->next = newNode;
            newNode->prev=temp;
            temp=newNode;
        }
    }

}
void insertByIdx(Node** head, int data, int pos){
    if(*head==NULL){
        printf("List has few elemnets than %d\n", pos);
        return;
    }
    Node* newNode = createNode(data);
    if(pos==1){
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }else{
        Node* temp = *head;
        for(int i=1; (i<pos-1 && temp->next!=NULL); i++){
            temp = temp->next;
        }
        newNode->next=temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;   
    }
}
void display( Node* head){
    struct Node* temp=head;
    while (temp!=NULL){
        printf("%d <-> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
int main(){
    Node *dlist = NULL;
    createList(&dlist, scanInt("Enter size of list  : "));
    display(dlist);
    insertByIdx(&dlist, scanInt("Enter data : "), 1);
    display(dlist);
    insertByIdx(&dlist, scanInt("Enter data : "), 2);
    display(dlist);
}