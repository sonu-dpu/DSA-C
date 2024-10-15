#include <stdio.h>
#include <stdlib.h>

// Node structure to represent each stack element
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);  // Exit if memory allocation fails
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to check if the stack is empty
int isEmpty(Node* top) {
    return top == NULL;
}

// Function to push an element onto the stack
void push(Node** top, int value) {
    Node* newNode = createNode(value);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(Node** top) {
    if (isEmpty(*top)) {
        printf("Stack Underflow! No element to pop.\n");
        return -1;
    } else {
        Node* temp = *top;
        int poppedValue = temp->data;
        *top = (*top)->next;
        free(temp);
        printf("Popped %d from the stack.\n", poppedValue);
        return poppedValue;
    }
}

// Function to peek at the top element of the stack
int peek(Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return -1;
    } else {
        return top->data;
    }
}

// Function to display the stack elements
void display(Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements:\n");
        Node* temp = top;
        while (temp != NULL) {
            printf("%d\n", temp->data);
            temp = temp->next;
        }
    }
}

int main() {
    Node* top = NULL;  // Initialize an empty stack

    // Test stack operations
    push(&top, 10);
    push(&top, 20);
    push(&top, 30);
    display(top);
    
    pop(&top);
    display(top);
    
    printf("Top element is %d\n", peek(top));

    return 0;
}
