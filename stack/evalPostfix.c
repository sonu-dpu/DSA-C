#include<stdio.h>
#include <stdlib.h>
#include <ctype.h> 

typedef struct {
    int data[100];
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

void push(Stack* stack,int value){
    stack->top++;
    stack->data[stack->top] = value;
}
int pop(Stack* stack){
    if(isEmpty(stack)){
        printf("Stack Underflow!\n");
        exit(1);
    }
    return stack->data[(stack->top)--];
}
int evaluatePostfix(char* str){
    Stack stack;
    initialize(&stack);
    for(int i=0; i<strlen(str); i++){
        if(isdigit(str[i])){
            push(&stack, str[i] - '0');
        }
        else{
            int oprand2 = pop(&stack);
            int oprand1 = pop(&stack);
            int result;
            switch (str[i]){
            case '+':
                result = oprand1 + oprand2;
                break;
            case '-':
                result = oprand1 - oprand2;
                break;
             case '*':
                result = oprand1 * oprand2;
                break;
             case '/':
                result = oprand1 / oprand2;
                break;                          
            default: 
                    printf("Unsupported operator %c\n", str[i]);
                    exit(1);
            }
            push(&stack, result);
        }
    }
    return pop(&stack);
}

int main(){
    char exp[20];
    scanf("%s", exp);
    int result = evaluatePostfix(exp);
    printf("Result of postfix exp %s = %d", exp,result);
}