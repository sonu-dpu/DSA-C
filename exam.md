
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

# reverse using extra space 
```c
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
```

# Binary Search 
## Using loop
```c
int binarySearch(int arr[], int n, int key){
    int left = 0;
    int right = n-1;
    while(left<=right){// left should not cross right 
        int mid = (left + right)/2;
        if(arr[mid]==key){
            return mid;
        }
        // ignore left porting
        if(arr[mid]<key){
            left =  mid+1;
        }else{
            right = mid-1;
        }
    }
    return -1;
}
```
## using recursion
```c
int binary2(int arr[], int left,int right, int key){
    if (left>right){
        return -1;
    }
    int mid = (left + right)/2;
    if(arr[mid]==key){
        return mid;
    }
    if(arr[mid]<key){
        return binary2(arr, mid+1, right, key);
    } else{
        return binary2(arr, left, mid-1, key);
    }

}
```

