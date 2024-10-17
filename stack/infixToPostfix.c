#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>  // For isdigit function
#include <string.h> // For string functions

#define MAX 100 // Define maximum size of the stack

// Stack structure
typedef struct {
    char data[MAX];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
int isFull(Stack* stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack* stack, char value) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    printf("%c pushed onto stack\n",value);
    stack->data[++(stack->top)] = value;
}

// Function to pop an element from the stack
char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->data[(stack->top)--];
}
char peek(Stack* stack) {
    if (isEmpty(stack)) {
        return -1;
    }
    return stack->data[stack->top];
}

int precedence(char op){
    if(op=='+' || op=='-') return 1;
    else if(op=='*' || op=='/') return 2;
    return 0;
}
int isOperator(char ch){
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

void convertToPostfix(char* infix, char* postfix) {
    Stack stack;
    initialize(&stack);
    int k = 0; // Index for postfix expression

    for (int i = 0; infix[i] != '\0'; i++) {
        char current = infix[i];

        // If the current character is an operand, add it to postfix expression
        if (isalnum(current)) {
            postfix[k++] = current;
        }
        // If the current character is '(', push it to the stack
        else if (current == '(') {
            push(&stack, current);
        }
        // If the current character is ')', pop from stack until '(' is found
        else if (current == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(') {
                postfix[k++] = pop(&stack);
            }
            pop(&stack); // Pop '(' from the stack
        }
        // If the current character is an operator
        else if (isOperator(current)) {
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(current)) {
                postfix[k++] = pop(&stack);
            }
            push(&stack, current);
        }
    }

    // Pop all remaining operators in the stack
    while (!isEmpty(&stack)) {
        postfix[k++] = pop(&stack);
    }

    postfix[k] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[MAX];
    char postfix[MAX];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    convertToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);

    return 0;
}