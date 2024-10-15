#include<stdio.h>
#define MAX 5
typedef struct stack{
    int arr[MAX];
    int top;
} Stack;

void init(Stack* s){
    s->top=-1;
}
int isFull(Stack* s){
    return s->top == MAX-1;
}
int isEmpty(Stack* s){
    return s->top==-1;
}
void push(Stack* s, int data){
    if(isFull(s)){
        printf("Stack overflow!!!\n");
        return;
    }
    s->top++;
    s->arr[s->top]=data;
    printf("%d inserted\n", data);
}
void pop(Stack* s){
    if(isEmpty(s)){
        printf("stack is empty\n");
        return;
    }
    int data = s->arr[s->top];
    s->top--;
    printf("Deleted %d \n", data);
}
 void display(Stack*s){
    if (isEmpty(s)){
        printf("stack is empty\n");
    }else{
        for (int i = s->top; i >=0; i--){
            printf("%d\n",s->arr[i]);
        }
    }
    
 }
int main(){
    Stack stack;
    init(&stack);
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 10);
    /// stack overflow here
    // push(&stack, 50);
    // pop(&stack);
    // pop(&stack);
    // pop(&stack);
    // pop(&stack);
    // ///stack got empty herer
    // pop(&stack);
    // pop(&stack);

    display(&stack);

}