
# Basic code
```c
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
```


# Search Element in Singly LL
```c
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
```

# Delete last node in singly LL

```c
struct Node* deleteEnd(struct Node* head){
    struct Node* temp = head;
    while(temp->next->next!=NULL){
        temp = temp->next;
    }
    int data = temp->next->data;
    free(temp->next);
    printf("\nfreed %d\n", data);
    temp->next = NULL;
    return head;
}
```

# Insert midle Singly LL
```c
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
```