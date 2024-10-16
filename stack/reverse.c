#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
    char data;
    struct Node* next;
};

// Global pointer to the top of the stack
struct Node* top = NULL;

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(char data) {
    struct Node* newNode = createNode(data);
    newNode->next = top;
    top = newNode;
}

// Function to display the elements of the stack
void display() {
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%c", temp->data);
        temp = temp->next;
    }
}
void reverse(){
     char str[30];
    scanf("%[^\n]s", str);
    for(int i=0; i<strlen(str); i++){
        push(str[i]);
    }
    printf("Reversed str : ");

    // Display the stack
    display();
}

int main() {
    // Push elements onto the stack
    reverse();
   
    
    return 0;
}
