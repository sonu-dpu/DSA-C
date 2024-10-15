#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Global pointer to the top of the stack
struct Node* top = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to push an element onto the stack
void push(int data) {
    struct Node* newNode = createNode(data);
    newNode->next = top;
    top = newNode;
}

// Function to display the elements of the stack
void display() {
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    // Push elements onto the stack
    push(10);
    push(30);
    push(50);

    // Display the stack
    display();
    
    return 0;
}
