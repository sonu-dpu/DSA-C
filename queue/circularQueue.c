#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Define the maximum size of the queue

// Queue structure
typedef struct {
    int data[MAX];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initialize(Queue *queue) {
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is full
int isFull(Queue *queue) {
    return (queue->rear + 1) % MAX == queue->front;
}

// Function to check if the queue is empty
int isEmpty(Queue *queue) {
    return queue->front == -1;
}

// Function to enqueue (add) an element to the queue
void enqueue(Queue *queue, int value) {
    if (isFull(queue)) {
        printf("Queue Overflow! Cannot enqueue %d\n", value);
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear = (queue->rear + 1) % MAX;
        queue->data[queue->rear] = value;
        printf("Enqueued %d to the queue.\n", value);
    }
}

// Function to dequeue (remove) an element from the queue
int dequeue(Queue *queue) {
    if (isEmpty(queue)) {
        printf("Queue Underflow! No element to dequeue.\n");
        return -1;
    } else {
        int value = queue->data[queue->front];
        if (queue->front == queue->rear) {
            // If the queue becomes empty after this operation
            queue->front = -1;
            queue->rear = -1;
        } else {
            queue->front = (queue->front + 1) % MAX;
        }
        printf("Dequeued %d from the queue.\n", value);
        return value;
    }
} 

void display(Queue *queue){
    if(isEmpty(queue)){
        printf("Queue is empty.\n");
    }else{
        int i = queue->front;
        while(1){
            printf("%d ", queue->data[i]);
            if(i == queue->rear) break;
            i = (i+1)%MAX;
        }
    }
}

int main() {
    Queue queue;
    initialize(&queue);

    // Test queue operations
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);  // Queue should be full after this
    display(&queue);
    
    dequeue(&queue);
    display(&queue);

    enqueue(&queue, 60);  // Enqueue after dequeuing
    display(&queue);

    return 0;
}


