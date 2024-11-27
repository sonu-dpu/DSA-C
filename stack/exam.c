#include<stdio.h>
#define MAX 5
typedef struct stack{
    int arr[MAX];
    int top;
} Stack;
void init(struct stack* s){
    s->top=-1;
}
void push(struct stack* s, int data){
    if(s->top==MAX-1){
        printf("stack is full\n");
        return;
    }
    s->top++;
    s->arr[s->top] = data;
    printf("pushed %d onto stack\n", data);
}
int pop(struct stack* s){
    if(s->top==-1){
        printf("Stack is empty\n");
        return -1;
    }
    int data = s->arr[s->top];
    s->top--;
    printf("popped %d\n", data);
    return data;
}
int main(){
    struct stack s;
    init(&s);
    push(&s, 10);
    push(&s, 30);
    push(&s, 60);
    push(&s, 60);
    push(&s, 60);
    push(&s, 60);
    push(&s, 60);
    pop(&s);
    pop(&s);
    pop(&s);
    pop(&s);

}