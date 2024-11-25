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
void display(struct Node* n1){
    struct Node* temp=n1;
    while (temp!=NULL){
        printf("%d -> ", temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}



int searchElement(struct Node* head, int key){
    struct Node* temp = head;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(temp->data == key){
            //element found return pos
            return cnt;
        }
        temp = temp->next;
    }
    //element not found 
    return -1;
}

void deleteEnd(struct Node* head){
    struct Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    int data = temp->next->data;
    free(temp->next);
    printf("\nfreed %d\n", data);
    temp->next = NULL;

}

struct Node* insertMid(struct Node* head, int data, int pos){
    struct Node* temp = head;
    struct Node* newNode = createNode(data);
    if(pos==1){
        newNode->next = temp;
        return newNode;
    }else{
        for(int i=1; i<pos-1; i++){
           temp=temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    return head;

}
///c) Write C function to reverse singly linked list.
struct Node* reverseList(struct Node* head){
    struct Node* temp = head;
    struct Node* reverse = NULL;
    while (temp!=NULL){
        int data = temp->data;
        reverse = insertFirst(reverse, data);
        temp = temp->next;
    }
      
    return reverse;
}

int main(){
    struct Node* slist =NULL;
    slist = insertFirst(slist,10);
    slist = insertFirst(slist,12);
    slist = insertFirst(slist,13);
    slist = insertFirst(slist,15); 
    display(slist);
    slist = insertMid(slist, 11, 1);
    display(slist);
    slist = reverseList(slist);
    display(slist);
}